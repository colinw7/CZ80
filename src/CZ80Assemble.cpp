#include <CZ80.h>
#include <CZ80Op.h>

#include <CStrUtil.h>
#include <COStreamFile.h>
#include <CFileParse.h>

#ifdef CL_PARSER
#include <CCeilP.h>
#endif

#include <cstdarg>

bool
CZ80::
assemble(CFile *ifile, std::ostream &os)
{
  COStreamFile ofile(os);

  return assemble(ifile, &ofile);
}

bool
CZ80::
assemble(CFile *ifile, CFile *ofile)
{
  return assemble(ifile, ofile);
}

bool
CZ80::
assemble(CFile *ifile, CFileBase *ofile)
{
  assemble_data_.init();

  bool flag = true;

  bool continued;

  CFileParse parse(ifile);

  for (uint pass = 1; pass <= 2; ++pass) {
    parse.rewind();

    setPC(0);

    assemble_data_.initPass();

    assembleLoadLine(&parse);

    while (! parse.eof()) {
      if (getVerbose() && pass == 2 && ! assemble_data_.isStream()) {
        std::string str = parse.getBuffer();

        if (str != "")
          ofile->write("; " + parse.getBuffer() + '\n');
      }

      std::string op_str;

      if (! assembleParseOp(&parse, op_str, pass, &continued)) {
        flag = false;
        break;
      }

      if (pass == 2) {
        if (! assemble_data_.isStream()) {
          if (op_str != "")
            ofile->write(op_str + '\n');
        }
      }

      if (! continued)
        assembleLoadLine(&parse);
    }

    if (! flag)
      break;
  }

  //-----

  // Dump values for stream

  if (assemble_data_.isStream())
    assembleDumpValues(ofile);

  return flag;
}

void
CZ80::
assembleLoadLine(CFileParse *parse)
{
  parse->loadLine();

  assemble_data_.nextLine(parse);
}

void
CZ80::
assembleDumpValues(CFileBase *ofile)
{
  assemble_data_.dumpValues(ofile);
}

bool
CZ80::
assembleParseOp(CFileParse *parse, std::string &op_str, uint pass, bool *continued)
{
  bool set_op_str = ! assemble_data_.isStream() && (pass == 2);

  *continued = false;

  CZ80OpData op_data;
  CZ80Op     op, *op1;

  op_data.z80 = this;
  op_data.op  = &op;

  op.func  = NULL;
  op.type1 = A_NONE;
  op.arg1  = 0;
  op.type2 = A_NONE;
  op.arg2  = 0;

  op_data.num_values1 = 0;
  op_data.num_values2 = 0;

  CZ80Macro::ArgList macroArgs;
  std::string        macroBody;

  /*----*/

  parse->skipSpace();

  if (parse->eol() || parse->isChar(';'))
    return true;

  /*----*/

  std::string  str, str1, str2;
  uint reg_id, op_id, flag_id;

  if (! parse->readIdentifier(str)) {
    assembleError("Missing identifier");
    return false;
  }

  bool is_op = false;

  uint i, j;

  parse->skipSpace();

  if      (parse->isChar(':')) {
    parse->skipChar();

    assemble_data_.setLastLabel(str);

    assembleSetLabelValue(str, getPC());

    if (set_op_str) {
      str1 = "";
      str2 = " ; " + str + ":";

      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }

    if (! assembleParseOp(parse, op_str, pass, continued))
      return false;
  }
  else if (parse->isChar('=')) {
    parse->skipChar();

    parse->skipSpace();

    std::string expr;

    while (! parse->eol() && ! parse->isChar(';')) {
      uchar c = parse->readChar();

      expr += c;
    }

    if (! assembleEvalExpr(expr, &i)) {
      assembleError("Invalid expression \'%s\'", expr.c_str());
      return false;
    }

    assembleSetLabelValue(str, i);
  }
  else if (CStrUtil::casecmp(str, "ORG") == 0) {
    if (! assembleParseInteger(parse, pass, &i)) {
      assembleError("Invalid origin value");
      return false;
    }

#if 0
    if (pass == 2 && assemble_data_.isStream()) {
      ushort pc = getPC();

      for ( ; i < pc; ++i)
        assemble_data_.addValue(i, 0);
    }
#endif

    setPC(i);

    if (set_op_str) {
      str1 = "";
      str2 = " ; ORG  0x" + CStrUtil::toHexString(i & 0xFFFF, 4);

      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }
  }
  else if (CStrUtil::casecmp(str, "EQU") == 0) {
    if (! assembleParseInteger(parse, pass, &i)) {
      assembleError("Invalid equate value");
      return false;
    }

    if (assemble_data_.getLastLabel() == "") {
      assembleError("No label for equate");
      return false;
    }

    assembleSetLabelValue(assemble_data_.getLastLabel(), i);

    if (set_op_str) {
      str1 = "";
      str2 = " ; EQU  0x" + CStrUtil::toHexString(i & 0xFFFF, 4);

      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }
  }
  else if (CStrUtil::casecmp(str, "EXPR") == 0) {
    std::string expr;

    parse->skipSpace();

    while (! parse->eol() && ! parse->isChar(';') && ! parse->isChar('|')) {
      uchar c = parse->readChar();

      expr += c;
    }

    if (assemble_data_.getLastLabel() == "") {
      assembleError("No label for expression");
      return false;
    }

    if (! assembleEvalExpr(expr, &i)) {
      assembleError("Invalid expression \'%s\'", expr.c_str());
      return false;
    }

    assembleSetLabelValue(assemble_data_.getLastLabel(), i);

    if (set_op_str) {
      str1 = "";
      str2 = " ; EXPR " + expr;

      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }
  }
  else if (CStrUtil::casecmp(str, "DEFB") == 0) {
    if (set_op_str) {
      str1 = CStrUtil::toHexString(getPC(), 4);
      str2 = " ; DEFB";
    }

    parse->skipSpace();

    if (parse->isChar('\"') || parse->isChar('\'')) {
      uchar end_char = parse->readChar();

      if (set_op_str) {
        str2 += ' ';
        str2 += end_char;
      }

      while (! parse->eol() && ! parse->isChar(end_char)) {
        uchar c =  parse->readChar();

        if (c == '\\') {
          if (parse->eol() || parse->isChar(end_char)) {
            assembleError("Missing terminator for DEFB string");
            return false;
          }

          std::string cstr;

          cstr += (char) c;

          uchar c1 = parse->readChar();

          cstr += (char) c1;

          if      (c1 == 'x') {
            if (parse->eol() || parse->isChar(end_char)) {
              assembleError("Missing terminator for DEFB string");
              return false;
            }

            uchar c1 = parse->readChar();

            cstr += (char) c1;

            if (parse->eol() || parse->isChar(end_char)) {
              assembleError("Missing terminator for DEFB string");
              return false;
            }

            uchar c2 = parse->readChar();

            cstr += (char) c2;
          }
          else if (c1 == '0') {
            if (! parse->eol() && ! parse->isChar(end_char)) {
              if (parse->eol() || parse->isChar(end_char)) {
                assembleError("Missing terminator for DEFB string");
                return false;
              }

              uchar c1 = parse->readChar();

              cstr += (char) c1;

              if (parse->eol() || parse->isChar(end_char)) {
                assembleError("Missing terminator for DEFB string");
                return false;
              }

              uchar c2 = parse->readChar();

              cstr += (char) c2;

              if (parse->eol() || parse->isChar(end_char)) {
                assembleError("Missing terminator for DEFB string");
                return false;
              }

              uchar c3 = parse->readChar();

              cstr += (char) c3;
            }
          }

          char c2;

          if (! CStrUtil::encodeEscapeChar(cstr, &c2)) {
            assembleError("Invalid escape code");
            return false;
          }

          c = c2;
        }

        if (set_op_str) {
          str1 += " " + CStrUtil::toHexString(c, 2);
          str2 += c;
        }

        if (pass == 2 && assemble_data_.isStream())
          assemble_data_.addValue(getPC(), c);

        incPC();
      }

      if (parse->eol()) {
        assembleError("Missing terminator for DEFB string");
        return false;
      }

      parse->skipChar();

      if (set_op_str)
        str2 += (char) end_char;
    }
    else {
      do {
        if (! assembleParseInteger(parse, pass, &i)) {
          assembleError("Invalid byte");
          return false;
        }

        if (set_op_str) {
          str1 += ' '   + CStrUtil::toHexString(i & 0xFF, 2);
          str2 += " 0x" + CStrUtil::toHexString(i & 0xFF, 2);
        }

        if (pass == 2 && assemble_data_.isStream())
          assemble_data_.addValue(getPC(), i & 0xFF);

        incPC();

        parse->skipSpace();

        if (parse->isChar(',')) {
          parse->skipChar();

          parse->skipSpace();
        }
      }
      while (! parse->eol() && ! parse->isChar(';') && ! parse->isChar('|'));
    }

    if (set_op_str) {
      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }
  }
  else if (CStrUtil::casecmp(str, "DEFW") == 0) {
    if (set_op_str) {
      str1 = CStrUtil::toHexString(getPC(), 4);
      str2 = " ; DEFW";
    }

    do {
      if (! assembleParseInteger(parse, pass, &i)) {
        assembleError("Invalid word");
        return false;
      }

      if (set_op_str) {
        str1 += ' '   + CStrUtil::toHexString( i & 0x00FF      , 2);
        str1 += ' '   + CStrUtil::toHexString((i & 0xFF00) >> 8, 2);
        str2 += " 0x" + CStrUtil::toHexString( i & 0xFFFF      , 4);
      }

      if (pass == 2 && assemble_data_.isStream()) {
        assemble_data_.addValue(getPC()    ,  i & 0x00FF      );
        assemble_data_.addValue(getPC() + 1, (i & 0xFF00) >> 8);
      }

      incPC(2);

      parse->skipSpace();

      if (parse->isChar(',')) {
        parse->skipChar();

        parse->skipSpace();
      }
    }
    while (! parse->eol() && ! parse->isChar(';') && ! parse->isChar('|'));

    if (set_op_str) {
      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }
  }
  else if (CStrUtil::casecmp(str, "DEFS") == 0) {
    if (set_op_str) {
      str1 = "";
      str2 = " ; DEFS";
    }

    if (! assembleParseInteger(parse, pass, &i)) {
      assembleError("Invalid space size");
      return false;
    }

    if (set_op_str)
      str2 += " 0x" + CStrUtil::toHexString(i & 0xFFFF, 4);

    parse->skipSpace();

    j = 0;

    if (parse->isChar(',')) {
      parse->skipChar();

      parse->skipSpace();

      if (! assembleParseInteger(parse, pass, &j)) {
        assembleError("Invalid space value");
        return false;
      }

      if (set_op_str)
        str2 += ", " + CStrUtil::toHexString(j, 2);

      if (set_op_str) {
        str1 = CStrUtil::toHexString(getPC(), 4);

        for (uint i1 = 0; i1 < i; ++i1)
          str1 += ' ' + CStrUtil::toHexString(j, 2);
      }
    }

    if (pass == 2 && assemble_data_.isStream()) {
      for (uint i1 = 0; i1 < i; ++i1)
        assemble_data_.addValue(getPC() + i1, j);
    }

    incPC(i);

    if (set_op_str) {
      while (str1.size() < 18)
        str1 += ' ';

      op_str = str1 + str2;
    }
  }
  else if (CStrUtil::casecmp(str, "MACRO") == 0) {
    parse->skipSpace();

    std::string name;

    if (! parse->readIdentifier(name)) {
      assembleError("Missing identifier");
      return false;
    }

    parse->skipSpace();

    if (! parse->isChar('(')) {
      assembleError("Missing (");
      return false;
    }

    parse->skipChar();

    std::string argStr;

    while (! parse->eol() && ! parse->isChar(')'))
      argStr += parse->readChar();

    if (! parse->isChar(')')) {
      assembleError("Missing )");
      return false;
    }

    parse->skipChar();

    parse->skipSpace();

    std::string body;

    while (true) {
      if      (parse->isChar('\\')) {
        parse->skipChar();

        if (parse->eol())
          assembleLoadLine(parse);
        else
          body += '\\';
      }
      else if (parse->eol())
        break;
      else
        body += parse->readChar();
    }

    std::vector<std::string> args;

    CStrUtil::addFields(argStr, args, ",", true);

    assembleDefineMacro(name, args, body);

    return true;
  }
  else if (assembleGetMacro(str, macroArgs, macroBody)) {
    std::string argsStr;

    while (! parse->eol() && ! parse->isChar(';')) {
      uchar c = parse->readChar();

      argsStr += c;
    }

    argsStr = CStrUtil::stripSpaces(argsStr);

    uint argsLen = argsStr.size();

    if (argsLen > 0 && argsStr[0] == '(') {
      argsStr = CStrUtil::stripSpaces(argsStr.substr(1));

      argsLen = argsStr.size();
    }

    if (argsLen > 0 && argsStr[argsLen - 1] == ')') {
      argsStr = CStrUtil::stripSpaces(argsStr.substr(0, argsLen - 1));

      argsLen = argsStr.size();
    }

    std::vector<std::string> args;

    CStrUtil::addFields(argsStr, args, ",", true);

    std::string macroBody1 = macroBody;

    uint numArgs = std::min(macroArgs.size(), args.size());

    for (uint i = 0; i < numArgs; ++i)
      macroBody1 = CStrUtil::replace(macroBody1, macroArgs[i], args[i]);

    parse->unread(macroBody1);

    bool continued1 = false;

    if (! assembleParseOp(parse, op_str, pass, &continued1))
      return false;

    while (continued1) {
      if (! assembleParseOp(parse, op_str, pass, &continued1))
        return false;
    }
  }
  else {
    is_op = true;

    if (! assembleStringToOpId(str, &op_id)) {
      assembleError("Invalid operator name %s", str.c_str());
      return false;
    }

    op.id = (CZ80OpId) op_id;

    if      (parse->isIdentifier()) {
      if (! parse->readIdentifier(str)) {
        assembleError("Invalid identifer");
        return false;
      }

      parse->skipSpace();

      if (parse->isChar('\'')) {
        str += parse->readChar();

        parse->skipSpace();
      }

      //--------

      if      (op.id == OP_JP   || op.id == OP_JR ||
               op.id == OP_CALL || op.id == OP_RET) {
        if      (assembleStringToFlagId(str, &flag_id)) {
          op.type1 = A_FLAG;
          op.arg1  = flag_id;

          op_data.num_values1 = 0;
        }
        else if (assembleStringToRegisterId(str, &reg_id)) {
          op.type1 = A_REG;
          op.arg1  = reg_id;

          op_data.num_values1 = 0;
        }
        else {
          parse->unread(str);

          if (assembleParseInteger(parse, pass, &i)) {
            if (op.id == OP_JR) {
              char o = i - getPC() - 2;

              i = *(uchar *) &o;

              op.type1 = A_S_NUM;
              op.arg1  = 2;

              op_data.num_values1 = 2;
              op_data.values1[0]  =  i & 0x00FF;
              op_data.values1[1]  = (i & 0xFF00) >> 8;
            }
            else {
              op.type1 = A_NUM;
              op.arg1  = 2;

              op_data.num_values1 = 2;
              op_data.values1[0]  =  i & 0x00FF;
              op_data.values1[1]  = (i & 0xFF00) >> 8;
            }
          }
          else {
            assembleError("Invalid destination %s", str.c_str());
            return false;
          }
        }
      }
      else {
        if      (assembleStringToRegisterId(str, &reg_id)) {
          op.type1 = A_REG;
          op.arg1  = reg_id;

          op_data.num_values1 = 0;
        }
        else {
          parse->unread(str);

          if (assembleParseInteger(parse, pass, &i)) {
            if (op.id == OP_DJNZ) {
              char o = i - getPC() - 2;

              i = *(uchar *) &o;

              op.type1 = A_S_NUM;
              op.arg1  = 2;

              op_data.num_values1 = 2;
              op_data.values1[0]  =  i & 0x00FF;
              op_data.values1[1]  = (i & 0xFF00) >> 8;
            }
            else {
              op.type1 = A_NUM;
              op.arg1  = 2;

              op_data.num_values1 = 2;
              op_data.values1[0]  =  i & 0x00FF;
              op_data.values1[1]  = (i & 0xFF00) >> 8;
            }
          }
          else {
            assembleError("Invalid destination %s", str.c_str());
            return false;
          }
        }
      }
    }
    else if (parse->isChar('+') || parse->isChar('-')) {
      int sign = 1;

      if (parse->isChar('-'))
        sign = -1;

      parse->skipChar();

      if (! assembleParseInteger(parse, pass, &i))
        return false;

      int si = i*sign;

      i = *(uint *) &si;

      if (op.id == OP_JR || op.id == OP_DJNZ) {
        op.type1 = A_S_NUM;
        op.arg1  = 2;

        op_data.num_values1 = 2;
        op_data.values1[0]  =  i & 0x00FF;
        op_data.values1[1]  = (i & 0xFF00) >> 8;
      }
      else {
        //assembleError("Invalid operator for offset");

        op.type1 = A_NUM;
        op.arg1  = 2;

        op_data.num_values1 = 2;
        op_data.values1[0]  =  i & 0x00FF;
        op_data.values1[1]  = (i & 0xFF00) >> 8;
      }
    }
    else if (assembleParseInteger(parse, pass, &i)) {
      if      (op.id == OP_RST || op.id == OP_IM  ||
               op.id == OP_IN  || op.id == OP_OUT ||
               op.id == OP_BIT || op.id == OP_SET || op.id == OP_RES) {
        op.type1 = A_CONST;
        op.arg1  = i & 0x0FF;
      }
      else if (op.id == OP_JR || op.id == OP_DJNZ) {
        char o = i - getPC() - 2;

        i = *(uchar *) &o;

        op.type1 = A_S_NUM;
        op.arg1  = 2;

        op_data.num_values1 = 2;
        op_data.values1[0]  =  i & 0x00FF;
        op_data.values1[1]  = (i & 0xFF00) >> 8;
      }
      else {
        op.type1 = A_NUM;
        op.arg1  = 2;

        op_data.num_values1 = 2;
        op_data.values1[0]  =  i & 0x00FF;
        op_data.values1[1]  = (i & 0xFF00) >> 8;
      }
    }
    else if (parse->isChar('(')) {
      parse->skipChar();

      parse->skipSpace();

      if      (parse->isIdentifier()) {
        if (! parse->readIdentifier(str)) {
          assembleError("Invalid identifer");
          return false;
        }

        parse->skipSpace();

        if (parse->isChar('\''))
          str += parse->readChar();

        if      (assembleStringToRegisterId(str, &reg_id)) {
          if (reg_id == R_IX || reg_id == R_IY) {
            if (assembleParseInteger(parse, pass, &i)) {
              op.type1 = A_PO_REG;
              op.arg1  = reg_id;

              op_data.num_values1 = 1;
              op_data.values1[0]  = i & 0x00FF;
            }
            else {
              op.type1 = A_P_REG;
              op.arg1  = reg_id;

              op_data.num_values1 = 0;
            }
          }
          else {
            op.type1 = A_P_REG;
            op.arg1  = reg_id;

            op_data.num_values1 = 0;
          }
        }
        else {
          parse->unread(str);

          if (assembleParseInteger(parse, pass, &i)) {
            op.type1 = A_P_NUM;
            op.arg1  = 2;

            op_data.num_values1 = 2;
            op_data.values1[0]  =  i & 0x00FF;
            op_data.values1[1]  = (i & 0xFF00) >> 8;
          }
          else {
            assembleError("Invalid destination %s", str.c_str());
            return false;
          }
        }
      }
      else if (assembleParseInteger(parse, pass, &i)) {
        op.type1 = A_P_NUM;
        op.arg1  = 2;

        op_data.num_values1 = 2;
        op_data.values1[0]  =  i & 0x00FF;
        op_data.values1[1]  = (i & 0xFF00) >> 8;
      }
      else {
        assembleError("Invalid destination %s", str.c_str());
        return false;
      }

      parse->skipSpace();

      if (! parse->isChar(')')) {
        assembleError("Missing close parenthesis");
        return false;
      }

      parse->skipChar();

      if (op.type1 == A_PO_REG) {
        if (parse->isString("->")) {
          parse->skipChar(2);

          parse->skipSpace();

          if (! parse->isIdentifier() ||
              ! parse->readIdentifier(str) ||
              ! assembleStringToRegisterId(str, &reg_id)) {
            assembleError("Invalid destination %s", str.c_str());
            return false;
          }

          switch (reg_id) {
            case R_A:
              op.type1 = A_PO_REG_A;
              break;
            case R_B:
              op.type1 = A_PO_REG_B;
              break;
            case R_C:
              op.type1 = A_PO_REG_C;
              break;
            case R_D:
              op.type1 = A_PO_REG_D;
              break;
            case R_E:
              op.type1 = A_PO_REG_E;
              break;
            case R_H:
              op.type1 = A_PO_REG_H;
              break;
            case R_L:
              op.type1 = A_PO_REG_L;
              break;
            default:
              assembleError("Invalid destination %s", str.c_str());
              return false;
          }
        }
      }
    }

    if (op.type1 != A_NONE) {
      parse->skipSpace();

      if (parse->isChar(',')) {
        parse->skipChar();

        parse->skipSpace();

        if      (parse->isIdentifier()) {
          if (! parse->readIdentifier(str)) {
            assembleError("Invalid identifer");
            return false;
          }

          parse->skipSpace();

          if (parse->isChar('\''))
            str += parse->readChar();

          if      (assembleStringToRegisterId(str, &reg_id)) {
            op.type2 = A_REG;
            op.arg2  = reg_id;

            op_data.num_values2 = 0;
          }
          else {
            parse->unread(str);

            if (assembleParseInteger(parse, pass, &i)) {
              if (op.id == OP_JR) {
                char o = i - getPC() - 2;

                i = *(uchar *) &o;

                op.type2 = A_S_NUM;
                op.arg2  = 2;

                op_data.num_values2 = 2;
                op_data.values2[0]  =  i & 0x00FF;
                op_data.values2[1]  = (i & 0xFF00) >> 8;
              }
              else {
                op.type2 = A_NUM;
                op.arg2  = 2;

                op_data.num_values2 = 2;
                op_data.values2[0]  =  i & 0x00FF;
                op_data.values2[1]  = (i & 0xFF00) >> 8;
              }
            }
            else {
              assembleError("Invalid source %s", str.c_str());
              return false;
            }
          }
        }
        else if (parse->isChar('+') || parse->isChar('-')) {
          int sign = 1;

          if (parse->isChar('-'))
            sign = -1;

          parse->skipChar();

          if (! assembleParseInteger(parse, pass, &i))
            return false;

          int si = i*sign;

          i = *(uint *) &si;

          if (op.id == OP_JR || op.id == OP_DJNZ) {
            op.type2 = A_S_NUM;
            op.arg2  = 2;

            op_data.num_values2 = 2;
            op_data.values2[0]  =  i & 0x00FF;
            op_data.values2[1]  = (i & 0xFF00) >> 8;
          }
          else {
            //assembleError("Invalid operator for offset");

            op.type2 = A_NUM;
            op.arg2  = 2;

            op_data.num_values2 = 2;
            op_data.values2[0]  =  i & 0x00FF;
            op_data.values2[1]  = (i & 0xFF00) >> 8;
          }
        }
        else if (assembleParseInteger(parse, pass, &i)) {
          if (op.id == OP_IN  || op.id == OP_OUT) {
            op.type2 = A_CONST;
            op.arg2  = i & 0x00FF;
          }
          else if (op.id == OP_JR || op.id == OP_DJNZ) {
            char o = i - getPC() - 2;

            i = *(uchar *) &o;

            op.type2 = A_S_NUM;
            op.arg2  = 2;

            op_data.num_values2 = 2;
            op_data.values2[0]  =  i & 0x00FF;
            op_data.values2[1]  = (i & 0xFF00) >> 8;
          }
          else {
            op.type2 = A_NUM;
            op.arg2  = 2;

            op_data.num_values2 = 2;
            op_data.values2[0]  =  i & 0x00FF;
            op_data.values2[1]  = (i & 0xFF00) >> 8;
          }
        }
        else if (parse->isChar('(')) {
          parse->skipChar();

          parse->skipSpace();

          if      (parse->isIdentifier()) {
            if (! parse->readIdentifier(str)) {
              assembleError("Invalid identifer");
              return false;
            }

            parse->skipSpace();

            if (parse->isChar('\''))
              str += parse->readChar();

            if      (assembleStringToRegisterId(str, &reg_id)) {
              if (reg_id == R_IX || reg_id == R_IY) {
                if (assembleParseInteger(parse, pass, &i)) {
                  op.type2 = A_PO_REG;
                  op.arg2  = reg_id;

                  op_data.num_values2 = 1;
                  op_data.values2[0]  = i & 0x00FF;
                }
                else {
                  op.type2 = A_P_REG;
                  op.arg2  = reg_id;

                  op_data.num_values2 = 0;
                }
              }
              else {
                op.type2 = A_P_REG;
                op.arg2  = reg_id;

                op_data.num_values2 = 0;
              }
            }
            else {
              parse->unread(str);

              if (assembleParseInteger(parse, pass, &i)) {
                op.type2 = A_P_NUM;
                op.arg2  = 2;

                op_data.num_values2 = 2;
                op_data.values2[0]  =  i & 0x00FF;
                op_data.values2[1]  = (i & 0xFF00) >> 8;
              }
              else {
                assembleError("Invalid destination %s", str.c_str());
                return false;
              }
            }
          }
          else if (assembleParseInteger(parse, pass, &i)) {
            op.type2 = A_P_NUM;
            op.arg2  = 2;

            op_data.num_values2 = 2;
            op_data.values2[0]  =  i & 0x00FF;
            op_data.values2[1]  = (i & 0xFF00) >> 8;
          }
          else {
            assembleError("Invalid destination %s", str.c_str());
            return false;
          }

          parse->skipSpace();

          if (! parse->isChar(')')) {
            assembleError("Missing close parenthesis");
            return false;
          }

          parse->skipChar();

          if (op.type2 == A_PO_REG) {
            if (parse->isString("->")) {
              parse->skipChar(2);

              parse->skipSpace();

              if (! parse->isIdentifier() ||
                  ! parse->readIdentifier(str) ||
                  ! assembleStringToRegisterId(str, &reg_id)) {
                assembleError("Invalid destination %s", str.c_str());
                return false;
              }

              switch (reg_id) {
                case R_A:
                  op.type2 = A_PO_REG_A;
                  break;
                case R_B:
                  op.type2 = A_PO_REG_B;
                  break;
                case R_C:
                  op.type2 = A_PO_REG_C;
                  break;
                case R_D:
                  op.type2 = A_PO_REG_D;
                  break;
                case R_E:
                  op.type2 = A_PO_REG_E;
                  break;
                case R_H:
                  op.type2 = A_PO_REG_H;
                  break;
                case R_L:
                  op.type2 = A_PO_REG_L;
                  break;
                default:
                  assembleError("Invalid destination %s", str.c_str());
                  return false;
              }
            }
          }
        }
      }
    }
  }

  parse->skipSpace();

  if (! parse->eol() && ! parse->isChar(';') && ! parse->isChar('|')) {
    assembleError("Extra characters ignored");

    parse->dumpBuffer(std::cerr);
  }

  if (parse->isChar('|')) {
    parse->skipChar();

    *continued = true;
  }

  if (is_op) {
    if (! lookupOp(&op, &op1)) {
      assembleError("Invalid operator data");
      return false;
    }

    op_data.op = op1;

    if (op_data.op->type1 == A_NUM || op_data.op->type1 == A_S_NUM)
      op_data.num_values1 = op_data.op->arg1;

    if (op_data.op->type2 == A_NUM || op_data.op->type2 == A_S_NUM)
      op_data.num_values2 = op_data.op->arg2;

    if (set_op_str) {
      str1 = CStrUtil::toHexString(getPC(), 4) + " " + op_data.toTxt();
      str2 = op_data.getOpString();

      uint len = str1.size();

      for (uint i = len; i < 18; ++i)
        str1 += " ";

      op_str = str1 + " ; " + str2;
    }

    if (pass == 2 && assemble_data_.isStream()) {
      uchar *values;
      uint   num_values;

      op_data.toValues(&values, &num_values);

      for (uint i = 0; i < num_values; ++i)
        assemble_data_.addValue(getPC() + i, values[i]);
    }

    incPC(op_data.getSize());
  }

  return true;
}

bool
CZ80::
assembleParseInteger(CFileParse *parse, uint pass, uint *i)
{
  parse->skipSpace();

  if       (parse->isIdentifier()) {
    std::string str;

    if (! parse->readIdentifier(str))
      return false;

    if (isLabelName(str))
      getLabelValue(str, i);
    else {
      if (pass == 2)
        return false;

      *i = 0;
    }

    //--------

    parse->skipSpace();

    if (parse->isChar('@')) {
      parse->skipChar();

      parse->skipSpace();

      if      (parse->isChar('L'))
        *i =  *i & 0x00FF;
      else if (parse->isChar('H'))
        *i = (*i & 0xFF00) >> 8;
      else {
        assembleError("Invalid value modified");
        return false;
      }

      parse->skipChar();

      parse->skipSpace();
    }

    //--------

    if (parse->isChar('+') || parse->isChar('-')) {
      int sign = 1;

      if (parse->isChar('-'))
        sign = -1;

      parse->skipChar();

      parse->skipSpace();

      uint d;

      if (! assembleParseInteger(parse, pass, &d))
        return false;

      int si = *i + d*sign;

      *i = *(uint *) &si;
    }

    //--------

    return true;
  }
  else if (parse->isChar('\'')) {
    parse->skipChar();

    if (parse->eol()) {
      assembleError("Missing character");
      return false;
    }

    uchar c = parse->readChar();

    if (c == '\\') {
      if (parse->eol() || parse->isChar('\'')) {
        assembleError("Missing character");
        return false;
      }

      std::string cstr;

      cstr += (char) c;

      uchar c1 = parse->readChar();

      cstr += (char) c1;

      if      (c1 == 'x') {
        if (parse->eol() || parse->isChar('\'')) {
          assembleError("Missing terminator for char");
          return false;
        }

        uchar c1 = parse->readChar();

        cstr += (char) c1;

        if (parse->eol() || parse->isChar('\'')) {
          assembleError("Missing terminator for char");
          return false;
        }

        uchar c2 = parse->readChar();

        cstr += (char) c2;
      }
      else if (c1 == '0') {
        if (! parse->eol() && ! parse->isChar('\'')) {
          if (parse->eol() || parse->isChar('\'')) {
            assembleError("Missing terminator for char");
            return false;
          }

          uchar c1 = parse->readChar();

          cstr += (char) c1;

          if (parse->eol() || parse->isChar('\'')) {
            assembleError("Missing terminator for char");
            return false;
          }

          uchar c2 = parse->readChar();

          cstr += (char) c2;

          if (parse->eol() || parse->isChar('\'')) {
            assembleError("Missing terminator for char");
            return false;
          }

          uchar c3 = parse->readChar();

          cstr += (char) c3;
        }
      }

      char c2;

      if (! CStrUtil::encodeEscapeChar(cstr, &c2)) {
        assembleError("Invalid escape code");
        return false;
      }

      c = c2;
    }

    if (parse->eol()) {
      assembleError("Missing character");
      return false;
    }

    if (! parse->isChar('\'')) {
      assembleError("Missing terminating character quote");
      return false;
    }

    parse->skipChar();

    *i = c;

    return true;
  }
  else {
    int si, sign = 1;

    if (parse->isChar('+') || parse->isChar('-')) {
      if (parse->isChar('-'))
        sign = -1;

      parse->skipChar();

      parse->skipSpace();
    }

    if      (parse->isString("0x")) {
      parse->skipChar(2);

      if (! parse->readBaseInteger(16, i)) {
        assembleError("Invalid hex number");
        return false;
      }

      si = (*i)*sign;

      *i = *(uint *) &si;

      return true;
    }
    else if (parse->isDigit()) {
      if (! parse->readInteger(i)) {
        assembleError("Invalid decimal number");
        return false;
      }

      si = (*i)*sign;

      *i = *(uint *) &si;

      return true;
    }
    else if (parse->isIdentifier()) {
      std::string str;

      if (! parse->readIdentifier(str))
        return false;

      if (isLabelName(str))
        getLabelValue(str, i);
      else {
        if (pass == 2)
          return false;

        *i = 0;
      }

      return true;
    }
    else
      return false;
  }
}

void
CZ80::
assembleSetLabelValue(const std::string &name, uint value)
{
  setLabelValue(name, value);

#ifdef CL_PARSER
  ClParserValuePtr pval = ClParserValueMgrInst->createValue((long) value);

  if (! ClParserInst->isVariable(name))
    ClParserInst->createVar(name, pval);
  else
    ClParserInst->setVariableValue(name, pval);
#endif

  assemble_data_.setNameValue(name, value);
}

bool
CZ80::
assembleEvalExpr(const std::string &expr, uint *value)
{
#ifdef CL_PARSER
  ClParserValuePtr pcVal = ClParserValueMgrInst->createValue((long) getPC());

  if (! ClParserInst->isVariable("PC"))
    ClParserInst->createVar("PC", pcVal);
  else
    ClParserInst->setVariableValue("PC", pcVal);

  ClParserExpr pexpr(expr);

  ClParserValuePtr pvalue;

  if (! pexpr.exec(pvalue))
    return false;

  long l;

  if (! pvalue->integerValue(&l))
    return false;

  *value = l;

  return true;
#else
  return false;
#endif
}

void
CZ80::
assembleError(const char *format, ...)
{
  va_list vargs;

  va_start(vargs, format);

  std::cerr << "Line " << assemble_data_.getCurrentLineNum() << ": ";
  std::cerr << CStrUtil::vstrprintf(format, &vargs) << ": ";
  std::cerr << "'" << assemble_data_.getCurrentLine() << "'" << std::endl;

  va_end(vargs);
}

void
CZ80::
assembleAll(ushort pc, std::ostream &os)
{
  CZ80Op *op;

  setPC(pc);

  for (uint i = 0; i < 1726; ++i) {
    op = getIndOp(i);

    assembleOp(op, os);
  }
}

void
CZ80::
assembleOp(CZ80Op *op, std::ostream &os)
{
  if (op->func == NULL)
    return;

  CZ80OpData op_data;

  op_data.z80         = this;
  op_data.op          = op;
  op_data.values1[0]  = 0;
  op_data.values1[1]  = 0;
  op_data.num_values1 = 2;
  op_data.values2[0]  = 0;
  op_data.values2[1]  = 0;
  op_data.num_values2 = 2;

  std::string str = op_data.getOpString();

  os << str << std::endl;

  setPC(getPC() + op->getSize());
}

bool
CZ80::
assembleStringToOpId(const std::string &str, uint *id)
{
  std::string str1 = CStrUtil::toUpper(str);

  for (uint i = 0; i < cz80_num_op_names; ++i)
    if (str1 == cz80_op_names[i]) {
      *id = i - 1;
      return true;
    }

  return false;
}

bool
CZ80::
assembleStringToFlagId(const std::string &str, uint *id)
{
  std::string str1 = CStrUtil::toUpper(str);

  for (uint i = 0; i < cz80_num_flag_names; ++i)
    if (str1 == cz80_flag_names[i]) {
      *id = i;
      return true;
    }

  return false;
}

bool
CZ80::
assembleStringToRegisterId(const std::string &str, uint *id)
{
  std::string str1 = CStrUtil::toUpper(str);

  for (uint i = 0; i < cz80_num_register_names; ++i)
    if (str1 == cz80_register_names[i]) {
      *id = i;
      return true;
    }

  return false;
}

void
CZ80::
assembleDefineMacro(const std::string &name, const std::vector<std::string> &args,
                    const std::string &body)
{
  assemble_macros_[name] = CZ80Macro(name, args, body);
}

bool
CZ80::
assembleGetMacro(const std::string &name, std::vector<std::string> &args, std::string &body) const
{
  MacroMap::const_iterator p = assemble_macros_.find(name);

  if (p == assemble_macros_.end())
    return false;

  const CZ80Macro &macro = (*p).second;

  args = macro.getArgs();
  body = macro.getBody();

  return true;
}

void
CZ80::
assembleDumpSymbols()
{
  assemble_data_.dumpSymbols();
}

//------

CZ80AssembleData::
CZ80AssembleData() :
 stream_(false), values_pc_min_(0), values_pc_max_(0), values_pc_set_(false),
 current_line_num_(0)
{
}

void
CZ80AssembleData::
init()
{
  values_pc_min_ = 0;
  values_pc_max_ = 0;
  values_pc_set_ = false;

  values_.clear();

  name_values_.clear();
}

void
CZ80AssembleData::
initPass()
{
  last_label_       = "";
  current_line_num_ = 0;
}

void
CZ80AssembleData::
nextLine(CFileParse *parse)
{
  ++current_line_num_;

  current_line_ = parse->getBuffer();
}

void
CZ80AssembleData::
addValue(ushort pc, uchar c)
{
  if (! values_pc_set_) {
    values_pc_min_ = pc;
    values_pc_max_ = pc;
    values_pc_set_ = true;
  }
  else {
    values_pc_min_ = std::min(pc, values_pc_min_);
    values_pc_max_ = std::max(pc, values_pc_max_);
  }

  values_[pc] = c;
}

void
CZ80AssembleData::
setLastLabel(const std::string &str)
{
  last_label_ = str;
}

void
CZ80AssembleData::
setNameValue(const std::string &name, uint value)
{
  name_values_[name] = value;
}

void
CZ80AssembleData::
dumpValues(CFileBase *ofile)
{
  uint num_values = (values_pc_max_ - values_pc_min_ + 1);
  uint num_lines  = num_values / 8;

  uint pc = values_pc_min_;

  std::string str;

  for (uint i = 0; i < num_lines; ++i) {
    str = CStrUtil::toHexString(pc, 4);

    for (uint j = 0; j < 8; ++j, ++pc)
      str += " " + CStrUtil::toHexString(values_[pc], 2);

    str += "\n";

    ofile->write(str);
  }

  if (pc <= values_pc_max_) {
    str = CStrUtil::toHexString(pc, 4);

    uint d = values_pc_max_ - pc + 1;

    for (uint j = 0; j < d; ++j, ++pc)
      str += " " + CStrUtil::toHexString(values_[pc], 2);

    for ( ; d < 8; ++d)
      str += " " + CStrUtil::toHexString(0, 2);

    str += "\n";

    ofile->write(str);
  }
}

void
CZ80AssembleData::
dumpSymbols() const
{
  NameValueMap::const_iterator p1, p2;

  for (p1 = name_values_.begin(), p2 = name_values_.end(); p1 != p2; ++p1) {
    uint value = (*p1).second & 0xFFFF;

    std::cout << (*p1).first << "=" << CStrUtil::toHexString(value, 4) << std::endl;
  }
}

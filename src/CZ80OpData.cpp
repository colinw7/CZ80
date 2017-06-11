#include <CZ80OpData.h>

const char *
CZ80OpData::
getName() const
{
  return op->getName();
}

void
CZ80OpData::
execute()
{
  op->execute(this);
}

void
CZ80OpData::
dump(CFile *file)
{
  file->write((const uchar *) &op->ind, sizeof(op->ind));

  file->write((const uchar *) &num_values1, sizeof(num_values1));

  for (uint i = 0; i < num_values1; ++i)
    file->write((const uchar *) &values1[i], sizeof(values1[i]));

  file->write((const uchar *) &num_values2, sizeof(num_values2));

  for (uint i = 0; i < num_values2; ++i)
    file->write((const uchar *) &values2[i], sizeof(values2[i]));
}

bool
CZ80OpData::
undump(CFile *file)
{
  uchar  b;
  ushort s;

  file->read((uchar *) &s, sizeof(s));

  op = CZ80::getIndOp(s);

  if (op == NULL)
    return false;

  file->read((uchar *) &b, sizeof(b));

  if (b > 2) {
    std::cerr << "Invalid num values 1 " << (int) b << std::endl;
    return false;
  }

  num_values1 = b;

  for (uint i = 0; i < num_values1; ++i) {
    file->read((uchar *) &b, sizeof(b));

    values1[i] = b;
  }

  file->read((uchar *) &b, sizeof(b));

  if (b > 2) {
    std::cerr << "Invalid num values 2 " << (int) b << std::endl;
    return false;
  }

  num_values2 = b;

  for (uint i = 0; i < num_values2; ++i) {
    file->read((uchar *) &b, sizeof(b));

    values2[i] = b;
  }

  return true;
}

void
CZ80OpData::
dumpTxt(std::ostream &os)
{
  std::string str1 = CStrUtil::toHexString(z80->getPC(), 4) + " " + toTxt();
  std::string str2 = getOpString();

  uint len = str1.size();

  for (uint i = len; i < 13; ++i)
    str1 += " ";

  os << str1 << " " << " ; " << str2 << std::endl;
}

std::string
CZ80OpData::
toTxt()
{
  std::string str;

  if (op->ind < 1280) {
    str += op->getCode();

    for (uint i = 0; i < num_values1; ++i)
      str += " " + CStrUtil::toHexString(values1[i], 2);

    for (uint i = 0; i < num_values2; ++i)
      str += " " + CStrUtil::toHexString(values2[i], 2);
  }
  else {
    if (num_values1 > 0)
      str += op->getExtCode(values1[0]);
    else
      str += op->getExtCode(values2[0]);
  }

  return str;
}

void
CZ80OpData::
toValues(uchar **values, uint *num_values)
{
  static uchar svalues[5];

  *num_values = 0;
  *values     = svalues;

  if (op->ind < 1280) {
    uchar *values3;
    uint   num_values3;

    op->getValues(&values3, &num_values3);

    for (uint i = 0; i < num_values3; ++i)
      (*values)[(*num_values)++] = values3[i];

    for (uint i = 0; i < num_values1; ++i)
      (*values)[(*num_values)++] = values1[i];

    for (uint i = 0; i < num_values2; ++i)
      (*values)[(*num_values)++] = values2[i];
  }
  else {
    if (num_values1 > 0) {
      uchar *values3;
      uint   num_values3;

      op->getExtValues(values1[0], &values3, &num_values3);

      for (uint i = 0; i < num_values3; ++i)
        (*values)[(*num_values)++] = values3[i];
    }
    else {
      uchar *values3;
      uint   num_values3;

      op->getExtValues(values2[0], &values3, &num_values3);

      for (uint i = 0; i < num_values3; ++i)
        (*values)[(*num_values)++] = values3[i];
    }
  }
}

void
CZ80OpData::
printStr(std::ostream &os)
{
  os << getOpString();
}

std::string
CZ80OpData::
getOpString()
{
  std::string str = op->getName();

  ushort len1 = str.size();

  if (op->type1 != 0) {
    for ( ; len1 < 5; ++len1)
      str += " ";

    str += getArgString(op->type1, op->arg1, values1, num_values1);

    if (op->type2 != 0) {
      str += ", ";

      str += getArgString(op->type2, op->arg2, values2, num_values2);
    }
  }

  return str;
}

std::string
CZ80OpData::
getArgString(uint type, uint arg, uchar *args, ushort)
{
  std::string str, name;

  if      (type == A_NUM) {
    if      (arg == 1)
      str += "0x" + CStrUtil::toHexString(args[0], 2);
    else if (arg == 2) {
      ushort s = (args[1] << 8) | args[0];

      if (z80 != NULL && z80->getValueLabel(s, name))
        str += name;
      else
        str += "0x" + CStrUtil::toHexString(s, 4);
    }
  }
  else if (type == A_S_NUM) {
    if      (arg == 1) {
      schar o = *(schar *) &args[0];

#ifdef CZ80_RELATIVE_OFFSETS
      if (o >= 0)
        str += "+0x" + CStrUtil::toHexString( o, 2);
      else
        str += "-0x" + CStrUtil::toHexString(-o, 2);
#else
      if (z80 != NULL) {
        ushort s = z80->getPC() + o;

        if (z80->getValueLabel(s, name))
          str += name;
        else
          str += "0x" + CStrUtil::toHexString(s, 4);
      }
      else {
        if (o >= 0)
          str += "+0x" + CStrUtil::toHexString( o, 2);
        else
          str += "-0x" + CStrUtil::toHexString(-o, 2);
      }
#endif
    }
    else if (arg == 2) {
      ushort s = (args[1] << 8) | args[0];

      str += "0x" + CStrUtil::toHexString(s, 4);
    }
  }
  else if (type == A_P_REG)
    str += "(" + CZ80::getRegisterName(arg) + ")";
  else if (type == A_P_NUM) {
    if      (arg == 1)
      str += "(0x" + CStrUtil::toHexString(args[0], 2) + ")";
    else if (arg == 2) {
      ushort s = (args[1] << 8) | args[0];

      str += "(0x" + CStrUtil::toHexString(s, 4) + ")";
    }
  }
  else if (type == A_PO_REG) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")";
  }
  else if (type == A_FLAG)
    str += CZ80::getFlagName(arg);
  else if (type == A_REG)
    str += CZ80::getRegisterName(arg);
  else if (type == A_CONST)
    str += "0x" + CStrUtil::toHexString(arg, 2);
  else if (type == A_PO_REG_A) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->A";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->A";
  }
  else if (type == A_PO_REG_B) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->B";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->B";
  }
  else if (type == A_PO_REG_C) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->C";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->C";
  }
  else if (type == A_PO_REG_D) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->D";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->D";
  }
  else if (type == A_PO_REG_E) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->E";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->E";
  }
  else if (type == A_PO_REG_H) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->H";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->H";
  }
  else if (type == A_PO_REG_L) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+0x" + CStrUtil::toHexString( o, 2) + ")->L";
    else
      str += "-0x" + CStrUtil::toHexString(-o, 2) + ")->L";
  }
  else
    str += "??";

  return str;
}

uchar
CZ80OpData::
getSize()
{
  return op->getSize();
}

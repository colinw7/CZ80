#include <CZ80OpData.h>
#include <CZ80.h>
#include <CZ80Op.h>
#include <CFile.h>
#include <CStrUtil.h>

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

  if (! op)
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
dumpTxt(ushort pc, std::ostream &os)
{
  std::string str1 = CZ80::hexString(pc) + " " + toTxt();
  std::string str2 = getOpString(pc);

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
      str += " " + CZ80::hexString(values1[i]);

    for (uint i = 0; i < num_values2; ++i)
      str += " " + CZ80::hexString(values2[i]);
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
printStr(ushort pc, std::ostream &os)
{
  os << getOpString(pc);
}

std::string
CZ80OpData::
getOpString(ushort pc)
{
  std::string str = op->getName();

  ushort len1 = str.size();

  if (op->type1 != 0) {
    for ( ; len1 < 5; ++len1)
      str += " ";

    str += getArgString(pc, op->type1, op->arg1, values1, num_values1);

    if (op->type2 != 0) {
      str += ", ";

      str += getArgString(pc, op->type2, op->arg2, values2, num_values2);
    }
  }

  return str;
}

std::string
CZ80OpData::
getArgString(ushort pc, uint type, uint arg, uchar *args, ushort)
{
  std::string str, name;

  if      (type == A_NUM) {
    if      (arg == 1)
      str += CZ80::hexString("0x", args[0]);
    else if (arg == 2) {
      ushort s = (args[1] << 8) | args[0];

      if (z80 && z80->getValueLabel(s, name))
        str += name;
      else
        str += CZ80::hexString("0x", s);
    }
  }
  else if (type == A_S_NUM) {
    if      (arg == 1) {
      schar o = *(schar *) &args[0];

#ifdef CZ80_RELATIVE_OFFSETS
      if (o >= 0)
        str += "+" + CZ80::hexString("0x",  o);
      else
        str += "-" + CZ80::hexString("0x", -o);
#else
      if (z80) {
        ushort s = pc + o;

        if (z80->getValueLabel(s, name))
          str += name;
        else
          str += CZ80::hexString("0x", s);
      }
      else {
        if (o >= 0)
          str += "+" + CZ80::hexString("0x", (uchar) o);
        else
          str += "-" + CZ80::hexString("0x", (uchar)-o);
      }
#endif
    }
    else if (arg == 2) {
      ushort s = (args[1] << 8) | args[0];

      str += CZ80::hexString("0x", s);
    }
  }
  else if (type == A_P_REG) {
    str += "(" + CZ80::getRegisterName(arg) + ")";
  }
  else if (type == A_P_NUM) {
    if      (arg == 1)
      str += "(" + CZ80::hexString("0x", args[0]) + ")";
    else if (arg == 2) {
      ushort s = (args[1] << 8) | args[0];

      str += "(" + CZ80::hexString("0x", s) + ")";
    }
  }
  else if (type == A_PO_REG) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")";
  }
  else if (type == A_FLAG) {
    str += CZ80::getFlagName(arg);
  }
  else if (type == A_REG) {
    str += CZ80::getRegisterName(arg);
  }
  else if (type == A_CONST) {
    str += CZ80::hexString("0x", (uchar) arg);
  }
  else if (type == A_PO_REG_A) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->A";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->A";
  }
  else if (type == A_PO_REG_B) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->B";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->B";
  }
  else if (type == A_PO_REG_C) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->C";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->C";
  }
  else if (type == A_PO_REG_D) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->D";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->D";
  }
  else if (type == A_PO_REG_E) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->E";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->E";
  }
  else if (type == A_PO_REG_H) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->H";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->H";
  }
  else if (type == A_PO_REG_L) {
    schar o = *(schar *) &args[0];

    str += "(" + CZ80::getRegisterName(arg);

    if (o >= 0)
      str += "+" + CZ80::hexString("0x", (uchar) o) + ")->L";
    else
      str += "-" + CZ80::hexString("0x", (uchar)-o) + ")->L";
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

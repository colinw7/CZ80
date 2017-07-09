#include <CZ80.h>
#include <CZ80Op.h>
#include <CZ80OpData.h>
#include <CStrUtil.h>

const char *
CZ80Op::
getName() const
{
  return cz80_op_names[id + 1];
}

void
CZ80Op::
dumpCount(std::ostream &os)
{
  std::string count_str = CStrUtil::toString(count);

  while (count_str.size() < 8)
    count_str += " ";

  ushort pc = 0; // TODO ?

  std::string txt = toTxt(pc);

  os << count_str << " " << txt << std::endl;

  os.flush();
}

std::string
CZ80Op::
toTxt(ushort pc)
{
  CZ80OpData opData;

  opData.z80 = nullptr;
  opData.op  = this;

  opData.num_values1 = 2;
  opData.values1[0]  = 0;
  opData.values1[1]  = 0;
  opData.num_values2 = 2;
  opData.values2[0]  = 0;
  opData.values2[1]  = 0;

  return opData.getOpString(pc);
}

std::string
CZ80Op::
getCode()
{
  std::string str;

  if      (ind <  256)
    str +=         CStrUtil::toHexString(ind       , 2);
  else if (ind <  512)
    str += "cb " + CStrUtil::toHexString(ind -  256, 2);
  else if (ind <  768)
    str += "dd " + CStrUtil::toHexString(ind -  512, 2);
  else if (ind < 1024)
    str += "ed " + CStrUtil::toHexString(ind -  768, 2);
  else if (ind < 1280)
    str += "fd " + CStrUtil::toHexString(ind - 1024, 2);

  return str;
}

std::string
CZ80Op::
getExtCode(uchar c)
{
  std::string str;

  if      (ind < 1536)
    str += "dd cb " + CStrUtil::toHexString(c, 2) + " " +
                      CStrUtil::toHexString(ind - 1280, 2);
  else if (ind < 1792)
    str += "fd cb " + CStrUtil::toHexString(c, 2) + " " +
                      CStrUtil::toHexString(ind - 1536, 2);

  return str;
}

void
CZ80Op::
getValues(uchar **values, uint *num_values)
{
  static uchar values1[3];

  *num_values = 0;
  *values     = values1;

  if      (ind <  256)
    (*values)[(*num_values)++] = ind;
  else if (ind <  512) {
    (*values)[(*num_values)++] = 0xCB;
    (*values)[(*num_values)++] = ind -  256;
  }
  else if (ind <  768) {
    (*values)[(*num_values)++] = 0xDD;
    (*values)[(*num_values)++] = ind -  512;
  }
  else if (ind < 1024) {
    (*values)[(*num_values)++] = 0xED;
    (*values)[(*num_values)++] = ind -  768;
  }
  else if (ind < 1280) {
    (*values)[(*num_values)++] = 0xFD;
    (*values)[(*num_values)++] = ind - 1024;
  }
}

void
CZ80Op::
getExtValues(uchar c, uchar **values, uint *num_values)
{
  static uchar values1[4];

  *num_values = 0;
  *values     = values1;

  if      (ind < 1536) {
    (*values)[(*num_values)++] = 0xDD;
    (*values)[(*num_values)++] = 0xCB;
    (*values)[(*num_values)++] = c;
    (*values)[(*num_values)++] = ind - 1280;
  }
  else if (ind < 1792) {
    (*values)[(*num_values)++] = 0xFD;
    (*values)[(*num_values)++] = 0xCB;
    (*values)[(*num_values)++] = c;
    (*values)[(*num_values)++] = ind - 1536;
  }
}

bool
CZ80Op::
cmp(const CZ80Op &op)
{
  if (id != op.id)
    return false;

  ushort type_1, arg_1, type_2, arg_2;

  type_1 = type1;
  arg_1  = arg1;
  type_2 = op.type1;
  arg_2  = op.arg1;

  if (type_1 == A_S_NUM) type_1 = A_NUM;
  if (type_2 == A_S_NUM) type_2 = A_NUM;

  if (type_1 == A_NUM || type_1 == A_P_NUM) arg_1 = 1;
  if (type_2 == A_NUM || type_2 == A_P_NUM) arg_2 = 1;

  if (type_1 != type_2 || arg_1 != arg_2)
    return false;

  type_1 = type2;
  arg_1  = arg2;
  type_2 = op.type2;
  arg_2  = op.arg2;

  if (type_1 == A_S_NUM) type_1 = A_NUM;
  if (type_2 == A_S_NUM) type_2 = A_NUM;

  if (type_1 == A_NUM || type_1 == A_P_NUM) arg_1 = 1;
  if (type_2 == A_NUM || type_2 == A_P_NUM) arg_2 = 1;

  if (type_1 != type_2 || arg_1 != arg_2)
    return false;

  return true;
}

uchar
CZ80Op::
getSize()
{
  uchar size = 1;

  if (ind >= 256)
    ++size;

  if (ind >= 1280)
    ++size;

  if      (type1 == A_NUM || type1 == A_S_NUM || type1 == A_P_NUM) {
    size += arg1;
  }
  else if (type1 == A_PO_REG   || type1 == A_PO_REG_A ||
           type1 == A_PO_REG_B || type1 == A_PO_REG_C ||
           type1 == A_PO_REG_D || type1 == A_PO_REG_E ||
           type1 == A_PO_REG_H || type1 == A_PO_REG_L) {
    ++size;
  }

  if      (type2 == A_NUM || type2 == A_S_NUM || type2 == A_P_NUM) {
    size += arg2;
  }
  else if (type2 == A_PO_REG   || type2 == A_PO_REG_A ||
           type2 == A_PO_REG_B || type2 == A_PO_REG_C ||
           type2 == A_PO_REG_D || type2 == A_PO_REG_E ||
           type2 == A_PO_REG_H || type2 == A_PO_REG_L) {
    ++size;
  }

  return size;
}

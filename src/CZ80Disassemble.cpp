#include <CZ80.h>
#include <CZ80Op.h>
#include <CStrUtil.h>

bool
CZ80::
disassemble(std::ostream &os)
{
  return disassemble(load_pos_, load_len_, os);
}

bool
CZ80::
disassemble(ushort pos, ushort len, std::ostream &os)
{
  ushort pos1 = pos;
  ushort pos2 = getPC() + len;

  std::string str;
  ushort      len1, i;

  CZ80OpData op_data;

  //----

  ushort addr = 0;

  uint id = 1;

  setPC(pos);

  while ((pos1 = getPC()) < pos2) {
    readOpData(&op_data);

    if (op_data.op == NULL)
      continue;

    if      (op_data.op->id == OP_JP || op_data.op->id == OP_CALL) {
      if      (op_data.op->type1 == A_NUM)
        addr = op_data.getUWord1();
      else if (op_data.op->type2 == A_NUM)
        addr = op_data.getUWord2();
      else
        continue;

      if (! getValueLabel(addr, str)) {
        setLabelValue("LABEL_" + CStrUtil::toString(id), addr);

        ++id;
      }
    }
    else if (op_data.op->id == OP_JR || op_data.op->id == OP_DJNZ) {
      if      (op_data.op->type1 == A_S_NUM)
        addr = getPC() + op_data.getSByte1();
      else if (op_data.op->type2 == A_S_NUM)
        addr = getPC() + op_data.getSByte2();

      if (! getValueLabel(addr, str)) {
        setLabelValue("LABEL_" + CStrUtil::toString(id), addr);

        ++id;
      }
    }
  }

  //----

  setPC(pos);

  os << "  ORG  0x" << CStrUtil::toHexString(pos, 4) << std::endl;

  os << std::endl;

  while ((pos1 = getPC()) < pos2) {
    if (getValueLabel(pos1, str))
      os << str << ":" << std::endl;

    //-----

    readOpData(&op_data);

    if (op_data.op == NULL)
      continue;

    //-----

    str = op_data.getOpString();

    os << "  " << str;

    for (i = str.size(); i < 18; ++i)
      os << " ";

    os << " ; ";

    os << CStrUtil::toHexString(pos1, 4);

    len1 = 4;

    for (i = pos1; i < getPC(); ++i) {
      os << " " << CStrUtil::toHexString(getByte(i), 2);

      len1 += 3;
    }

    for ( ; len1 < 18; ++len1)
      os << " ";

    os << std::endl;
  }

  return true;
}

#include <CZ80Disassemble.h>
#include <CZ80OpData.h>

bool
CZ80::
disassemble(std::ostream &os)
{
  return disassemble(load_pos_, ushort(load_len_), os);
}

bool
CZ80::
disassemble(ushort pos, ushort len, std::ostream &os)
{
  ushort pos1 = pos;
  ushort pos2 = pos + len;

  std::string str;
  ushort      len1, i;

  CZ80OpData opData;

  //----

  ushort addr = 0;

  uint id = 1;

  // parse labels addresses
  while (pos1 < pos2) {
    readOpData(pos1, &opData);

    if (! opData.op)
      continue;

    int epos = pos1 + opData.op->len;

    if      (opData.op->id == OP_JP || opData.op->id == OP_CALL) {
      if      (opData.op->type1 == A_NUM)
        addr = opData.getUWord1();
      else if (opData.op->type2 == A_NUM)
        addr = opData.getUWord2();
      else
        continue;

      if (! getValueLabel(addr, str)) {
        setLabelValue("LABEL_" + CStrUtil::toString(id), addr);

        ++id;
      }
    }
    else if (opData.op->id == OP_JR || opData.op->id == OP_DJNZ) {
      if      (opData.op->type1 == A_S_NUM)
        addr = ushort(epos + int(opData.getSByte1()));
      else if (opData.op->type2 == A_S_NUM)
        addr = ushort(epos + int(opData.getSByte2()));

      if (! getValueLabel(addr, str)) {
        setLabelValue("LABEL_" + CStrUtil::toString(id), addr);

        ++id;
      }
    }

    pos1 += opData.op->len;
  }

  //----

  // disassemble instructions
  pos1 = pos;

  os << "  ORG  0x" << CStrUtil::toHexString(pos1, 4) << std::endl;

  os << std::endl;

  while (pos1 < pos2) {
    if (getValueLabel(pos1, str))
      os << str << ":" << std::endl;

    //----

    readOpData(pos1, &opData);

    if (! opData.op)
      continue;

    int epos = pos1 + opData.op->len;

    //----

    str = opData.getOpString(pos1);

    os << "  " << str;

    for (i = ushort(str.size()); i < 18; ++i)
      os << " ";

    os << " ; ";

    os << CStrUtil::toHexString(pos1, 4);

    len1 = 4;

    for (i = pos1; i < epos; ++i) {
      os << " " << CStrUtil::toHexString(getByte(i), 2);

      len1 += 3;
    }

    for ( ; len1 < 18; ++len1)
      os << " ";

    os << std::endl;

    //----

    pos1 += opData.op->len;
  }

  return true;
}

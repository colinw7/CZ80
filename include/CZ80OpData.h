#ifndef CZ80OpData_H
#define CZ80OpData_H

#include <CZ80.h>
#include <CZ80Types.h>
#include <CZ80Op.h>
#include <iostream>
#include <cassert>

struct CZ80Op;
class  CFile;

struct CZ80OpData {
  CZ80*   z80         { nullptr };
  CZ80Op* op          { nullptr };
  uchar   values1[2]  { 0, 0 };
  uchar   num_values1 { 0 };
  uchar   values2[2]  { 0, 0 };
  uchar   num_values2 { 0 };

  const char *getName() const;

  uchar  getUByte1() const { assert(num_values1 > 0); return values1[0]; }
  ushort getUWord1() const { assert(num_values1 > 1); return (values1[1] << 8) | values1[0]; }
  uchar  getUByte2() const { assert(num_values2 > 0); return values2[0]; }
  ushort getUWord2() const { assert(num_values2 > 1); return (values2[1] << 8) | values2[0]; }

  char  getSByte1() const { return (schar ) getUByte1(); }
  short getSWord1() const { return (sshort) getUWord1(); }
  char  getSByte2() const { return (schar ) getUByte2(); }
  short getSWord2() const { return (sshort) getUWord2(); }

  void setPByte1(uchar  b) { z80->setByte(getUWord1(), b); }
  void setPWord1(ushort w) { z80->setWord(getUWord1(), w); }

  uchar  getPByte2() const { return z80->getByte(getUWord2()); }
  ushort getPWord2() const { return z80->getWord(getUWord2()); }

  uchar getPOIX1() const { return z80->getPOIX(getSByte1()); }
  uchar getPOIY1() const { return z80->getPOIY(getSByte1()); }
  uchar getPOIX2() const { return z80->getPOIX(getSByte2()); }
  uchar getPOIY2() const { return z80->getPOIY(getSByte2()); }

  void setPOIX1(uchar b) { z80->setPOIX(getSByte1(), b); }
  void setPOIY1(uchar b) { z80->setPOIY(getSByte1(), b); }

  ushort getRPC1() { return z80->getPC() + getSByte1(); }
  ushort getRPC2() { return z80->getPC() + getSByte2(); }

  void execute();

  void dump  (CFile *file);
  bool undump(CFile *file);

  void dumpTxt(ushort pc, std::ostream &os=std::cout);

  std::string toTxt();

  void toValues(uchar **values, uint *num_values);

  void tracePC(ushort to) { z80->tracePC(op->len, to); }

  void printStr(ushort pc, std::ostream &os);

  std::string getOpString(ushort pc);

  std::string getArgString(ushort pc, uint type, uint arg, uchar *args, ushort num_args);

  uchar getSize();
};

#endif

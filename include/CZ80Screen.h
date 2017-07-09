#ifndef CZ80Screen_H
#define CZ80Screen_H

#include <CZ80Types.h>

class CZ80;

class CZ80Screen {
 public:
  CZ80Screen(CZ80 &z80_i) : z80(z80_i) { }

  virtual ~CZ80Screen() { }

  virtual void screenMemChanged(ushort, ushort) { }

  virtual void screenStep(int) { }

 protected:
  CZ80 &z80;
};

#endif

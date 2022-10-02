#ifndef CZ80RstData_H
#define CZ80RstData_H

class CZ80RstData {
 public:
  CZ80RstData(CZ80 &z80_i) : z80(z80_i) { }

  virtual ~CZ80RstData() { }

  virtual void rst(ushort) { }

 protected:
  CZ80 &z80;
};

//---

class CZ80StdRstData : public CZ80RstData {
 public:
  CZ80StdRstData(CZ80 &z80_) :
   CZ80RstData(z80_), newline_(true) {
  }

  void rst(ushort id) override;

  virtual void rstFwd(ushort) { }

 protected:
  bool newline_ { true };
};

#endif

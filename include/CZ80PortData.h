#ifndef CZ80PortData_H
#define CZ80PortData_H

class CZ80PortData {
 public:
  CZ80PortData(CZ80 &z80_i) : z80(z80_i) { }

  virtual ~CZ80PortData() { }

  virtual void out(uchar, uchar) { }
  virtual uchar in(uchar, uchar) { return 0; }

  virtual void keyPress  (const CKeyEvent &) { }
  virtual void keyRelease(const CKeyEvent &) { }

 protected:
  CZ80 &z80;
};

#endif

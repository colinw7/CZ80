#ifndef CZ80SpeedData_H
#define CZ80SpeedData_H

class CZ80;

class CZ80SpeedData {
 public:
  CZ80SpeedData(CZ80 &z80) :
   z80_(z80) {
  }

  virtual ~CZ80SpeedData() { }

  double getMhz() const { return mhz_; }

  virtual void init();

  virtual void interrupt();

  virtual void calcMhz();

  virtual void output();

 private:
  CZ80&  z80_;
  int    secs_  { 0 };
  int    usecs_ { 0 };
  double mhz_   { 1 };
};

#endif

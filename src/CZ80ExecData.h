#ifndef CZ80ExecData_H
#define CZ80ExecData_H

// class to notify pre/post instruction step
class CZ80ExecData {
 public:
  CZ80ExecData(CZ80 &z80) :
   z80_(z80) {
  }

  virtual ~CZ80ExecData() { }

  virtual void preStep () { }
  virtual void postStep() { }

  virtual void decT(uchar) { }
  virtual void incT(uchar) { }

  virtual void overflowT() { }

  virtual void setStop(bool) { }

  virtual void setHalt(bool) { }

 protected:
  CZ80 &z80_;
};

#endif

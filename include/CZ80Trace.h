#ifndef CZ80Trace_H
#define CZ80Trace_H

#include <CZ80Reg.h>
#include <CZ80Types.h>

class CZ80;

class CZ80Trace {
 public:
  CZ80Trace(CZ80 &z80_i) : z80(z80_i) { }

  virtual ~CZ80Trace() { }

  virtual void initProc() { }
  virtual void termProc() { }

  virtual void preStepProc () { }
  virtual void postStepProc() { }

  virtual void regChanged(CZ80Reg) { }
  virtual void memChanged(ushort, ushort) { }

  virtual void breakpointsChanged() { }

  virtual void traceBackChanged() { }

  virtual void setStop(bool) { }
  virtual void setHalt(bool) { }

 protected:
  CZ80 &z80;
};

#endif

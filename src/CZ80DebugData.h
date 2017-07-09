#ifndef CZ80DebugData_H
#define CZ80DebugData_H

class CZ80;
class CZ80Trace;

#include <CZ80Reg.h>
#include <CZ80Types.h>
#include <vector>
#include <list>
#include <cstring>

class CZ80DebugData {
 public:
  CZ80DebugData(CZ80 &z80) :
   z80_(z80) {
    memset(breakpoints_, 0, sizeof(breakpoints_));
  }

  virtual ~CZ80DebugData() { }

  void addTrace(CZ80Trace *trace);

  void callInitProcs();
  void callTermProcs();

  void callPreStepProcs();
  void callPostStepProcs();

  void callRegChanged(const CZ80Reg &reg);

  void callBreakpointsChangeProcs();

  void addBreakpoint(ushort pc);
  void removeBreakpoint(ushort pc);
  void removeAllBreakpoints();
  bool isBreakpoint(ushort pc);
  void getBreakpoints(std::vector<ushort> &addrs);

  void setAFChanged (bool flag) { af_changed_   = flag; }
  void setBCChanged (bool flag) { bc_changed_   = flag; }
  void setDEChanged (bool flag) { de_changed_   = flag; }
  void setHLChanged (bool flag) { hl_changed_   = flag; }
  void setIXChanged (bool flag) { ix_changed_   = flag; }
  void setIYChanged (bool flag) { iy_changed_   = flag; }
  void setSPChanged (bool flag) { sp_changed_   = flag; }
  void setPCChanged (bool flag) { pc_changed_   = flag; }
  void setIChanged  (bool flag) { i_changed_    = flag; }
  void setIMChanged (bool flag) { im_changed_   = flag; }
  void setAF1Changed(bool flag) { af_1_changed_ = flag; }
  void setBC1Changed(bool flag) { bc_1_changed_ = flag; }
  void setDE1Changed(bool flag) { de_1_changed_ = flag; }
  void setHL1Changed(bool flag) { hl_1_changed_ = flag; }
  void setIFFChanged(bool flag) { iff_changed_  = flag; }

  void setMemChanged(bool flag) { memChanged_ = flag; }

  void memPreWrite (ushort pos, ushort len);
  void memPostWrite(ushort pos, ushort len);

  void traceBackChanged();

  void setStop(bool b);
  void setHalt(bool b);

 protected:
  typedef std::list<CZ80Trace *> TraceList;

  CZ80&     z80_;
  uint      breakpoints_[2048];
  TraceList traceList_;

  bool af_changed_   { false };
  bool bc_changed_   { false };
  bool de_changed_   { false };
  bool hl_changed_   { false };
  bool ix_changed_   { false };
  bool iy_changed_   { false };
  bool sp_changed_   { false };
  bool pc_changed_   { false };
  bool i_changed_    { false };
  bool im_changed_   { false };
  bool af_1_changed_ { false };
  bool bc_1_changed_ { false };
  bool de_1_changed_ { false };
  bool hl_1_changed_ { false };
  bool iff_changed_  { false };

  bool   memChanged_     { false };
  ushort memChangedPos1_ { 0 };
  ushort memChangedPos2_ { 0 };
};

#endif

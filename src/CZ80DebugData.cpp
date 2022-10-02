#include <CZ80DebugData.h>
#include <CZ80Trace.h>
#include <CBits.h>

#define CZ80_CALL_TRACE_PROC(n) { \
for (const auto &trace : traceList_) \
  trace->n(); \
}

#define CZ80_CALL_TRACE_PROC_1(n,a1) { \
for (const auto &trace : traceList_) \
  trace->n(a1); \
}

#define CZ80_CALL_TRACE_PROC_2(n,a1,a2) { \
for (const auto &trace : traceList_) \
  trace->n(a1,a2); \
}

void
CZ80DebugData::
addTrace(CZ80Trace *trace)
{
  traceList_.push_back(trace);
}

void
CZ80DebugData::
callInitProcs()
{
  CZ80_CALL_TRACE_PROC(initProc);
}

void
CZ80DebugData::
callTermProcs()
{
  CZ80_CALL_TRACE_PROC(termProc);
}

void
CZ80DebugData::
callPreStepProcs()
{
  setAFChanged (false);
  setBCChanged (false);
  setDEChanged (false);
  setHLChanged (false);
  setIXChanged (false);
  setIYChanged (false);
  setSPChanged (false);
  setPCChanged (false);
  setIChanged  (false);
  setIMChanged (false);
  setAF1Changed(false);
  setBC1Changed(false);
  setDE1Changed(false);
  setHL1Changed(false);
  setIFFChanged(false);
  setMemChanged(false);

  CZ80_CALL_TRACE_PROC(preStepProc);
}

void
CZ80DebugData::
callPostStepProcs()
{
  for (const auto &trace : traceList_) {
    if (af_changed_  ) trace->regChanged(CZ80Reg::AF);
    if (bc_changed_  ) trace->regChanged(CZ80Reg::BC);
    if (de_changed_  ) trace->regChanged(CZ80Reg::DE);
    if (hl_changed_  ) trace->regChanged(CZ80Reg::HL);
    if (ix_changed_  ) trace->regChanged(CZ80Reg::IX);
    if (iy_changed_  ) trace->regChanged(CZ80Reg::IY);
    if (sp_changed_  ) trace->regChanged(CZ80Reg::SP);
    if (pc_changed_  ) trace->regChanged(CZ80Reg::PC);
    if (i_changed_   ) trace->regChanged(CZ80Reg::I);
    if (im_changed_  ) trace->regChanged(CZ80Reg::IM);
    if (iff_changed_ ) trace->regChanged(CZ80Reg::IFF);
    if (af_1_changed_) trace->regChanged(CZ80Reg::AF1);
    if (bc_1_changed_) trace->regChanged(CZ80Reg::BC1);
    if (de_1_changed_) trace->regChanged(CZ80Reg::DE1);
    if (hl_1_changed_) trace->regChanged(CZ80Reg::HL1);

    if (memChanged_)
      trace->memChanged(memChangedPos1_, ushort(memChangedPos2_ - memChangedPos1_ + 1));

    trace->postStepProc();
  }
}

void
CZ80DebugData::
callRegChanged(const CZ80Reg &reg)
{
  for (const auto &trace : traceList_)
    trace->regChanged(reg);
}

void
CZ80DebugData::
callBreakpointsChangeProcs()
{
  CZ80_CALL_TRACE_PROC(breakpointsChanged);
}

void
CZ80DebugData::
addBreakpoint(ushort pc)
{
  ushort row = pc >> 5;
  ushort col = pc & 0x1F; // 0-31 (32 bit flags)

  SET_BIT(breakpoints_[row], col);

  callBreakpointsChangeProcs();
}

void
CZ80DebugData::
removeBreakpoint(ushort pc)
{
  ushort row = pc >> 5;
  ushort col = pc & 0x1F; // 0-31 (32 bit flags)

  RST_BIT(breakpoints_[row], col);

  callBreakpointsChangeProcs();
}

void
CZ80DebugData::
removeAllBreakpoints()
{
  memset(breakpoints_, 0, sizeof(breakpoints_));

  callBreakpointsChangeProcs();
}

bool
CZ80DebugData::
isBreakpoint(ushort pc)
{
  ushort row = pc >> 5;
  ushort col = pc & 0x1F;

  return TST_BIT(breakpoints_[row], col);
}

void
CZ80DebugData::
getBreakpoints(std::vector<ushort> &addrs)
{
  ushort pc = 0;

  for (ushort i = 0; i < 2048; ++i) {
    if (breakpoints_[i]) {
      for (ushort j = 0; j < 32; ++j, ++pc)
        if (TST_BIT(breakpoints_[i], j)) addrs.push_back(pc);
    }
    else
      pc += 32;
  }
}

void
CZ80DebugData::
memPreWrite(ushort /*pos*/, ushort /*len*/)
{
}

void
CZ80DebugData::
memPostWrite(ushort pos, ushort len)
{
  ushort pos2 = ushort(pos + len - 1);

  if (! memChanged_) {
    memChanged_     = true;
    memChangedPos1_ = pos;
    memChangedPos2_ = pos2;
  }
  else {
    memChangedPos1_ = std::min(memChangedPos1_, pos);
    memChangedPos2_ = std::max(memChangedPos2_, pos2);
  }
}

void
CZ80DebugData::
traceBackChanged()
{
  CZ80_CALL_TRACE_PROC(traceBackChanged);
}

void
CZ80DebugData::
setStop(bool b)
{
  CZ80_CALL_TRACE_PROC_1(setStop, b);
}

void
CZ80DebugData::
setHalt(bool b)
{
  CZ80_CALL_TRACE_PROC_1(setHalt, b);
}

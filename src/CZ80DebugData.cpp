#include <CZ80.h>
#include <CStrUtil.h>

#define CZ80_CALL_TRACE_PROC(n) { \
TraceList::iterator ps = trace_list_.begin(); \
TraceList::iterator pe = trace_list_.end  (); \
 \
for ( ; ps != pe; ++ps) \
  (*ps)->n(); \
}

#define CZ80_CALL_TRACE_PROC_1(n,a1) { \
TraceList::iterator ps = trace_list_.begin(); \
TraceList::iterator pe = trace_list_.end  (); \
 \
for ( ; ps != pe; ++ps) \
  (*ps)->n(a1); \
}

#define CZ80_CALL_TRACE_PROC_2(n,a1,a2) { \
TraceList::iterator ps = trace_list_.begin(); \
TraceList::iterator pe = trace_list_.end  (); \
 \
for ( ; ps != pe; ++ps) \
  (*ps)->n(a1,a2); \
}

void
CZ80DebugData::
addTrace(CZ80Trace *trace)
{
  trace_list_.push_back(trace);
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
  TraceList::iterator ps = trace_list_.begin();
  TraceList::iterator pe = trace_list_.end  ();

  for ( ; ps != pe; ++ps) {
    if (af_changed_  ) (*ps)->regChanged(CZ80_REG_AF);
    if (bc_changed_  ) (*ps)->regChanged(CZ80_REG_BC);
    if (de_changed_  ) (*ps)->regChanged(CZ80_REG_DE);
    if (hl_changed_  ) (*ps)->regChanged(CZ80_REG_HL);
    if (ix_changed_  ) (*ps)->regChanged(CZ80_REG_IX);
    if (iy_changed_  ) (*ps)->regChanged(CZ80_REG_IY);
    if (sp_changed_  ) (*ps)->regChanged(CZ80_REG_SP);
    if (pc_changed_  ) (*ps)->regChanged(CZ80_REG_PC);
    if (i_changed_   ) (*ps)->regChanged(CZ80_REG_I);
    if (im_changed_  ) (*ps)->regChanged(CZ80_REG_IM);
    if (iff_changed_ ) (*ps)->regChanged(CZ80_REG_IFF);
    if (af_1_changed_) (*ps)->regChanged(CZ80_REG_AF1);
    if (bc_1_changed_) (*ps)->regChanged(CZ80_REG_BC1);
    if (de_1_changed_) (*ps)->regChanged(CZ80_REG_DE1);
    if (hl_1_changed_) (*ps)->regChanged(CZ80_REG_HL1);

    if (mem_changed_)
      (*ps)->memChanged(mem_changed_pos1_, mem_changed_pos2_ - mem_changed_pos1_ + 1);

    (*ps)->postStepProc();
  }
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
  ushort col = pc & 0x1F;

  SET_BIT(breakpoints_[row], col);

  callBreakpointsChangeProcs();
}

void
CZ80DebugData::
removeBreakpoint(ushort pc)
{
  ushort row = pc >> 5;
  ushort col = pc & 0x1F;

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
memChanged(ushort pos, ushort len)
{
  ushort pos2 = pos + len - 1;

  if (! mem_changed_) {
    mem_changed_      = true;
    mem_changed_pos1_ = pos;
    mem_changed_pos2_ = pos2;
  }
  else {
    mem_changed_pos1_ = std::min(mem_changed_pos1_, pos);
    mem_changed_pos2_ = std::max(mem_changed_pos2_, pos2);
  }
}

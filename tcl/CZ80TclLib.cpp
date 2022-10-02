#include <CZ80TclLib.h>
#include <CZ80TclLibScreen.h>
#include <CZ80RstData.h>
#include <CZ80OpData.h>

#include <CTclAppCommand.h>
#include <CXLib.h>
#include <CStrUtil.h>

#include <CZ80TclLib.k>

#define CZ80TclLibAppCommand(N) \
class N : public CTclAppCommand { \
 public: \
  N(CZ80TclLib *z80) : \
    CTclAppCommand(z80, #N), z80_(z80) { \
  } \
\
  CZ80TclLib *z80() const { return z80_; } \
\
 protected: \
  bool proc(int argc, const char **argv); \
\
 private: \
  CZ80TclLib *z80_ { nullptr }; \
};

CZ80TclLibAppCommand(CZ80TclLibExecute)
CZ80TclLibAppCommand(CZ80TclLibNext)
CZ80TclLibAppCommand(CZ80TclLibStep)
CZ80TclLibAppCommand(CZ80TclLibContinue)
CZ80TclLibAppCommand(CZ80TclLibStop)
CZ80TclLibAppCommand(CZ80TclLibRestart)
CZ80TclLibAppCommand(CZ80TclLibSetAddr)
CZ80TclLibAppCommand(CZ80TclLibRedrawScreen)
CZ80TclLibAppCommand(CZ80TclLibAddBreakpoint)
CZ80TclLibAppCommand(CZ80TclLibDelBreakpoint)
CZ80TclLibAppCommand(CZ80TclLibClrBreakpoint)
CZ80TclLibAppCommand(CZ80TclLibSetTrace)
CZ80TclLibAppCommand(CZ80TclLibExit)

CZ80TclLib::
CZ80TclLib(int argc, char **argv) :
 CTclApp(argc, argv), z80_(NULL), trace_(NULL), screen_(NULL),
 rst_data_(NULL), init_file_bin_(false), init_file_snapshot_(false),
 debug_(false), follow_(true), startup_(false), startup_pos_(0)
{
  if (argc > 1)
    init_filename_ = argv[1];
}

CZ80TclLib::
~CZ80TclLib()
{
  delete trace_;
  delete z80_;
}

void
CZ80TclLib::
setZ80(CZ80 *z80)
{
  z80_ = z80;
}

void
CZ80TclLib::
setScreen(CZ80TclLibScreen *screen)
{
  screen_ = screen;
}

void
CZ80TclLib::
setScreenCanvas(CZ80TclLibScreenCanvas *canvas)
{
  if (screen_ != NULL)
    screen_->canvas = canvas;
}

void
CZ80TclLib::
drawScreen()
{
  if (screen_ != NULL)
    screen_->redraw();
}

void
CZ80TclLib::
addBreakpoint()
{
  if (! z80_->isBreakpoint(z80_->getPC()))
    z80_->addBreakpoint(z80_->getPC());
}

void
CZ80TclLib::
delBreakpoint()
{
  if (z80_->isBreakpoint(z80_->getPC()))
    z80_->removeBreakpoint(z80_->getPC());
}

void
CZ80TclLib::
clrBreakpoint()
{
  z80_->removeAllBreakpoints();
}

void
CZ80TclLib::
setTrace(bool flag)
{
  follow_ = flag;
}

void
CZ80TclLib::
addStdRstData()
{
  rst_data_ = reinterpret_cast<CZ80RstData *>(1);
}

void
CZ80TclLib::
init()
{
  if (z80_ == NULL)
    z80_ = new CZ80();

  if (debug_)
    trace_ = new CZ80TclLibDebugTrace(*z80_, this);
  else
    trace_ = new CZ80TclLibBasicTrace(*z80_, this);

  z80_->addTrace(trace_);

  if (init_filename_ != "") {
    if      (init_file_bin_)
      z80_->loadBin(init_filename_);
    else if (init_file_snapshot_) {
      z80_->loadSnapshot(init_filename_);

      setStartup(z80_->getPC());
    }
    else
      z80_->load(init_filename_);
  }

  if (rst_data_ != NULL) {
    rst_data_ = new CZ80StdRstData(*z80_);

    z80_->setRstData(rst_data_);
  }

  CTclApp::init();
}

void
CZ80TclLib::
startup()
{
  if (debug_)
    eval("CZ80TclLibCreateDebug");

  if (screen_ != NULL) {
    setIntegerVar("cz80_tcl_screen_width" , screen_->width);
    setIntegerVar("cz80_tcl_screen_height", screen_->height);

    eval("CZ80TclLibCreateScreenWidget");

    if (! debug_)
      eval("CZ80TclLibAddScreenRefresh");
  }

  //---

  if (debug_) {
    setMemoryText();

    setInstructionsText();

    setStackText();

    setBreakpointText();

    updateAll();
  }

  //----

  if (startup_) {
    z80_->setLoadPos(startup_pos_);

    z80_->execute();
  }
}

void
CZ80TclLib::
setMemoryText()
{
  eval("CZ80TclLibClearMemoryText");

  unsigned int pos = 0;
  unsigned int len = 65536;

  ushort num_lines = ushort(len / 8);

  if ((len % 8) != 0) ++num_lines;

  z80_->setPC(ushort(pos));

  std::string str;

  unsigned int pos1 = pos;

  for (unsigned short i = 0; i < num_lines; ++i) {
    str = CStrUtil::toHexString(pos1, 4);

    if (i == 0)
      eval("CZ80TclLibAddAddrMemoryText {%s}", str.c_str());
    else
      eval("CZ80TclLibAddAddrMemoryText {\n%s}", str.c_str());

    //-----

    str = "";

    for (unsigned short j = 0; j < 8; ++j)
      str += CStrUtil::toHexString(z80_->getByte(pos1 + j), 2) + " ";

    str += "  ";

    for (unsigned short j = 0; j < 8; ++j) {
      unsigned char c = z80_->getByte(pos1 + j);

      str += getByteChar(c);
    }

    pos1 += 8;

    eval("CZ80TclLibAddNormalMemoryText \"  %s\"", str.c_str());
  }

  z80_->setPC(pos1);
}

std::string
CZ80TclLib::
getByteChar(unsigned char c)
{
  std::string str;

  if (c > 31 && c < 80) {
    if      (c == '$')
      str += "\\$";
    else if (c == '\"')
      str += "\\\"";
    else if (c == '[')
      str += "\\[";
    else if (c == ']')
      str += "\\]";
    else if (c == '\\')
      str += "\\\\";
    else
      str += c;
  }
  else
    str += '.';

  return str;
}

void
CZ80TclLib::
setInstructionsText()
{
  instruction_line_map_.clear();

  eval("CZ80TclLibClearInstructionsText");

#if 0
  unsigned int pos1 = z80_->getLoadPos();
  unsigned int pos2 = pos1 + z80_->getLoadLen();
#else
  unsigned int pos1 = 0;
  unsigned int pos2 = 65535;
#endif

  z80_->setPC(pos1);

  CZ80OpData op_data;

  std::string str;

  unsigned int this_pc = z80_->getPC();
  unsigned int last_pc = this_pc;

  unsigned int line_num = 1;

  while (this_pc >= last_pc && this_pc < pos2) {
    instruction_line_map_[this_pc] = line_num;

    //-----

    str = CStrUtil::toHexString(this_pc, 4);

    if (this_pc != pos1)
      eval("CZ80TclLibAddAddrInstructionsText {\n  %s}", str.c_str());
    else
      eval("CZ80TclLibAddAddrInstructionsText {  %s}", str.c_str());

    //-----

    z80_->readOpData(this_pc, &op_data);

    last_pc = this_pc;
    this_pc = this_pc + op_data.op->len;

    //-----

    str = " ";

    unsigned short len1 = 0;

    for (unsigned int i = last_pc; i < this_pc; ++i) {
      str += " ";
      str += CStrUtil::toHexString(z80_->getByte(i), 2);

      len1 += 3;
    }

    for ( ; len1 < 12; ++len1)
      str += " ";

    eval("CZ80TclLibAddNormalInstructionsText {%s}", str.c_str());

    //-----

    str = " ; ";

    if (op_data.op != NULL)
      str += op_data.getOpString(this_pc);
    else
      str += "??";

    eval("CZ80TclLibAddCodeInstructionsText {%s}", str.c_str());

    //-----

    ++line_num;
  }

  pos1 = z80_->getLoadPos();

  z80_->setPC(pos1);
}

void
CZ80TclLib::
setStackText()
{
  eval("CZ80TclLibClearStackText");

  unsigned short sp = z80_->getSP();

  sp -= 4;

  std::string str;

  for (unsigned short i = 0; i < 16; ++i) {
    unsigned short sp1 = sp + i;

    str = CStrUtil::toHexString(sp1, 4);

    if      (i == 0)
      eval("CZ80TclLibAddAddrStackText { %s}", str.c_str());
    else if (i == 4) {
      eval("CZ80TclLibAddCurrStackText {\n>}");
      eval("CZ80TclLibAddAddrStackText {%s}", str.c_str());
    }
    else
      eval("CZ80TclLibAddAddrStackText {\n %s}", str.c_str());

    //-----

    str = CStrUtil::toHexString(z80_->getByte(sp1), 2);

    eval("CZ80TclLibAddNormalStackText {  %s}", str.c_str());
  }
}

void
CZ80TclLib::
setBreakpointText()
{
  static std::list<unsigned int> breakpoints_;

  eval("CZ80TclLibClearBreakpointText");

  std::list<unsigned int>::iterator p1 = breakpoints_.begin();
  std::list<unsigned int>::iterator p2 = breakpoints_.end  ();

  for ( ; p1 != p2; ++p1)
    eval("CZ80TclLibUnmarkBreakpoint {%d}", *p1);

  breakpoints_ .clear();

  //----

  std::vector<unsigned short> addrs;

  z80_->getBreakpoints(addrs);

  std::string str;

  for (unsigned int i = 0; i < addrs.size(); ++i) {
    str = CStrUtil::toHexString(addrs[i], 4);

    if (i != 0)
      eval("CZ80TclLibAddNormalBreakpointText {\n%s}", str.c_str());
    else
      eval("CZ80TclLibAddNormalBreakpointText {%s}", str.c_str());

    InstructionLineMap::iterator p = instruction_line_map_.find(addrs[i]);

    if (p != instruction_line_map_.end()) {
      eval("CZ80TclLibMarkBreakpoint {%d}", (*p).second);

      breakpoints_.push_back((*p).second);
    }
  }
}

void
CZ80TclLib::
addCommands()
{
  new CZ80TclLibExecute      (this);
  new CZ80TclLibNext         (this);
  new CZ80TclLibStep         (this);
  new CZ80TclLibContinue     (this);
  new CZ80TclLibStop         (this);
  new CZ80TclLibRestart      (this);
  new CZ80TclLibSetAddr      (this);
  new CZ80TclLibRedrawScreen (this);
  new CZ80TclLibAddBreakpoint(this);
  new CZ80TclLibDelBreakpoint(this);
  new CZ80TclLibClrBreakpoint(this);
  new CZ80TclLibSetTrace     (this);
  new CZ80TclLibExit         (this);

  new CZ80TclLibScreenCanvasCmd(this);
}

std::string
CZ80TclLib::
getTclStr()
{
  return CZ80TclLib_TK;
}

void
CZ80TclLib::
initProc()
{
}

void
CZ80TclLib::
termProc()
{
}

void
CZ80TclLib::
preStepProc()
{
  if (debug_ && follow_)
    updateOp();
}

void
CZ80TclLib::
postStepProc()
{
  if (debug_ && follow_)
    updateGUI();

  if (trace_ != NULL)
    eval("update");
}

void
CZ80TclLib::
regChanged(CZ80Reg reg)
{
  if (! debug_ || ! follow_) return;

  if (reg == CZ80Reg::AF  || reg == CZ80Reg::NONE) {
    setStringVar("cz80_tcl_af", CStrUtil::toHexString(z80_->getAF(), 4));

    setIntegerVar("cz80_tcl_c_flag", z80_->tstCFlag());
    setIntegerVar("cz80_tcl_n_flag", z80_->tstNFlag());
    setIntegerVar("cz80_tcl_p_flag", z80_->tstPFlag());
    setIntegerVar("cz80_tcl_x_flag", z80_->tstXFlag());
    setIntegerVar("cz80_tcl_h_flag", z80_->tstHFlag());
    setIntegerVar("cz80_tcl_y_flag", z80_->tstYFlag());
    setIntegerVar("cz80_tcl_z_flag", z80_->tstZFlag());
    setIntegerVar("cz80_tcl_s_flag", z80_->tstSFlag());
  }
  if (reg == CZ80Reg::BC  || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_bc", CStrUtil::toHexString(z80_->getBC(), 4));
  if (reg == CZ80Reg::DE  || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_de", CStrUtil::toHexString(z80_->getDE(), 4));
  if (reg == CZ80Reg::HL  || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_hl", CStrUtil::toHexString(z80_->getHL(), 4));
  if (reg == CZ80Reg::IX  || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_ix" , CStrUtil::toHexString(z80_->getIX (), 4));
  if (reg == CZ80Reg::IY  || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_iy" , CStrUtil::toHexString(z80_->getIY (), 4));
  if (reg == CZ80Reg::SP  || reg == CZ80Reg::NONE) {
    setStringVar("cz80_tcl_sp", CStrUtil::toHexString(z80_->getSP(), 4));

    setStackText();
  }
  if (reg == CZ80Reg::PC  || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_pc" , CStrUtil::toHexString(z80_->getPC (), 4));
  if (reg == CZ80Reg::I   || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_i"  , CStrUtil::toHexString(z80_->getI  (), 2));
  if (reg == CZ80Reg::R   || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_r"  , CStrUtil::toHexString(z80_->getR  (), 2));
  if (reg == CZ80Reg::AF1 || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_af_1" , CStrUtil::toHexString(z80_->getAF1(), 4));
  if (reg == CZ80Reg::BC1 || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_bc_1" , CStrUtil::toHexString(z80_->getBC1(), 4));
  if (reg == CZ80Reg::DE1 || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_de_1" , CStrUtil::toHexString(z80_->getDE1(), 4));
  if (reg == CZ80Reg::HL1 || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_hl_1" , CStrUtil::toHexString(z80_->getHL1(), 4));
  if (reg == CZ80Reg::IFF || reg == CZ80Reg::NONE)
    setStringVar("cz80_tcl_iff", CStrUtil::toHexString(z80_->getIFF(), 2));
}

void
CZ80TclLib::
memChanged(unsigned short pos, unsigned short len)
{
  if (debug_ && follow_) {
    unsigned short pos1 = pos;
    unsigned short pos2 = pos + len;

    for (pos = pos1; pos < pos2; ++pos) {
      unsigned short posd = pos / 8;
      unsigned short posh = posd * 8;
      unsigned short posl = pos - posh;

      unsigned char c = z80_->getByte(pos);

      std::string str = getByteChar(c);

      eval("CZ80TclLibSetMem %d %d {%s} \"%s\"",
           posd + 1, posl, CStrUtil::toHexString(c, 2).c_str(), str.c_str());
    }
  }

  if (screen_ != NULL && screen_->containsMem(pos, len))
    screen_->redraw();
}

void
CZ80TclLib::
breakpointsChanged()
{
  setBreakpointText();
}

void
CZ80TclLib::
updateAll()
{
  regChanged(CZ80Reg::NONE);

  updateOp();

  markPC();
}

void
CZ80TclLib::
updateOp()
{
  CZ80OpData op_data;

  z80_->getOpData(&op_data);

  std::string str = op_data.getOpString(z80_->getPC());

  setStringVar("cz80_tcl_op_data", str);
}

void
CZ80TclLib::
updateGUI()
{
  updateOp();

  markPC();
}

void
CZ80TclLib::
execute()
{
  z80_->execute();
}

void
CZ80TclLib::
next()
{
  z80_->next();
}

void
CZ80TclLib::
step()
{
  z80_->step();
}

void
CZ80TclLib::
cont()
{
  z80_->cont();
}

void
CZ80TclLib::
stop()
{
  z80_->stop();
}

void
CZ80TclLib::
restart()
{
  z80_->reset();

  setPC(z80_->getLoadPos());
}

void
CZ80TclLib::
setPC(unsigned short pc)
{
  z80_->setPC(pc);

  if (debug_)
    updateGUI();
}

void
CZ80TclLib::
markPC()
{
  unsigned short pc = z80_->getPC();

  InstructionLineMap::iterator p = instruction_line_map_.find(pc);

  if (p != instruction_line_map_.end())
    eval("CZ80TclLibMarkPC {%d}", (*p).second);
}

void
CZ80TclLib::
keyPress(const CKeyEvent &kevent)
{
  z80_->keyPress(kevent);
}

void
CZ80TclLib::
keyRelease(const CKeyEvent &kevent)
{
  z80_->keyRelease(kevent);
}

void
CZ80TclLibDebugTrace::
initProc()
{
  tcl->initProc();
}

void
CZ80TclLibDebugTrace::
termProc()
{
  tcl->termProc();
}

void
CZ80TclLibDebugTrace::
preStepProc()
{
  tcl->preStepProc();
}

void
CZ80TclLibDebugTrace::
postStepProc()
{
  tcl->postStepProc();
}

void
CZ80TclLibDebugTrace::
regChanged(CZ80Reg reg)
{
  tcl->regChanged(reg);
}

void
CZ80TclLibDebugTrace::
memChanged(unsigned short pos, unsigned short len)
{
  tcl->memChanged(pos, len);
}

void
CZ80TclLibDebugTrace::
breakpointsChanged()
{
  tcl->breakpointsChanged();
}

void
CZ80TclLibBasicTrace::
postStepProc()
{
  tcl->postStepProc();
}

bool
CZ80TclLibExecute::
proc(int, const char **)
{
  z80_->execute();

  return true;
}

bool
CZ80TclLibNext::
proc(int, const char **)
{
  z80_->next();

  return true;
}

bool
CZ80TclLibStep::
proc(int, const char **)
{
  z80_->step();

  return true;
}

bool
CZ80TclLibContinue::
proc(int, const char **)
{
  z80_->cont();

  return true;
}

bool
CZ80TclLibStop::
proc(int, const char **)
{
  z80_->stop();

  return true;
}

bool
CZ80TclLibRestart::
proc(int, const char **)
{
  z80_->restart();

  return true;
}

bool
CZ80TclLibSetAddr::
proc(int argc, const char **argv)
{
  unsigned int addr;

  if (argc < 1 || ! CStrUtil::decodeHexString(argv[1], &addr))
    return false;

  z80_->setPC(addr);

  return true;
}

bool
CZ80TclLibRedrawScreen::
proc(int, const char **)
{
  z80_->drawScreen();

  return true;
}

bool
CZ80TclLibAddBreakpoint::
proc(int, const char **)
{
  z80_->addBreakpoint();

  return true;
}

bool
CZ80TclLibDelBreakpoint::
proc(int, const char **)
{
  z80_->delBreakpoint();

  return true;
}

bool
CZ80TclLibClrBreakpoint::
proc(int, const char **)
{
  z80_->clrBreakpoint();

  return true;
}

bool
CZ80TclLibSetTrace::
proc(int argc, const char **argv)
{
  if (argc < 1)
    return false;

  bool flag = CStrUtil::toInteger(argv[1]);

  z80_->setTrace(flag);

  return true;
}

bool
CZ80TclLibExit::
proc(int, const char **)
{
  exit(0);
}

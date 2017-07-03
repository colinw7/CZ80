#include <CZ80.h>
#include <CZ80OpP.h>
#include <CFile.h>
#include <CStrUtil.h>

#ifdef CL_PARSER
#include <CCeilP.h>
#endif

CZ80::
CZ80()
{
  memory_ = new uchar [65536];
  flags_  = new uchar [65536];

  memset(memory_, 0, 65536);
  memset(flags_ , 0, 65536);

  mhz_ = 4.00;
  htz_ = 50.0;
  t_   = 0;

  allowInterrupts_ = true;

  im2_ = 0xfe;

  ifreq_ = int(mhz_*1e6/htz_);

  setWord(0x0000, 0x76);
  setWord(0x0008, 0x76);
  setWord(0x0010, 0x76);
  setWord(0x0018, 0x76);
  setWord(0x0020, 0x76);
  setWord(0x0028, 0x76);
  setWord(0x0030, 0x76);
  setWord(0x0038, 0x76);

  load_pos_ = 0;
  load_len_ = 65536;

  initOpInds();

  reset();

#ifdef CL_PARSER
  ClParserInst->init();

  ClParserInst->setCaseSensitive(false);
#endif
}

CZ80::
~CZ80()
{
#ifdef CL_PARSER
  ClParserInst->term();
#endif

  delete dump_file_;

  delete [] memory_;
  delete [] flags_;
}

void
CZ80::
setDump(bool dump)
{
  dump_ = dump;

  if      (  dump_ && dump_file_ == nullptr)
    dump_file_ = new CFile("CZ80.dump");
  else if (! dump_ && dump_file_ != nullptr) {
    delete dump_file_;

    dump_file_ = nullptr;
  }
}

void
CZ80::
initOpInds()
{
  uint ind = 0;

  for (uint i = 0; i < 256; ++i) op_normal[i].ind = ind++;
  for (uint i = 0; i < 256; ++i) op_cb    [i].ind = ind++;
  for (uint i = 0; i < 256; ++i) op_dd    [i].ind = ind++;
  for (uint i = 0; i < 256; ++i) op_ed    [i].ind = ind++;
  for (uint i = 0; i < 256; ++i) op_fd    [i].ind = ind++;
  for (uint i = 0; i < 256; ++i) op_dd_cb [i].ind = ind++;
  for (uint i = 0; i < 256; ++i) op_fd_cb [i].ind = ind++;
}

void
CZ80::
reset()
{
  resetRegisters();

  setHalt(false);

  setStop(false);

  if (debugData_) {
    debugData_->removeAllBreakpoints();

    debugData_->callPostStepProcs();
  }
}

void
CZ80::
resetRegisters()
{
  setAF(0);
  setBC(0);
  setDE(0);
  setHL(0);

  setAF1(0);
  setBC1(0);
  setDE1(0);
  setHL1(0);

  setIX(0);
  setIY(0);

  setSP(0);
  setPC(0);

  setI(0);
  setR(0);

  setIFF(0);

  setIM(0);
}

void
CZ80::
setMemData(CZ80MemData *memData)
{
  memData_ = memData;
}

void
CZ80::
setPortData(CZ80PortData *portData)
{
  portData_ = portData;
}

void
CZ80::
setScreen(CZ80Screen *screen)
{
  screen_ = screen;
}

void
CZ80::
setRstData(CZ80RstData *rstData)
{
  rstData_ = rstData;
}

void
CZ80::
setDebugData(CZ80DebugData *debugData)
{
  debugData_ = debugData;
}

void
CZ80::
setSpeedData(CZ80SpeedData *speedData)
{
  speedData_ = speedData;
}

//------------

void
CZ80::
setHalt(bool halt)
{
  if (halt != halt_) {
    halt_ = halt;

    setT(ifreq_ - 4);
  }
}

bool
CZ80::
getHalt() const
{
  return halt_;
}

//------------

void
CZ80::
setAssembleStream(bool stream)
{
  assembleData_.setStream(stream);
}

//------------

void
CZ80::
addTrace(CZ80Trace *trace)
{
  if (! debugData_)
    debugData_ = new CZ80DebugData(*this);

  debugData_->addTrace(trace);
}

void
CZ80::
addBreakpoint(ushort pc)
{
  if (debugData_)
    debugData_->addBreakpoint(pc);
}

void
CZ80::
removeBreakpoint(ushort pc)
{
  if (debugData_)
    debugData_->removeBreakpoint(pc);
}

void
CZ80::
removeAllBreakpoints()
{
  if (debugData_)
    debugData_->removeAllBreakpoints();
}

bool
CZ80::
isBreakpoint(ushort pc)
{
  if (debugData_)
    return debugData_->isBreakpoint(pc);
  else
    return false;
}

void
CZ80::
getBreakpoints(std::vector<ushort> &addrs)
{
  if (debugData_)
    debugData_->getBreakpoints(addrs);
}

//------------

void
CZ80::
keyPress(CKeyType key_type)
{
  if (portData_)
    portData_->keyPress(key_type);
}

void
CZ80::
keyRelease(CKeyType key_type)
{
  if (portData_)
    portData_->keyRelease(key_type);
}

//------------

void
CZ80::
setA(uchar a)
{
  registers_.a_ = a;

  if (debugData_)
    debugData_->setAFChanged(true);
}

void
CZ80::
setF(uchar f)
{
  registers_.f_ = f;

  if (debugData_)
    debugData_->setAFChanged(true);
}

void
CZ80::
setB(uchar b)
{
  registers_.b_ = b;

  if (debugData_)
    debugData_->setBCChanged(true);
}

void
CZ80::
setC(uchar c)
{
  registers_.c_ = c;

  if (debugData_)
    debugData_->setBCChanged(true);
}

void
CZ80::
setD(uchar d)
{
  registers_.d_ = d;

  if (debugData_)
    debugData_->setDEChanged(true);
}

void
CZ80::
setE(uchar e)
{
  registers_.e_ = e;

  if (debugData_)
    debugData_->setDEChanged(true);
}

void
CZ80::
setH(uchar h)
{
  registers_.h_ = h;

  if (debugData_)
    debugData_->setHLChanged(true);
}

void
CZ80::
setL(uchar l)
{
  registers_.l_ = l;

  if (debugData_)
    debugData_->setHLChanged(true);
}

void
CZ80::
setI(uchar i)
{
  registers_.i_ = i;

  if (debugData_)
    debugData_->setIChanged(true);
}

void
CZ80::
setAF(ushort af)
{
  registers_.af_ = af;

  if (debugData_)
    debugData_->setAFChanged(true);
}

void
CZ80::
setBC(ushort bc)
{
  registers_.bc_ = bc;

  if (debugData_)
    debugData_->setBCChanged(true);
}

void
CZ80::
setDE(ushort de)
{
  registers_.de_ = de;

  if (debugData_)
    debugData_->setDEChanged(true);
}

void
CZ80::
setHL(ushort hl)
{
  registers_.hl_ = hl;

  if (debugData_)
    debugData_->setHLChanged(true);
}

void
CZ80::
setSP(ushort sp)
{
  registers_.sp_ = sp;

  if (debugData_)
    debugData_->setSPChanged(true);
}

void
CZ80::
setPC(ushort pc)
{
  registers_.pc_ = pc;

  setHalt(false);

  if (debugData_)
    debugData_->setPCChanged(true);
}

void
CZ80::
setIX(ushort ix)
{
  registers_.ix_ = ix;

  if (debugData_)
    debugData_->setIXChanged(true);
}

void
CZ80::
setIY(ushort iy)
{
  registers_.iy_ = iy;

  if (debugData_)
    debugData_->setIYChanged(true);
}

void
CZ80::
setIXH(uchar ixh)
{
  registers_.ixh_ = ixh;

  if (debugData_)
    debugData_->setIXChanged(true);
}

void
CZ80::
setIXL(uchar ixl)
{
  registers_.ixl_ = ixl;

  if (debugData_)
    debugData_->setIXChanged(true);
}

void
CZ80::
setIYH(uchar iyh)
{
  registers_.iyh_ = iyh;

  if (debugData_)
    debugData_->setIYChanged(true);
}

void
CZ80::
setIYL(uchar iyl)
{
  registers_.iyl_ = iyl;

  if (debugData_)
    debugData_->setIYChanged(true);
}

void
CZ80::
setIFF(ushort iff)
{
  registers_.iff_ = iff;

  if (debugData_)
    debugData_->setIFFChanged(true);
}

void
CZ80::
setIFF1(uchar iff1)
{
  registers_.iff1_ = iff1;

  if (debugData_)
    debugData_->setIFFChanged(true);
}

void
CZ80::
setIFF2(uchar iff2)
{
  registers_.iff2_ = iff2;

  if (debugData_)
    debugData_->setIFFChanged(true);
}

void
CZ80::
setAF1(ushort af)
{
  registers_.af_1_ = af;

  if (debugData_)
    debugData_->setAF1Changed(true);
}

void
CZ80::
setBC1(ushort bc)
{
  registers_.bc_1_ = bc;

  if (debugData_)
    debugData_->setBC1Changed(true);
}

void
CZ80::
setDE1(ushort de)
{
  registers_.de_1_ = de;

  if (debugData_)
    debugData_->setDE1Changed(true);
}

void
CZ80::
setHL1(ushort hl)
{
  registers_.hl_1_ = hl;

  if (debugData_)
    debugData_->setHL1Changed(true);
}

void
CZ80::
setIM(uchar im)
{
  registers_.im_ = im;

//if (registers_.im_ == 1)
//  call(0x0038);

  if (debugData_)
    debugData_->setIMChanged(true);
}

void
CZ80::
setPBC(uchar bc)
{
  setByte(getBC(), bc);
}

void
CZ80::
setPDE(uchar de)
{
  setByte(getDE(), de);
}

void
CZ80::
setPHL(uchar hl)
{
  setByte(getHL(), hl);
}

void
CZ80::
setPOIX(schar o, uchar ix)
{
  setByte(getIX() + o, ix);
}

void
CZ80::
setPOIY(schar o, uchar iy)
{
  setByte(getIY() + o, iy);
}

void
CZ80::
setPSP2(ushort w)
{
  setWord(getSP(), w);
}

//---------

void
CZ80::
setFlag(uchar bit)
{
  SET_BIT(registers_.f_, bit);

  if (debugData_)
    debugData_->setAFChanged(true);
}

void
CZ80::
resFlag(uchar bit)
{
  RST_BIT(registers_.f_, bit);

  if (debugData_)
    debugData_->setAFChanged(true);
}

uchar
CZ80::
tstFlag(uchar bit)
{
  return TST_BIT(registers_.f_, bit);
}

//---------

void
CZ80::
incR(uchar d)
{
  registers_.r_ += d;
}

void
CZ80::
decR(uchar d)
{
  if (d >= registers_.r_)
    registers_.r_ -= d;
  else
    registers_.r_ = 0;
}

void
CZ80::
decT(ushort d)
{
  if (t_ >= d)
    t_ -= d;
  else
    t_ = 0;
}

void
CZ80::
incT(ushort d)
{
  if (t_ + d <= ifreq_)
    t_ += d;
  else
    t_ = interrupt();
}

int
CZ80::
interrupt()
{
  if (! allowInterrupts_)
    return 0;

  if (speedData_)
    speedData_->interrupt();

  // If not a non-maskable interrupt

  if (! getIFF1())
    return 0;

  setHalt(false);

  switch (getIM() ) {
    case 0: {
      // TODO: proper implementation

      di();

      call(56);

      return 13;
    }

    case 1: {
      di();

      call(56);

      return 13;
    }

    case 2: {
      int addr = (getI() << 8) | im2_;

      di();

      call(getWord(addr));

      return 19;
    }

    default:
      return 0;
  }
}

//---------

void
CZ80::
setByte(uchar c)
{
  setByte(getPC(), c);
}

void
CZ80::
setByte(ushort pos, uchar c)
{
  setBytes(&c, pos, 1);
}

void
CZ80::
setWord(ushort w)
{
  setWord(getPC(), w);
}

void
CZ80::
setWord(ushort pos, ushort w)
{
  setBytes((uchar *) &w, pos, 2);
}

void
CZ80::
setBytes(uchar *c, ushort pos, ushort len)
{
  // fail if read-only

  if (flags_[pos] & CZ80_MEM_READ_ONLY) {
    std::cerr << "Invalid memory access @ " << std::hex << int(pos) <<
                 " from " << int(getPC()) << std::dec << std::endl;
    return;
  }

  // set memory

  memcpy(&memory_[pos], c, len);

  // debugger hook

  if (debugData_)
    debugData_->memChanged(pos, len);

  // mem notify

  if (memData_)
    memData_->memWrite(c, pos, len);

  // update screen

  if (screen_) {
    ushort pos1 = pos;
    ushort pos2 = pos + len - 1;

    while (pos1 <= pos2 && ! (flags_[pos1] & CZ80_MEM_SCREEN))
      ++pos1;

    while (pos2 >= pos1 && ! (flags_[pos2] & CZ80_MEM_SCREEN))
      --pos2;

    if (pos1 <= pos2)
      screen_->memChanged(pos1, pos2 - pos1 + 1);
  }
}

uchar
CZ80::
getByte() const
{
  return getByte(getPC());
}

uchar
CZ80::
getByte(ushort pos) const
{
  uchar c;

  getBytes(&c, pos, 1);

  return c;
}

ushort
CZ80::
getWord() const
{
  return getWord(getPC());
}

ushort
CZ80::
getWord(ushort pos) const
{
  uchar c[2];

  getBytes(c, pos, 2);

  return (c[1] << 8) | c[0];
}

void
CZ80::
getBytes(uchar *c, ushort pos, ushort len) const
{
  if (! memData_ || ! memData_->memRead(c, pos, len))
    memcpy(c, &memory_[pos], len);
}

//---------

void
CZ80::
setMemFlags(ushort pos, ushort len, uchar flag)
{
  for (ushort i = 0; i < len; ++i, ++pos)
    flags_[pos] |= flag;
}

void
CZ80::
resetMemFlags(ushort pos, ushort len, uchar flag)
{
  for (ushort i = 0; i < len; ++i, ++pos)
    flags_[pos] &= ~flag;
}

//---------

void
CZ80::
pushAF()
{
  push(getAF());
}

void
CZ80::
pushBC()
{
  push(getBC());
}

void
CZ80::
pushDE()
{
  push(getDE());
}

void
CZ80::
pushHL()
{
  push(getHL());
}

void
CZ80::
pushIX()
{
  push(getIX());
}

void
CZ80::
pushIY()
{
  push(getIY());
}

void
CZ80::
pushPC()
{
  push(getPC());
}

void
CZ80::
push(ushort r)
{
  setSP(getSP() - 2);

  setPSP2(r);
}

//---------

void
CZ80::
popAF()
{
  setAF(pop());
}

void
CZ80::
popBC()
{
  setBC(pop());
}

void
CZ80::
popDE()
{
  setDE(pop());
}

void
CZ80::
popHL()
{
  setHL(pop());
}

void
CZ80::
popIX()
{
  setIX(pop());
}

void
CZ80::
popIY()
{
  setIY(pop());
}

void
CZ80::
popPC()
{
  setPC(pop());
}

ushort
CZ80::
pop()
{
  ushort r = getPSP2();

  setSP(getSP() + 2);

  return r;
}

//---------

ushort
CZ80::
peek()
{
  ushort r = getPSP2();

  return r;
}

//---------

void
CZ80::
addA(uchar a)
{
  setA(addR(getA(), a));
}

void
CZ80::
addHL(ushort hl)
{
#ifdef CZ80_ADD_16_RETAIN_SZP
  bool s = tstSFlag();
  bool z = tstZFlag();
  bool p = tstPFlag();
#endif

  uchar h = (hl & 0xFF00) >> 8;
  uchar l =  hl & 0x00FF ;

  setL(addR(getL(), l));
  setH(adcR(getH(), h));

#ifdef CZ80_ADD_16_RETAIN_SZP
  setSFlag(s);
  setZFlag(z);
  setPFlag(p);
#else
  setZFlag(getHL() == 0x0000);
#endif
}

uchar
CZ80::
addR(uchar r, uchar a)
{
  int sa = (int) (char)  r         + (int) (char)  a;
  int ua = (int)         r         + (int)         a;
  int ha = (int)        (r & 0x0F) + (int)        (a & 0x0F);

  setVFlag(sa != (char) ua);

  setCFlag(ua > 0xFF);
  setHFlag(ha > 0x0F);

  r += a;

  setRFlags(r);

  resNFlag();

  return r;
}

void
CZ80::
addIX(ushort ix)
{
#ifdef CZ80_ADD_16_RETAIN_SZP
  bool s = tstSFlag();
  bool z = tstZFlag();
  bool p = tstPFlag();
#endif

  uchar ixh = (ix & 0xFF00) >> 8;
  uchar ixl =  ix & 0x00FF ;

  setIXL(addR(getIXL(), ixl));
  setIXH(adcR(getIXH(), ixh));

#ifdef CZ80_ADD_16_RETAIN_SZP
  setSFlag(s);
  setZFlag(z);
  setPFlag(p);
#else
  setZFlag(getIX() == 0x0000);
#endif
}

void
CZ80::
addIY(ushort iy)
{
#ifdef CZ80_ADD_16_RETAIN_SZP
  bool s = tstSFlag();
  bool z = tstZFlag();
  bool p = tstPFlag();
#endif

  uchar iyh = (iy & 0xFF00) >> 8;
  uchar iyl =  iy & 0x00FF ;

  setIYL(addR(getIYL(), iyl));
  setIYH(adcR(getIYH(), iyh));

#ifdef CZ80_ADD_16_RETAIN_SZP
  setSFlag(s);
  setZFlag(z);
  setPFlag(p);
#else
  setZFlag(getIY() == 0x0000);
#endif
}

void
CZ80::
adcA(uchar a)
{
  setA(adcR(getA(), a));
}

void
CZ80::
adcHL(ushort hl)
{
  uchar h = (hl & 0xFF00) >> 8;
  uchar l =  hl & 0x00FF ;

  setL(adcR(getL(), l));
  setH(adcR(getH(), h));

  setZFlag(getHL() == 0x0000);
}

uchar
CZ80::
adcR(uchar r, uchar a)
{
  uchar c = tstCFlag();

  int sa = (int) (char)  r         + (int) (char)  a         + (int) c;
  int ua = (int)         r         + (int)         a         + (int) c;
  int ha = (int)        (r & 0x0F) + (int)        (a & 0x0F) + (int) c;

  setVFlag(sa != (char) ua);

  setCFlag(ua > 0xFF);
  setHFlag(ha > 0x0F);

  r += a + c;

  setRFlags(r);

  resNFlag();

  return r;
}

//---------

void
CZ80::
subA(uchar a)
{
  setA(subR(getA(), a));
}

uchar
CZ80::
subR(uchar r, uchar a)
{
  int sd = (int) (char)  r        - (int) (char)  a;
  int ud = (int)         r        - (int)         a;
  int hd = (int)        (r & 0xF) - (int)        (a & 0x0F);

  setVFlag(sd != (char) ud);

  setCFlag(ud < 0x00);
  setHFlag(hd < 0x00);

  r -= a;

  setRFlags(r);

  setNFlag();

  return r;
}

void
CZ80::
sbcA(uchar a)
{
  setA(sbcR(getA(), a));
}

void
CZ80::
sbcHL(ushort hl)
{
  uchar h = (hl & 0xFF00) >> 8;
  uchar l =  hl & 0x00FF ;

  setL(sbcR(getL(), l));
  setH(sbcR(getH(), h));

  setZFlag(getHL() == 0x0000);
}

uchar
CZ80::
sbcR(uchar r, uchar a)
{
  uchar c = tstCFlag();

  int sd = (int) (char)  r         - (int) (char)  a         - (int) c;
  int ud = (int)         r         - (int)         a         - (int) c;
  int hd = (int)        (r & 0x0F) - (int)        (a & 0x0F) - (int) c;

  setVFlag(sd != (char) ud);

  setCFlag(ud <  0x00);
  setHFlag(hd <  0x00);

  r -= a + c;

  setRFlags(r);

  setNFlag();

  return r;
}

//---------

void
CZ80::
cpA(uchar a)
{
  subR(getA(), a);

#ifdef CZ80_CP_COPY_XY_FLAGS
  setXFlag(a & 0x08);
  setYFlag(a & 0x20);
#endif
}

//---------

void
CZ80::
incA()
{
  setA(inc(getA()));
}

void
CZ80::
incB()
{
  setB(inc(getB()));
}

void
CZ80::
incC()
{
  setC(inc(getC()));
}

void
CZ80::
incD()
{
  setD(inc(getD()));
}

void
CZ80::
incE()
{
  setE(inc(getE()));
}

void
CZ80::
incH()
{
  setH(inc(getH()));
}

void
CZ80::
incL()
{
  setL(inc(getL()));
}

void
CZ80::
incIXL()
{
  setIXL(inc(getIXL()));
}

void
CZ80::
incIXH()
{
  setIXH(inc(getIXH()));
}

void
CZ80::
incIYL()
{
  setIYL(inc(getIYL()));
}

void
CZ80::
incIYH()
{
  setIYH(inc(getIYH()));
}

void
CZ80::
incBC()
{
  setBC(getBC() + 1);
}

void
CZ80::
incDE()
{
  setDE(getDE() + 1);
}

void
CZ80::
incHL()
{
  setHL(getHL() + 1);
}

void
CZ80::
incSP()
{
  setSP(getSP() + 1);
}

void
CZ80::
incPC(sshort o)
{
  setPC(getPC() + o);
}

void
CZ80::
incIX()
{
  setIX(getIX() + 1);
}

void
CZ80::
incIY()
{
  setIY(getIY() + 1);
}

void
CZ80::
incPHL()
{
  setPHL(inc(getPHL()));
}

void
CZ80::
incPOIX(schar o)
{
  setPOIX(o, inc(getPOIX(o)));
}

void
CZ80::
incPOIY(schar o)
{
  setPOIY(o, inc(getPOIY(o)));
}

//---------

void
CZ80::
decA()
{
  setA(dec(getA()));
}

void
CZ80::
decB()
{
  setB(dec(getB()));
}

void
CZ80::
decC()
{
  setC(dec(getC()));
}

void
CZ80::
decD()
{
  setD(dec(getD()));
}

void
CZ80::
decE()
{
  setE(dec(getE()));
}

void
CZ80::
decH()
{
  setH(dec(getH()));
}

void
CZ80::
decL()
{
  setL(dec(getL()));
}

void
CZ80::
decIXL()
{
  setIXL(dec(getIXL()));
}

void
CZ80::
decIXH()
{
  setIXH(dec(getIXH()));
}

void
CZ80::
decIYL()
{
  setIYL(dec(getIYL()));
}

void
CZ80::
decIYH()
{
  setIYH(dec(getIYH()));
}

void
CZ80::
decBC()
{
  setBC(getBC() - 1);
}

void
CZ80::
decDE()
{
  setDE(getDE() - 1);
}

void
CZ80::
decHL()
{
  setHL(getHL() - 1);
}

void
CZ80::
decSP()
{
  setSP(getSP() - 1);
}

void
CZ80::
decPC(sshort o)
{
  setPC(getPC() - o);
}

void
CZ80::
decIX()
{
  setIX(getIX() - 1);
}

void
CZ80::
decIY()
{
  setIY(getIY() - 1);
}

void
CZ80::
decPHL()
{
  setPHL(dec(getPHL()));
}

void
CZ80::
decPOIX(schar o)
{
  setPOIX(o, dec(getPOIX(o)));
}

void
CZ80::
decPOIY(schar o)
{
  setPOIY(o, dec(getPOIY(o)));
}

//---------

uchar
CZ80::
inc(uchar r)
{
  ++r;

  setHFlag((r & 0x0F) == 0x00);
  setVFlag( r         == 0x80);

  setRFlags(r);

  resNFlag();

  return r;
}

uchar
CZ80::
dec(uchar r)
{
  --r;

  setHFlag((r & 0x0F) == 0x0F);
  setVFlag( r         == 0x7F);

  setRFlags(r);

  setNFlag();

  return r;
}

//-------------

void
CZ80::
andA(uchar a)
{
  setA(getA() & a);

  setBRFlags(getA());

  resCFlag();
  setHFlag();
}

void
CZ80::
orA(uchar a)
{
  setA(getA() | a);

  setBRFlags(getA());

  resCFlag();
  resHFlag();
}

void
CZ80::
xorA(uchar a)
{
  setA(getA() ^ a);

  setBRFlags(getA());

  resCFlag();
  resHFlag();
}

//---------

void
CZ80::
sllA()
{
  setA(sll(getA()));
}

void
CZ80::
sllB()
{
  setB(sll(getB()));
}

void
CZ80::
sllC()
{
  setC(sll(getC()));
}

void
CZ80::
sllD()
{
  setD(sll(getD()));
}

void
CZ80::
sllE()
{
  setE(sll(getE()));
}

void
CZ80::
sllH()
{
  setH(sll(getH()));
}

void
CZ80::
sllL()
{
  setL(sll(getL()));
}

void
CZ80::
sllPHL()
{
  setPHL(sll(getPHL()));
}

void
CZ80::
sllPOIX(schar o)
{
  setPOIX(o, sll(getPOIX(o)));
}

void
CZ80::
sllPOIY(schar o)
{
  setPOIY(o, sll(getPOIY(o)));
}

//---------

void
CZ80::
srlA()
{
  setA(srl(getA()));
}

void
CZ80::
srlB()
{
  setB(srl(getB()));
}

void
CZ80::
srlC()
{
  setC(srl(getC()));
}

void
CZ80::
srlD()
{
  setD(srl(getD()));
}

void
CZ80::
srlE()
{
  setE(srl(getE()));
}

void
CZ80::
srlH()
{
  setH(srl(getH()));
}

void
CZ80::
srlL()
{
  setL(srl(getL()));
}

void
CZ80::
srlPHL()
{
  setPHL(srl(getPHL()));
}

void
CZ80::
srlPOIX(schar o)
{
  setPOIX(o, srl(getPOIX(o)));
}

void
CZ80::
srlPOIY(schar o)
{
  setPOIY(o, srl(getPOIY(o)));
}

//---------

void
CZ80::
slaA()
{
  setA(sla(getA()));
}

void
CZ80::
slaB()
{
  setB(sla(getB()));
}

void
CZ80::
slaC()
{
  setC(sla(getC()));
}

void
CZ80::
slaD()
{
  setD(sla(getD()));
}

void
CZ80::
slaE()
{
  setE(sla(getE()));
}

void
CZ80::
slaH()
{
  setH(sla(getH()));
}

void
CZ80::
slaL()
{
  setL(sla(getL()));
}

void
CZ80::
slaPHL()
{
  setPHL(sla(getPHL()));
}

void
CZ80::
slaPOIX(schar o)
{
  setPOIX(o, sla(getPOIX(o)));
}

void
CZ80::
slaPOIY(schar o)
{
  setPOIY(o, sla(getPOIY(o)));
}

//---------

void
CZ80::
sraA()
{
  setA(sra(getA()));
}

void
CZ80::
sraB()
{
  setB(sra(getB()));
}

void
CZ80::
sraC()
{
  setC(sra(getC()));
}

void
CZ80::
sraD()
{
  setD(sra(getD()));
}

void
CZ80::
sraE()
{
  setE(sra(getE()));
}

void
CZ80::
sraH()
{
  setH(sra(getH()));
}

void
CZ80::
sraL()
{
  setL(sra(getL()));
}

void
CZ80::
sraPHL()
{
  setPHL(sra(getPHL()));
}

void
CZ80::
sraPOIX(schar o)
{
  setPOIX(o, sra(getPOIX(o)));
}

void
CZ80::
sraPOIY(schar o)
{
  setPOIY(o, sra(getPOIY(o)));
}

//---------

void
CZ80::
rlA()
{
  setA(rl(getA()));
}

void
CZ80::
rlB()
{
  setB(rl(getB()));
}

void
CZ80::
rlC()
{
  setC(rl(getC()));
}

void
CZ80::
rlD()
{
  setD(rl(getD()));
}

void
CZ80::
rlE()
{
  setE(rl(getE()));
}

void
CZ80::
rlH()
{
  setH(rl(getH()));
}

void
CZ80::
rlL()
{
  setL(rl(getL()));
}

void
CZ80::
rlPHL()
{
  setPHL(rl(getPHL()));
}

void
CZ80::
rlPOIX(schar o)
{
  setPOIX(o, rl(getPOIX(o)));
}

void
CZ80::
rlPOIY(schar o)
{
  setPOIY(o, rl(getPOIY(o)));
}

//---------

void
CZ80::
rlcA()
{
  setA(rlc(getA()));
}

void
CZ80::
rlcB()
{
  setB(rlc(getB()));
}

void
CZ80::
rlcC()
{
  setC(rlc(getC()));
}

void
CZ80::
rlcD()
{
  setD(rlc(getD()));
}

void
CZ80::
rlcE()
{
  setE(rlc(getE()));
}

void
CZ80::
rlcH()
{
  setH(rlc(getH()));
}

void
CZ80::
rlcL()
{
  setL(rlc(getL()));
}

void
CZ80::
rlcPHL()
{
  setPHL(rlc(getPHL()));
}

void
CZ80::
rlcPOIX(schar o)
{
  setPOIX(o, rlc(getPOIX(o)));
}

void
CZ80::
rlcPOIY(schar o)
{
  setPOIY(o, rlc(getPOIY(o)));
}

//---------

void
CZ80::
rrA()
{
  setA(rr(getA()));
}

void
CZ80::
rrB()
{
  setB(rr(getB()));
}

void
CZ80::
rrC()
{
  setC(rr(getC()));
}

void
CZ80::
rrD()
{
  setD(rr(getD()));
}

void
CZ80::
rrE()
{
  setE(rr(getE()));
}

void
CZ80::
rrH()
{
  setH(rr(getH()));
}

void
CZ80::
rrL()
{
  setL(rr(getL()));
}

void
CZ80::
rrPHL()
{
  setPHL(rr(getPHL()));
}

void
CZ80::
rrPOIX(schar o)
{
  setPOIX(o, rr(getPOIX(o)));
}

void
CZ80::
rrPOIY(schar o)
{
  setPOIY(o, rr(getPOIY(o)));
}

//---------

void
CZ80::
rrcA()
{
  setA(rrc(getA()));
}

void
CZ80::
rrcB()
{
  setB(rrc(getB()));
}

void
CZ80::
rrcC()
{
  setC(rrc(getC()));
}

void
CZ80::
rrcD()
{
  setD(rrc(getD()));
}

void
CZ80::
rrcE()
{
  setE(rrc(getE()));
}

void
CZ80::
rrcH()
{
  setH(rrc(getH()));
}

void
CZ80::
rrcL()
{
  setL(rrc(getL()));
}

void
CZ80::
rrcPHL()
{
  setPHL(rrc(getPHL()));
}

void
CZ80::
rrcPOIX(schar o)
{
  setPOIX(o, rrc(getPOIX(o)));
}

void
CZ80::
rrcPOIY(schar o)
{
  setPOIY(o, rrc(getPOIY(o)));
}

//---------------

void
CZ80::
rlca()
{
  uchar r = getA();

  uchar s = (r & 0x80) ? 0x01 : 0x00;

  r = (r << 1) | s;

  setA(r);

  setXFlag(r & 0x08);
  setYFlag(r & 0x20);
  resNFlag();

  setCFlag(s);
  resHFlag();
}

uchar
CZ80::
rlc(uchar r)
{
  uchar s = (r & 0x80) ? 0x01 : 0x00;

  r = (r << 1) | s;

  setBRFlags(r);

  setCFlag(s);
  resHFlag();

  return r;
}

//---------

void
CZ80::
rla()
{
  uchar r = getA();

  uchar s  = (r & 0x80) ? 0x01 : 0x00;
  uchar s1 = tstCFlag() ? 0x01 : 0x00;

  r = (r << 1) | s1;

  setA(r);

  setXFlag(r & 0x08);
  setYFlag(r & 0x20);
  resNFlag();

  setCFlag(s);
  resHFlag();
}

uchar
CZ80::
rl(uchar r)
{
  uchar s  = (r & 0x80) ? 0x01 : 0x00;
  uchar s1 = tstCFlag() ? 0x01 : 0x00;

  r = (r << 1) | s1;

  setBRFlags(r);

  setCFlag(s);
  resHFlag();

  return r;
}

//---------

void
CZ80::
rrca()
{
  uchar r = getA();

  uchar s = (r & 0x01) ? 0x80 : 0x00;

  r = (r >> 1) | s;

  setA(r);

  setXFlag(r & 0x08);
  setYFlag(r & 0x20);
  resNFlag();

  setCFlag(s);
  resHFlag();
}

uchar
CZ80::
rrc(uchar r)
{
  uchar s = (r & 0x01) ? 0x80 : 0x00;

  r = (r >> 1) | s;

  setBRFlags(r);

  setCFlag(s);
  resHFlag();

  return r;
}

//---------

void
CZ80::
rra()
{
  uchar r = getA();

  uchar s  = (r & 0x01) ? 0x01 : 0x00;
  uchar s1 = tstCFlag() ? 0x80 : 0x00;

  r = (r >> 1) | s1;

  setA(r);

  setXFlag(r & 0x08);
  setYFlag(r & 0x20);
  resHFlag();

  setCFlag(s);
  resNFlag();
}

uchar
CZ80::
rr(uchar r)
{
  uchar s  = (r & 0x01) ? 0x01 : 0x00;
  uchar s1 = tstCFlag() ? 0x80 : 0x00;

  r = (r >> 1) | s1;

  setBRFlags(r);

  setCFlag(s);
  resHFlag();

  return r;
}

//---------

uchar
CZ80::
sll(uchar r)
{
  uchar s = (r & 0x80) ? 0x01 : 0x00;

  r <<= 1;

  r |= 0x01;

  setBRFlags(r);

  setCFlag(s);
  resHFlag();

  return r;
}

uchar
CZ80::
srl(uchar r)
{
  uchar c = (r & 0x01) ? 0x01 : 0x00;

  r >>= 1;

  setBRFlags(r);

  setCFlag(c);
  resHFlag();

  return r;
}

uchar
CZ80::
sla(uchar r)
{
  uchar s = (r & 0x80) ? 0x01 : 0x00;

  r <<= 1;

  setBRFlags(r);

  setCFlag(s);
  resHFlag();

  return r;
}

uchar
CZ80::
sra(uchar r)
{
  uchar s = (r & 0x80) ? 0x80 : 0x00;
  uchar c = (r & 0x01) ? 0x01 : 0x00;

  r >>= 1;

  r |= s;

  setBRFlags(r);

  setCFlag(c);
  resHFlag();

  return r;
}

//---------------

void
CZ80::
rld()
{
  uchar hl = getPHL();
  uchar a  = getA  ();

  uchar b1 = (hl & 0x0F) << 4;
  uchar b2 = (hl & 0xF0) >> 4;
  uchar b3 = (a  & 0x0F);
  uchar b4 = (a  & 0xF0);

  setPHL(b1 | b3);
  setA  (b4 | b2);

  setBRFlags(getA());

  resHFlag();
}

void
CZ80::
rrd()
{
  uchar hl = getPHL();
  uchar a  = getA  ();

  uchar b1 = (hl & 0x0F);
  uchar b2 = (hl & 0xF0) >> 4;
  uchar b3 = (a  & 0x0F) << 4;
  uchar b4 = (a  & 0xF0);

  setPHL(b3 | b2);
  setA  (b4 | b1);

  setBRFlags(getA());

  resHFlag();
}

//------------

void
CZ80::
call(ushort addr)
{
  pushPC();

  setPC(addr);
}

//------------

void
CZ80::
rst(ushort id)
{
  if (rstData_) {
    pushPC();

    rstData_->rst(id);

    popPC();
  }
  else
    call(id);
}

//------------

void
CZ80::
tstBitA(uchar bit)
{
  tstBitR(getA(), bit, false);
}

void
CZ80::
tstBitB(uchar bit)
{
  tstBitR(getB(), bit, false);
}

void
CZ80::
tstBitC(uchar bit)
{
  tstBitR(getC(), bit, false);
}

void
CZ80::
tstBitD(uchar bit)
{
  tstBitR(getD(), bit, false);
}

void
CZ80::
tstBitE(uchar bit)
{
  tstBitR(getE(), bit, false);
}

void
CZ80::
tstBitH(uchar bit)
{
  tstBitR(getH(), bit, false);
}

void
CZ80::
tstBitL(uchar bit)
{
  tstBitR(getL(), bit, false);
}

void
CZ80::
tstBitPHL(uchar bit)
{
  tstBitR(getPHL(), bit, true);
}

void
CZ80::
tstBitPOIX(schar o, uchar bit, bool is_phl)
{
  uint r = getPOIX(o);

  tstBitR(r, bit, is_phl);
}

void
CZ80::
tstBitPOIY(schar o, uchar bit, bool is_phl)
{
  uint r = getPOIY(o);

  tstBitR(r, bit, is_phl);
}

void
CZ80::
tstBitR(uchar r, uchar bit, bool is_phl)
{
  bool f = TST_BIT(r, bit);

  if (bit == 7)
    setSFlag(f);

  resZFlag(f);

  if (! is_phl)
    setYFlag(r & 0x20);
  else
    resYFlag();

  setHFlag();

  if (! is_phl)
    setXFlag(r & 0x08);
  else
    resXFlag();

  resPFlag(f);

  resNFlag();
}

//---------

void
CZ80::
setBitA(uchar bit)
{
  setA(setBitR(getA(), bit));
}

void
CZ80::
setBitB(uchar bit)
{
  setB(setBitR(getB(), bit));
}

void
CZ80::
setBitC(uchar bit)
{
  setC(setBitR(getC(), bit));
}

void
CZ80::
setBitD(uchar bit)
{
  setD(setBitR(getD(), bit));
}

void
CZ80::
setBitE(uchar bit)
{
  setE(setBitR(getE(), bit));
}

void
CZ80::
setBitH(uchar bit)
{
  setH(setBitR(getH(), bit));
}

void
CZ80::
setBitL(uchar bit)
{
  setL(setBitR(getL(), bit));
}

void
CZ80::
setBitPHL(uchar bit)
{
  setPHL(setBitR(getPHL(), bit));
}

void
CZ80::
setBitPOIX(schar o, uchar bit)
{
  setPOIX(o, setBitR(getPOIX(o), bit));
}

void
CZ80::
setBitPOIY(schar o, uchar bit)
{
  setPOIY(o, setBitR(getPOIY(o), bit));
}

uchar
CZ80::
setBitR(uchar r, uchar bit)
{
  SET_BIT(r, bit);

  return r;
}

//---------

void
CZ80::
resBitA(uchar bit)
{
  setA(resBitR(getA(), bit));
}

void
CZ80::
resBitB(uchar bit)
{
  setB(resBitR(getB(), bit));
}

void
CZ80::
resBitC(uchar bit)
{
  setC(resBitR(getC(), bit));
}

void
CZ80::
resBitD(uchar bit)
{
  setD(resBitR(getD(), bit));
}

void
CZ80::
resBitE(uchar bit)
{
  setE(resBitR(getE(), bit));
}

void
CZ80::
resBitH(uchar bit)
{
  setH(resBitR(getH(), bit));
}

void
CZ80::
resBitL(uchar bit)
{
  setL(resBitR(getL(), bit));
}

void
CZ80::
resBitPHL(uchar bit)
{
  setPHL(resBitR(getPHL(), bit));
}

void
CZ80::
resBitPOIX(schar o, uchar bit)
{
  setPOIX(o, resBitR(getPOIX(o), bit));
}

void
CZ80::
resBitPOIY(schar o, uchar bit)
{
  setPOIY(o, resBitR(getPOIY(o), bit));
}

uchar
CZ80::
resBitR(uchar r, uchar bit)
{
  RST_BIT(r, bit);

  return r;
}

//------------

// General Purpose Routines

void
CZ80::
daa()
{
  uchar a = getA();

  uchar a1 =  a & 0x0F;
  uchar a2 = (a & 0xF0) >> 4;

  uchar d = 0;

  if (! tstCFlag()) {
    if      (a2 <  10 && ! tstHFlag() && a1 < 10) { d = 0x00; }
    else if (a2 <  10 &&   tstHFlag() && a1 < 10) { d = 0x06; }
    else if (a2 <   9                 && a1 >  9) { d = 0x06; }
    else if (a2 >   9 && ! tstHFlag() && a1 < 10) { d = 0x60; }
    else if (a2 >   8                 && a1 >  9) { d = 0x66; }
    else if (a2 >   9 &&   tstHFlag() && a1 < 10) { d = 0x66; }

    setCFlag(d >= 0x60);
  }
  else {
    if      (            ! tstHFlag() && a1 < 10) { d = 0x60; }
    else if (              tstHFlag() && a1 < 10) { d = 0x66; }
    else if (                            a1 >  9) { d = 0x66; }
  }

  if (! tstNFlag())
    setHFlag(a1 > 9);
  else
    setHFlag(tstHFlag() && a1 < 6);

  if (! tstNFlag())
    a += d;
  else
    a -= d;

  setA(a);

  setRFlags(a);

  setPFlag(tstParity(a));
}

void
CZ80::
cpl()
{
  uchar r  = getA();
  uchar r1 = ~r;

  setA(r1);

  setHFlag();
  setNFlag();

  setXFlag(r1 & 0x08);
  setYFlag(r1 & 0x20);
}

void
CZ80::
neg()
{
  uchar r = getA();

  setHFlag(r &  0x0F);
  setPFlag(r == 0x80);
  setCFlag(r != 0x00);

  setA((r - 1) ^ 0xFF);

  setRFlags(getA());

  setNFlag();
}

void
CZ80::
ccf()
{
  uchar r = getA();

  setHFlag(tstCFlag());

  resCFlag(tstCFlag());

  setXFlag(r & 0x08);
  setYFlag(r & 0x20);

  resNFlag();
}

void
CZ80::
scf()
{
  uchar r = getA();

  resHFlag();

  setCFlag();

  setXFlag(r & 0x08);
  setYFlag(r & 0x20);

  resNFlag();
}

void
CZ80::
di()
{
  setIFF1(0);
  setIFF2(0);
}

void
CZ80::
ei()
{
  setIFF1(1);
  setIFF2(1);
}

void
CZ80::
reti()
{
  setIFF1(getIFF2());

  popPC();
}

void
CZ80::
retn()
{
  setIFF1(getIFF2());

  popPC();
}

void
CZ80::
halt()
{
//setPC(getPC() - 1);

  setHalt(true);
}

//------------

// Exchange Instructions

void
CZ80::
ex_de_hl()
{
  ushort de = getDE();
  ushort hl = getHL();

  setDE(hl);
  setHL(de);
}

void
CZ80::
ex_af_af1()
{
  ushort af  = getAF ();
  ushort af1 = getAF1();

  setAF (af1);
  setAF1(af);
}

void
CZ80::
ex_p_sp_hl()
{
  ushort sp = getPSP2();
  ushort hl = getHL();

  setPSP2(hl);
  setHL  (sp);
}

void
CZ80::
ex_p_sp_ix()
{
  ushort sp = getPSP2();
  ushort ix = getIX();

  setPSP2(ix);
  setIX  (sp);
}

void
CZ80::
ex_p_sp_iy()
{
  ushort sp = getPSP2();
  ushort iy = getIY();

  setPSP2(iy);
  setIY  (sp);
}

void
CZ80::
exx()
{
  ushort t;

  t = getBC1(); setBC1(getBC()); setBC(t);
  t = getDE1(); setDE1(getDE()); setDE(t);
  t = getHL1(); setHL1(getHL()); setHL(t);
}

//---------

void
CZ80::
ldi()
{
  setPDE(getPHL2());

  uchar r = getA() + getPHL2();

  setXFlag(r & 0x08);
  setYFlag(r & 0x02);

  incDE();
  incHL();
  decBC();

  setVFlag(getBC() != 0);

  resHFlag();
  resNFlag();
}

void
CZ80::
ldir()
{
  decR(2);

  do {
    ldi();

    incT(21);

    // TODO: check interrupt

    incR(2);
  }
  while (tstVFlag());

  decT(5);
}

void
CZ80::
ldd()
{
  setPDE(getPHL2());

  uchar r = getA() + getPHL2();

  setXFlag(r & 0x08);
  setYFlag(r & 0x02);

  decDE();
  decHL();
  decBC();

  setVFlag(getBC() != 0);

  resHFlag();
  resNFlag();
}

void
CZ80::
lddr()
{
  decR(2);

  do {
    ldd();

    incT(21);

    // TODO: check interrupr

    incR(2);
  }
  while (tstVFlag());

  decT(5);
}

//---------

void
CZ80::
cpi()
{
  bool c = tstCFlag();

  uchar r = subR(getA(), getPHL());

  if (tstHFlag())
    --r;

  setXFlag(r & 0x08);
  setYFlag(r & 0x02);

  incHL();
  decBC();

  setVFlag(getBC() != 0);

  setCFlag(c);
}

void
CZ80::
cpir()
{
  decR(2);

  do {
    cpi();

    incT(21);

    // TODO: check interrupr

    incR(2);
  }
  while (tstVFlag() && ! tstZFlag());

  decT(5);
}

void
CZ80::
cpd()
{
  bool c = tstCFlag();

  uchar r = subR(getA(), getPHL());

  if (tstHFlag())
    --r;

  setXFlag(r & 0x08);
  setYFlag(r & 0x02);

  decHL();
  decBC();

  setVFlag(getBC() != 0);

  setCFlag(c);
}

void
CZ80::
cpdr()
{
  decR(2);

  do {
    cpd();

    incT(21);

    // TODO: check interrupr

    incR(2);
  }
  while (tstVFlag() && ! tstZFlag());

  decT(5);
}

//-------------------

void
CZ80::
outC(uchar r)
{
  uchar port = getC();

  out(port, r);
}

void
CZ80::
out(uchar port, uchar value)
{
  if (! portData_) {
    std::cerr << "No port defined" << std::endl;
    halt();
    return;
  }

  portData_->out(port, value);
}

uchar
CZ80::
inC()
{
  uchar port = getC();
  uchar qual = getB();

  uchar r = in(port, qual);

  setBRFlags(r);

  resHFlag();

  return r;
}

uchar
CZ80::
in(uchar port, uchar qual)
{
  if (! portData_) {
    std::cerr << "No port defined" << std::endl;
    halt();
    return 0;
  }

  return portData_->in(port, qual);
}

//---------

void
CZ80::
setBRFlags(uchar r)
{
  setRFlags(r);

  setPFlag(tstParity(r));

  resNFlag();
}

void
CZ80::
setRFlags(uchar r)
{
  setZFlag(r == 0x00);
  setXFlag(r  & 0x08);
  setYFlag(r  & 0x20);
  setSFlag(r  & 0x80);
}

bool
CZ80::
tstParity(uchar r)
{
  uint n = 0;

  while (r > 0) {
    n += (r & 1);

    r >>= 1;
  }

  return ! (n & 1);
}

//-----------------

bool
CZ80::
isLabelName(const std::string &name)
{
  return labelData_.isLabelName(name);
}

void
CZ80::
setLabelValue(const std::string &name, uint value)
{
  labelData_.setLabelValue(name, value);
}

bool
CZ80::
getLabelValue(const std::string &name, uint *value)
{
  return labelData_.getLabelValue(name, value);
}

bool
CZ80::
getValueLabel(uint value, std::string &name)
{
  return labelData_.getValueLabel(value, name);
}

//---------

bool
CZ80::
undump(CFile *file, std::ostream &os)
{
  CZ80OpData opData;

  opData.z80 = this;

  while (! file->eof()) {
    if (! opData.undump(file))
      return false;

    opData.printStr(os);

    os << std::endl;
  }

  return true;
}

/*----------*/

void
CZ80::
getOpData(CZ80OpData *opData)
{
  ushort pc   = getPC();
  bool   halt = getHalt();

  readOpData(opData);

  setPC(pc);

  setHalt(halt);
}

void
CZ80::
readOpData(CZ80OpData *opData)
{
  opData->z80 = this;
  opData->op  = readOp();

  if (! opData->op) {
    halt();
    return;
  }

  readOpValues(opData->op,
               opData->values1, &opData->num_values1,
               opData->values2, &opData->num_values2);
}

CZ80Op *
CZ80::
readOp()
{
  uchar c = getByte();

  incPC();

  CZ80Op *op = &op_normal[c];

  if (! op->func) {
    uchar c1 = getByte();

    incPC();

    if      (c == 0xCB) {
      op = &op_cb[c1];
    }
    else if (c == 0xDD) {
      op = &op_dd[c1];

      if (! op->func) {
        uchar c2 = getByte();

        incPC();

        if      (c1 == 0xCB) {
          uchar c3 = getByte();

          incPC();

          op = &op_dd_cb[c3];

          op->edata = c2;
        }
      }
    }
    else if (c == 0xED) {
      op = &op_ed[c1];
    }
    else if (c == 0xFD) {
      op = &op_fd[c1];

      if (! op->func) {
        uchar c2 = getByte();

        incPC();

        if      (c1 == 0xCB) {
          uchar c3 = getByte();

          incPC();

          op = &op_fd_cb[c3];

          op->edata = c2;
        }
      }
    }
  }

  return op;
}

void
CZ80::
readOpValues(CZ80Op *op, uchar *values1, uchar *num_values1,
             uchar *values2, uchar *num_values2)
{
  if (op->type1 != 0) {
    *num_values1 = getNumArgValues(op->type1, op->arg1);

    for (uint i = 0; i < *num_values1; ++i) {
      if (op->ind < 1280) {
        values1[i] = getByte();

        incPC();
      }
      else
        values1[i] = op->edata;
    }

    if (op->type2 != 0) {
      *num_values2 = getNumArgValues(op->type2, op->arg2);

      for (ushort i = 0; i < *num_values2; ++i) {
        if (op->ind < 1280) {
          values2[i] = getByte();

          incPC();
        }
        else
          values2[i] = op->edata;
      }
    }
    else
      *num_values2 = 0;
  }
  else {
    *num_values1 = 0;
    *num_values2 = 0;
  }
}

uchar
CZ80::
getNumArgValues(uint type, uint arg)
{
  switch (type) {
    case A_NUM:
      return arg;
    case A_S_NUM:
      return arg;
    case A_P_REG:
      return 0;
    case A_P_NUM:
      return arg;
    case A_PO_REG:
      return 1;
    case A_FLAG:
      return 0;
    case A_REG:
      return 0;
    case A_CONST:
      return 0;
    case A_PO_REG_A:
    case A_PO_REG_B:
    case A_PO_REG_C:
    case A_PO_REG_D:
    case A_PO_REG_E:
    case A_PO_REG_H:
    case A_PO_REG_L:
      return 1;
    default:
      return 0;
  }
}

/*----------*/

std::string
CZ80::
getRegisterName(uint reg)
{
  switch (reg) {
    case R_A:   return "A";
    case R_B:   return "B";
    case R_C:   return "C";
    case R_D:   return "D";
    case R_E:   return "E";
    case R_F:   return "F";
    case R_H:   return "H";
    case R_L:   return "L";
    case R_I:   return "I";
    case R_R:   return "R";
    case R_AF:  return "AF";
    case R_BC:  return "BC";
    case R_DE:  return "DE";
    case R_HL:  return "HL";
    case R_SP:  return "SP";
    case R_IX:  return "IX";
    case R_IY:  return "IY";
    case R_AF1: return "AF\'";
    case R_IXH: return "IXh";
    case R_IYH: return "IYh";
    case R_IXL: return "IXl";
    case R_IYL: return "IYl";
    case R_PC : return "PC";
    default:    return "??";
  }
}

std::string
CZ80::
getFlagName(uint flag)
{
  switch (flag) {
    case F_Z:  return "Z";
    case F_NZ: return "NZ";
    case F_C:  return "C";
    case F_NC: return "NC";
    case F_PO: return "PO";
    case F_PE: return "PE";
    case F_P:  return "P";
    case F_M:  return "M";
    case F_H:  return "H";
    case F_N:  return "N";
    default:   return "??";
  }
}

uchar
CZ80::
getRegValue8(uint reg)
{
  switch (reg) {
    case R_A:   return getA();
    case R_B:   return getB();
    case R_C:   return getC();
    case R_D:   return getD();
    case R_E:   return getE();
    case R_H:   return getH();
    case R_L:   return getL();
    case R_I:   return getI();
    case R_R:   return getR();
    case R_IXH: return getIXH();
    case R_IYH: return getIYH();
    case R_IXL: return getIXL();
    case R_IYL: return getIYL();
    default:    return 0;
  }
}

ushort
CZ80::
getRegValue16(uint reg)
{
  switch (reg) {
    case R_AF:  return getAF();
    case R_BC:  return getBC();
    case R_DE:  return getDE();
    case R_HL:  return getHL();
    case R_SP:  return getSP();
    case R_PC:  return getPC();
    case R_IX:  return getIX();
    case R_IY:  return getIY();
    case R_AF1: return getAF1();
    default:    return 0;
  }
}

ushort
CZ80::
getPRegValue16(uint reg)
{
  switch (reg) {
    case R_AF: return getPAF();
    case R_BC: return getPBC();
    case R_DE: return getPDE();
    case R_HL: return getPHL();
    case R_SP: return getPSP2();
    case R_PC: return getPPC2();
    case R_IX: return getPIX2();
    case R_IY: return getPIY2();
    default:   return 0;
  }
}

/*----------*/

void
CZ80::
printState(std::ostream &os)
{
  printRegValue8(os, R_A);

  os << "           ";

  printRegValue8(os, R_F);

  os << "(" << getFlagsString() << ")" << std::endl;

  printRegValue16AndPtr(os, R_BC);
  printRegValue16AndPtr(os, R_DE);
  printRegValue16AndPtr(os, R_HL);

  os << std::endl;

  printRegValue16AndPtr(os, R_IX);
  printRegValue16AndPtr(os, R_IY);
  printRegValue16AndPtr(os, R_PC);
  printRegValue16AndPtr(os, R_SP);

  os << std::endl;
}

void
CZ80::
printRegValue8(std::ostream &os, uint reg)
{
  uchar r = getRegValue8(reg);

  os << getRegisterName(reg) << "  " <<
        "0x" << CStrUtil::toHexString(r, 2);
}

void
CZ80::
printRegValue16AndPtr(std::ostream &os, uint reg)
{
  ushort r  = getRegValue16(reg);
  ushort pr = getPRegValue16(reg);

  os << getRegisterName(reg) << " " <<
         "0x" << CStrUtil::toHexString(r , 4) <<
        "(0x" << CStrUtil::toHexString(pr, 4) << ") ";
}

/*----------*/

std::string
CZ80::
getFlagsString()
{
  std::string str;

  str += (tstCFlag() ? "C" : ".");
  str += (tstNFlag() ? "N" : ".");
  str += (tstPFlag() ? "P" : ".");
  str += (tstXFlag() ? "X" : ".");
  str += (tstHFlag() ? "H" : ".");
  str += (tstYFlag() ? "Y" : ".");
  str += (tstZFlag() ? "Z" : ".");
  str += (tstSFlag() ? "S" : ".");

  return str;
}

/*----------*/

bool
CZ80::
lookupOp(CZ80Op *op, CZ80Op **op1)
{
  for (uint i = 0; i < 256; ++i) {
    if (op_normal[i].cmp(*op)) {
      *op1 = &op_normal[i];
      return true;
    }
  }

  for (uint i = 0; i < 256; ++i) {
    if (op_cb[i].cmp(*op)) {
      *op1 = &op_cb[i];
      return true;
    }
  }

  for (uint i = 0; i < 256; ++i) {
    if (op_dd[i].cmp(*op)) {
      *op1 = &op_dd[i];
      return true;
    }
  }

  for (uint i = 0; i < 256; ++i) {
    if (op_ed[i].cmp(*op)) {
      *op1 = &op_ed[i];
      return true;
    }
  }

  for (uint i = 0; i < 256; ++i) {
    if (op_fd[i].cmp(*op)) {
      *op1 = &op_fd[i];
      return true;
    }
  }

  for (uint i = 0; i < 256; ++i) {
    if (op_dd_cb[i].cmp(*op)) {
      *op1 = &op_dd_cb[i];
      return true;
    }
  }

  for (uint i = 0; i < 256; ++i) {
    if (op_fd_cb[i].cmp(*op)) {
      *op1 = &op_fd_cb[i];
      return true;
    }
  }

  return false;
}

CZ80Op *
CZ80::
getIndOp(uint ind)
{
  if      (ind <  256) return &op_normal[ind -    0];
  else if (ind <  512) return &op_cb    [ind -  256];
  else if (ind <  768) return &op_dd    [ind -  512];
  else if (ind < 1024) return &op_ed    [ind -  768];
  else if (ind < 1280) return &op_fd    [ind - 1024];
  else if (ind < 1536) return &op_dd_cb [ind - 1280];
  else if (ind < 1792) return &op_fd_cb [ind - 1536];
  else {
    std::cerr << "Invalid op id " << ind << std::endl;
    return nullptr;
  }
}

/*----------*/

void
CZ80::
dumpOpCounts(std::ostream &os)
{
  for (uint i = 0; i < 256; ++i)
    if (op_normal[i].count > 0)
      op_normal[i].dumpCount(os);

  for (uint i = 0; i < 256; ++i)
    if (op_cb[i].count > 0)
      op_cb[i].dumpCount(os);

  for (uint i = 0; i < 256; ++i)
    if (op_dd[i].count > 0)
      op_dd[i].dumpCount(os);

  for (uint i = 0; i < 256; ++i)
    if (op_ed[i].count > 0)
      op_ed[i].dumpCount(os);

  for (uint i = 0; i < 256; ++i)
    if (op_fd[i].count > 0)
      op_fd[i].dumpCount(os);

  for (uint i = 0; i < 256; ++i)
    if (op_dd_cb[i].count > 0)
      op_dd_cb[i].dumpCount(os);

  for (uint i = 0; i < 256; ++i)
    if (op_fd_cb[i].count > 0)
      op_fd_cb[i].dumpCount(os);
}

void
CZ80::
resetOpCounts()
{
  for (uint i = 0; i < 256; ++i)
    op_normal[i].count = 0;

  for (uint i = 0; i < 256; ++i)
    op_cb[i].count = 0;

  for (uint i = 0; i < 256; ++i)
    op_dd[i].count = 0;

  for (uint i = 0; i < 256; ++i)
    op_ed[i].count = 0;

  for (uint i = 0; i < 256; ++i)
    op_fd[i].count = 0;

  for (uint i = 0; i < 256; ++i)
    op_dd_cb[i].count = 0;

  for (uint i = 0; i < 256; ++i)
    op_fd_cb[i].count = 0;
}

//-------

void
CZ80::
tracePC()
{
  pc_buffer_.add(registers_.pc_);
}

void
CZ80::
traceBack()
{
  pc_buffer_.print(std::cout);
}

CZ80::CircBuffer::
CircBuffer()
{
  pos_      = 0;
  last_pos_ = 0;
  size_     = 32;
  num_      = 0;

  buffer_.resize(size_);
}

void
CZ80::CircBuffer::
add(ushort value)
{
  if (num_ > 0 && buffer_[last_pos_] == value)
    return;

  buffer_[pos_] = value;

  last_pos_ = pos_++;

  if (pos_ >= size_)
    pos_ = 0;

  if (num_ < size_) ++num_;
}

void
CZ80::CircBuffer::
print(std::ostream &os) const
{
  int pos = last_pos_;

  for (uint i = 0; i < num_; ++i) {
    if (pos < 0) pos = size_ - 1;

    if (i > 0) os << " ";

    os << "0x" << CStrUtil::toHexString(buffer_[pos], 4);

    --pos;
  }

  os << std::endl;
}

//-------

bool
CZ80MemData::
memRead(uchar *, ushort, ushort)
{
  return false;
}

void
CZ80MemData::
memWrite(const uchar *, ushort, ushort)
{
}

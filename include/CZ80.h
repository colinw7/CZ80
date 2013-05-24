#ifndef CZ80_H
#define CZ80_H

#include <map>
#include <string>
#include <vector>
#include <list>
#include <cstring>
#include <iostream>

//-----------------

#define SET_FLAG(v,f)  ((v) |=  (f))
#define RST_FLAG(v,f)  ((v) &= ~(f))
#define TST_FLAG(v,f) (((v) &   (f)) ? true : false)

#define RESET_FLAG(v,f) RST_FLAG(v,f)
#define IS_FLAG(v,f)    TST_FLAG(v,f)

#define SET_BIT(v,n) SET_FLAG(v,1<<(n))
#define RST_BIT(v,n) RST_FLAG(v,1<<(n))
#define TST_BIT(v,n) TST_FLAG(v,1<<(n))

#define RESET_BIT(v,n) RST_BIT(v,n)
#define IS_BIT(v,n)    TST_BIT(v,n)

//-----------------

typedef signed char    schar;
typedef unsigned char  uchar;
typedef signed short   sshort;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

// Flags
//  76543210
//  SZYHXPNC

enum CZ80Flag {
  CZ80_FLAG_NONE=-1,

  CZ80_FLAG_C=0,
  CZ80_FLAG_N=1,
  CZ80_FLAG_P=2,
  CZ80_FLAG_V=2,
  CZ80_FLAG_X=3,
  CZ80_FLAG_H=4,
  CZ80_FLAG_Y=5,
  CZ80_FLAG_Z=6,
  CZ80_FLAG_S=7,

  CZ80_FLAG_INV=(1<<30),

  CZ80_FLAG_NC=(CZ80_FLAG_C|CZ80_FLAG_INV),
  CZ80_FLAG_NN=(CZ80_FLAG_N|CZ80_FLAG_INV),
  CZ80_FLAG_NP=(CZ80_FLAG_P|CZ80_FLAG_INV),
  CZ80_FLAG_NV=(CZ80_FLAG_V|CZ80_FLAG_INV),
  CZ80_FLAG_NX=(CZ80_FLAG_X|CZ80_FLAG_INV),
  CZ80_FLAG_NH=(CZ80_FLAG_H|CZ80_FLAG_INV),
  CZ80_FLAG_NY=(CZ80_FLAG_Y|CZ80_FLAG_INV),
  CZ80_FLAG_NZ=(CZ80_FLAG_Z|CZ80_FLAG_INV),
  CZ80_FLAG_NS=(CZ80_FLAG_S|CZ80_FLAG_INV)
};

// Registers

enum CZ80Reg {
  CZ80_REG_NONE=0,

  CZ80_REG_A    =(1<< 0),
  CZ80_REG_B    =(1<< 1),
  CZ80_REG_C    =(1<< 2),
  CZ80_REG_D    =(1<< 3),
  CZ80_REG_E    =(1<< 4),
  CZ80_REG_F    =(1<< 5),
  CZ80_REG_H    =(1<< 6),
  CZ80_REG_L    =(1<< 7),
  CZ80_REG_IXL  =(1<< 8),
  CZ80_REG_IXH  =(1<< 9),
  CZ80_REG_IYL  =(1<<10),
  CZ80_REG_IYH  =(1<<11),
  CZ80_REG_SP   =(1<<12),
  CZ80_REG_PC   =(1<<13),
  CZ80_REG_A1   =(1<<14),
  CZ80_REG_B1   =(1<<15),
  CZ80_REG_C1   =(1<<16),
  CZ80_REG_D1   =(1<<17),
  CZ80_REG_E1   =(1<<18),
  CZ80_REG_F1   =(1<<19),
  CZ80_REG_H1   =(1<<20),
  CZ80_REG_L1   =(1<<21),
  CZ80_REG_I    =(1<<22),
  CZ80_REG_R    =(1<<23),
  CZ80_REG_IM   =(1<<24),
  CZ80_REG_IFF  =(1<<25),
  CZ80_REG_PHL  =(1<<26),
  CZ80_REG_PO_IX=(1<<27),
  CZ80_REG_PO_IY=(1<<28),
  CZ80_REG_N    =(1<<29),
  CZ80_REG_AF   =(CZ80_REG_A  |CZ80_REG_F),
  CZ80_REG_BC   =(CZ80_REG_B  |CZ80_REG_C),
  CZ80_REG_DE   =(CZ80_REG_D  |CZ80_REG_E),
  CZ80_REG_HL   =(CZ80_REG_H  |CZ80_REG_L),
  CZ80_REG_IX   =(CZ80_REG_IXH|CZ80_REG_IXL),
  CZ80_REG_IY   =(CZ80_REG_IYH|CZ80_REG_IYL),
  CZ80_REG_AF1  =(CZ80_REG_A1 |CZ80_REG_F1),
  CZ80_REG_BC1  =(CZ80_REG_B1 |CZ80_REG_C1),
  CZ80_REG_DE1  =(CZ80_REG_D1 |CZ80_REG_E1),
  CZ80_REG_HL1  =(CZ80_REG_H1 |CZ80_REG_L1)
};

//------

class  CFile;
class  CFileBase;
class  CFileParse;
class  CKeyEvent;
class  CZ80;
struct CZ80Op;
struct CZ80OpData;
struct CZ80Trace;
struct CZ80PortData;
struct CZ80Screen;
struct CZ80RstData;
class  CZ80DebugData;
class  CZ80MemData;
struct CZ80SpeedData;

typedef void (CZ80OpProc)(CZ80OpData *op_data);

typedef CZ80OpProc *CZ80OpProcP;

//------

// Register Data
//  . Separate structure so can read/write as single value)
//  . Use unnamed unions for direct access to single or double registers

struct CZ80Registers {
  union { ushort af_  ; struct { uchar f_  ; uchar a_  ; }; };
  union { ushort bc_  ; struct { uchar c_  ; uchar b_  ; }; };
  union { ushort de_  ; struct { uchar e_  ; uchar d_  ; }; };
  union { ushort hl_  ; struct { uchar l_  ; uchar h_  ; }; };
  union { ushort af_1_; struct { uchar f_1_; uchar a_1_; }; };
  union { ushort bc_1_; struct { uchar c_1_; uchar b_1_; }; };
  union { ushort de_1_; struct { uchar e_1_; uchar d_1_; }; };
  union { ushort hl_1_; struct { uchar l_1_; uchar h_1_; }; };
  union { ushort ix_  ; struct { uchar ixl_; uchar ixh_; }; };
  union { ushort iy_  ; struct { uchar iyl_; uchar iyh_; }; };

  ushort sp_, pc_;

  uchar i_;

  uint r_; // use uint so can use as high res count for speed debug

  union { ushort iff_; struct { uchar iff1_; uchar iff2_; }; };

  uchar im_;
};

//----------

// Data only used by assembler

class CZ80AssembleData {
 public:
  CZ80AssembleData();

  void init();

  void initPass();

  bool isStream() const { return stream_; }

  void setStream(bool stream) { stream_ = stream; }

  void nextLine(CFileParse *parse);

  uint getCurrentLineNum() const { return current_line_num_; }

  const std::string &getCurrentLine() const { return current_line_; }

  void addValue(ushort pc, uchar c);

  void setLastLabel(const std::string &str);

  const std::string &getLastLabel() const { return last_label_; }

  void setNameValue(const std::string &name, uint value);

  void dumpValues(CFileBase *ofile);

  void dumpSymbols() const;

 private:
  typedef std::map<std::string,uint> NameValueMap;
  typedef std::map<ushort,uchar>     PCValueMap;

  bool         stream_;
  ushort       values_pc_min_, values_pc_max_;
  bool         values_pc_set_;
  PCValueMap   values_;
  std::string  current_line_;
  uint         current_line_num_;
  std::string  last_label_;
  NameValueMap name_values_;
};

//----------

// Label Data (used by assembler/disassemble)

class CZ80LabelData {
 public:
  typedef std::map<int,std::string> LabelValueNameMap;

 public:
  CZ80LabelData() { }

  void clearLabels();

  bool isLabelName(const std::string &name);
  bool isLabelValue(uint value);

  void setLabelValue(const std::string &name, uint value);
  bool getLabelValue(const std::string &name, uint *value);

  void setValueLabel(uint value, const std::string &name);
  bool getValueLabel(uint value, std::string &name);

 private:
  LabelValueNameMap label_value_name_map_;
};

//----------

enum CZ80MemFlag {
  CZ80_MEM_READ_WRITE=0,
  CZ80_MEM_READ_ONLY =(1<<0),
  CZ80_MEM_SCREEN    =(1<<1)
};

//----------

class CZ80Macro {
 public:
  typedef std::vector<std::string> ArgList;

 public:
  CZ80Macro(const std::string &name="", const ArgList &args=ArgList(), const std::string &body="") :
   name_(name), args_(args), body_(body) {
  }

  const ArgList     &getArgs() const { return args_; }
  const std::string &getBody() const { return body_; }

 private:
  std::string name_;
  ArgList     args_;
  std::string body_;
};

//----------

class CZ80 {
 private:
  class CircBuffer {
   public:
    CircBuffer();

    void add(ushort value);

    void print(std::ostream &os) const;

   private:
    uint                pos_;
    uint                last_pos_;
    uint                size_;
    uint                num_;
    std::vector<ushort> buffer_;
  };

 private:
  typedef std::map<std::string,CZ80Macro> MacroMap;

  bool halt_;
  bool stop_;
  bool allow_interrupts_;

  uchar         *memory_;
  uchar         *flags_;
  CZ80Registers  registers_;

  CircBuffer pc_buffer_;

  double mhz_;
  double htz_;
  ushort ifreq_;
  ushort t_;
  ushort im2_;

  ushort load_pos_;
  uint   load_len_;

  bool verbose_;

  CZ80PortData  *port_data_;
  CZ80Screen    *screen_;
  CZ80RstData   *rst_data_;
  CZ80DebugData *debug_data_;
  CZ80MemData   *mem_data_;
  CZ80SpeedData *speed_data_;

  bool   dump_;
  CFile *dump_file_;

  CZ80AssembleData assemble_data_;
  MacroMap         assemble_macros_;
  CZ80LabelData    label_data_;

 public:
  CZ80();
 ~CZ80();

  // -----------

  void reset();
  void resetRegisters();

 private:
  void initOpInds();

  // -----------

  // Control

 public:
  ushort getIFreq() const { return ifreq_; }

  void setDump(bool dump);
  bool getDump() const { return dump_; }

  void setVerbose(bool verbose) { verbose_ = verbose; }
  bool getVerbose() { return verbose_; }

  void setPortData(CZ80PortData *port_data);

  void setScreen(CZ80Screen *screen);

  CZ80Screen *getScreen() const { return screen_; }

  void setRstData(CZ80RstData *rst_data);

  void setDebugData(CZ80DebugData *debug_data);

  void setMemData(CZ80MemData *mem_data);

  void setSpeedData(CZ80SpeedData *speed_data);

  void setHalt(bool halt);
  bool getHalt() const;

  void setStop(bool stop) { stop_ = stop; }
  bool getStop() const { return stop_; }

  void setAssembleStream(bool stream);

  ushort getLoadPos() const { return load_pos_; }
  ushort getLoadLen() const { return load_len_; }

  void setLoadPos(ushort pos) { load_pos_ = pos; }
  void setLoadLen(ushort len) { load_len_ = len; }

  // -----------

  // Debug

  void addTrace(CZ80Trace *trace);

  void addBreakpoint(ushort pc);
  void removeBreakpoint(ushort pc);
  void removeAllBreakpoints();
  bool isBreakpoint(ushort pc);
  void getBreakpoints(std::vector<ushort> &addrs);

  // -----------

  // Labels

  bool isLabelName(const std::string &name);
  void setLabelValue(const std::string &name, uint value);
  bool getLabelValue(const std::string &name, uint *value);
  bool getValueLabel(uint value, std::string &name);

  // -----------

  // Interrupts

  void setAllowInterrups(bool allow) { allow_interrupts_ = allow; }

  void setIM2(ushort im2) { im2_ = im2; }

  // -----------

  // Port

  void keyPress  (const CKeyEvent &kevent);
  void keyRelease(const CKeyEvent &kevent);

  // -----------

 public:
  // CPU State

  uchar getA() const { return registers_.a_; }
  uchar getF() const { return registers_.f_; }
  uchar getB() const { return registers_.b_; }
  uchar getC() const { return registers_.c_; }
  uchar getD() const { return registers_.d_; }
  uchar getE() const { return registers_.e_; }
  uchar getH() const { return registers_.h_; }
  uchar getL() const { return registers_.l_; }
  uchar getI() const { return registers_.i_; }

  ushort getAF  () const { return registers_.af_  ; }
  ushort getBC  () const { return registers_.bc_  ; }
  ushort getDE  () const { return registers_.de_  ; }
  ushort getHL  () const { return registers_.hl_  ; }
  ushort getSP  () const { return registers_.sp_  ; }
  ushort getPC  () const { return registers_.pc_  ; }
  ushort getIX  () const { return registers_.ix_  ; }
  ushort getIY  () const { return registers_.iy_  ; }
  uchar  getIXL () const { return registers_.ixl_ ; }
  uchar  getIXH () const { return registers_.ixh_ ; }
  uchar  getIYL () const { return registers_.iyl_ ; }
  uchar  getIYH () const { return registers_.iyh_ ; }
  ushort getIFF () const { return registers_.iff_ ; }
  uchar  getIFF1() const { return registers_.iff1_; }
  uchar  getIFF2() const { return registers_.iff2_; }

  ushort getAF1() const { return registers_.af_1_ ; }
  ushort getBC1() const { return registers_.bc_1_ ; }
  ushort getDE1() const { return registers_.de_1_ ; }
  ushort getHL1() const { return registers_.hl_1_ ; }

  uchar getIM() const { return registers_.im_; }

  uchar getPAF() const { return getByte(getAF()); }
  uchar getPBC() const { return getByte(getBC()); }
  uchar getPDE() const { return getByte(getDE()); }
  uchar getPHL() const { return getByte(getHL()); }
  uchar getPIX() const { return getByte(getIX()); }
  uchar getPIY() const { return getByte(getIY()); }
  uchar getPSP() const { return getByte(getSP()); }

  ushort getPBC2() const { return getWord(getBC()); }
  ushort getPDE2() const { return getWord(getDE()); }
  ushort getPHL2() const { return getWord(getHL()); }
  ushort getPIX2() const { return getWord(getIX()); }
  ushort getPIY2() const { return getWord(getIY()); }
  ushort getPPC2() const { return getWord(getPC()); }
  ushort getPSP2() const { return getWord(getSP()); }

  uchar getPOIX(schar o) const { return getByte(getIX() + o); }
  uchar getPOIY(schar o) const { return getByte(getIY() + o); }

  ushort getPOIX2(schar o) const { return getWord(getIX() + o); }
  ushort getPOIY2(schar o) const { return getWord(getIY() + o); }

  // TODO: Inline ?

  void setA(uchar a);
  void setF(uchar f);
  void setB(uchar b);
  void setC(uchar c);
  void setD(uchar d);
  void setE(uchar e);
  void setH(uchar h);
  void setL(uchar l);
  void setI(uchar i);

  void setAF  (ushort af);
  void setBC  (ushort bc);
  void setDE  (ushort de);
  void setHL  (ushort hl);
  void setSP  (ushort sp);
  void setPC  (ushort pc);
  void setIX  (ushort ix);
  void setIY  (ushort iy);
  void setIXL (uchar  ix);
  void setIXH (uchar  ix);
  void setIYL (uchar  iy);
  void setIYH (uchar  iy);
  void setIFF (ushort iff);
  void setIFF1(uchar  iff1);
  void setIFF2(uchar  iff2);

  void setAF1(ushort af);
  void setBC1(ushort bc);
  void setDE1(ushort de);
  void setHL1(ushort hl);

  void setIM(uchar im);

  void setPBC(uchar bc);
  void setPDE(uchar bc);
  void setPHL(uchar bc);

  void setPOIX(schar o, uchar ix);
  void setPOIY(schar o, uchar iy);

  void setPSP2(ushort sp);

  void  setFlag(uchar bit);
  void  resFlag(uchar bit);
  uchar tstFlag(uchar bit);

  void setCFlag(bool b=true) {b ? setFlag(CZ80_FLAG_C) : resFlag(CZ80_FLAG_C);}
  void setNFlag(bool b=true) {b ? setFlag(CZ80_FLAG_N) : resFlag(CZ80_FLAG_N);}
  void setPFlag(bool b=true) {b ? setFlag(CZ80_FLAG_P) : resFlag(CZ80_FLAG_P);}
  void setVFlag(bool b=true) {b ? setFlag(CZ80_FLAG_V) : resFlag(CZ80_FLAG_V);}
  void setXFlag(bool b=true) {b ? setFlag(CZ80_FLAG_X) : resFlag(CZ80_FLAG_X);}
  void setHFlag(bool b=true) {b ? setFlag(CZ80_FLAG_H) : resFlag(CZ80_FLAG_H);}
  void setYFlag(bool b=true) {b ? setFlag(CZ80_FLAG_Y) : resFlag(CZ80_FLAG_Y);}
  void setZFlag(bool b=true) {b ? setFlag(CZ80_FLAG_Z) : resFlag(CZ80_FLAG_Z);}
  void setSFlag(bool b=true) {b ? setFlag(CZ80_FLAG_S) : resFlag(CZ80_FLAG_S);}

  void resCFlag(bool b=true) {b ? resFlag(CZ80_FLAG_C) : setFlag(CZ80_FLAG_C);}
  void resNFlag(bool b=true) {b ? resFlag(CZ80_FLAG_N) : setFlag(CZ80_FLAG_N);}
  void resPFlag(bool b=true) {b ? resFlag(CZ80_FLAG_P) : setFlag(CZ80_FLAG_P);}
  void resVFlag(bool b=true) {b ? resFlag(CZ80_FLAG_V) : setFlag(CZ80_FLAG_V);}
  void resXFlag(bool b=true) {b ? resFlag(CZ80_FLAG_X) : setFlag(CZ80_FLAG_X);}
  void resHFlag(bool b=true) {b ? resFlag(CZ80_FLAG_H) : setFlag(CZ80_FLAG_H);}
  void resYFlag(bool b=true) {b ? resFlag(CZ80_FLAG_Y) : setFlag(CZ80_FLAG_Y);}
  void resZFlag(bool b=true) {b ? resFlag(CZ80_FLAG_Z) : setFlag(CZ80_FLAG_Z);}
  void resSFlag(bool b=true) {b ? resFlag(CZ80_FLAG_S) : setFlag(CZ80_FLAG_S);}

  uchar tstCFlag() { return tstFlag(CZ80_FLAG_C); }
  uchar tstNFlag() { return tstFlag(CZ80_FLAG_N); }
  uchar tstPFlag() { return tstFlag(CZ80_FLAG_P); }
  uchar tstVFlag() { return tstFlag(CZ80_FLAG_V); }
  uchar tstXFlag() { return tstFlag(CZ80_FLAG_X); }
  uchar tstHFlag() { return tstFlag(CZ80_FLAG_H); }
  uchar tstYFlag() { return tstFlag(CZ80_FLAG_Y); }
  uchar tstZFlag() { return tstFlag(CZ80_FLAG_Z); }
  uchar tstSFlag() { return tstFlag(CZ80_FLAG_S); }

  void setR(uchar r) { registers_.r_ = r; }

  uint  getHR() const { return registers_.r_; }
  uchar getR () const { return getHR() & 0x7F; }

  void decR(uchar d);
  void incR(uchar d);

  void setT(ushort t) { t_ = t; }

  ushort getT() const { return t_; }

  void decT(ushort d);
  void incT(ushort d);

  int interrupt();

  // ------

  // CPU Memory

 public:
  uchar  getByte() const;
  uchar  getByte(ushort pos) const;
  ushort getWord() const;
  ushort getWord(ushort pos) const;
  char   getSByte() const { return (schar) getByte(); }
  char   getSByte(ushort pos) const { return (schar) getByte(pos); }
  short  getSWord() const { return (sshort) getWord(); }
  short  getSWord(ushort pos) const { return (sshort) getWord(pos); }
  void   getBytes(uchar *c, ushort pos, ushort len) const;

  void setByte(uchar c);
  void setByte(ushort pos, uchar c);
  void setWord(ushort c);
  void setWord(ushort pos, ushort c);
  void setBytes(uchar *c, ushort pos, ushort len);

  void setMemFlags(ushort pos, ushort len, uchar flag);
  void resetMemFlags(ushort pos, ushort len, uchar flag);

  // ---------

 public:
  // CPU Ops

  void pushAF();
  void pushBC();
  void pushDE();
  void pushHL();
  void pushIX();
  void pushIY();
  void pushPC();

  void push(ushort r);

  void popAF();
  void popBC();
  void popDE();
  void popHL();
  void popIX();
  void popIY();
  void popPC();

  ushort pop();

  ushort peek();

  void addA (uchar  a);
  void addHL(ushort hl);
  void addIX(ushort ix);
  void addIY(ushort iy);

  void adcA (uchar  a);
  void adcHL(ushort hl);

  void subA(uchar a);

  void sbcA (uchar  a);
  void sbcHL(ushort hl);

  void cpA(uchar a);

  void andA(uchar a);
  void orA (uchar a);
  void xorA(uchar a);

  void incA();
  void incB();
  void incC();
  void incD();
  void incE();
  void incH();
  void incL();
  void incIXL();
  void incIXH();
  void incIYL();
  void incIYH();
  void incBC();
  void incDE();
  void incHL();
  void incSP();
  void incPC(sshort o=1);
  void incIX();
  void incIY();
  void incPHL();
  void incPOIX(schar o);
  void incPOIY(schar o);

  void decA();
  void decB();
  void decC();
  void decD();
  void decE();
  void decH();
  void decL();
  void decIXL();
  void decIXH();
  void decIYL();
  void decIYH();
  void decBC();
  void decDE();
  void decHL();
  void decSP();
  void decPC(sshort o=1);
  void decIX();
  void decIY();
  void decPHL();
  void decPOIX(schar o);
  void decPOIY(schar o);

  void sllA();
  void sllB();
  void sllC();
  void sllD();
  void sllE();
  void sllH();
  void sllL();
  void sllPHL();
  void sllPOIX(schar o);
  void sllPOIY(schar o);

  void srlA();
  void srlB();
  void srlC();
  void srlD();
  void srlE();
  void srlH();
  void srlL();
  void srlPHL();
  void srlPOIX(schar o);
  void srlPOIY(schar o);

  void slaA();
  void slaB();
  void slaC();
  void slaD();
  void slaE();
  void slaH();
  void slaL();
  void slaPHL();
  void slaPOIX(schar o);
  void slaPOIY(schar o);

  void sraA();
  void sraB();
  void sraC();
  void sraD();
  void sraE();
  void sraH();
  void sraL();
  void sraPHL();
  void sraPOIX(schar o);
  void sraPOIY(schar o);

  void rlA();
  void rlB();
  void rlC();
  void rlD();
  void rlE();
  void rlH();
  void rlL();
  void rlPHL();
  void rlPOIX(schar o);
  void rlPOIY(schar o);

  void rlcA();
  void rlcB();
  void rlcC();
  void rlcD();
  void rlcE();
  void rlcH();
  void rlcL();
  void rlcPHL();
  void rlcPOIX(schar o);
  void rlcPOIY(schar o);

  void rrA();
  void rrB();
  void rrC();
  void rrD();
  void rrE();
  void rrH();
  void rrL();
  void rrPHL();
  void rrPOIX(schar o);
  void rrPOIY(schar o);

  void rrcA();
  void rrcB();
  void rrcC();
  void rrcD();
  void rrcE();
  void rrcH();
  void rrcL();
  void rrcPHL();
  void rrcPOIX(schar o);
  void rrcPOIY(schar o);

  void rld();
  void rrd();

  void tstBitA(uchar bit);
  void tstBitB(uchar bit);
  void tstBitC(uchar bit);
  void tstBitD(uchar bit);
  void tstBitE(uchar bit);
  void tstBitH(uchar bit);
  void tstBitL(uchar bit);
  void tstBitPHL(uchar bit);
  void tstBitPOIX(schar o, uchar bit, bool is_phl);
  void tstBitPOIY(schar o, uchar bit, bool is_phl);

  void setBitA(uchar bit);
  void setBitB(uchar bit);
  void setBitC(uchar bit);
  void setBitD(uchar bit);
  void setBitE(uchar bit);
  void setBitH(uchar bit);
  void setBitL(uchar bit);
  void setBitPHL(uchar bit);
  void setBitPOIX(schar o, uchar bit);
  void setBitPOIY(schar o, uchar bit);

  void resBitA(uchar bit);
  void resBitB(uchar bit);
  void resBitC(uchar bit);
  void resBitD(uchar bit);
  void resBitE(uchar bit);
  void resBitH(uchar bit);
  void resBitL(uchar bit);
  void resBitPHL(uchar bit);
  void resBitPOIX(schar o, uchar bit);
  void resBitPOIY(schar o, uchar bit);

  void call(ushort addr);

  void rst(ushort id);

  void daa();
  void cpl();
  void neg();
  void ccf();
  void scf();
  void di();
  void ei();
  void reti();
  void retn();

  void halt();
  void stop();

  void ex_de_hl();
  void ex_af_af1();
  void ex_p_sp_hl();
  void ex_p_sp_ix();
  void ex_p_sp_iy();
  void exx();
  void ldi();
  void ldir();
  void ldd();
  void lddr();
  void cpi();
  void cpir();
  void cpd();
  void cpdr();

  void outC(uchar value);
  void out(uchar port, uchar value);

  uchar inC();
  uchar in(uchar port, uchar qual);

  // ---------

  // Load

 public:
  bool load(const std::string &file);
  bool load(CFile *file);
  bool load(CFile *file, ushort *pos, ushort *len);

  bool loadBin(const std::string &file);
  bool loadBin(CFile *file);
  bool loadBin(CFile *file, ushort *pos, ushort *len);

 private:
  uchar addR(uchar r, uchar a);
  uchar adcR(uchar r, uchar a);
  uchar subR(uchar r, uchar a);
  uchar sbcR(uchar r, uchar a);

  uchar setBitR(uchar r, uchar bit);
  uchar resBitR(uchar r, uchar bit);
  void  tstBitR(uchar r, uchar bit, bool is_phl);

  uchar inc(uchar r);
  uchar dec(uchar r);

  uchar sll(uchar r);
  uchar srl(uchar r);
  uchar sla(uchar r);
  uchar sra(uchar r);

  void rlca();
  void rla();
  void rrca();
  void rra ();

  uchar rlc(uchar r);
  uchar rl (uchar r);
  uchar rrc(uchar r);
  uchar rr (uchar r);

  void setBRFlags(uchar r);
  void setRFlags(uchar r);

  bool tstParity(uchar c);

  // ---------

  // Disassemble

 public:
  bool disassemble(std::ostream &os=std::cout);
  bool disassemble(ushort pos, ushort len, std::ostream &os=std::cout);

  // ---------

  // Assemble

 public:
  bool assemble(CFile *ifile, std::ostream &os=std::cout);
  bool assemble(CFile *ifile, CFile *ofile);

  void assembleAll(ushort pc, std::ostream &os=std::cout);

  void assembleDumpSymbols();

 private:
  bool assemble(CFile *ifile, CFileBase *ofile);

  void assembleLoadLine(CFileParse *parse);

  void assembleDumpValues(CFileBase *ofile);

  bool assembleParseOp(CFileParse *parse, std::string &str, uint pass, bool *continued);

  bool assembleParseInteger(CFileParse *parse, uint pass, uint *i);

  void assembleSetLabelValue(const std::string &name, uint value);

  bool assembleEvalExpr(const std::string &expr, uint *value);

  void assembleError(const char *format, ...);

  void assembleOp(CZ80Op *op, std::ostream &os=std::cout);

  bool assembleStringToOpId(const std::string &str, uint *id);
  bool assembleStringToFlagId(const std::string &str, uint *id);
  bool assembleStringToRegisterId(const std::string &str, uint *id);

  void assembleDefineMacro(const std::string &name, const std::vector<std::string> &args,
                           const std::string &body);

  bool assembleGetMacro(const std::string &name, std::vector<std::string> &args,
                        std::string &body) const;

  // ---------

  // Execute

 public:
  bool execute();
  bool execute(ushort pos);

  bool next();
  bool step();
  bool cont();

 private:
  bool execute1(bool notify);
  bool step1(bool notify);

  // ---------

 public:
  bool undump(CFile *file, std::ostream &os=std::cout);

  // ---------

  // Read Next Memory Op

 public:
  void getOpData(CZ80OpData *op_data);

  void readOpData(CZ80OpData *op_data);

 private:
  CZ80Op *readOp();

  void readOpValues(CZ80Op *op, uchar *values1, uchar *num_values1,
                    uchar *values2, uchar *num_values2);

  uchar getNumArgValues(uint type, uint arg);

  // ---------

  // Functions

 public:
  //  adc

  static CZ80OpProc f_adc_a_a;
  static CZ80OpProc f_adc_a_b;
  static CZ80OpProc f_adc_a_c;
  static CZ80OpProc f_adc_a_d;
  static CZ80OpProc f_adc_a_e;
  static CZ80OpProc f_adc_a_h;
  static CZ80OpProc f_adc_a_l;
  static CZ80OpProc f_adc_a_ixh;
  static CZ80OpProc f_adc_a_ixl;
  static CZ80OpProc f_adc_a_iyh;
  static CZ80OpProc f_adc_a_iyl;
  static CZ80OpProc f_adc_a_p_hl;
  static CZ80OpProc f_adc_a_n;
  static CZ80OpProc f_adc_a_po_ix;
  static CZ80OpProc f_adc_a_po_iy;
  static CZ80OpProc f_adc_hl_bc;
  static CZ80OpProc f_adc_hl_de;
  static CZ80OpProc f_adc_hl_hl;
  static CZ80OpProc f_adc_hl_sp;

  // add

  static CZ80OpProc f_add_a_a;
  static CZ80OpProc f_add_a_b;
  static CZ80OpProc f_add_a_c;
  static CZ80OpProc f_add_a_d;
  static CZ80OpProc f_add_a_e;
  static CZ80OpProc f_add_a_h;
  static CZ80OpProc f_add_a_l;
  static CZ80OpProc f_add_a_ixh;
  static CZ80OpProc f_add_a_ixl;
  static CZ80OpProc f_add_a_iyh;
  static CZ80OpProc f_add_a_iyl;
  static CZ80OpProc f_add_a_p_hl;
  static CZ80OpProc f_add_a_n;
  static CZ80OpProc f_add_a_po_ix;
  static CZ80OpProc f_add_a_po_iy;
  static CZ80OpProc f_add_hl_bc;
  static CZ80OpProc f_add_hl_de;
  static CZ80OpProc f_add_hl_hl;
  static CZ80OpProc f_add_hl_sp;
  static CZ80OpProc f_add_ix_bc;
  static CZ80OpProc f_add_ix_de;
  static CZ80OpProc f_add_ix_ix;
  static CZ80OpProc f_add_ix_sp;
  static CZ80OpProc f_add_iy_bc;
  static CZ80OpProc f_add_iy_de;
  static CZ80OpProc f_add_iy_iy;
  static CZ80OpProc f_add_iy_sp;

  // and

  static CZ80OpProc f_and_a;
  static CZ80OpProc f_and_b;
  static CZ80OpProc f_and_c;
  static CZ80OpProc f_and_d;
  static CZ80OpProc f_and_e;
  static CZ80OpProc f_and_h;
  static CZ80OpProc f_and_l;
  static CZ80OpProc f_and_ixh;
  static CZ80OpProc f_and_ixl;
  static CZ80OpProc f_and_iyh;
  static CZ80OpProc f_and_iyl;
  static CZ80OpProc f_and_p_hl;
  static CZ80OpProc f_and_n;
  static CZ80OpProc f_and_po_ix;
  static CZ80OpProc f_and_po_iy;

  // bit

  static CZ80OpProc f_bit_a_n;
  static CZ80OpProc f_bit_b_n;
  static CZ80OpProc f_bit_c_n;
  static CZ80OpProc f_bit_d_n;
  static CZ80OpProc f_bit_e_n;
  static CZ80OpProc f_bit_h_n;
  static CZ80OpProc f_bit_l_n;
  static CZ80OpProc f_bit_p_hl_n;

  static CZ80OpProc f_bit_po_ix_n;
  static CZ80OpProc f_bit_po_ix_ns;
  static CZ80OpProc f_bit_po_iy_n;
  static CZ80OpProc f_bit_po_iy_ns;

  // call

  static CZ80OpProc f_call;
  static CZ80OpProc f_call_z;
  static CZ80OpProc f_call_nz;
  static CZ80OpProc f_call_c;
  static CZ80OpProc f_call_nc;
  static CZ80OpProc f_call_pe;
  static CZ80OpProc f_call_po;
  static CZ80OpProc f_call_p;
  static CZ80OpProc f_call_m;

  static CZ80OpProc f_ccf;

  // cp

  static CZ80OpProc f_cp_a;
  static CZ80OpProc f_cp_b;
  static CZ80OpProc f_cp_c;
  static CZ80OpProc f_cp_d;
  static CZ80OpProc f_cp_e;
  static CZ80OpProc f_cp_h;
  static CZ80OpProc f_cp_l;
  static CZ80OpProc f_cp_ixh;
  static CZ80OpProc f_cp_ixl;
  static CZ80OpProc f_cp_iyh;
  static CZ80OpProc f_cp_iyl;
  static CZ80OpProc f_cp_p_hl;
  static CZ80OpProc f_cp_n;
  static CZ80OpProc f_cp_po_ix;
  static CZ80OpProc f_cp_po_iy;

  static CZ80OpProc f_cpd;
  static CZ80OpProc f_cpdr;
  static CZ80OpProc f_cpi;
  static CZ80OpProc f_cpir;
  static CZ80OpProc f_cpl;
  static CZ80OpProc f_daa;

  // dec

  static CZ80OpProc f_dec_a;
  static CZ80OpProc f_dec_b;
  static CZ80OpProc f_dec_c;
  static CZ80OpProc f_dec_d;
  static CZ80OpProc f_dec_e;
  static CZ80OpProc f_dec_h;
  static CZ80OpProc f_dec_l;
  static CZ80OpProc f_dec_p_hl;
  static CZ80OpProc f_dec_po_ix;
  static CZ80OpProc f_dec_po_iy;
  static CZ80OpProc f_dec_bc;
  static CZ80OpProc f_dec_de;
  static CZ80OpProc f_dec_hl;
  static CZ80OpProc f_dec_sp;
  static CZ80OpProc f_dec_ix;
  static CZ80OpProc f_dec_iy;
  static CZ80OpProc f_dec_ixh;
  static CZ80OpProc f_dec_ixl;
  static CZ80OpProc f_dec_iyh;
  static CZ80OpProc f_dec_iyl;

  static CZ80OpProc f_di;
  static CZ80OpProc f_djnz;
  static CZ80OpProc f_ei;

  // ex

  static CZ80OpProc f_ex_de_hl;
  static CZ80OpProc f_ex_af_af1;
  static CZ80OpProc f_ex_p_sp_hl;
  static CZ80OpProc f_ex_p_sp_ix;
  static CZ80OpProc f_ex_p_sp_iy;

  static CZ80OpProc f_exx;
  static CZ80OpProc f_halt;

  // im

  static CZ80OpProc f_im_n;

  // in

  static CZ80OpProc f_in_a_p_n;
  static CZ80OpProc f_in_a_p_c;
  static CZ80OpProc f_in_b_p_c;
  static CZ80OpProc f_in_c_p_c;
  static CZ80OpProc f_in_d_p_c;
  static CZ80OpProc f_in_e_p_c;
  static CZ80OpProc f_in_h_p_c;
  static CZ80OpProc f_in_l_p_c;
  static CZ80OpProc f_in_n_p_c;

  // inc

  static CZ80OpProc f_inc_a;
  static CZ80OpProc f_inc_b;
  static CZ80OpProc f_inc_c;
  static CZ80OpProc f_inc_d;
  static CZ80OpProc f_inc_e;
  static CZ80OpProc f_inc_h;
  static CZ80OpProc f_inc_l;
  static CZ80OpProc f_inc_p_hl;
  static CZ80OpProc f_inc_po_ix;
  static CZ80OpProc f_inc_po_iy;
  static CZ80OpProc f_inc_bc;
  static CZ80OpProc f_inc_de;
  static CZ80OpProc f_inc_hl;
  static CZ80OpProc f_inc_sp;
  static CZ80OpProc f_inc_ix;
  static CZ80OpProc f_inc_iy;
  static CZ80OpProc f_inc_ixh;
  static CZ80OpProc f_inc_ixl;
  static CZ80OpProc f_inc_iyh;
  static CZ80OpProc f_inc_iyl;

  static CZ80OpProc f_ind;
  static CZ80OpProc f_indr;
  static CZ80OpProc f_ini;
  static CZ80OpProc f_inir;

  // jp

  static CZ80OpProc f_jp;
  static CZ80OpProc f_jp_z;
  static CZ80OpProc f_jp_nz;
  static CZ80OpProc f_jp_c;
  static CZ80OpProc f_jp_nc;
  static CZ80OpProc f_jp_pe;
  static CZ80OpProc f_jp_po;
  static CZ80OpProc f_jp_p;
  static CZ80OpProc f_jp_m;
  static CZ80OpProc f_jp_hl;
  static CZ80OpProc f_jp_ix;
  static CZ80OpProc f_jp_iy;

  // jr

  static CZ80OpProc f_jr;
  static CZ80OpProc f_jr_z;
  static CZ80OpProc f_jr_nz;
  static CZ80OpProc f_jr_c;
  static CZ80OpProc f_jr_nc;

  // ld

  static CZ80OpProc f_ld_a_n;
  static CZ80OpProc f_ld_b_n;
  static CZ80OpProc f_ld_c_n;
  static CZ80OpProc f_ld_d_n;
  static CZ80OpProc f_ld_e_n;
  static CZ80OpProc f_ld_h_n;
  static CZ80OpProc f_ld_l_n;
  static CZ80OpProc f_ld_bc_nn;
  static CZ80OpProc f_ld_de_nn;
  static CZ80OpProc f_ld_hl_nn;
  static CZ80OpProc f_ld_sp_nn;
  static CZ80OpProc f_ld_ix_nn;
  static CZ80OpProc f_ld_iy_nn;
  static CZ80OpProc f_ld_ixh_n;
  static CZ80OpProc f_ld_ixl_n;
  static CZ80OpProc f_ld_iyh_n;
  static CZ80OpProc f_ld_iyl_n;

  static CZ80OpProc f_ld_a_a;
  static CZ80OpProc f_ld_a_b;
  static CZ80OpProc f_ld_a_c;
  static CZ80OpProc f_ld_a_d;
  static CZ80OpProc f_ld_a_e;
  static CZ80OpProc f_ld_a_h;
  static CZ80OpProc f_ld_a_l;
  static CZ80OpProc f_ld_a_i;
  static CZ80OpProc f_ld_a_r;
  static CZ80OpProc f_ld_a_ixh;
  static CZ80OpProc f_ld_a_ixl;
  static CZ80OpProc f_ld_a_iyh;
  static CZ80OpProc f_ld_a_iyl;

  static CZ80OpProc f_ld_b_a;
  static CZ80OpProc f_ld_b_b;
  static CZ80OpProc f_ld_b_c;
  static CZ80OpProc f_ld_b_d;
  static CZ80OpProc f_ld_b_e;
  static CZ80OpProc f_ld_b_h;
  static CZ80OpProc f_ld_b_l;
  static CZ80OpProc f_ld_b_ixh;
  static CZ80OpProc f_ld_b_ixl;
  static CZ80OpProc f_ld_b_iyh;
  static CZ80OpProc f_ld_b_iyl;

  static CZ80OpProc f_ld_c_a;
  static CZ80OpProc f_ld_c_b;
  static CZ80OpProc f_ld_c_c;
  static CZ80OpProc f_ld_c_d;
  static CZ80OpProc f_ld_c_e;
  static CZ80OpProc f_ld_c_h;
  static CZ80OpProc f_ld_c_l;
  static CZ80OpProc f_ld_c_ixh;
  static CZ80OpProc f_ld_c_ixl;
  static CZ80OpProc f_ld_c_iyh;
  static CZ80OpProc f_ld_c_iyl;

  static CZ80OpProc f_ld_d_a;
  static CZ80OpProc f_ld_d_b;
  static CZ80OpProc f_ld_d_c;
  static CZ80OpProc f_ld_d_d;
  static CZ80OpProc f_ld_d_e;
  static CZ80OpProc f_ld_d_h;
  static CZ80OpProc f_ld_d_l;
  static CZ80OpProc f_ld_d_ixh;
  static CZ80OpProc f_ld_d_ixl;
  static CZ80OpProc f_ld_d_iyh;
  static CZ80OpProc f_ld_d_iyl;

  static CZ80OpProc f_ld_e_a;
  static CZ80OpProc f_ld_e_b;
  static CZ80OpProc f_ld_e_c;
  static CZ80OpProc f_ld_e_d;
  static CZ80OpProc f_ld_e_e;
  static CZ80OpProc f_ld_e_h;
  static CZ80OpProc f_ld_e_l;
  static CZ80OpProc f_ld_e_ixh;
  static CZ80OpProc f_ld_e_ixl;
  static CZ80OpProc f_ld_e_iyh;
  static CZ80OpProc f_ld_e_iyl;

  static CZ80OpProc f_ld_h_a;
  static CZ80OpProc f_ld_h_b;
  static CZ80OpProc f_ld_h_c;
  static CZ80OpProc f_ld_h_d;
  static CZ80OpProc f_ld_h_e;
  static CZ80OpProc f_ld_h_h;
  static CZ80OpProc f_ld_h_l;
  static CZ80OpProc f_ld_h_ixh;
  static CZ80OpProc f_ld_h_ixl;
  static CZ80OpProc f_ld_h_iyh;
  static CZ80OpProc f_ld_h_iyl;

  static CZ80OpProc f_ld_l_a;
  static CZ80OpProc f_ld_l_b;
  static CZ80OpProc f_ld_l_c;
  static CZ80OpProc f_ld_l_d;
  static CZ80OpProc f_ld_l_e;
  static CZ80OpProc f_ld_l_h;
  static CZ80OpProc f_ld_l_l;
  static CZ80OpProc f_ld_l_ixh;
  static CZ80OpProc f_ld_l_ixl;
  static CZ80OpProc f_ld_l_iyh;
  static CZ80OpProc f_ld_l_iyl;

  static CZ80OpProc f_ld_ixh_a;
  static CZ80OpProc f_ld_ixh_b;
  static CZ80OpProc f_ld_ixh_c;
  static CZ80OpProc f_ld_ixh_d;
  static CZ80OpProc f_ld_ixh_e;
  static CZ80OpProc f_ld_ixh_ixh;
  static CZ80OpProc f_ld_ixh_ixl;

  static CZ80OpProc f_ld_ixl_a;
  static CZ80OpProc f_ld_ixl_b;
  static CZ80OpProc f_ld_ixl_c;
  static CZ80OpProc f_ld_ixl_d;
  static CZ80OpProc f_ld_ixl_e;
  static CZ80OpProc f_ld_ixl_ixh;
  static CZ80OpProc f_ld_ixl_ixl;

  static CZ80OpProc f_ld_iyh_a;
  static CZ80OpProc f_ld_iyh_b;
  static CZ80OpProc f_ld_iyh_c;
  static CZ80OpProc f_ld_iyh_d;
  static CZ80OpProc f_ld_iyh_e;
  static CZ80OpProc f_ld_iyh_iyh;
  static CZ80OpProc f_ld_iyh_iyl;

  static CZ80OpProc f_ld_iyl_a;
  static CZ80OpProc f_ld_iyl_b;
  static CZ80OpProc f_ld_iyl_c;
  static CZ80OpProc f_ld_iyl_d;
  static CZ80OpProc f_ld_iyl_e;
  static CZ80OpProc f_ld_iyl_iyh;
  static CZ80OpProc f_ld_iyl_iyl;

  static CZ80OpProc f_ld_i_a;
  static CZ80OpProc f_ld_r_a;

  static CZ80OpProc f_ld_a_p_bc;
  static CZ80OpProc f_ld_a_p_de;
  static CZ80OpProc f_ld_a_p_hl;
  static CZ80OpProc f_ld_b_p_hl;
  static CZ80OpProc f_ld_c_p_hl;
  static CZ80OpProc f_ld_d_p_hl;
  static CZ80OpProc f_ld_e_p_hl;
  static CZ80OpProc f_ld_h_p_hl;
  static CZ80OpProc f_ld_l_p_hl;
  static CZ80OpProc f_ld_n_p_hl;

  static CZ80OpProc f_ld_p_bc_a;
  static CZ80OpProc f_ld_p_de_a;
  static CZ80OpProc f_ld_p_hl_a;
  static CZ80OpProc f_ld_p_hl_b;
  static CZ80OpProc f_ld_p_hl_c;
  static CZ80OpProc f_ld_p_hl_d;
  static CZ80OpProc f_ld_p_hl_e;
  static CZ80OpProc f_ld_p_hl_h;
  static CZ80OpProc f_ld_p_hl_l;
  static CZ80OpProc f_ld_p_hl_n;

  static CZ80OpProc f_ld_a_p_nn;
  static CZ80OpProc f_ld_bc_p_nn;
  static CZ80OpProc f_ld_de_p_nn;
  static CZ80OpProc f_ld_hl_p_nn;
  static CZ80OpProc f_ld_sp_p_nn;
  static CZ80OpProc f_ld_ix_p_nn;
  static CZ80OpProc f_ld_iy_p_nn;

  static CZ80OpProc f_ld_p_nn_a;
  static CZ80OpProc f_ld_p_nn_bc;
  static CZ80OpProc f_ld_p_nn_de;
  static CZ80OpProc f_ld_p_nn_hl;
  static CZ80OpProc f_ld_p_nn_sp;
  static CZ80OpProc f_ld_p_nn_ix;
  static CZ80OpProc f_ld_p_nn_iy;

  static CZ80OpProc f_ld_sp_hl;
  static CZ80OpProc f_ld_sp_ix;
  static CZ80OpProc f_ld_sp_iy;

  static CZ80OpProc f_ld_a_po_ix;
  static CZ80OpProc f_ld_b_po_ix;
  static CZ80OpProc f_ld_c_po_ix;
  static CZ80OpProc f_ld_d_po_ix;
  static CZ80OpProc f_ld_e_po_ix;
  static CZ80OpProc f_ld_h_po_ix;
  static CZ80OpProc f_ld_l_po_ix;

  static CZ80OpProc f_ld_a_po_iy;
  static CZ80OpProc f_ld_b_po_iy;
  static CZ80OpProc f_ld_c_po_iy;
  static CZ80OpProc f_ld_d_po_iy;
  static CZ80OpProc f_ld_e_po_iy;
  static CZ80OpProc f_ld_h_po_iy;
  static CZ80OpProc f_ld_l_po_iy;

  static CZ80OpProc f_ld_po_ix_a;
  static CZ80OpProc f_ld_po_ix_b;
  static CZ80OpProc f_ld_po_ix_c;
  static CZ80OpProc f_ld_po_ix_d;
  static CZ80OpProc f_ld_po_ix_e;
  static CZ80OpProc f_ld_po_ix_h;
  static CZ80OpProc f_ld_po_ix_l;
  static CZ80OpProc f_ld_po_ix_n;

  static CZ80OpProc f_ld_po_iy_a;
  static CZ80OpProc f_ld_po_iy_b;
  static CZ80OpProc f_ld_po_iy_c;
  static CZ80OpProc f_ld_po_iy_d;
  static CZ80OpProc f_ld_po_iy_e;
  static CZ80OpProc f_ld_po_iy_h;
  static CZ80OpProc f_ld_po_iy_l;
  static CZ80OpProc f_ld_po_iy_n;

  // ldd

  static CZ80OpProc f_ldd;
  static CZ80OpProc f_lddr;
  static CZ80OpProc f_ldi;
  static CZ80OpProc f_ldir;
  static CZ80OpProc f_neg;
  static CZ80OpProc f_nop;

  // or

  static CZ80OpProc f_or_a;
  static CZ80OpProc f_or_b;
  static CZ80OpProc f_or_c;
  static CZ80OpProc f_or_d;
  static CZ80OpProc f_or_e;
  static CZ80OpProc f_or_h;
  static CZ80OpProc f_or_l;
  static CZ80OpProc f_or_ixh;
  static CZ80OpProc f_or_ixl;
  static CZ80OpProc f_or_iyh;
  static CZ80OpProc f_or_iyl;
  static CZ80OpProc f_or_p_hl;
  static CZ80OpProc f_or_n;
  static CZ80OpProc f_or_po_ix;
  static CZ80OpProc f_or_po_iy;

  static CZ80OpProc f_otdr;
  static CZ80OpProc f_otir;

  // out

  static CZ80OpProc f_out_p_n_a;
  static CZ80OpProc f_out_p_c_a;
  static CZ80OpProc f_out_p_c_b;
  static CZ80OpProc f_out_p_c_c;
  static CZ80OpProc f_out_p_c_d;
  static CZ80OpProc f_out_p_c_e;
  static CZ80OpProc f_out_p_c_h;
  static CZ80OpProc f_out_p_c_l;
  static CZ80OpProc f_out_p_c_n;

  static CZ80OpProc f_outd;
  static CZ80OpProc f_outi;

  // pop

  static CZ80OpProc f_pop_af;
  static CZ80OpProc f_pop_bc;
  static CZ80OpProc f_pop_de;
  static CZ80OpProc f_pop_hl;
  static CZ80OpProc f_pop_ix;
  static CZ80OpProc f_pop_iy;

  // push

  static CZ80OpProc f_push_af;
  static CZ80OpProc f_push_bc;
  static CZ80OpProc f_push_de;
  static CZ80OpProc f_push_hl;
  static CZ80OpProc f_push_ix;
  static CZ80OpProc f_push_iy;

  // res

  static CZ80OpProc f_res_po_ix_n;
  static CZ80OpProc f_res_po_iy_n;
  static CZ80OpProc f_res_a_n;
  static CZ80OpProc f_res_b_n;
  static CZ80OpProc f_res_c_n;
  static CZ80OpProc f_res_d_n;
  static CZ80OpProc f_res_e_n;
  static CZ80OpProc f_res_h_n;
  static CZ80OpProc f_res_l_n;
  static CZ80OpProc f_res_p_hl_n;
  static CZ80OpProc f_res_po_ix_a_n;
  static CZ80OpProc f_res_po_ix_b_n;
  static CZ80OpProc f_res_po_ix_c_n;
  static CZ80OpProc f_res_po_ix_d_n;
  static CZ80OpProc f_res_po_ix_e_n;
  static CZ80OpProc f_res_po_ix_h_n;
  static CZ80OpProc f_res_po_ix_l_n;
  static CZ80OpProc f_res_po_iy_a_n;
  static CZ80OpProc f_res_po_iy_b_n;
  static CZ80OpProc f_res_po_iy_c_n;
  static CZ80OpProc f_res_po_iy_d_n;
  static CZ80OpProc f_res_po_iy_e_n;
  static CZ80OpProc f_res_po_iy_h_n;
  static CZ80OpProc f_res_po_iy_l_n;

  static void f_res_po_ix_a_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_ix_b_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_ix_c_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_ix_d_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_ix_e_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_ix_h_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_ix_l_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_a_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_b_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_c_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_d_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_e_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_h_n(CZ80OpData *op_data, uchar o);
  static void f_res_po_iy_l_n(CZ80OpData *op_data, uchar o);

  // ret

  static CZ80OpProc f_ret;
  static CZ80OpProc f_ret_z;
  static CZ80OpProc f_ret_nz;
  static CZ80OpProc f_ret_c;
  static CZ80OpProc f_ret_nc;
  static CZ80OpProc f_ret_pe;
  static CZ80OpProc f_ret_po;
  static CZ80OpProc f_ret_p;
  static CZ80OpProc f_ret_m;

  static CZ80OpProc f_reti;
  static CZ80OpProc f_retn;

  // rl

  static CZ80OpProc f_rl_a;
  static CZ80OpProc f_rl_b;
  static CZ80OpProc f_rl_c;
  static CZ80OpProc f_rl_d;
  static CZ80OpProc f_rl_e;
  static CZ80OpProc f_rl_h;
  static CZ80OpProc f_rl_l;
  static CZ80OpProc f_rl_p_hl;
  static CZ80OpProc f_rl_po_ix;
  static CZ80OpProc f_rl_po_ix_a;
  static CZ80OpProc f_rl_po_ix_b;
  static CZ80OpProc f_rl_po_ix_c;
  static CZ80OpProc f_rl_po_ix_d;
  static CZ80OpProc f_rl_po_ix_e;
  static CZ80OpProc f_rl_po_ix_h;
  static CZ80OpProc f_rl_po_ix_l;
  static CZ80OpProc f_rl_po_iy;
  static CZ80OpProc f_rl_po_iy_a;
  static CZ80OpProc f_rl_po_iy_b;
  static CZ80OpProc f_rl_po_iy_c;
  static CZ80OpProc f_rl_po_iy_d;
  static CZ80OpProc f_rl_po_iy_e;
  static CZ80OpProc f_rl_po_iy_h;
  static CZ80OpProc f_rl_po_iy_l;

  // rla

  static CZ80OpProc f_rla;

  // rlc

  static CZ80OpProc f_rlc_a;
  static CZ80OpProc f_rlc_b;
  static CZ80OpProc f_rlc_c;
  static CZ80OpProc f_rlc_d;
  static CZ80OpProc f_rlc_e;
  static CZ80OpProc f_rlc_h;
  static CZ80OpProc f_rlc_l;
  static CZ80OpProc f_rlc_p_hl;
  static CZ80OpProc f_rlc_po_ix;
  static CZ80OpProc f_rlc_po_ix_a;
  static CZ80OpProc f_rlc_po_ix_b;
  static CZ80OpProc f_rlc_po_ix_c;
  static CZ80OpProc f_rlc_po_ix_d;
  static CZ80OpProc f_rlc_po_ix_e;
  static CZ80OpProc f_rlc_po_ix_h;
  static CZ80OpProc f_rlc_po_ix_l;
  static CZ80OpProc f_rlc_po_iy;
  static CZ80OpProc f_rlc_po_iy_a;
  static CZ80OpProc f_rlc_po_iy_b;
  static CZ80OpProc f_rlc_po_iy_c;
  static CZ80OpProc f_rlc_po_iy_d;
  static CZ80OpProc f_rlc_po_iy_e;
  static CZ80OpProc f_rlc_po_iy_h;
  static CZ80OpProc f_rlc_po_iy_l;

  static CZ80OpProc f_rlca;
  static CZ80OpProc f_rld;

  // rr

  static CZ80OpProc f_rr_a;
  static CZ80OpProc f_rr_b;
  static CZ80OpProc f_rr_c;
  static CZ80OpProc f_rr_d;
  static CZ80OpProc f_rr_e;
  static CZ80OpProc f_rr_h;
  static CZ80OpProc f_rr_l;
  static CZ80OpProc f_rr_p_hl;
  static CZ80OpProc f_rr_po_ix;
  static CZ80OpProc f_rr_po_ix_a;
  static CZ80OpProc f_rr_po_ix_b;
  static CZ80OpProc f_rr_po_ix_c;
  static CZ80OpProc f_rr_po_ix_d;
  static CZ80OpProc f_rr_po_ix_e;
  static CZ80OpProc f_rr_po_ix_h;
  static CZ80OpProc f_rr_po_ix_l;
  static CZ80OpProc f_rr_po_iy;
  static CZ80OpProc f_rr_po_iy_a;
  static CZ80OpProc f_rr_po_iy_b;
  static CZ80OpProc f_rr_po_iy_c;
  static CZ80OpProc f_rr_po_iy_d;
  static CZ80OpProc f_rr_po_iy_e;
  static CZ80OpProc f_rr_po_iy_h;
  static CZ80OpProc f_rr_po_iy_l;

  // rra

  static CZ80OpProc f_rra;

  // rrc

  static CZ80OpProc f_rrc_a;
  static CZ80OpProc f_rrc_b;
  static CZ80OpProc f_rrc_c;
  static CZ80OpProc f_rrc_d;
  static CZ80OpProc f_rrc_e;
  static CZ80OpProc f_rrc_h;
  static CZ80OpProc f_rrc_l;
  static CZ80OpProc f_rrc_p_hl;
  static CZ80OpProc f_rrc_po_ix;
  static CZ80OpProc f_rrc_po_ix_a;
  static CZ80OpProc f_rrc_po_ix_b;
  static CZ80OpProc f_rrc_po_ix_c;
  static CZ80OpProc f_rrc_po_ix_d;
  static CZ80OpProc f_rrc_po_ix_e;
  static CZ80OpProc f_rrc_po_ix_h;
  static CZ80OpProc f_rrc_po_ix_l;
  static CZ80OpProc f_rrc_po_iy;
  static CZ80OpProc f_rrc_po_iy_a;
  static CZ80OpProc f_rrc_po_iy_b;
  static CZ80OpProc f_rrc_po_iy_c;
  static CZ80OpProc f_rrc_po_iy_d;
  static CZ80OpProc f_rrc_po_iy_e;
  static CZ80OpProc f_rrc_po_iy_h;
  static CZ80OpProc f_rrc_po_iy_l;

  static CZ80OpProc f_rrca;
  static CZ80OpProc f_rrd;

  // rst

  static CZ80OpProc f_rst_n;

  // sbc

  static CZ80OpProc f_sbc_a_a;
  static CZ80OpProc f_sbc_a_b;
  static CZ80OpProc f_sbc_a_c;
  static CZ80OpProc f_sbc_a_d;
  static CZ80OpProc f_sbc_a_e;
  static CZ80OpProc f_sbc_a_h;
  static CZ80OpProc f_sbc_a_l;
  static CZ80OpProc f_sbc_a_ixh;
  static CZ80OpProc f_sbc_a_ixl;
  static CZ80OpProc f_sbc_a_iyh;
  static CZ80OpProc f_sbc_a_iyl;
  static CZ80OpProc f_sbc_a_p_hl;
  static CZ80OpProc f_sbc_a_n;
  static CZ80OpProc f_sbc_po_ix;
  static CZ80OpProc f_sbc_po_iy;
  static CZ80OpProc f_sbc_hl_bc;
  static CZ80OpProc f_sbc_hl_de;
  static CZ80OpProc f_sbc_hl_hl;
  static CZ80OpProc f_sbc_hl_sp;

  static CZ80OpProc f_scf;

  // set

  static CZ80OpProc f_set_a_n;
  static CZ80OpProc f_set_b_n;
  static CZ80OpProc f_set_c_n;
  static CZ80OpProc f_set_d_n;
  static CZ80OpProc f_set_e_n;
  static CZ80OpProc f_set_h_n;
  static CZ80OpProc f_set_l_n;
  static CZ80OpProc f_set_p_hl_n;
  static CZ80OpProc f_set_po_ix_n;
  static CZ80OpProc f_set_po_ix_a_n;
  static CZ80OpProc f_set_po_ix_b_n;
  static CZ80OpProc f_set_po_ix_c_n;
  static CZ80OpProc f_set_po_ix_d_n;
  static CZ80OpProc f_set_po_ix_e_n;
  static CZ80OpProc f_set_po_ix_h_n;
  static CZ80OpProc f_set_po_ix_l_n;
  static CZ80OpProc f_set_po_iy_n;
  static CZ80OpProc f_set_po_iy_a_n;
  static CZ80OpProc f_set_po_iy_b_n;
  static CZ80OpProc f_set_po_iy_c_n;
  static CZ80OpProc f_set_po_iy_d_n;
  static CZ80OpProc f_set_po_iy_e_n;
  static CZ80OpProc f_set_po_iy_h_n;
  static CZ80OpProc f_set_po_iy_l_n;

  static void f_set_po_ix_a_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_ix_b_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_ix_c_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_ix_d_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_ix_e_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_ix_h_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_ix_l_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_a_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_b_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_c_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_d_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_e_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_h_n(CZ80OpData *op_data, uchar o);
  static void f_set_po_iy_l_n(CZ80OpData *op_data, uchar o);

  // sla

  static CZ80OpProc f_sla_a;
  static CZ80OpProc f_sla_b;
  static CZ80OpProc f_sla_c;
  static CZ80OpProc f_sla_d;
  static CZ80OpProc f_sla_e;
  static CZ80OpProc f_sla_h;
  static CZ80OpProc f_sla_l;
  static CZ80OpProc f_sla_p_hl;
  static CZ80OpProc f_sla_po_ix;
  static CZ80OpProc f_sla_po_ix_a;
  static CZ80OpProc f_sla_po_ix_b;
  static CZ80OpProc f_sla_po_ix_c;
  static CZ80OpProc f_sla_po_ix_d;
  static CZ80OpProc f_sla_po_ix_e;
  static CZ80OpProc f_sla_po_ix_h;
  static CZ80OpProc f_sla_po_ix_l;
  static CZ80OpProc f_sla_po_iy;
  static CZ80OpProc f_sla_po_iy_a;
  static CZ80OpProc f_sla_po_iy_b;
  static CZ80OpProc f_sla_po_iy_c;
  static CZ80OpProc f_sla_po_iy_d;
  static CZ80OpProc f_sla_po_iy_e;
  static CZ80OpProc f_sla_po_iy_h;
  static CZ80OpProc f_sla_po_iy_l;

  // sll

  static CZ80OpProc f_sll_a;
  static CZ80OpProc f_sll_b;
  static CZ80OpProc f_sll_c;
  static CZ80OpProc f_sll_d;
  static CZ80OpProc f_sll_e;
  static CZ80OpProc f_sll_h;
  static CZ80OpProc f_sll_l;
  static CZ80OpProc f_sll_p_hl;
  static CZ80OpProc f_sll_po_ix;
  static CZ80OpProc f_sll_po_ix_a;
  static CZ80OpProc f_sll_po_ix_b;
  static CZ80OpProc f_sll_po_ix_c;
  static CZ80OpProc f_sll_po_ix_d;
  static CZ80OpProc f_sll_po_ix_e;
  static CZ80OpProc f_sll_po_ix_h;
  static CZ80OpProc f_sll_po_ix_l;
  static CZ80OpProc f_sll_po_iy;
  static CZ80OpProc f_sll_po_iy_a;
  static CZ80OpProc f_sll_po_iy_b;
  static CZ80OpProc f_sll_po_iy_c;
  static CZ80OpProc f_sll_po_iy_d;
  static CZ80OpProc f_sll_po_iy_e;
  static CZ80OpProc f_sll_po_iy_h;
  static CZ80OpProc f_sll_po_iy_l;

  // sra

  static CZ80OpProc f_sra_a;
  static CZ80OpProc f_sra_b;
  static CZ80OpProc f_sra_c;
  static CZ80OpProc f_sra_d;
  static CZ80OpProc f_sra_e;
  static CZ80OpProc f_sra_h;
  static CZ80OpProc f_sra_l;
  static CZ80OpProc f_sra_p_hl;
  static CZ80OpProc f_sra_po_ix;
  static CZ80OpProc f_sra_po_ix_a;
  static CZ80OpProc f_sra_po_ix_b;
  static CZ80OpProc f_sra_po_ix_c;
  static CZ80OpProc f_sra_po_ix_d;
  static CZ80OpProc f_sra_po_ix_e;
  static CZ80OpProc f_sra_po_ix_h;
  static CZ80OpProc f_sra_po_ix_l;
  static CZ80OpProc f_sra_po_iy;
  static CZ80OpProc f_sra_po_iy_a;
  static CZ80OpProc f_sra_po_iy_b;
  static CZ80OpProc f_sra_po_iy_c;
  static CZ80OpProc f_sra_po_iy_d;
  static CZ80OpProc f_sra_po_iy_e;
  static CZ80OpProc f_sra_po_iy_h;
  static CZ80OpProc f_sra_po_iy_l;

  // srl

  static CZ80OpProc f_srl_a;
  static CZ80OpProc f_srl_b;
  static CZ80OpProc f_srl_c;
  static CZ80OpProc f_srl_d;
  static CZ80OpProc f_srl_e;
  static CZ80OpProc f_srl_h;
  static CZ80OpProc f_srl_l;
  static CZ80OpProc f_srl_p_hl;
  static CZ80OpProc f_srl_po_ix;
  static CZ80OpProc f_srl_po_ix_a;
  static CZ80OpProc f_srl_po_ix_b;
  static CZ80OpProc f_srl_po_ix_c;
  static CZ80OpProc f_srl_po_ix_d;
  static CZ80OpProc f_srl_po_ix_e;
  static CZ80OpProc f_srl_po_ix_h;
  static CZ80OpProc f_srl_po_ix_l;
  static CZ80OpProc f_srl_po_iy;
  static CZ80OpProc f_srl_po_iy_a;
  static CZ80OpProc f_srl_po_iy_b;
  static CZ80OpProc f_srl_po_iy_c;
  static CZ80OpProc f_srl_po_iy_d;
  static CZ80OpProc f_srl_po_iy_e;
  static CZ80OpProc f_srl_po_iy_h;
  static CZ80OpProc f_srl_po_iy_l;

  // sub

  static CZ80OpProc f_sub_a;
  static CZ80OpProc f_sub_b;
  static CZ80OpProc f_sub_c;
  static CZ80OpProc f_sub_d;
  static CZ80OpProc f_sub_e;
  static CZ80OpProc f_sub_h;
  static CZ80OpProc f_sub_l;
  static CZ80OpProc f_sub_ixh;
  static CZ80OpProc f_sub_ixl;
  static CZ80OpProc f_sub_iyh;
  static CZ80OpProc f_sub_iyl;
  static CZ80OpProc f_sub_p_hl;
  static CZ80OpProc f_sub_n;
  static CZ80OpProc f_sub_po_ix;
  static CZ80OpProc f_sub_po_iy;

  // xor

  static CZ80OpProc f_xor_a;
  static CZ80OpProc f_xor_b;
  static CZ80OpProc f_xor_c;
  static CZ80OpProc f_xor_d;
  static CZ80OpProc f_xor_e;
  static CZ80OpProc f_xor_h;
  static CZ80OpProc f_xor_l;
  static CZ80OpProc f_xor_ixh;
  static CZ80OpProc f_xor_ixl;
  static CZ80OpProc f_xor_iyh;
  static CZ80OpProc f_xor_iyl;
  static CZ80OpProc f_xor_p_hl;
  static CZ80OpProc f_xor_n;
  static CZ80OpProc f_xor_po_ix;
  static CZ80OpProc f_xor_po_iy;

  static CZ80OpProc f_err;

  // --------

  // Debug

 public:
  static std::string getRegisterName(uint reg );
  static std::string getFlagName    (uint flag);

  uchar  getRegValue8(uint reg);
  ushort getRegValue16(uint reg);
  ushort getPRegValue16(uint reg);

  void printState(std::ostream &os=std::cout);

  void printRegValue8(std::ostream &os, uint reg);
  void printRegValue16AndPtr(std::ostream &os, uint reg);

  std::string getFlagsString();

  // --------

  bool lookupOp(CZ80Op *op, CZ80Op **op1);

  static CZ80Op *getIndOp(uint ind);

  // --------

  // Op Counts

  void dumpOpCounts(std::ostream &os);
  void resetOpCounts();

  // --------

  void tracePC();
  void traceBack();

  // --------

  // Snapshot

 public:
  bool saveSnapshot(const std::string &filename="snapshot.z80");

  bool loadSnapshot(const std::string &filename);
  bool loadSnapshot(CFile *file);
};

struct CZ80Op;

struct CZ80OpData {
  CZ80 *   z80;
  CZ80Op * op;
  uchar    values1[2];
  uchar    num_values1;
  uchar    values2[2];
  uchar    num_values2;

  const char *getName() const;

  uchar  getUByte1() const { return values1[0]; }
  ushort getUWord1() const { return (values1[1] << 8) | values1[0]; }
  uchar  getUByte2() const { return values2[0]; }
  ushort getUWord2() const { return (values2[1] << 8) | values2[0]; }

  char  getSByte1() const { return (schar ) getUByte1(); }
  short getSWord1() const { return (sshort) getUWord1(); }
  char  getSByte2() const { return (schar ) getUByte2(); }
  short getSWord2() const { return (sshort) getUWord2(); }

  void setPByte1(uchar  b) { z80->setByte(getUWord1(), b); }
  void setPWord1(ushort w) { z80->setWord(getUWord1(), w); }

  uchar  getPByte2() const { return z80->getByte(getUWord2()); }
  ushort getPWord2() const { return z80->getWord(getUWord2()); }

  uchar getPOIX1() const { return z80->getPOIX(getSByte1()); }
  uchar getPOIY1() const { return z80->getPOIY(getSByte1()); }
  uchar getPOIX2() const { return z80->getPOIX(getSByte2()); }
  uchar getPOIY2() const { return z80->getPOIY(getSByte2()); }

  void setPOIX1(uchar b) { z80->setPOIX(getSByte1(), b); }
  void setPOIY1(uchar b) { z80->setPOIY(getSByte1(), b); }

  ushort getRPC1() { return z80->getPC() + getSByte1(); }
  ushort getRPC2() { return z80->getPC() + getSByte2(); }

  void execute();

  void dump(CFile *file);
  bool undump(CFile *file);

  void dumpTxt(std::ostream &os=std::cout);

  std::string toTxt();

  void toValues(uchar **values, uint *num_values);

  void printStr(std::ostream &os);

  std::string getOpString();

  std::string getArgString(uint type, uint arg, uchar *args, ushort num_args);

  uchar getSize();
};

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

 protected:
  CZ80 &z80;
};

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

class CZ80Screen {
 public:
  CZ80Screen(CZ80 &z80_i) : z80(z80_i) { }

  virtual ~CZ80Screen() { }

  virtual void memChanged(ushort, ushort) { }

 protected:
  CZ80 &z80;
};

class CZ80RstData {
 public:
  CZ80RstData(CZ80 &z80_i) : z80(z80_i) { }

  virtual ~CZ80RstData() { }

  virtual void rst(ushort) { }

 protected:
  CZ80 &z80;
};

class CZ80StdRstData : public CZ80RstData {
 public:
  CZ80StdRstData(CZ80 &z80) :
   CZ80RstData(z80), newline_(true) {
  }

  virtual ~CZ80StdRstData() { }

  void rst(ushort id);

  virtual void rstFwd(ushort) { }

 protected:
  bool newline_;
};

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
  CZ80   &z80_;
  int     secs_;
  int     usecs_;
  double  mhz_;
};

class CZ80DebugData {
 protected:
  typedef std::list<CZ80Trace *> TraceList;

  CZ80      &z80_;
  uint       breakpoints_[2048];
  TraceList  trace_list_;

  bool af_changed_;
  bool bc_changed_;
  bool de_changed_;
  bool hl_changed_;
  bool ix_changed_;
  bool iy_changed_;
  bool sp_changed_;
  bool pc_changed_;
  bool i_changed_;
  bool im_changed_;
  bool af_1_changed_;
  bool bc_1_changed_;
  bool de_1_changed_;
  bool hl_1_changed_;
  bool iff_changed_;

  bool   mem_changed_;
  ushort mem_changed_pos1_;
  ushort mem_changed_pos2_;

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
  void setMemChanged(bool flag) { mem_changed_  = flag; }

  void memChanged(ushort pos, ushort len);
};

class CZ80MemData {
 protected:
  CZ80 z80_;

 public:
  CZ80MemData(CZ80 &z80) :
   z80_(z80) {
  }

  virtual ~CZ80MemData() { }

  virtual bool memRead(uchar *c, ushort pos, ushort len);

  virtual void memWrite(const uchar *c, ushort pos, ushort len);
};

#endif

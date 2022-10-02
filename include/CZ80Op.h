#ifndef CZ80Op_H
#define CZ80Op_H

enum CZ80ArgId {
  A_NONE    =0,

  A_NUM     =1,
  A_S_NUM   =2,
  A_P_NUM   =4,
  A_FLAG    =5,
  A_REG     =6,
  A_CONST   =7,
  A_P_REG   =8,
  A_PO_REG  =9,
  A_PO_REG_A=10,
  A_PO_REG_B=11,
  A_PO_REG_C=12,
  A_PO_REG_D=13,
  A_PO_REG_E=14,
  A_PO_REG_H=15,
  A_PO_REG_L=16
};

enum CZ80FlagId {
  F_NONE=-1,

  F_C=0,
  F_N,
  F_PE,
  F_H,
  F_Z,
  F_M,
  F_NC,
  F_PO,
  F_NZ,
  F_P
};

enum CZ80RegisterId {
  R_NONE=-1,

  R_A=0,
  R_B,
  R_C,
  R_D,
  R_E,
  R_F,
  R_H,
  R_L,
  R_IXL,
  R_IXH,
  R_IYL,
  R_IYH,
  R_I,
  R_R,
  R_SP,
  R_PC,
  R_AF,
  R_BC,
  R_DE,
  R_HL,
  R_IX,
  R_IY,
  R_A1,
  R_B1,
  R_C1,
  R_D1,
  R_E1,
  R_F1,
  R_H1,
  R_L1,
  R_AF1
};

// op indices (if change this then update cz80_op_names)
enum CZ80OpId {
  OP_NONE=-1,

  OP_ADC=0,
  OP_ADD,
  OP_AND,
  OP_BIT,
  OP_CALL,
  OP_CCF,
  OP_CP,
  OP_CPD,
  OP_CPDR,
  OP_CPI,
  OP_CPIR,
  OP_CPL,
  OP_DAA,
  OP_DEC,
  OP_DI,
  OP_DJNZ,
  OP_EI,
  OP_EX,
  OP_EXX,
  OP_HALT,
  OP_IM,
  OP_IN,
  OP_INC,
  OP_IND,
  OP_INDR,
  OP_INI,
  OP_INIR,
  OP_JP,
  OP_JR,
  OP_LD,
  OP_LDD,
  OP_LDDR,
  OP_LDI,
  OP_LDIR,
  OP_NEG,
  OP_NOP,
  OP_OR,
  OP_OTDR,
  OP_OTIR,
  OP_OUT,
  OP_OUTD,
  OP_OUTI,
  OP_POP,
  OP_PUSH,
  OP_RES,
  OP_RET,
  OP_RETI,
  OP_RETN,
  OP_RL,
  OP_RLA,
  OP_RLC,
  OP_RLCA,
  OP_RLD,
  OP_RR,
  OP_RRA,
  OP_RRC,
  OP_RRCA,
  OP_RRD,
  OP_RST,
  OP_SBC,
  OP_SCF,
  OP_SET,
  OP_SLA,
  OP_SLL,
  OP_SRA,
  OP_SRL,
  OP_SUB,
  OP_XOR
};

struct CZ80OpData;

struct CZ80Op {
  CZ80OpId    id    { OP_NOP }; // op id
  CZ80OpProcP func  { 0 };      // callback
  ushort      arg1  { 0 };      // first arg data
  ushort      type1 { 0 };      // first arg type
  ushort      arg2  { 0 };      // second arg data
  ushort      type2 { 0 };      // second arg type
  uchar       r     { 0 };      // register count
  ushort      t     { 0 };      // cycle count
  uchar       len   { 0 };      // instruction len
  ushort      ind   { 0 };      // index (auto set)
  ulong       count { 0 };      // execution count
  uchar       edata { 0 };      // execution data

  CZ80Op() { }

  CZ80Op(CZ80OpId id1, CZ80OpProcP func1, ushort arg11, ushort type11, ushort arg21, ushort type21,
         uchar r1, ushort t1) :
   id(id1), func(func1), arg1(arg11), type1(type11), arg2(arg21), type2(type21), r(r1), t(t1) {
  }

  const char *getName() const;

  void execute(CZ80OpData *opData) {
#ifdef CZ80_COUNT_CALLS
    ++count;
#endif

    if (func)
      (*func)(opData);
  }

  void dumpCount(std::ostream &os);

  std::string toTxt(ushort pc);

  std::string getCode();

  std::string getExtCode(uchar c);

  void getValues(uchar **values, uint *num_values);

  void getExtValues(uchar c, uchar **values, uint *num_values);

  bool cmp(const CZ80Op &op);

  uchar getSize();
};

extern const char *cz80_op_names[];
extern uint        cz80_num_op_names;

extern const char *cz80_flag_names[];
extern uint        cz80_num_flag_names;

extern const char *cz80_register_names[];
extern uint        cz80_num_register_names;

#endif

#ifndef CZ80Reg_H
#define CZ80Reg_H

// Registers

enum class CZ80Reg {
  NONE=0,

  A    =(1<< 0),
  B    =(1<< 1),
  C    =(1<< 2),
  D    =(1<< 3),
  E    =(1<< 4),
  F    =(1<< 5),
  H    =(1<< 6),
  L    =(1<< 7),
  IXL  =(1<< 8),
  IXH  =(1<< 9),
  IYL  =(1<<10),
  IYH  =(1<<11),
  SP   =(1<<12),
  PC   =(1<<13),
  A1   =(1<<14),
  B1   =(1<<15),
  C1   =(1<<16),
  D1   =(1<<17),
  E1   =(1<<18),
  F1   =(1<<19),
  H1   =(1<<20),
  L1   =(1<<21),
  I    =(1<<22),
  R    =(1<<23),
  IM   =(1<<24),
  IFF  =(1<<25),
  PHL  =(1<<26),
  PO_IX=(1<<27),
  PO_IY=(1<<28),
  N    =(1<<29),
  AF   =(A  |F),
  BC   =(B  |C),
  DE   =(D  |E),
  HL   =(H  |L),
  IX   =(IXH|IXL),
  IY   =(IYH|IYL),
  AF1  =(A1 |F1),
  BC1  =(B1 |C1),
  DE1  =(D1 |E1),
  HL1  =(H1 |L1)
};

#endif

#ifndef CZ80Registers_H
#define CZ80Registers_H

// Register Data
//  . Separate structure so can read/write as single value)
//  . Use unnamed unions for direct access to single or double registers

struct CZ80Registers {
  struct AF { uchar f_  ; uchar a_  ; };
  struct BC { uchar c_  ; uchar b_  ; };
  struct DE { uchar e_  ; uchar d_  ; };
  struct HL { uchar l_  ; uchar h_  ; };
  struct IX { uchar ixl_; uchar ixh_; };
  struct IY { uchar iyl_; uchar iyh_; };

  union { ushort af_; AF AF_; };
  union { ushort bc_; BC BC_; };
  union { ushort de_; DE DE_; };
  union { ushort hl_; HL HL_; };

  union { ushort af_1_; AF AF_1_; };
  union { ushort bc_1_; BC BC_1_; };
  union { ushort de_1_; DE DE_1_; };
  union { ushort hl_1_; HL HL_1_; };

  union { ushort ix_; IX IX_; };
  union { ushort iy_; IY IY_; };

  ushort sp_, pc_;

  uchar i_;

  uint r_; // use uint so can use as high res count for speed debug

  struct IFF { uchar iff1_; uchar iff2_; };

  union { ushort iff_; IFF IFF_; };

  uchar im_;
};

#endif

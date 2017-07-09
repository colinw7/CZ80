#ifndef CZ80Registers_H
#define CZ80Registers_H

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

#endif

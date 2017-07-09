#define TSTR(INSN,MEMOP,IY,IX,HL,DE,BC,FLAGS,ACC,SP) \
lab_##__MACRO_ID__: | \
  DEFB INSN | \
  DEFS expr(lab_##__MACRO_ID__+4-$),0 | \
  DEFW MEMOP,IY,IX,HL,DE,BC | \
  DEFB FLAGS | \
  DEFB ACC | \
  DEFW SP

#define TMSG(M) \
lab_##__MACRO_ID__: | \
  DEFB M | \
  DEFS expr(lab_##__MACRO_ID__+30-$),'.' | \
  DEFB '$'

; <adc,sbc> hl,<bc,de,hl,sp> (38,912 cycles)
adc16:
  DEFB 0xc7            ; flag mask
  TSTR((0xed,0x42),0x832c,0x4f88,0xf22b,0xb339,0x7e1f,0x1563,0xd3,0x89,0x465e)
  TSTR((0,0x38),0,0,0,0xf821,0,0,0,0,0)         ; (1024 cycles)
  TSTR(0,0,0,0,-1,-1,-1,0xd7,0,-1)              ; (38 cycles)
  DEFB 0xf8,0xb4,0xea,0xa9                     ; expected crc
  TMSG('<adc,sbc> hl,<bc,de,hl,sp>')

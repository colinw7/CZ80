; nop
0000 00          ; NOP
; ld   BC, 0x0000
0001 01 00 00    ; LD   BC, 0x0000
; ld   (BC), A
0004 02          ; LD   (BC), A
; inc  BC
0005 03          ; INC  BC
; inc  B
0006 04          ; INC  B
; dec  B
0007 05          ; DEC  B
; ld   B, 0x00
0008 06 00       ; LD   B, 0x00
; rlca
000a 07          ; RLCA
; ex   AF, AF'
000b 08          ; EX   AF, AF'
; add  HL, BC
000c 09          ; ADD  HL, BC
; ld   A, (BC)
000d 0a          ; LD   A, (BC)
; dec  BC
000e 0b          ; DEC  BC
; inc  C
000f 0c          ; INC  C
; dec  C
0010 0d          ; DEC  C
; ld   C, 0x00
0011 0e 00       ; LD   C, 0x00
; rrca
0013 0f          ; RRCA
; djnz +0x00
0014 10 00       ; DJNZ +0x00
; ld   DE, 0x0000
0016 11 00 00    ; LD   DE, 0x0000
; ld   (DE), A
0019 12          ; LD   (DE), A
; inc  DE
001a 13          ; INC  DE
; inc  D
001b 14          ; INC  D
; dec  D
001c 15          ; DEC  D
; ld   D, 0x00
001d 16 00       ; LD   D, 0x00
; rla
001f 17          ; RLA
; jr   +0x00
0020 18 00       ; JR   +0x00
; add  HL, DE
0022 19          ; ADD  HL, DE
; ld   A, (DE)
0023 1a          ; LD   A, (DE)
; dec  DE
0024 1b          ; DEC  DE
; inc  E
0025 1c          ; INC  E
; dec  E
0026 1d          ; DEC  E
; ld   E, 0x00
0027 1e 00       ; LD   E, 0x00
; rra
0029 1f          ; RRA
; jr   NZ, +0x00
002a 20 00       ; JR   NZ, +0x00
; ld   HL, 0x0000
002c 21 00 00    ; LD   HL, 0x0000
; ld   (0x0000), HL
002f 22 00 00    ; LD   (0x0000), HL
; inc  HL
0032 23          ; INC  HL
; inc  H
0033 24          ; INC  H
; dec  H
0034 25          ; DEC  H
; ld   H, 0x00
0035 26 00       ; LD   H, 0x00
; daa
0037 27          ; DAA
; jr   Z, +0x00
0038 28 00       ; JR   Z, +0x00
; add  HL, HL
003a 29          ; ADD  HL, HL
; ld   HL, (0x0000)
003b 2a 00 00    ; LD   HL, (0x0000)
; dec  HL
003e 2b          ; DEC  HL
; inc  L
003f 2c          ; INC  L
; dec  L
0040 2d          ; DEC  L
; ld   L, 0x00
0041 2e 00       ; LD   L, 0x00
; cpl
0043 2f          ; CPL
; jr   NC, +0x00
0044 30 00       ; JR   NC, +0x00
; ld   SP, 0x0000
0046 31 00 00    ; LD   SP, 0x0000
; ld   (0x0000), A
0049 32 00 00    ; LD   (0x0000), A
; inc  SP
004c 33          ; INC  SP
; inc  (HL)
004d 34          ; INC  (HL)
; dec  (HL)
004e 35          ; DEC  (HL)
; ld   (HL), 0x00
004f 36 00       ; LD   (HL), 0x00
; scf
0051 37          ; SCF
; jr   C, +0x00
0052 38 00       ; JR   C, +0x00
; add  HL, SP
0054 39          ; ADD  HL, SP
; ld   A, (0x0000)
0055 3a 00 00    ; LD   A, (0x0000)
; dec  SP
0058 3b          ; DEC  SP
; inc  A
0059 3c          ; INC  A
; dec  A
005a 3d          ; DEC  A
; ld   A, 0x00
005b 3e 00       ; LD   A, 0x00
; ccf
005d 3f          ; CCF
; ld   B, B
005e 40          ; LD   B, B
; ld   B, C
005f 41          ; LD   B, C
; ld   B, D
0060 42          ; LD   B, D
; ld   B, E
0061 43          ; LD   B, E
; ld   B, H
0062 44          ; LD   B, H
; ld   B, L
0063 45          ; LD   B, L
; ld   B, (HL)
0064 46          ; LD   B, (HL)
; ld   B, A
0065 47          ; LD   B, A
; ld   C, B
0066 48          ; LD   C, B
; ld   C, C
0067 49          ; LD   C, C
; ld   C, D
0068 4a          ; LD   C, D
; ld   C, E
0069 4b          ; LD   C, E
; ld   C, H
006a 4c          ; LD   C, H
; ld   C, L
006b 4d          ; LD   C, L
; ld   C, (HL)
006c 4e          ; LD   C, (HL)
; ld   C, A
006d 4f          ; LD   C, A
; ld   D, B
006e 50          ; LD   D, B
; ld   D, C
006f 51          ; LD   D, C
; ld   D, D
0070 52          ; LD   D, D
; ld   D, E
0071 53          ; LD   D, E
; ld   D, H
0072 54          ; LD   D, H
; ld   D, L
0073 55          ; LD   D, L
; ld   D, (HL)
0074 56          ; LD   D, (HL)
; ld   D, A
0075 57          ; LD   D, A
; ld   E, B
0076 58          ; LD   E, B
; ld   E, C
0077 59          ; LD   E, C
; ld   E, D
0078 5a          ; LD   E, D
; ld   E, E
0079 5b          ; LD   E, E
; ld   E, H
007a 5c          ; LD   E, H
; ld   E, L
007b 5d          ; LD   E, L
; ld   E, (HL)
007c 5e          ; LD   E, (HL)
; ld   E, A
007d 5f          ; LD   E, A
; ld   H, B
007e 60          ; LD   H, B
; ld   H, C
007f 61          ; LD   H, C
; ld   H, D
0080 62          ; LD   H, D
; ld   H, E
0081 63          ; LD   H, E
; ld   H, H
0082 64          ; LD   H, H
; ld   H, L
0083 65          ; LD   H, L
; ld   H, (HL)
0084 66          ; LD   H, (HL)
; ld   H, A
0085 67          ; LD   H, A
; ld   L, B
0086 68          ; LD   L, B
; ld   L, C
0087 69          ; LD   L, C
; ld   L, D
0088 6a          ; LD   L, D
; ld   L, E
0089 6b          ; LD   L, E
; ld   L, H
008a 6c          ; LD   L, H
; ld   L, L
008b 6d          ; LD   L, L
; ld   L, (HL)
008c 6e          ; LD   L, (HL)
; ld   L, A
008d 6f          ; LD   L, A
; ld   (HL), B
008e 70          ; LD   (HL), B
; ld   (HL), C
008f 71          ; LD   (HL), C
; ld   (HL), D
0090 72          ; LD   (HL), D
; ld   (HL), E
0091 73          ; LD   (HL), E
; ld   (HL), H
0092 74          ; LD   (HL), H
; ld   (HL), L
0093 75          ; LD   (HL), L
; halt
0094 76          ; HALT
; ld   (HL), A
0095 77          ; LD   (HL), A
; ld   A, B
0096 78          ; LD   A, B
; ld   A, C
0097 79          ; LD   A, C
; ld   A, D
0098 7a          ; LD   A, D
; ld   A, E
0099 7b          ; LD   A, E
; ld   A, H
009a 7c          ; LD   A, H
; ld   A, L
009b 7d          ; LD   A, L
; ld   A, (HL)
009c 7e          ; LD   A, (HL)
; ld   A, A
009d 7f          ; LD   A, A
; add  A, B
009e 80          ; ADD  A, B
; add  A, C
009f 81          ; ADD  A, C
; add  A, D
00a0 82          ; ADD  A, D
; add  A, E
00a1 83          ; ADD  A, E
; add  A, H
00a2 84          ; ADD  A, H
; add  A, L
00a3 85          ; ADD  A, L
; add  A, (HL)
00a4 86          ; ADD  A, (HL)
; add  A, A
00a5 87          ; ADD  A, A
; adc  A, B
00a6 88          ; ADC  A, B
; adc  A, C
00a7 89          ; ADC  A, C
; adc  A, D
00a8 8a          ; ADC  A, D
; adc  A, E
00a9 8b          ; ADC  A, E
; adc  A, H
00aa 8c          ; ADC  A, H
; adc  A, L
00ab 8d          ; ADC  A, L
; adc  A, (HL)
00ac 8e          ; ADC  A, (HL)
; adc  A, A
00ad 8f          ; ADC  A, A
; sub  B
00ae 90          ; SUB  B
; sub  C
00af 91          ; SUB  C
; sub  D
00b0 92          ; SUB  D
; sub  E
00b1 93          ; SUB  E
; sub  H
00b2 94          ; SUB  H
; sub  L
00b3 95          ; SUB  L
; sub  (HL)
00b4 96          ; SUB  (HL)
; sub  A
00b5 97          ; SUB  A
; sbc  A, B
00b6 98          ; SBC  A, B
; sbc  A, C
00b7 99          ; SBC  A, C
; sbc  A, D
00b8 9a          ; SBC  A, D
; sbc  A, E
00b9 9b          ; SBC  A, E
; sbc  A, H
00ba 9c          ; SBC  A, H
; sbc  A, L
00bb 9d          ; SBC  A, L
; sbc  A, (HL)
00bc 9e          ; SBC  A, (HL)
; sbc  A, A
00bd 9f          ; SBC  A, A
; and  B
00be a0          ; AND  B
; and  C
00bf a1          ; AND  C
; and  D
00c0 a2          ; AND  D
; and  E
00c1 a3          ; AND  E
; and  H
00c2 a4          ; AND  H
; and  L
00c3 a5          ; AND  L
; and  (HL)
00c4 a6          ; AND  (HL)
; and  A
00c5 a7          ; AND  A
; xor  B
00c6 a8          ; XOR  B
; xor  C
00c7 a9          ; XOR  C
; xor  D
00c8 aa          ; XOR  D
; xor  E
00c9 ab          ; XOR  E
; xor  H
00ca ac          ; XOR  H
; xor  L
00cb ad          ; XOR  L
; xor  (HL)
00cc ae          ; XOR  (HL)
; xor  A
00cd af          ; XOR  A
; or   B
00ce b0          ; OR   B
; or   C
00cf b1          ; OR   C
; or   D
00d0 b2          ; OR   D
; or   E
00d1 b3          ; OR   E
; or   H
00d2 b4          ; OR   H
; or   L
00d3 b5          ; OR   L
; or   (HL)
00d4 b6          ; OR   (HL)
; or   A
00d5 b7          ; OR   A
; cp   B
00d6 b8          ; CP   B
; cp   C
00d7 b9          ; CP   C
; cp   D
00d8 ba          ; CP   D
; cp   E
00d9 bb          ; CP   E
; cp   H
00da bc          ; CP   H
; cp   L
00db bd          ; CP   L
; cp   (HL)
00dc be          ; CP   (HL)
; cp   A
00dd bf          ; CP   A
; ret  NZ
00de c0          ; RET  NZ
; pop  BC
00df c1          ; POP  BC
; jp   NZ, 0x0000
00e0 c2 00 00    ; JP   NZ, 0x0000
; jp   0x0000
00e3 c3 00 00    ; JP   0x0000
; call NZ, 0x0000
00e6 c4 00 00    ; CALL NZ, 0x0000
; push BC
00e9 c5          ; PUSH BC
; add  A, 0x00
00ea c6 00       ; ADD  A, 0x00
; rst  0x00
00ec c7          ; RST  0x00
; ret  Z
00ed c8          ; RET  Z
; ret
00ee c9          ; RET
; jp   Z, 0x0000
00ef ca 00 00    ; JP   Z, 0x0000
; call Z, 0x0000
00f2 cc 00 00    ; CALL Z, 0x0000
; call 0x0000
00f5 cd 00 00    ; CALL 0x0000
; adc  A, 0x00
00f8 ce 00       ; ADC  A, 0x00
; rst  0x08
00fa cf          ; RST  0x08
; ret  NC
00fb d0          ; RET  NC
; pop  DE
00fc d1          ; POP  DE
; jp   NC, 0x0000
00fd d2 00 00    ; JP   NC, 0x0000
; out  (0x00), A
0100 d3 00 00    ; OUT  (0x00), A
; call NC, 0x0000
0102 d4 00 00    ; CALL NC, 0x0000
; push DE
0105 d5          ; PUSH DE
; sub  0x00
0106 d6 00       ; SUB  0x00
; rst  0x10
0108 d7          ; RST  0x10
; ret  C
0109 d8          ; RET  C
; exx
010a d9          ; EXX
; jp   C, 0x0000
010b da 00 00    ; JP   C, 0x0000
; in   A, (0x00)
010e db 00 00    ; IN   A, (0x00)
; call C, 0x0000
0110 dc 00 00    ; CALL C, 0x0000
; sbc  A, 0x00
0113 de 00       ; SBC  A, 0x00
; rst  0x18
0115 df          ; RST  0x18
; ret  PO
0116 e0          ; RET  PO
; pop  HL
0117 e1          ; POP  HL
; jp   PO, 0x0000
0118 e2 00 00    ; JP   PO, 0x0000
; ex   (SP), HL
011b e3          ; EX   (SP), HL
; call PO, 0x0000
011c e4 00 00    ; CALL PO, 0x0000
; push HL
011f e5          ; PUSH HL
; and  0x00
0120 e6 00       ; AND  0x00
; rst  0x20
0122 e7          ; RST  0x20
; ret  PE
0123 e8          ; RET  PE
; jp   HL
0124 e9          ; JP   HL
; jp   PE, 0x0000
0125 ea 00 00    ; JP   PE, 0x0000
; ex   DE, HL
0128 eb          ; EX   DE, HL
; call PE, 0x0000
0129 ec 00 00    ; CALL PE, 0x0000
; xor  0x00
012c ee 00       ; XOR  0x00
; rst  0x28
012e ef          ; RST  0x28
; ret  P
012f f0          ; RET  P
; pop  AF
0130 f1          ; POP  AF
; jp   P, 0x0000
0131 f2 00 00    ; JP   P, 0x0000
; di
0134 f3          ; DI
; call P, 0x0000
0135 f4 00 00    ; CALL P, 0x0000
; push AF
0138 f5          ; PUSH AF
; or   0x00
0139 f6 00       ; OR   0x00
; rst  0x30
013b f7          ; RST  0x30
; ret  M
013c f8          ; RET  M
; ld   SP, HL
013d f9          ; LD   SP, HL
; jp   M, 0x0000
013e fa 00 00    ; JP   M, 0x0000
; ei
0141 fb          ; EI
; call M, 0x0000
0142 fc 00 00    ; CALL M, 0x0000
; cp   0x00
0145 fe 00       ; CP   0x00
; rst  0x38
0147 ff          ; RST  0x38
; rlc  B
0148 cb 00       ; RLC  B
; rlc  C
014a cb 01       ; RLC  C
; rlc  D
014c cb 02       ; RLC  D
; rlc  E
014e cb 03       ; RLC  E
; rlc  H
0150 cb 04       ; RLC  H
; rlc  L
0152 cb 05       ; RLC  L
; rlc  (HL)
0154 cb 06       ; RLC  (HL)
; rlc  A
0156 cb 07       ; RLC  A
; rrc  B
0158 cb 08       ; RRC  B
; rrc  C
015a cb 09       ; RRC  C
; rrc  D
015c cb 0a       ; RRC  D
; rrc  E
015e cb 0b       ; RRC  E
; rrc  H
0160 cb 0c       ; RRC  H
; rrc  L
0162 cb 0d       ; RRC  L
; rrc  (HL)
0164 cb 0e       ; RRC  (HL)
; rrc  A
0166 cb 0f       ; RRC  A
; rl   B
0168 cb 10       ; RL   B
; rl   C
016a cb 11       ; RL   C
; rl   D
016c cb 12       ; RL   D
; rl   E
016e cb 13       ; RL   E
; rl   H
0170 cb 14       ; RL   H
; rl   L
0172 cb 15       ; RL   L
; rl   (HL)
0174 cb 16       ; RL   (HL)
; rl   A
0176 cb 17       ; RL   A
; rr   B
0178 cb 18       ; RR   B
; rr   C
017a cb 19       ; RR   C
; rr   D
017c cb 1a       ; RR   D
; rr   E
017e cb 1b       ; RR   E
; rr   H
0180 cb 1c       ; RR   H
; rr   L
0182 cb 1d       ; RR   L
; rr   (HL)
0184 cb 1e       ; RR   (HL)
; rr   A
0186 cb 1f       ; RR   A
; sla  B
0188 cb 20       ; SLA  B
; sla  C
018a cb 21       ; SLA  C
; sla  D
018c cb 22       ; SLA  D
; sla  E
018e cb 23       ; SLA  E
; sla  H
0190 cb 24       ; SLA  H
; sla  L
0192 cb 25       ; SLA  L
; sla  (HL)
0194 cb 26       ; SLA  (HL)
; sla  A
0196 cb 27       ; SLA  A
; sra  B
0198 cb 28       ; SRA  B
; sra  C
019a cb 29       ; SRA  C
; sra  D
019c cb 2a       ; SRA  D
; sra  E
019e cb 2b       ; SRA  E
; sra  H
01a0 cb 2c       ; SRA  H
; sra  L
01a2 cb 2d       ; SRA  L
; sra  (HL)
01a4 cb 2e       ; SRA  (HL)
; sra  A
01a6 cb 2f       ; SRA  A
; sll  B
01a8 cb 30       ; SLL  B
; sll  C
01aa cb 31       ; SLL  C
; sll  D
01ac cb 32       ; SLL  D
; sll  E
01ae cb 33       ; SLL  E
; sll  H
01b0 cb 34       ; SLL  H
; sll  L
01b2 cb 35       ; SLL  L
; sll  (HL)
01b4 cb 36       ; SLL  (HL)
; sll  A
01b6 cb 37       ; SLL  A
; srl  B
01b8 cb 38       ; SRL  B
; srl  C
01ba cb 39       ; SRL  C
; srl  D
01bc cb 3a       ; SRL  D
; srl  E
01be cb 3b       ; SRL  E
; srl  H
01c0 cb 3c       ; SRL  H
; srl  L
01c2 cb 3d       ; SRL  L
; srl  (HL)
01c4 cb 3e       ; SRL  (HL)
; srl  A
01c6 cb 3f       ; SRL  A
; bit  0x00, B
01c8 cb 40       ; BIT  0x00, B
; bit  0x00, C
01ca cb 41       ; BIT  0x00, C
; bit  0x00, D
01cc cb 42       ; BIT  0x00, D
; bit  0x00, E
01ce cb 43       ; BIT  0x00, E
; bit  0x00, H
01d0 cb 44       ; BIT  0x00, H
; bit  0x00, L
01d2 cb 45       ; BIT  0x00, L
; bit  0x00, (HL)
01d4 cb 46       ; BIT  0x00, (HL)
; bit  0x00, A
01d6 cb 47       ; BIT  0x00, A
; bit  0x01, B
01d8 cb 48       ; BIT  0x01, B
; bit  0x01, C
01da cb 49       ; BIT  0x01, C
; bit  0x01, D
01dc cb 4a       ; BIT  0x01, D
; bit  0x01, E
01de cb 4b       ; BIT  0x01, E
; bit  0x01, H
01e0 cb 4c       ; BIT  0x01, H
; bit  0x01, L
01e2 cb 4d       ; BIT  0x01, L
; bit  0x01, (HL)
01e4 cb 4e       ; BIT  0x01, (HL)
; bit  0x01, A
01e6 cb 4f       ; BIT  0x01, A
; bit  0x02, B
01e8 cb 50       ; BIT  0x02, B
; bit  0x02, C
01ea cb 51       ; BIT  0x02, C
; bit  0x02, D
01ec cb 52       ; BIT  0x02, D
; bit  0x02, E
01ee cb 53       ; BIT  0x02, E
; bit  0x02, H
01f0 cb 54       ; BIT  0x02, H
; bit  0x02, L
01f2 cb 55       ; BIT  0x02, L
; bit  0x02, (HL)
01f4 cb 56       ; BIT  0x02, (HL)
; bit  0x02, A
01f6 cb 57       ; BIT  0x02, A
; bit  0x03, B
01f8 cb 58       ; BIT  0x03, B
; bit  0x03, C
01fa cb 59       ; BIT  0x03, C
; bit  0x03, D
01fc cb 5a       ; BIT  0x03, D
; bit  0x03, E
01fe cb 5b       ; BIT  0x03, E
; bit  0x03, H
0200 cb 5c       ; BIT  0x03, H
; bit  0x03, L
0202 cb 5d       ; BIT  0x03, L
; bit  0x03, (HL)
0204 cb 5e       ; BIT  0x03, (HL)
; bit  0x03, A
0206 cb 5f       ; BIT  0x03, A
; bit  0x04, B
0208 cb 60       ; BIT  0x04, B
; bit  0x04, C
020a cb 61       ; BIT  0x04, C
; bit  0x04, D
020c cb 62       ; BIT  0x04, D
; bit  0x04, E
020e cb 63       ; BIT  0x04, E
; bit  0x04, H
0210 cb 64       ; BIT  0x04, H
; bit  0x04, L
0212 cb 65       ; BIT  0x04, L
; bit  0x04, (HL)
0214 cb 66       ; BIT  0x04, (HL)
; bit  0x04, A
0216 cb 67       ; BIT  0x04, A
; bit  0x05, B
0218 cb 68       ; BIT  0x05, B
; bit  0x05, C
021a cb 69       ; BIT  0x05, C
; bit  0x05, D
021c cb 6a       ; BIT  0x05, D
; bit  0x05, E
021e cb 6b       ; BIT  0x05, E
; bit  0x05, H
0220 cb 6c       ; BIT  0x05, H
; bit  0x05, L
0222 cb 6d       ; BIT  0x05, L
; bit  0x05, (HL)
0224 cb 6e       ; BIT  0x05, (HL)
; bit  0x05, A
0226 cb 6f       ; BIT  0x05, A
; bit  0x06, B
0228 cb 70       ; BIT  0x06, B
; bit  0x06, C
022a cb 71       ; BIT  0x06, C
; bit  0x06, D
022c cb 72       ; BIT  0x06, D
; bit  0x06, E
022e cb 73       ; BIT  0x06, E
; bit  0x06, H
0230 cb 74       ; BIT  0x06, H
; bit  0x06, L
0232 cb 75       ; BIT  0x06, L
; bit  0x06, (HL)
0234 cb 76       ; BIT  0x06, (HL)
; bit  0x06, A
0236 cb 77       ; BIT  0x06, A
; bit  0x07, B
0238 cb 78       ; BIT  0x07, B
; bit  0x07, C
023a cb 79       ; BIT  0x07, C
; bit  0x07, D
023c cb 7a       ; BIT  0x07, D
; bit  0x07, E
023e cb 7b       ; BIT  0x07, E
; bit  0x07, H
0240 cb 7c       ; BIT  0x07, H
; bit  0x07, L
0242 cb 7d       ; BIT  0x07, L
; bit  0x07, (HL)
0244 cb 7e       ; BIT  0x07, (HL)
; bit  0x07, A
0246 cb 7f       ; BIT  0x07, A
; res  0x00, B
0248 cb 80       ; RES  0x00, B
; res  0x00, C
024a cb 81       ; RES  0x00, C
; res  0x00, D
024c cb 82       ; RES  0x00, D
; res  0x00, E
024e cb 83       ; RES  0x00, E
; res  0x00, H
0250 cb 84       ; RES  0x00, H
; res  0x00, L
0252 cb 85       ; RES  0x00, L
; res  0x00, (HL)
0254 cb 86       ; RES  0x00, (HL)
; res  0x00, A
0256 cb 87       ; RES  0x00, A
; res  0x01, B
0258 cb 88       ; RES  0x01, B
; res  0x01, C
025a cb 89       ; RES  0x01, C
; res  0x01, D
025c cb 8a       ; RES  0x01, D
; res  0x01, E
025e cb 8b       ; RES  0x01, E
; res  0x01, H
0260 cb 8c       ; RES  0x01, H
; res  0x01, L
0262 cb 8d       ; RES  0x01, L
; res  0x01, (HL)
0264 cb 8e       ; RES  0x01, (HL)
; res  0x01, A
0266 cb 8f       ; RES  0x01, A
; res  0x02, B
0268 cb 90       ; RES  0x02, B
; res  0x02, C
026a cb 91       ; RES  0x02, C
; res  0x02, D
026c cb 92       ; RES  0x02, D
; res  0x02, E
026e cb 93       ; RES  0x02, E
; res  0x02, H
0270 cb 94       ; RES  0x02, H
; res  0x02, L
0272 cb 95       ; RES  0x02, L
; res  0x02, (HL)
0274 cb 96       ; RES  0x02, (HL)
; res  0x02, A
0276 cb 97       ; RES  0x02, A
; res  0x03, B
0278 cb 98       ; RES  0x03, B
; res  0x03, C
027a cb 99       ; RES  0x03, C
; res  0x03, D
027c cb 9a       ; RES  0x03, D
; res  0x03, E
027e cb 9b       ; RES  0x03, E
; res  0x03, H
0280 cb 9c       ; RES  0x03, H
; res  0x03, L
0282 cb 9d       ; RES  0x03, L
; res  0x03, (HL)
0284 cb 9e       ; RES  0x03, (HL)
; res  0x03, A
0286 cb 9f       ; RES  0x03, A
; res  0x04, B
0288 cb a0       ; RES  0x04, B
; res  0x04, C
028a cb a1       ; RES  0x04, C
; res  0x04, D
028c cb a2       ; RES  0x04, D
; res  0x04, E
028e cb a3       ; RES  0x04, E
; res  0x04, H
0290 cb a4       ; RES  0x04, H
; res  0x04, L
0292 cb a5       ; RES  0x04, L
; res  0x04, (HL)
0294 cb a6       ; RES  0x04, (HL)
; res  0x04, A
0296 cb a7       ; RES  0x04, A
; res  0x05, B
0298 cb a8       ; RES  0x05, B
; res  0x05, C
029a cb a9       ; RES  0x05, C
; res  0x05, D
029c cb aa       ; RES  0x05, D
; res  0x05, E
029e cb ab       ; RES  0x05, E
; res  0x05, H
02a0 cb ac       ; RES  0x05, H
; res  0x05, L
02a2 cb ad       ; RES  0x05, L
; res  0x05, (HL)
02a4 cb ae       ; RES  0x05, (HL)
; res  0x05, A
02a6 cb af       ; RES  0x05, A
; res  0x06, B
02a8 cb b0       ; RES  0x06, B
; res  0x06, C
02aa cb b1       ; RES  0x06, C
; res  0x06, D
02ac cb b2       ; RES  0x06, D
; res  0x06, E
02ae cb b3       ; RES  0x06, E
; res  0x06, H
02b0 cb b4       ; RES  0x06, H
; res  0x06, L
02b2 cb b5       ; RES  0x06, L
; res  0x06, (HL)
02b4 cb b6       ; RES  0x06, (HL)
; res  0x06, A
02b6 cb b7       ; RES  0x06, A
; res  0x07, B
02b8 cb b8       ; RES  0x07, B
; res  0x07, C
02ba cb b9       ; RES  0x07, C
; res  0x07, D
02bc cb ba       ; RES  0x07, D
; res  0x07, E
02be cb bb       ; RES  0x07, E
; res  0x07, H
02c0 cb bc       ; RES  0x07, H
; res  0x07, L
02c2 cb bd       ; RES  0x07, L
; res  0x07, (HL)
02c4 cb be       ; RES  0x07, (HL)
; res  0x07, A
02c6 cb bf       ; RES  0x07, A
; set  0x00, B
02c8 cb c0       ; SET  0x00, B
; set  0x00, C
02ca cb c1       ; SET  0x00, C
; set  0x00, D
02cc cb c2       ; SET  0x00, D
; set  0x00, E
02ce cb c3       ; SET  0x00, E
; set  0x00, H
02d0 cb c4       ; SET  0x00, H
; set  0x00, L
02d2 cb c5       ; SET  0x00, L
; set  0x00, (HL)
02d4 cb c6       ; SET  0x00, (HL)
; set  0x00, A
02d6 cb c7       ; SET  0x00, A
; set  0x01, B
02d8 cb c8       ; SET  0x01, B
; set  0x01, C
02da cb c9       ; SET  0x01, C
; set  0x01, D
02dc cb ca       ; SET  0x01, D
; set  0x01, E
02de cb cb       ; SET  0x01, E
; set  0x01, H
02e0 cb cc       ; SET  0x01, H
; set  0x01, L
02e2 cb cd       ; SET  0x01, L
; set  0x01, (HL)
02e4 cb ce       ; SET  0x01, (HL)
; set  0x01, A
02e6 cb cf       ; SET  0x01, A
; set  0x02, B
02e8 cb d0       ; SET  0x02, B
; set  0x02, C
02ea cb d1       ; SET  0x02, C
; set  0x02, D
02ec cb d2       ; SET  0x02, D
; set  0x02, E
02ee cb d3       ; SET  0x02, E
; set  0x02, H
02f0 cb d4       ; SET  0x02, H
; set  0x02, L
02f2 cb d5       ; SET  0x02, L
; set  0x02, (HL)
02f4 cb d6       ; SET  0x02, (HL)
; set  0x02, A
02f6 cb d7       ; SET  0x02, A
; set  0x03, B
02f8 cb d8       ; SET  0x03, B
; set  0x03, C
02fa cb d9       ; SET  0x03, C
; set  0x03, D
02fc cb da       ; SET  0x03, D
; set  0x03, E
02fe cb db       ; SET  0x03, E
; set  0x03, H
0300 cb dc       ; SET  0x03, H
; set  0x03, L
0302 cb dd       ; SET  0x03, L
; set  0x03, (HL)
0304 cb de       ; SET  0x03, (HL)
; set  0x03, A
0306 cb df       ; SET  0x03, A
; set  0x04, B
0308 cb e0       ; SET  0x04, B
; set  0x04, C
030a cb e1       ; SET  0x04, C
; set  0x04, D
030c cb e2       ; SET  0x04, D
; set  0x04, E
030e cb e3       ; SET  0x04, E
; set  0x04, H
0310 cb e4       ; SET  0x04, H
; set  0x04, L
0312 cb e5       ; SET  0x04, L
; set  0x04, (HL)
0314 cb e6       ; SET  0x04, (HL)
; set  0x04, A
0316 cb e7       ; SET  0x04, A
; set  0x05, B
0318 cb e8       ; SET  0x05, B
; set  0x05, C
031a cb e9       ; SET  0x05, C
; set  0x05, D
031c cb ea       ; SET  0x05, D
; set  0x05, E
031e cb eb       ; SET  0x05, E
; set  0x05, H
0320 cb ec       ; SET  0x05, H
; set  0x05, L
0322 cb ed       ; SET  0x05, L
; set  0x05, (HL)
0324 cb ee       ; SET  0x05, (HL)
; set  0x05, A
0326 cb ef       ; SET  0x05, A
; set  0x06, B
0328 cb f0       ; SET  0x06, B
; set  0x06, C
032a cb f1       ; SET  0x06, C
; set  0x06, D
032c cb f2       ; SET  0x06, D
; set  0x06, E
032e cb f3       ; SET  0x06, E
; set  0x06, H
0330 cb f4       ; SET  0x06, H
; set  0x06, L
0332 cb f5       ; SET  0x06, L
; set  0x06, (HL)
0334 cb f6       ; SET  0x06, (HL)
; set  0x06, A
0336 cb f7       ; SET  0x06, A
; set  0x07, B
0338 cb f8       ; SET  0x07, B
; set  0x07, C
033a cb f9       ; SET  0x07, C
; set  0x07, D
033c cb fa       ; SET  0x07, D
; set  0x07, E
033e cb fb       ; SET  0x07, E
; set  0x07, H
0340 cb fc       ; SET  0x07, H
; set  0x07, L
0342 cb fd       ; SET  0x07, L
; set  0x07, (HL)
0344 cb fe       ; SET  0x07, (HL)
; set  0x07, A
0346 cb ff       ; SET  0x07, A
; nop
0348 00          ; NOP
; ld   BC, 0x0000
0349 01 00 00    ; LD   BC, 0x0000
; ld   (BC), A
034c 02          ; LD   (BC), A
; inc  BC
034d 03          ; INC  BC
; inc  B
034e 04          ; INC  B
; dec  B
034f 05          ; DEC  B
; ld   B, 0x00
0350 06 00       ; LD   B, 0x00
; rlca
0352 07          ; RLCA
; ex   AF, AF'
0353 08          ; EX   AF, AF'
; add  IX, BC
0354 dd 09       ; ADD  IX, BC
; ld   A, (BC)
0356 0a          ; LD   A, (BC)
; dec  BC
0357 0b          ; DEC  BC
; inc  C
0358 0c          ; INC  C
; dec  C
0359 0d          ; DEC  C
; ld   C, 0x00
035a 0e 00       ; LD   C, 0x00
; rrca
035c 0f          ; RRCA
; djnz +0x00
035d 10 00       ; DJNZ +0x00
; ld   DE, 0x0000
035f 11 00 00    ; LD   DE, 0x0000
; ld   (DE), A
0362 12          ; LD   (DE), A
; inc  DE
0363 13          ; INC  DE
; inc  D
0364 14          ; INC  D
; dec  D
0365 15          ; DEC  D
; ld   D, 0x00
0366 16 00       ; LD   D, 0x00
; rla
0368 17          ; RLA
; jr   +0x00
0369 18 00       ; JR   +0x00
; add  IX, DE
036b dd 19       ; ADD  IX, DE
; ld   A, (DE)
036d 1a          ; LD   A, (DE)
; dec  DE
036e 1b          ; DEC  DE
; inc  E
036f 1c          ; INC  E
; dec  E
0370 1d          ; DEC  E
; ld   E, 0x00
0371 1e 00       ; LD   E, 0x00
; rra
0373 1f          ; RRA
; jr   NZ, +0x00
0374 20 00       ; JR   NZ, +0x00
; ld   IX, 0x0000
0376 dd 21 00 00 ; LD   IX, 0x0000
; ld   (0x0000), IX
037a dd 22 00 00 ; LD   (0x0000), IX
; inc  IX
037e dd 23       ; INC  IX
; inc  IXh
0380 dd 24       ; INC  IXh
; dec  IXh
0382 dd 25       ; DEC  IXh
; ld   IXh, 0x00
0384 dd 26 00    ; LD   IXh, 0x00
; daa
0387 27          ; DAA
; jr   Z, +0x00
0388 28 00       ; JR   Z, +0x00
; add  IX, IX
038a dd 29       ; ADD  IX, IX
; ld   IX, (0x0000)
038c dd 2a 00 00 ; LD   IX, (0x0000)
; dec  IX
0390 dd 2b       ; DEC  IX
; inc  IXl
0392 dd 2c       ; INC  IXl
; dec  IXl
0394 dd 2d       ; DEC  IXl
; ld   IXl, 0x00
0396 dd 2e 00    ; LD   IXl, 0x00
; cpl
0399 2f          ; CPL
; jr   NC, +0x00
039a 30 00       ; JR   NC, +0x00
; ld   SP, 0x0000
039c 31 00 00    ; LD   SP, 0x0000
; ld   (0x0000), A
039f 32 00 00    ; LD   (0x0000), A
; inc  SP
03a2 33          ; INC  SP
; inc  (IX+0x00)
03a3 dd 34 00    ; INC  (IX+0x00)
; dec  (IX+0x00)
03a7 dd 35 00    ; DEC  (IX+0x00)
; ld   (IX+0x00), 0x00
03ab dd 36 00 00 ; LD   (IX+0x00), 0x00
; scf
03af 37          ; SCF
; jr   C, +0x00
03b0 38 00       ; JR   C, +0x00
; add  IX, SP
03b2 dd 39       ; ADD  IX, SP
; ld   A, (0x0000)
03b4 3a 00 00    ; LD   A, (0x0000)
; dec  SP
03b7 3b          ; DEC  SP
; inc  A
03b8 3c          ; INC  A
; dec  A
03b9 3d          ; DEC  A
; ld   A, 0x00
03ba 3e 00       ; LD   A, 0x00
; ccf
03bc 3f          ; CCF
; ld   B, B
03bd 40          ; LD   B, B
; ld   B, C
03be 41          ; LD   B, C
; ld   B, D
03bf 42          ; LD   B, D
; ld   B, E
03c0 43          ; LD   B, E
; ld   B, IXh
03c1 dd 44       ; LD   B, IXh
; ld   B, IXl
03c3 dd 45       ; LD   B, IXl
; ld   B, (IX+0x00)
03c5 dd 46 00    ; LD   B, (IX+0x00)
; ld   B, A
03c7 47          ; LD   B, A
; ld   C, B
03c8 48          ; LD   C, B
; ld   C, C
03c9 49          ; LD   C, C
; ld   C, D
03ca 4a          ; LD   C, D
; ld   C, E
03cb 4b          ; LD   C, E
; ld   C, IXh
03cc dd 4c       ; LD   C, IXh
; ld   C, IXl
03ce dd 4d       ; LD   C, IXl
; ld   C, (IX+0x00)
03d0 dd 4e 00    ; LD   C, (IX+0x00)
; ld   C, A
03d2 4f          ; LD   C, A
; ld   D, B
03d3 50          ; LD   D, B
; ld   D, C
03d4 51          ; LD   D, C
; ld   D, D
03d5 52          ; LD   D, D
; ld   D, E
03d6 53          ; LD   D, E
; ld   D, IXh
03d7 dd 54       ; LD   D, IXh
; ld   D, IXl
03d9 dd 55       ; LD   D, IXl
; ld   D, (IX+0x00)
03db dd 56 00    ; LD   D, (IX+0x00)
; ld   D, A
03dd 57          ; LD   D, A
; ld   E, B
03de 58          ; LD   E, B
; ld   E, C
03df 59          ; LD   E, C
; ld   E, D
03e0 5a          ; LD   E, D
; ld   E, E
03e1 5b          ; LD   E, E
; ld   E, IXh
03e2 dd 5c       ; LD   E, IXh
; ld   E, IXl
03e4 dd 5d       ; LD   E, IXl
; ld   E, (IX+0x00)
03e6 dd 5e 00    ; LD   E, (IX+0x00)
; ld   E, A
03e8 5f          ; LD   E, A
; ld   IXh, B
03e9 dd 60       ; LD   IXh, B
; ld   IXh, C
03eb dd 61       ; LD   IXh, C
; ld   IXh, D
03ed dd 62       ; LD   IXh, D
; ld   IXh, E
03ef dd 63       ; LD   IXh, E
; ld   IXh, IXh
03f1 dd 64       ; LD   IXh, IXh
; ld   IXh, IXl
03f3 dd 65       ; LD   IXh, IXl
; ld   H, (IX+0x00)
03f5 dd 66 00    ; LD   H, (IX+0x00)
; ld   IXh, A
03f7 dd 67       ; LD   IXh, A
; ld   IXl, B
03f9 dd 68       ; LD   IXl, B
; ld   IXl, C
03fb dd 69       ; LD   IXl, C
; ld   IXl, D
03fd dd 6a       ; LD   IXl, D
; ld   IXl, E
03ff dd 6b       ; LD   IXl, E
; ld   IXl, H
0401 dd 6c       ; LD   IXl, H
; ld   IXl, IXl
0403 dd 6d       ; LD   IXl, IXl
; ld   L, (IX+0x00)
0405 dd 6e 00    ; LD   L, (IX+0x00)
; ld   IXl, A
0407 dd 6f       ; LD   IXl, A
; ld   (IX+0x00), B
0409 dd 70 00    ; LD   (IX+0x00), B
; ld   (IX+0x00), C
040d dd 71 00    ; LD   (IX+0x00), C
; ld   (IX+0x00), D
0411 dd 72 00    ; LD   (IX+0x00), D
; ld   (IX+0x00), E
0415 dd 73 00    ; LD   (IX+0x00), E
; ld   (IX+0x00), H
0419 dd 74 00    ; LD   (IX+0x00), H
; ld   (IX+0x00), L
041d dd 75 00    ; LD   (IX+0x00), L
; halt
0421 76          ; HALT
; ld   (IX+0x00), A
0422 dd 77 00    ; LD   (IX+0x00), A
; ld   A, B
0426 78          ; LD   A, B
; ld   A, C
0427 79          ; LD   A, C
; ld   A, D
0428 7a          ; LD   A, D
; ld   A, E
0429 7b          ; LD   A, E
; ld   A, IXh
042a dd 7c       ; LD   A, IXh
; ld   A, IXl
042c dd 7d       ; LD   A, IXl
; ld   A, (IX+0x00)
042e dd 7e 00    ; LD   A, (IX+0x00)
; ld   A, A
0430 7f          ; LD   A, A
; add  A, B
0431 80          ; ADD  A, B
; add  A, C
0432 81          ; ADD  A, C
; add  A, D
0433 82          ; ADD  A, D
; add  A, E
0434 83          ; ADD  A, E
; add  A, IXh
0435 dd 84       ; ADD  A, IXh
; add  A, IXl
0437 dd 85       ; ADD  A, IXl
; add  A, (IX+0x00)
0439 dd 86 00    ; ADD  A, (IX+0x00)
; add  A, A
043b 87          ; ADD  A, A
; adc  A, B
043c 88          ; ADC  A, B
; adc  A, C
043d 89          ; ADC  A, C
; adc  A, D
043e 8a          ; ADC  A, D
; adc  A, E
043f 8b          ; ADC  A, E
; adc  A, IXh
0440 dd 8c       ; ADC  A, IXh
; adc  A, IXl
0442 dd 8d       ; ADC  A, IXl
; adc  A, (IX+0x00)
0444 dd 8e 00    ; ADC  A, (IX+0x00)
; adc  A, A
0446 8f          ; ADC  A, A
; sub  B
0447 90          ; SUB  B
; sub  C
0448 91          ; SUB  C
; sub  D
0449 92          ; SUB  D
; sub  E
044a 93          ; SUB  E
; sub  IXh
044b dd 94       ; SUB  IXh
; sub  IXl
044d dd 95       ; SUB  IXl
; sub  (IX+0x00)
044f dd 96 00    ; SUB  (IX+0x00)
; sub  A
0453 97          ; SUB  A
; sbc  A, B
0454 98          ; SBC  A, B
; sbc  A, C
0455 99          ; SBC  A, C
; sbc  A, D
0456 9a          ; SBC  A, D
; sbc  A, E
0457 9b          ; SBC  A, E
; sbc  A, IXh
0458 dd 9c       ; SBC  A, IXh
; sbc  A, IXl
045a dd 9d       ; SBC  A, IXl
; sbc  (IX+0x00)
045c dd 9e 00    ; SBC  (IX+0x00)
; sbc  A, A
0460 9f          ; SBC  A, A
; and  B
0461 a0          ; AND  B
; and  C
0462 a1          ; AND  C
; and  D
0463 a2          ; AND  D
; and  E
0464 a3          ; AND  E
; and  IXh
0465 dd a4       ; AND  IXh
; and  IXl
0467 dd a5       ; AND  IXl
; and  (IX+0x00)
0469 dd a6 00    ; AND  (IX+0x00)
; and  A
046d a7          ; AND  A
; xor  B
046e a8          ; XOR  B
; xor  C
046f a9          ; XOR  C
; xor  D
0470 aa          ; XOR  D
; xor  E
0471 ab          ; XOR  E
; xor  IXh
0472 dd ac       ; XOR  IXh
; xor  IXl
0474 dd ad       ; XOR  IXl
; xor  (IX+0x00)
0476 dd ae 00    ; XOR  (IX+0x00)
; xor  A
047a af          ; XOR  A
; or   B
047b b0          ; OR   B
; or   C
047c b1          ; OR   C
; or   D
047d b2          ; OR   D
; or   E
047e b3          ; OR   E
; or   IXh
047f dd b4       ; OR   IXh
; or   IXl
0481 dd b5       ; OR   IXl
; or   (IX+0x00)
0483 dd b6 00    ; OR   (IX+0x00)
; or   A
0487 b7          ; OR   A
; cp   B
0488 b8          ; CP   B
; cp   C
0489 b9          ; CP   C
; cp   D
048a ba          ; CP   D
; cp   E
048b bb          ; CP   E
; cp   IXh
048c dd bc       ; CP   IXh
; cp   IXl
048e dd bd       ; CP   IXl
; cp   (IX+0x00)
0490 dd be 00    ; CP   (IX+0x00)
; cp   A
0494 bf          ; CP   A
; ret  NZ
0495 c0          ; RET  NZ
; pop  BC
0496 c1          ; POP  BC
; jp   NZ, 0x0000
0497 c2 00 00    ; JP   NZ, 0x0000
; jp   0x0000
049a c3 00 00    ; JP   0x0000
; call NZ, 0x0000
049d c4 00 00    ; CALL NZ, 0x0000
; push BC
04a0 c5          ; PUSH BC
; add  A, 0x00
04a1 c6 00       ; ADD  A, 0x00
; rst  0x00
04a3 c7          ; RST  0x00
; ret  Z
04a4 c8          ; RET  Z
; ret
04a5 c9          ; RET
; jp   Z, 0x0000
04a6 ca 00 00    ; JP   Z, 0x0000
; call Z, 0x0000
04a9 cc 00 00    ; CALL Z, 0x0000
; call 0x0000
04ac cd 00 00    ; CALL 0x0000
; adc  A, 0x00
04af ce 00       ; ADC  A, 0x00
; rst  0x08
04b1 cf          ; RST  0x08
; ret  NC
04b2 d0          ; RET  NC
; pop  DE
04b3 d1          ; POP  DE
; jp   NC, 0x0000
04b4 d2 00 00    ; JP   NC, 0x0000
; out  (0x00), A
04b7 d3 00 00    ; OUT  (0x00), A
; call NC, 0x0000
04b9 d4 00 00    ; CALL NC, 0x0000
; push DE
04bc d5          ; PUSH DE
; sub  0x00
04bd d6 00       ; SUB  0x00
; rst  0x10
04bf d7          ; RST  0x10
; ret  C
04c0 d8          ; RET  C
; exx
04c1 d9          ; EXX
; jp   C, 0x0000
04c2 da 00 00    ; JP   C, 0x0000
; in   A, (0x00)
04c5 db 00 00    ; IN   A, (0x00)
; call C, 0x0000
04c7 dc 00 00    ; CALL C, 0x0000
; sbc  A, 0x00
04ca de 00       ; SBC  A, 0x00
; rst  0x18
04cc df          ; RST  0x18
; ret  PO
04cd e0          ; RET  PO
; pop  IX
04ce dd e1       ; POP  IX
; jp   PO, 0x0000
04d0 e2 00 00    ; JP   PO, 0x0000
; ex   (SP), IX
04d3 dd e3       ; EX   (SP), IX
; call PO, 0x0000
04d5 e4 00 00    ; CALL PO, 0x0000
; push IX
04d8 dd e5       ; PUSH IX
; and  0x00
04da e6 00       ; AND  0x00
; rst  0x20
04dc e7          ; RST  0x20
; ret  PE
04dd e8          ; RET  PE
; jp   IX
04de dd e9       ; JP   IX
; jp   PE, 0x0000
04e0 ea 00 00    ; JP   PE, 0x0000
; ex   DE, HL
04e3 eb          ; EX   DE, HL
; call PE, 0x0000
04e4 ec 00 00    ; CALL PE, 0x0000
; xor  0x00
04e7 ee 00       ; XOR  0x00
; rst  0x28
04e9 ef          ; RST  0x28
; ret  P
04ea f0          ; RET  P
; pop  AF
04eb f1          ; POP  AF
; jp   P, 0x0000
04ec f2 00 00    ; JP   P, 0x0000
; di
04ef f3          ; DI
; call P, 0x0000
04f0 f4 00 00    ; CALL P, 0x0000
; push AF
04f3 f5          ; PUSH AF
; or   0x00
04f4 f6 00       ; OR   0x00
; rst  0x30
04f6 f7          ; RST  0x30
; ret  M
04f7 f8          ; RET  M
; ld   SP, IX
04f8 dd f9       ; LD   SP, IX
; jp   M, 0x0000
04fa fa 00 00    ; JP   M, 0x0000
; ei
04fd fb          ; EI
; call M, 0x0000
04fe fc 00 00    ; CALL M, 0x0000
; cp   0x00
0501 fe 00       ; CP   0x00
; rst  0x38
0503 ff          ; RST  0x38
; nop
0504 00          ; NOP
; nop
0505 00          ; NOP
; nop
0506 00          ; NOP
; nop
0507 00          ; NOP
; nop
0508 00          ; NOP
; nop
0509 00          ; NOP
; nop
050a 00          ; NOP
; nop
050b 00          ; NOP
; nop
050c 00          ; NOP
; nop
050d 00          ; NOP
; nop
050e 00          ; NOP
; nop
050f 00          ; NOP
; nop
0510 00          ; NOP
; nop
0511 00          ; NOP
; nop
0512 00          ; NOP
; nop
0513 00          ; NOP
; nop
0514 00          ; NOP
; nop
0515 00          ; NOP
; nop
0516 00          ; NOP
; nop
0517 00          ; NOP
; nop
0518 00          ; NOP
; nop
0519 00          ; NOP
; nop
051a 00          ; NOP
; nop
051b 00          ; NOP
; nop
051c 00          ; NOP
; nop
051d 00          ; NOP
; nop
051e 00          ; NOP
; nop
051f 00          ; NOP
; nop
0520 00          ; NOP
; nop
0521 00          ; NOP
; nop
0522 00          ; NOP
; nop
0523 00          ; NOP
; nop
0524 00          ; NOP
; nop
0525 00          ; NOP
; nop
0526 00          ; NOP
; nop
0527 00          ; NOP
; nop
0528 00          ; NOP
; nop
0529 00          ; NOP
; nop
052a 00          ; NOP
; nop
052b 00          ; NOP
; nop
052c 00          ; NOP
; nop
052d 00          ; NOP
; nop
052e 00          ; NOP
; nop
052f 00          ; NOP
; nop
0530 00          ; NOP
; nop
0531 00          ; NOP
; nop
0532 00          ; NOP
; nop
0533 00          ; NOP
; nop
0534 00          ; NOP
; nop
0535 00          ; NOP
; nop
0536 00          ; NOP
; nop
0537 00          ; NOP
; nop
0538 00          ; NOP
; nop
0539 00          ; NOP
; nop
053a 00          ; NOP
; nop
053b 00          ; NOP
; nop
053c 00          ; NOP
; nop
053d 00          ; NOP
; nop
053e 00          ; NOP
; nop
053f 00          ; NOP
; nop
0540 00          ; NOP
; nop
0541 00          ; NOP
; nop
0542 00          ; NOP
; nop
0543 00          ; NOP
; in   B, (C)
0544 ed 40       ; IN   B, (C)
; out  (C), B
0546 ed 41       ; OUT  (C), B
; sbc  HL, BC
0548 ed 42       ; SBC  HL, BC
; ld   (0x0000), BC
054a ed 43 00 00 ; LD   (0x0000), BC
; neg
054e ed 44       ; NEG
; retn
0550 ed 45       ; RETN
; im   0x00
0552 ed 46       ; IM   0x00
; ld   I, A
0554 ed 47       ; LD   I, A
; in   C, (C)
0556 ed 48       ; IN   C, (C)
; out  (C), C
0558 ed 49       ; OUT  (C), C
; adc  HL, BC
055a ed 4a       ; ADC  HL, BC
; ld   BC, (0x0000)
055c ed 4b 00 00 ; LD   BC, (0x0000)
; neg
0560 ed 44       ; NEG
; reti
0562 ed 4d       ; RETI
; im   0x00
0564 ed 46       ; IM   0x00
; ld   R, A
0566 ed 4f       ; LD   R, A
; in   D, (C)
0568 ed 50       ; IN   D, (C)
; out  (C), D
056a ed 51       ; OUT  (C), D
; sbc  HL, DE
056c ed 52       ; SBC  HL, DE
; ld   (0x0000), DE
056e ed 53 00 00 ; LD   (0x0000), DE
; neg
0572 ed 44       ; NEG
; retn
0574 ed 45       ; RETN
; im   0x01
0576 ed 56       ; IM   0x01
; ld   A, I
0578 ed 57       ; LD   A, I
; in   E, (C)
057a ed 58       ; IN   E, (C)
; out  (C), E
057c ed 59       ; OUT  (C), E
; adc  HL, DE
057e ed 5a       ; ADC  HL, DE
; ld   DE, (0x0000)
0580 ed 5b 00 00 ; LD   DE, (0x0000)
; neg
0584 ed 44       ; NEG
; retn
0586 ed 45       ; RETN
; im   0x02
0588 ed 5e       ; IM   0x02
; ld   A, R
058a ed 5f       ; LD   A, R
; in   H, (C)
058c ed 60       ; IN   H, (C)
; out  (C), H
058e ed 61       ; OUT  (C), H
; sbc  HL, HL
0590 ed 62       ; SBC  HL, HL
; ld   (0x0000), HL
0592 22 00 00    ; LD   (0x0000), HL
; neg
0595 ed 44       ; NEG
; retn
0597 ed 45       ; RETN
; im   0x00
0599 ed 46       ; IM   0x00
; rrd
059b ed 67       ; RRD
; in   L, (C)
059d ed 68       ; IN   L, (C)
; out  (C), L
059f ed 69       ; OUT  (C), L
; adc  HL, HL
05a1 ed 6a       ; ADC  HL, HL
; ld   HL, (0x0000)
05a3 2a 00 00    ; LD   HL, (0x0000)
; neg
05a6 ed 44       ; NEG
; retn
05a8 ed 45       ; RETN
; im   0x00
05aa ed 46       ; IM   0x00
; rld
05ac ed 6f       ; RLD
; in   0x00, (C)
05ae ed 70       ; IN   0x00, (C)
; out  (C), 0x00
05b0 ed 71       ; OUT  (C), 0x00
; sbc  HL, SP
05b2 ed 72       ; SBC  HL, SP
; ld   (0x0000), SP
05b4 ed 73 00 00 ; LD   (0x0000), SP
; neg
05b8 ed 44       ; NEG
; retn
05ba ed 45       ; RETN
; im   0x01
05bc ed 56       ; IM   0x01
; nop
05be 00          ; NOP
; in   A, (C)
05bf ed 78       ; IN   A, (C)
; out  (C), A
05c1 ed 79       ; OUT  (C), A
; adc  HL, SP
05c3 ed 7a       ; ADC  HL, SP
; ld   SP, (0x0000)
05c5 ed 7b 00 00 ; LD   SP, (0x0000)
; neg
05c9 ed 44       ; NEG
; retn
05cb ed 45       ; RETN
; im   0x02
05cd ed 5e       ; IM   0x02
; nop
05cf 00          ; NOP
; nop
05d0 00          ; NOP
; nop
05d1 00          ; NOP
; nop
05d2 00          ; NOP
; nop
05d3 00          ; NOP
; nop
05d4 00          ; NOP
; nop
05d5 00          ; NOP
; nop
05d6 00          ; NOP
; nop
05d7 00          ; NOP
; nop
05d8 00          ; NOP
; nop
05d9 00          ; NOP
; nop
05da 00          ; NOP
; nop
05db 00          ; NOP
; nop
05dc 00          ; NOP
; nop
05dd 00          ; NOP
; nop
05de 00          ; NOP
; nop
05df 00          ; NOP
; nop
05e0 00          ; NOP
; nop
05e1 00          ; NOP
; nop
05e2 00          ; NOP
; nop
05e3 00          ; NOP
; nop
05e4 00          ; NOP
; nop
05e5 00          ; NOP
; nop
05e6 00          ; NOP
; nop
05e7 00          ; NOP
; nop
05e8 00          ; NOP
; nop
05e9 00          ; NOP
; nop
05ea 00          ; NOP
; nop
05eb 00          ; NOP
; nop
05ec 00          ; NOP
; nop
05ed 00          ; NOP
; nop
05ee 00          ; NOP
; nop
05ef 00          ; NOP
; ldi
05f0 ed a0       ; LDI
; cpi
05f2 ed a1       ; CPI
; ini
05f4 ed a2       ; INI
; outi
05f6 ed a3       ; OUTI
; nop
05f8 00          ; NOP
; nop
05f9 00          ; NOP
; nop
05fa 00          ; NOP
; nop
05fb 00          ; NOP
; ldd
05fc ed a8       ; LDD
; cpd
05fe ed a9       ; CPD
; ind
0600 ed aa       ; IND
; outd
0602 ed ab       ; OUTD
; nop
0604 00          ; NOP
; nop
0605 00          ; NOP
; nop
0606 00          ; NOP
; nop
0607 00          ; NOP
; ldir
0608 ed b0       ; LDIR
; cpir
060a ed b1       ; CPIR
; inir
060c ed b2       ; INIR
; otir
060e ed b3       ; OTIR
; nop
0610 00          ; NOP
; nop
0611 00          ; NOP
; nop
0612 00          ; NOP
; nop
0613 00          ; NOP
; lddr
0614 ed b8       ; LDDR
; cpdr
0616 ed b9       ; CPDR
; indr
0618 ed ba       ; INDR
; otdr
061a ed bb       ; OTDR
; nop
061c 00          ; NOP
; nop
061d 00          ; NOP
; nop
061e 00          ; NOP
; nop
061f 00          ; NOP
; nop
0620 00          ; NOP
; nop
0621 00          ; NOP
; nop
0622 00          ; NOP
; nop
0623 00          ; NOP
; nop
0624 00          ; NOP
; nop
0625 00          ; NOP
; nop
0626 00          ; NOP
; nop
0627 00          ; NOP
; nop
0628 00          ; NOP
; nop
0629 00          ; NOP
; nop
062a 00          ; NOP
; nop
062b 00          ; NOP
; nop
062c 00          ; NOP
; nop
062d 00          ; NOP
; nop
062e 00          ; NOP
; nop
062f 00          ; NOP
; nop
0630 00          ; NOP
; nop
0631 00          ; NOP
; nop
0632 00          ; NOP
; nop
0633 00          ; NOP
; nop
0634 00          ; NOP
; nop
0635 00          ; NOP
; nop
0636 00          ; NOP
; nop
0637 00          ; NOP
; nop
0638 00          ; NOP
; nop
0639 00          ; NOP
; nop
063a 00          ; NOP
; nop
063b 00          ; NOP
; nop
063c 00          ; NOP
; nop
063d 00          ; NOP
; nop
063e 00          ; NOP
; nop
063f 00          ; NOP
; nop
0640 00          ; NOP
; nop
0641 00          ; NOP
; nop
0642 00          ; NOP
; nop
0643 00          ; NOP
; nop
0644 00          ; NOP
; nop
0645 00          ; NOP
; nop
0646 00          ; NOP
; nop
0647 00          ; NOP
; nop
0648 00          ; NOP
; nop
0649 00          ; NOP
; nop
064a 00          ; NOP
; nop
064b 00          ; NOP
; nop
064c 00          ; NOP
; nop
064d 00          ; NOP
; nop
064e 00          ; NOP
; nop
064f 00          ; NOP
; nop
0650 00          ; NOP
; nop
0651 00          ; NOP
; nop
0652 00          ; NOP
; nop
0653 00          ; NOP
; nop
0654 00          ; NOP
; nop
0655 00          ; NOP
; nop
0656 00          ; NOP
; nop
0657 00          ; NOP
; nop
0658 00          ; NOP
; nop
0659 00          ; NOP
; nop
065a 00          ; NOP
; nop
065b 00          ; NOP
; nop
065c 00          ; NOP
; nop
065d 00          ; NOP
; nop
065e 00          ; NOP
; nop
065f 00          ; NOP
; nop
0660 00          ; NOP
; ld   BC, 0x0000
0661 01 00 00    ; LD   BC, 0x0000
; ld   (BC), A
0664 02          ; LD   (BC), A
; inc  BC
0665 03          ; INC  BC
; inc  B
0666 04          ; INC  B
; dec  B
0667 05          ; DEC  B
; ld   B, 0x00
0668 06 00       ; LD   B, 0x00
; rlca
066a 07          ; RLCA
; ex   AF, AF'
066b 08          ; EX   AF, AF'
; add  IY, BC
066c fd 09       ; ADD  IY, BC
; ld   A, (BC)
066e 0a          ; LD   A, (BC)
; dec  BC
066f 0b          ; DEC  BC
; inc  C
0670 0c          ; INC  C
; dec  C
0671 0d          ; DEC  C
; ld   C, 0x00
0672 0e 00       ; LD   C, 0x00
; rrca
0674 0f          ; RRCA
; djnz +0x00
0675 10 00       ; DJNZ +0x00
; ld   DE, 0x0000
0677 11 00 00    ; LD   DE, 0x0000
; ld   (DE), A
067a 12          ; LD   (DE), A
; inc  DE
067b 13          ; INC  DE
; inc  D
067c 14          ; INC  D
; dec  D
067d 15          ; DEC  D
; ld   D, 0x00
067e 16 00       ; LD   D, 0x00
; rla
0680 17          ; RLA
; jr   +0x00
0681 18 00       ; JR   +0x00
; add  IY, DE
0683 fd 19       ; ADD  IY, DE
; ld   A, (DE)
0685 1a          ; LD   A, (DE)
; dec  DE
0686 1b          ; DEC  DE
; inc  E
0687 1c          ; INC  E
; dec  E
0688 1d          ; DEC  E
; ld   E, 0x00
0689 1e 00       ; LD   E, 0x00
; rra
068b 1f          ; RRA
; jr   NZ, +0x00
068c 20 00       ; JR   NZ, +0x00
; ld   IY, 0x0000
068e fd 21 00 00 ; LD   IY, 0x0000
; ld   (0x0000), IY
0692 fd 22 00 00 ; LD   (0x0000), IY
; inc  IY
0696 fd 23       ; INC  IY
; inc  IYh
0698 fd 24       ; INC  IYh
; dec  IYh
069a fd 25       ; DEC  IYh
; ld   IYh, 0x00
069c fd 26 00    ; LD   IYh, 0x00
; daa
069f 27          ; DAA
; jr   Z, +0x00
06a0 28 00       ; JR   Z, +0x00
; add  IY, IY
06a2 fd 29       ; ADD  IY, IY
; ld   IY, (0x0000)
06a4 fd 2a 00 00 ; LD   IY, (0x0000)
; dec  IY
06a8 fd 2b       ; DEC  IY
; inc  IYl
06aa fd 2c       ; INC  IYl
; dec  IYl
06ac fd 2d       ; DEC  IYl
; ld   IYl, 0x00
06ae fd 2e 00    ; LD   IYl, 0x00
; cpl
06b1 2f          ; CPL
; jr   NC, +0x00
06b2 30 00       ; JR   NC, +0x00
; ld   SP, 0x0000
06b4 31 00 00    ; LD   SP, 0x0000
; ld   (0x0000), A
06b7 32 00 00    ; LD   (0x0000), A
; inc  SP
06ba 33          ; INC  SP
; inc  (IY+0x00)
06bb fd 34 00    ; INC  (IY+0x00)
; dec  (IY+0x00)
06bf fd 35 00    ; DEC  (IY+0x00)
; ld   (IY+0x00), 0x00
06c3 fd 36 00 00 ; LD   (IY+0x00), 0x00
; scf
06c7 37          ; SCF
; jr   C, +0x00
06c8 38 00       ; JR   C, +0x00
; add  IY, SP
06ca fd 39       ; ADD  IY, SP
; ld   A, (0x0000)
06cc 3a 00 00    ; LD   A, (0x0000)
; dec  SP
06cf 3b          ; DEC  SP
; inc  A
06d0 3c          ; INC  A
; dec  A
06d1 3d          ; DEC  A
; ld   A, 0x00
06d2 3e 00       ; LD   A, 0x00
; ccf
06d4 3f          ; CCF
; ld   B, B
06d5 40          ; LD   B, B
; ld   B, C
06d6 41          ; LD   B, C
; ld   B, D
06d7 42          ; LD   B, D
; ld   B, E
06d8 43          ; LD   B, E
; ld   B, IYh
06d9 fd 44       ; LD   B, IYh
; ld   B, IYl
06db fd 45       ; LD   B, IYl
; ld   B, (IY+0x00)
06dd fd 46 00    ; LD   B, (IY+0x00)
; ld   B, A
06df 47          ; LD   B, A
; ld   C, B
06e0 48          ; LD   C, B
; ld   C, C
06e1 49          ; LD   C, C
; ld   C, D
06e2 4a          ; LD   C, D
; ld   C, E
06e3 4b          ; LD   C, E
; ld   C, IYh
06e4 fd 4c       ; LD   C, IYh
; ld   C, IYl
06e6 fd 4d       ; LD   C, IYl
; ld   C, (IY+0x00)
06e8 fd 4e 00    ; LD   C, (IY+0x00)
; ld   C, A
06ea 4f          ; LD   C, A
; ld   D, B
06eb 50          ; LD   D, B
; ld   D, C
06ec 51          ; LD   D, C
; ld   D, D
06ed 52          ; LD   D, D
; ld   D, E
06ee 53          ; LD   D, E
; ld   D, IYh
06ef fd 54       ; LD   D, IYh
; ld   D, IYl
06f1 fd 55       ; LD   D, IYl
; ld   D, (IY+0x00)
06f3 fd 56 00    ; LD   D, (IY+0x00)
; ld   D, A
06f5 57          ; LD   D, A
; ld   E, B
06f6 58          ; LD   E, B
; ld   E, C
06f7 59          ; LD   E, C
; ld   E, D
06f8 5a          ; LD   E, D
; ld   E, E
06f9 5b          ; LD   E, E
; ld   E, IYh
06fa fd 5c       ; LD   E, IYh
; ld   E, IYl
06fc fd 5d       ; LD   E, IYl
; ld   E, (IY+0x00)
06fe fd 5e 00    ; LD   E, (IY+0x00)
; ld   E, A
0700 5f          ; LD   E, A
; ld   IYh, B
0701 fd 60       ; LD   IYh, B
; ld   IYh, C
0703 fd 61       ; LD   IYh, C
; ld   IYh, D
0705 fd 62       ; LD   IYh, D
; ld   IYh, E
0707 fd 63       ; LD   IYh, E
; ld   IYh, IYh
0709 fd 64       ; LD   IYh, IYh
; ld   IYh, IYl
070b fd 65       ; LD   IYh, IYl
; ld   H, (IY+0x00)
070d fd 66 00    ; LD   H, (IY+0x00)
; ld   IYh, A
070f fd 67       ; LD   IYh, A
; ld   IYl, B
0711 fd 68       ; LD   IYl, B
; ld   IYl, C
0713 fd 69       ; LD   IYl, C
; ld   IYl, D
0715 fd 6a       ; LD   IYl, D
; ld   IYl, E
0717 fd 6b       ; LD   IYl, E
; ld   IYl, IYh
0719 fd 6c       ; LD   IYl, IYh
; ld   IYl, IYl
071b fd 6d       ; LD   IYl, IYl
; ld   L, (IY+0x00)
071d fd 6e 00    ; LD   L, (IY+0x00)
; ld   IYl, A
071f fd 6f       ; LD   IYl, A
; ld   (IY+0x00), B
0721 fd 70 00    ; LD   (IY+0x00), B
; ld   (IY+0x00), C
0725 fd 71 00    ; LD   (IY+0x00), C
; ld   (IY+0x00), D
0729 fd 72 00    ; LD   (IY+0x00), D
; ld   (IY+0x00), E
072d fd 73 00    ; LD   (IY+0x00), E
; ld   (IY+0x00), H
0731 fd 74 00    ; LD   (IY+0x00), H
; ld   (IY+0x00), L
0735 fd 75 00    ; LD   (IY+0x00), L
; halt
0739 76          ; HALT
; ld   (IY+0x00), A
073a fd 77 00    ; LD   (IY+0x00), A
; ld   A, B
073e 78          ; LD   A, B
; ld   A, C
073f 79          ; LD   A, C
; ld   A, D
0740 7a          ; LD   A, D
; ld   A, E
0741 7b          ; LD   A, E
; ld   A, IYh
0742 fd 7c       ; LD   A, IYh
; ld   A, IYl
0744 fd 7d       ; LD   A, IYl
; ld   A, (IY+0x00)
0746 fd 7e 00    ; LD   A, (IY+0x00)
; ld   A, A
0748 7f          ; LD   A, A
; add  A, B
0749 80          ; ADD  A, B
; add  A, C
074a 81          ; ADD  A, C
; add  A, D
074b 82          ; ADD  A, D
; add  A, E
074c 83          ; ADD  A, E
; add  A, IYh
074d fd 84       ; ADD  A, IYh
; add  A, IYl
074f fd 85       ; ADD  A, IYl
; add  A, (IY+0x00)
0751 fd 86 00    ; ADD  A, (IY+0x00)
; add  A, A
0753 87          ; ADD  A, A
; adc  A, B
0754 88          ; ADC  A, B
; adc  A, C
0755 89          ; ADC  A, C
; adc  A, D
0756 8a          ; ADC  A, D
; adc  A, E
0757 8b          ; ADC  A, E
; adc  A, IYh
0758 fd 8c       ; ADC  A, IYh
; adc  A, IYl
075a fd 8d       ; ADC  A, IYl
; adc  A, (IY+0x00)
075c fd 8e 00    ; ADC  A, (IY+0x00)
; adc  A, A
075e 8f          ; ADC  A, A
; sub  B
075f 90          ; SUB  B
; sub  C
0760 91          ; SUB  C
; sub  D
0761 92          ; SUB  D
; sub  E
0762 93          ; SUB  E
; sub  IYh
0763 fd 94       ; SUB  IYh
; sub  IYl
0765 fd 95       ; SUB  IYl
; sub  (IY+0x00)
0767 fd 96 00    ; SUB  (IY+0x00)
; sub  A
076b 97          ; SUB  A
; sbc  A, B
076c 98          ; SBC  A, B
; sbc  A, C
076d 99          ; SBC  A, C
; sbc  A, D
076e 9a          ; SBC  A, D
; sbc  A, E
076f 9b          ; SBC  A, E
; sbc  A, IYh
0770 fd 9c       ; SBC  A, IYh
; sbc  A, IYl
0772 fd 9d       ; SBC  A, IYl
; sbc  (IY+0x00)
0774 fd 9e 00    ; SBC  (IY+0x00)
; sbc  A, A
0778 9f          ; SBC  A, A
; and  B
0779 a0          ; AND  B
; and  C
077a a1          ; AND  C
; and  D
077b a2          ; AND  D
; and  E
077c a3          ; AND  E
; and  IYh
077d fd a4       ; AND  IYh
; and  IYl
077f fd a5       ; AND  IYl
; and  (IY+0x00)
0781 fd a6 00    ; AND  (IY+0x00)
; and  A
0785 a7          ; AND  A
; xor  B
0786 a8          ; XOR  B
; xor  C
0787 a9          ; XOR  C
; xor  D
0788 aa          ; XOR  D
; xor  E
0789 ab          ; XOR  E
; xor  IYh
078a fd ac       ; XOR  IYh
; xor  IYl
078c fd ad       ; XOR  IYl
; xor  (IY+0x00)
078e fd ae 00    ; XOR  (IY+0x00)
; xor  A
0792 af          ; XOR  A
; or   B
0793 b0          ; OR   B
; or   C
0794 b1          ; OR   C
; or   D
0795 b2          ; OR   D
; or   E
0796 b3          ; OR   E
; or   IYh
0797 fd b4       ; OR   IYh
; or   IYl
0799 fd b5       ; OR   IYl
; or   (IY+0x00)
079b fd b6 00    ; OR   (IY+0x00)
; or   A
079f b7          ; OR   A
; cp   B
07a0 b8          ; CP   B
; cp   C
07a1 b9          ; CP   C
; cp   D
07a2 ba          ; CP   D
; cp   E
07a3 bb          ; CP   E
; cp   IYh
07a4 fd bc       ; CP   IYh
; cp   IYl
07a6 fd bd       ; CP   IYl
; cp   (IY+0x00)
07a8 fd be 00    ; CP   (IY+0x00)
; cp   A
07ac bf          ; CP   A
; ret  NZ
07ad c0          ; RET  NZ
; pop  BC
07ae c1          ; POP  BC
; jp   NZ, 0x0000
07af c2 00 00    ; JP   NZ, 0x0000
; jp   0x0000
07b2 c3 00 00    ; JP   0x0000
; call NZ, 0x0000
07b5 c4 00 00    ; CALL NZ, 0x0000
; push BC
07b8 c5          ; PUSH BC
; add  A, 0x00
07b9 c6 00       ; ADD  A, 0x00
; rst  0x00
07bb c7          ; RST  0x00
; ret  Z
07bc c8          ; RET  Z
; ret
07bd c9          ; RET
; jp   Z, 0x0000
07be ca 00 00    ; JP   Z, 0x0000
; call Z, 0x0000
07c1 cc 00 00    ; CALL Z, 0x0000
; call 0x0000
07c4 cd 00 00    ; CALL 0x0000
; adc  A, 0x00
07c7 ce 00       ; ADC  A, 0x00
; rst  0x08
07c9 cf          ; RST  0x08
; ret  NC
07ca d0          ; RET  NC
; pop  DE
07cb d1          ; POP  DE
; jp   NC, 0x0000
07cc d2 00 00    ; JP   NC, 0x0000
; out  (0x00), A
07cf d3 00 00    ; OUT  (0x00), A
; call NC, 0x0000
07d1 d4 00 00    ; CALL NC, 0x0000
; push DE
07d4 d5          ; PUSH DE
; sub  0x00
07d5 d6 00       ; SUB  0x00
; rst  0x10
07d7 d7          ; RST  0x10
; ret  C
07d8 d8          ; RET  C
; exx
07d9 d9          ; EXX
; jp   C, 0x0000
07da da 00 00    ; JP   C, 0x0000
; in   A, (0x00)
07dd db 00 00    ; IN   A, (0x00)
; call C, 0x0000
07df dc 00 00    ; CALL C, 0x0000
; sbc  A, 0x00
07e2 de 00       ; SBC  A, 0x00
; rst  0x18
07e4 df          ; RST  0x18
; ret  PO
07e5 e0          ; RET  PO
; pop  IY
07e6 fd e1       ; POP  IY
; jp   PO, 0x0000
07e8 e2 00 00    ; JP   PO, 0x0000
; ex   (SP), IY
07eb fd e3       ; EX   (SP), IY
; call PO, 0x0000
07ed e4 00 00    ; CALL PO, 0x0000
; push IY
07f0 fd e5       ; PUSH IY
; and  0x00
07f2 e6 00       ; AND  0x00
; rst  0x20
07f4 e7          ; RST  0x20
; ret  PE
07f5 e8          ; RET  PE
; jp   IY
07f6 fd e9       ; JP   IY
; jp   PE, 0x0000
07f8 ea 00 00    ; JP   PE, 0x0000
; ex   DE, HL
07fb eb          ; EX   DE, HL
; call PE, 0x0000
07fc ec 00 00    ; CALL PE, 0x0000
; xor  0x00
07ff ee 00       ; XOR  0x00
; rst  0x28
0801 ef          ; RST  0x28
; ret  P
0802 f0          ; RET  P
; pop  AF
0803 f1          ; POP  AF
; jp   P, 0x0000
0804 f2 00 00    ; JP   P, 0x0000
; di
0807 f3          ; DI
; call P, 0x0000
0808 f4 00 00    ; CALL P, 0x0000
; push AF
080b f5          ; PUSH AF
; or   0x00
080c f6 00       ; OR   0x00
; rst  0x30
080e f7          ; RST  0x30
; ret  M
080f f8          ; RET  M
; ld   SP, IY
0810 fd f9       ; LD   SP, IY
; jp   M, 0x0000
0812 fa 00 00    ; JP   M, 0x0000
; ei
0815 fb          ; EI
; call M, 0x0000
0816 fc 00 00    ; CALL M, 0x0000
; cp   0x00
0819 fe 00       ; CP   0x00
; rst  0x38
081b ff          ; RST  0x38
; rlc  (IX+0x00)->B
081c dd cb 00 00 ; RLC  (IX+0x00)->B
; rlc  (IX+0x00)->C
0821 dd cb 01 00 ; RLC  (IX+0x00)->C
; rlc  (IX+0x00)->D
0826 dd cb 02 00 ; RLC  (IX+0x00)->D
; rlc  (IX+0x00)->E
082b dd cb 03 00 ; RLC  (IX+0x00)->E
; rlc  (IX+0x00)->H
0830 dd cb 04 00 ; RLC  (IX+0x00)->H
; rlc  (IX+0x00)->L
0835 dd cb 05 00 ; RLC  (IX+0x00)->L
; rlc  (IX+0x00)
083a dd cb 06 00 ; RLC  (IX+0x00)
; rlc  (IX+0x00)->A
083f dd cb 07 00 ; RLC  (IX+0x00)->A
; rrc  (IX+0x00)->B
0844 dd cb 08 00 ; RRC  (IX+0x00)->B
; rrc  (IX+0x00)->C
0849 dd cb 09 00 ; RRC  (IX+0x00)->C
; rrc  (IX+0x00)->D
084e dd cb 0a 00 ; RRC  (IX+0x00)->D
; rrc  (IX+0x00)->E
0853 dd cb 0b 00 ; RRC  (IX+0x00)->E
; rrc  (IX+0x00)->H
0858 dd cb 0c 00 ; RRC  (IX+0x00)->H
; rrc  (IX+0x00)->L
085d dd cb 0d 00 ; RRC  (IX+0x00)->L
; rrc  (IX+0x00)
0862 dd cb 0e 00 ; RRC  (IX+0x00)
; rrc  (IX+0x00)->A
0867 dd cb 0f 00 ; RRC  (IX+0x00)->A
; rl   (IX+0x00)->B
086c dd cb 10 00 ; RL   (IX+0x00)->B
; rl   (IX+0x00)->C
0871 dd cb 11 00 ; RL   (IX+0x00)->C
; rl   (IX+0x00)->D
0876 dd cb 12 00 ; RL   (IX+0x00)->D
; rl   (IX+0x00)->E
087b dd cb 13 00 ; RL   (IX+0x00)->E
; rl   (IX+0x00)->H
0880 dd cb 14 00 ; RL   (IX+0x00)->H
; rl   (IX+0x00)->L
0885 dd cb 15 00 ; RL   (IX+0x00)->L
; rl   (IX+0x00)
088a dd cb 16 00 ; RL   (IX+0x00)
; rl   (IX+0x00)->A
088f dd cb 17 00 ; RL   (IX+0x00)->A
; rr   (IX+0x00)->B
0894 dd cb 18 00 ; RR   (IX+0x00)->B
; rr   (IX+0x00)->C
0899 dd cb 19 00 ; RR   (IX+0x00)->C
; rr   (IX+0x00)->D
089e dd cb 1a 00 ; RR   (IX+0x00)->D
; rr   (IX+0x00)->E
08a3 dd cb 1b 00 ; RR   (IX+0x00)->E
; rr   (IX+0x00)->H
08a8 dd cb 1c 00 ; RR   (IX+0x00)->H
; rr   (IX+0x00)->L
08ad dd cb 1d 00 ; RR   (IX+0x00)->L
; rr   (IX+0x00)
08b2 dd cb 1e 00 ; RR   (IX+0x00)
; rr   (IX+0x00)->A
08b7 dd cb 1f 00 ; RR   (IX+0x00)->A
; sla  (IX+0x00)->B
08bc dd cb 20 00 ; SLA  (IX+0x00)->B
; sla  (IX+0x00)->C
08c1 dd cb 21 00 ; SLA  (IX+0x00)->C
; sla  (IX+0x00)->D
08c6 dd cb 22 00 ; SLA  (IX+0x00)->D
; sla  (IX+0x00)->E
08cb dd cb 23 00 ; SLA  (IX+0x00)->E
; sla  (IX+0x00)->H
08d0 dd cb 24 00 ; SLA  (IX+0x00)->H
; sla  (IX+0x00)->L
08d5 dd cb 25 00 ; SLA  (IX+0x00)->L
; sla  (IX+0x00)
08da dd cb 26 00 ; SLA  (IX+0x00)
; sla  (IX+0x00)->A
08df dd cb 27 00 ; SLA  (IX+0x00)->A
; sra  (IX+0x00)->B
08e4 dd cb 28 00 ; SRA  (IX+0x00)->B
; sra  (IX+0x00)->C
08e9 dd cb 29 00 ; SRA  (IX+0x00)->C
; sra  (IX+0x00)->D
08ee dd cb 2a 00 ; SRA  (IX+0x00)->D
; sra  (IX+0x00)->E
08f3 dd cb 2b 00 ; SRA  (IX+0x00)->E
; sra  (IX+0x00)->H
08f8 dd cb 2c 00 ; SRA  (IX+0x00)->H
; sra  (IX+0x00)->L
08fd dd cb 2d 00 ; SRA  (IX+0x00)->L
; sra  (IX+0x00)
0902 dd cb 2e 00 ; SRA  (IX+0x00)
; sra  (IX+0x00)->A
0907 dd cb 2f 00 ; SRA  (IX+0x00)->A
; sll  (IX+0x00)->B
090c dd cb 30 00 ; SLL  (IX+0x00)->B
; sll  (IX+0x00)->C
0911 dd cb 31 00 ; SLL  (IX+0x00)->C
; sll  (IX+0x00)->D
0916 dd cb 32 00 ; SLL  (IX+0x00)->D
; sll  (IX+0x00)->E
091b dd cb 33 00 ; SLL  (IX+0x00)->E
; sll  (IX+0x00)->H
0920 dd cb 34 00 ; SLL  (IX+0x00)->H
; sll  (IX+0x00)->L
0925 dd cb 35 00 ; SLL  (IX+0x00)->L
; sll  (IX+0x00)
092a dd cb 36 00 ; SLL  (IX+0x00)
; sll  (IX+0x00)->A
092f dd cb 37 00 ; SLL  (IX+0x00)->A
; srl  (IX+0x00)->B
0934 dd cb 38 00 ; SRL  (IX+0x00)->B
; srl  (IX+0x00)->C
0939 dd cb 39 00 ; SRL  (IX+0x00)->C
; srl  (IX+0x00)->D
093e dd cb 3a 00 ; SRL  (IX+0x00)->D
; srl  (IX+0x00)->E
0943 dd cb 3b 00 ; SRL  (IX+0x00)->E
; srl  (IX+0x00)->H
0948 dd cb 3c 00 ; SRL  (IX+0x00)->H
; srl  (IX+0x00)->L
094d dd cb 3d 00 ; SRL  (IX+0x00)->L
; srl  (IX+0x00)
0952 dd cb 3e 00 ; SRL  (IX+0x00)
; srl  (IX+0x00)->A
0957 dd cb 3f 00 ; SRL  (IX+0x00)->A
; bit  0x00, (IX+0x00)
095c dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
095f dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
0962 dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
0965 dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
0968 dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
096b dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
096e dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x00, (IX+0x00)
0971 dd cb 40 00 ; BIT  0x00, (IX+0x00)
; bit  0x01, (IX+0x00)
0974 dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
0977 dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
097a dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
097d dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
0980 dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
0983 dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
0986 dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x01, (IX+0x00)
0989 dd cb 48 00 ; BIT  0x01, (IX+0x00)
; bit  0x02, (IX+0x00)
098c dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
098f dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
0992 dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
0995 dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
0998 dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
099b dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
099e dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x02, (IX+0x00)
09a1 dd cb 50 00 ; BIT  0x02, (IX+0x00)
; bit  0x03, (IX+0x00)
09a4 dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09a7 dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09aa dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09ad dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09b0 dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09b3 dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09b6 dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x03, (IX+0x00)
09b9 dd cb 58 00 ; BIT  0x03, (IX+0x00)
; bit  0x04, (IX+0x00)
09bc dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09bf dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09c2 dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09c5 dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09c8 dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09cb dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09ce dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x04, (IX+0x00)
09d1 dd cb 60 00 ; BIT  0x04, (IX+0x00)
; bit  0x05, (IX+0x00)
09d4 dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09d7 dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09da dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09dd dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09e0 dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09e3 dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09e6 dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x05, (IX+0x00)
09e9 dd cb 68 00 ; BIT  0x05, (IX+0x00)
; bit  0x06, (IX+0x00)
09ec dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
09ef dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
09f2 dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
09f5 dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
09f8 dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
09fb dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
09fe dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x06, (IX+0x00)
0a01 dd cb 70 00 ; BIT  0x06, (IX+0x00)
; bit  0x07, (IX+0x00)
0a04 dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a07 dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a0a dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a0d dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a10 dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a13 dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a16 dd cb 78 00 ; BIT  0x07, (IX+0x00)
; bit  0x07, (IX+0x00)
0a19 dd cb 78 00 ; BIT  0x07, (IX+0x00)
; res  0x00, (IX+0x00)->B
0a1c dd cb 80 00 ; RES  0x00, (IX+0x00)->B
; res  0x00, (IX+0x00)->C
0a1f dd cb 81 00 ; RES  0x00, (IX+0x00)->C
; res  0x00, (IX+0x00)->D
0a22 dd cb 82 00 ; RES  0x00, (IX+0x00)->D
; res  0x00, (IX+0x00)->E
0a25 dd cb 83 00 ; RES  0x00, (IX+0x00)->E
; res  0x00, (IX+0x00)->H
0a28 dd cb 84 00 ; RES  0x00, (IX+0x00)->H
; res  0x00, (IX+0x00)->L
0a2b dd cb 85 00 ; RES  0x00, (IX+0x00)->L
; res  0x00, (IX+0x00)
0a2e dd cb 86 00 ; RES  0x00, (IX+0x00)
; res  0x00, (IX+0x00)->A
0a31 dd cb 87 00 ; RES  0x00, (IX+0x00)->A
; res  0x01, (IX+0x00)->B
0a34 dd cb 88 00 ; RES  0x01, (IX+0x00)->B
; res  0x01, (IX+0x00)->C
0a37 dd cb 89 00 ; RES  0x01, (IX+0x00)->C
; res  0x01, (IX+0x00)->D
0a3a dd cb 8a 00 ; RES  0x01, (IX+0x00)->D
; res  0x01, (IX+0x00)->E
0a3d dd cb 8b 00 ; RES  0x01, (IX+0x00)->E
; res  0x01, (IX+0x00)->H
0a40 dd cb 8c 00 ; RES  0x01, (IX+0x00)->H
; res  0x01, (IX+0x00)->L
0a43 dd cb 8d 00 ; RES  0x01, (IX+0x00)->L
; res  0x01, (IX+0x00)
0a46 dd cb 8e 00 ; RES  0x01, (IX+0x00)
; res  0x01, (IX+0x00)->A
0a49 dd cb 8f 00 ; RES  0x01, (IX+0x00)->A
; res  0x02, (IX+0x00)->B
0a4c dd cb 90 00 ; RES  0x02, (IX+0x00)->B
; res  0x02, (IX+0x00)->C
0a4f dd cb 91 00 ; RES  0x02, (IX+0x00)->C
; res  0x02, (IX+0x00)->D
0a52 dd cb 92 00 ; RES  0x02, (IX+0x00)->D
; res  0x02, (IX+0x00)->E
0a55 dd cb 93 00 ; RES  0x02, (IX+0x00)->E
; res  0x02, (IX+0x00)->H
0a58 dd cb 94 00 ; RES  0x02, (IX+0x00)->H
; res  0x02, (IX+0x00)->L
0a5b dd cb 95 00 ; RES  0x02, (IX+0x00)->L
; res  0x02, (IX+0x00)
0a5e dd cb 96 00 ; RES  0x02, (IX+0x00)
; res  0x02, (IX+0x00)->A
0a61 dd cb 97 00 ; RES  0x02, (IX+0x00)->A
; res  0x03, (IX+0x00)->B
0a64 dd cb 98 00 ; RES  0x03, (IX+0x00)->B
; res  0x03, (IX+0x00)->C
0a67 dd cb 99 00 ; RES  0x03, (IX+0x00)->C
; res  0x03, (IX+0x00)->D
0a6a dd cb 9a 00 ; RES  0x03, (IX+0x00)->D
; res  0x03, (IX+0x00)->E
0a6d dd cb 9b 00 ; RES  0x03, (IX+0x00)->E
; res  0x03, (IX+0x00)->H
0a70 dd cb 9c 00 ; RES  0x03, (IX+0x00)->H
; res  0x03, (IX+0x00)->L
0a73 dd cb 9d 00 ; RES  0x03, (IX+0x00)->L
; res  0x03, (IX+0x00)
0a76 dd cb 9e 00 ; RES  0x03, (IX+0x00)
; res  0x03, (IX+0x00)->A
0a79 dd cb 9f 00 ; RES  0x03, (IX+0x00)->A
; res  0x04, (IX+0x00)->B
0a7c dd cb a0 00 ; RES  0x04, (IX+0x00)->B
; res  0x04, (IX+0x00)->C
0a7f dd cb a1 00 ; RES  0x04, (IX+0x00)->C
; res  0x04, (IX+0x00)->D
0a82 dd cb a2 00 ; RES  0x04, (IX+0x00)->D
; res  0x04, (IX+0x00)->E
0a85 dd cb a3 00 ; RES  0x04, (IX+0x00)->E
; res  0x04, (IX+0x00)->H
0a88 dd cb a4 00 ; RES  0x04, (IX+0x00)->H
; res  0x04, (IX+0x00)->L
0a8b dd cb a5 00 ; RES  0x04, (IX+0x00)->L
; res  0x04, (IX+0x00)
0a8e dd cb a6 00 ; RES  0x04, (IX+0x00)
; res  0x04, (IX+0x00)->A
0a91 dd cb a7 00 ; RES  0x04, (IX+0x00)->A
; res  0x05, (IX+0x00)->B
0a94 dd cb a8 00 ; RES  0x05, (IX+0x00)->B
; res  0x05, (IX+0x00)->C
0a97 dd cb a9 00 ; RES  0x05, (IX+0x00)->C
; res  0x05, (IX+0x00)->D
0a9a dd cb aa 00 ; RES  0x05, (IX+0x00)->D
; res  0x05, (IX+0x00)->E
0a9d dd cb ab 00 ; RES  0x05, (IX+0x00)->E
; res  0x05, (IX+0x00)->H
0aa0 dd cb ac 00 ; RES  0x05, (IX+0x00)->H
; res  0x05, (IX+0x00)->L
0aa3 dd cb ad 00 ; RES  0x05, (IX+0x00)->L
; res  0x05, (IX+0x00)
0aa6 dd cb ae 00 ; RES  0x05, (IX+0x00)
; res  0x05, (IX+0x00)->A
0aa9 dd cb af 00 ; RES  0x05, (IX+0x00)->A
; res  0x06, (IX+0x00)->B
0aac dd cb b0 00 ; RES  0x06, (IX+0x00)->B
; res  0x06, (IX+0x00)->C
0aaf dd cb b1 00 ; RES  0x06, (IX+0x00)->C
; res  0x06, (IX+0x00)->D
0ab2 dd cb b2 00 ; RES  0x06, (IX+0x00)->D
; res  0x06, (IX+0x00)->E
0ab5 dd cb b3 00 ; RES  0x06, (IX+0x00)->E
; res  0x06, (IX+0x00)->H
0ab8 dd cb b4 00 ; RES  0x06, (IX+0x00)->H
; res  0x06, (IX+0x00)->L
0abb dd cb b5 00 ; RES  0x06, (IX+0x00)->L
; res  0x06, (IX+0x00)
0abe dd cb b6 00 ; RES  0x06, (IX+0x00)
; res  0x06, (IX+0x00)->A
0ac1 dd cb b7 00 ; RES  0x06, (IX+0x00)->A
; res  0x07, (IX+0x00)->B
0ac4 dd cb b8 00 ; RES  0x07, (IX+0x00)->B
; res  0x07, (IX+0x00)->C
0ac7 dd cb b9 00 ; RES  0x07, (IX+0x00)->C
; res  0x07, (IX+0x00)->D
0aca dd cb ba 00 ; RES  0x07, (IX+0x00)->D
; res  0x07, (IX+0x00)->E
0acd dd cb bb 00 ; RES  0x07, (IX+0x00)->E
; res  0x07, (IX+0x00)->H
0ad0 dd cb bc 00 ; RES  0x07, (IX+0x00)->H
; res  0x07, (IX+0x00)->L
0ad3 dd cb bd 00 ; RES  0x07, (IX+0x00)->L
; res  0x07, (IX+0x00)
0ad6 dd cb be 00 ; RES  0x07, (IX+0x00)
; res  0x07, (IX+0x00)->A
0ad9 dd cb bf 00 ; RES  0x07, (IX+0x00)->A
; set  0x00, (IX+0x00)->B
0adc dd cb c0 00 ; SET  0x00, (IX+0x00)->B
; set  0x00, (IX+0x00)->C
0adf dd cb c1 00 ; SET  0x00, (IX+0x00)->C
; set  0x00, (IX+0x00)->D
0ae2 dd cb c2 00 ; SET  0x00, (IX+0x00)->D
; set  0x00, (IX+0x00)->E
0ae5 dd cb c3 00 ; SET  0x00, (IX+0x00)->E
; set  0x00, (IX+0x00)->H
0ae8 dd cb c4 00 ; SET  0x00, (IX+0x00)->H
; set  0x00, (IX+0x00)->L
0aeb dd cb c5 00 ; SET  0x00, (IX+0x00)->L
; set  0x00, (IX+0x00)
0aee dd cb c6 00 ; SET  0x00, (IX+0x00)
; set  0x00, (IX+0x00)->A
0af1 dd cb c7 00 ; SET  0x00, (IX+0x00)->A
; set  0x01, (IX+0x00)->B
0af4 dd cb c8 00 ; SET  0x01, (IX+0x00)->B
; set  0x01, (IX+0x00)->C
0af7 dd cb c9 00 ; SET  0x01, (IX+0x00)->C
; set  0x01, (IX+0x00)->D
0afa dd cb ca 00 ; SET  0x01, (IX+0x00)->D
; set  0x01, (IX+0x00)->E
0afd dd cb cb 00 ; SET  0x01, (IX+0x00)->E
; set  0x01, (IX+0x00)->H
0b00 dd cb cc 00 ; SET  0x01, (IX+0x00)->H
; set  0x01, (IX+0x00)->L
0b03 dd cb cd 00 ; SET  0x01, (IX+0x00)->L
; set  0x01, (IX+0x00)
0b06 dd cb ce 00 ; SET  0x01, (IX+0x00)
; set  0x01, (IX+0x00)->A
0b09 dd cb cf 00 ; SET  0x01, (IX+0x00)->A
; set  0x02, (IX+0x00)->B
0b0c dd cb d0 00 ; SET  0x02, (IX+0x00)->B
; set  0x02, (IX+0x00)->C
0b0f dd cb d1 00 ; SET  0x02, (IX+0x00)->C
; set  0x02, (IX+0x00)->D
0b12 dd cb d2 00 ; SET  0x02, (IX+0x00)->D
; set  0x02, (IX+0x00)->E
0b15 dd cb d3 00 ; SET  0x02, (IX+0x00)->E
; set  0x02, (IX+0x00)->H
0b18 dd cb d4 00 ; SET  0x02, (IX+0x00)->H
; set  0x02, (IX+0x00)->L
0b1b dd cb d5 00 ; SET  0x02, (IX+0x00)->L
; set  0x02, (IX+0x00)
0b1e dd cb d6 00 ; SET  0x02, (IX+0x00)
; set  0x02, (IX+0x00)->A
0b21 dd cb d7 00 ; SET  0x02, (IX+0x00)->A
; set  0x03, (IX+0x00)->B
0b24 dd cb d8 00 ; SET  0x03, (IX+0x00)->B
; set  0x03, (IX+0x00)->C
0b27 dd cb d9 00 ; SET  0x03, (IX+0x00)->C
; set  0x03, (IX+0x00)->D
0b2a dd cb da 00 ; SET  0x03, (IX+0x00)->D
; set  0x03, (IX+0x00)->E
0b2d dd cb db 00 ; SET  0x03, (IX+0x00)->E
; set  0x03, (IX+0x00)->H
0b30 dd cb dc 00 ; SET  0x03, (IX+0x00)->H
; set  0x03, (IX+0x00)->L
0b33 dd cb dd 00 ; SET  0x03, (IX+0x00)->L
; set  0x03, (IX+0x00)
0b36 dd cb de 00 ; SET  0x03, (IX+0x00)
; set  0x03, (IX+0x00)->A
0b39 dd cb df 00 ; SET  0x03, (IX+0x00)->A
; set  0x04, (IX+0x00)->B
0b3c dd cb e0 00 ; SET  0x04, (IX+0x00)->B
; set  0x04, (IX+0x00)->C
0b3f dd cb e1 00 ; SET  0x04, (IX+0x00)->C
; set  0x04, (IX+0x00)->D
0b42 dd cb e2 00 ; SET  0x04, (IX+0x00)->D
; set  0x04, (IX+0x00)->E
0b45 dd cb e3 00 ; SET  0x04, (IX+0x00)->E
; set  0x04, (IX+0x00)->H
0b48 dd cb e4 00 ; SET  0x04, (IX+0x00)->H
; set  0x04, (IX+0x00)->L
0b4b dd cb e5 00 ; SET  0x04, (IX+0x00)->L
; set  0x04, (IX+0x00)
0b4e dd cb e6 00 ; SET  0x04, (IX+0x00)
; set  0x04, (IX+0x00)->A
0b51 dd cb e7 00 ; SET  0x04, (IX+0x00)->A
; set  0x05, (IX+0x00)->B
0b54 dd cb e8 00 ; SET  0x05, (IX+0x00)->B
; set  0x05, (IX+0x00)->C
0b57 dd cb e9 00 ; SET  0x05, (IX+0x00)->C
; set  0x05, (IX+0x00)->D
0b5a dd cb ea 00 ; SET  0x05, (IX+0x00)->D
; set  0x05, (IX+0x00)->E
0b5d dd cb eb 00 ; SET  0x05, (IX+0x00)->E
; set  0x05, (IX+0x00)->H
0b60 dd cb ec 00 ; SET  0x05, (IX+0x00)->H
; set  0x05, (IX+0x00)->L
0b63 dd cb ed 00 ; SET  0x05, (IX+0x00)->L
; set  0x05, (IX+0x00)
0b66 dd cb ee 00 ; SET  0x05, (IX+0x00)
; set  0x05, (IX+0x00)->A
0b69 dd cb ef 00 ; SET  0x05, (IX+0x00)->A
; set  0x06, (IX+0x00)->B
0b6c dd cb f0 00 ; SET  0x06, (IX+0x00)->B
; set  0x06, (IX+0x00)->C
0b6f dd cb f1 00 ; SET  0x06, (IX+0x00)->C
; set  0x06, (IX+0x00)->D
0b72 dd cb f2 00 ; SET  0x06, (IX+0x00)->D
; set  0x06, (IX+0x00)->E
0b75 dd cb f3 00 ; SET  0x06, (IX+0x00)->E
; set  0x06, (IX+0x00)->H
0b78 dd cb f4 00 ; SET  0x06, (IX+0x00)->H
; set  0x06, (IX+0x00)->L
0b7b dd cb f5 00 ; SET  0x06, (IX+0x00)->L
; set  0x06, (IX+0x00)
0b7e dd cb f6 00 ; SET  0x06, (IX+0x00)
; set  0x06, (IX+0x00)->A
0b81 dd cb f7 00 ; SET  0x06, (IX+0x00)->A
; set  0x07, (IX+0x00)->B
0b84 dd cb f8 00 ; SET  0x07, (IX+0x00)->B
; set  0x07, (IX+0x00)->C
0b87 dd cb f9 00 ; SET  0x07, (IX+0x00)->C
; set  0x07, (IX+0x00)->D
0b8a dd cb fa 00 ; SET  0x07, (IX+0x00)->D
; set  0x07, (IX+0x00)->E
0b8d dd cb fb 00 ; SET  0x07, (IX+0x00)->E
; set  0x07, (IX+0x00)->H
0b90 dd cb fc 00 ; SET  0x07, (IX+0x00)->H
; set  0x07, (IX+0x00)->L
0b93 dd cb fd 00 ; SET  0x07, (IX+0x00)->L
; set  0x07, (IX+0x00)
0b96 dd cb fe 00 ; SET  0x07, (IX+0x00)
; set  0x07, (IX+0x00)->A
0b99 dd cb ff 00 ; SET  0x07, (IX+0x00)->A
; rlc  (IY+0x00)->B
0b9c fd cb 00 00 ; RLC  (IY+0x00)->B
; rlc  (IY+0x00)->C
0ba1 fd cb 01 00 ; RLC  (IY+0x00)->C
; rlc  (IY+0x00)->D
0ba6 fd cb 02 00 ; RLC  (IY+0x00)->D
; rlc  (IY+0x00)->E
0bab fd cb 03 00 ; RLC  (IY+0x00)->E
; rlc  (IY+0x00)->H
0bb0 fd cb 04 00 ; RLC  (IY+0x00)->H
; rlc  (IY+0x00)->L
0bb5 fd cb 05 00 ; RLC  (IY+0x00)->L
; rlc  (IY+0x00)
0bba fd cb 06 00 ; RLC  (IY+0x00)
; rlc  (IY+0x00)->A
0bbf fd cb 07 00 ; RLC  (IY+0x00)->A
; rrc  (IY+0x00)->B
0bc4 fd cb 08 00 ; RRC  (IY+0x00)->B
; rrc  (IY+0x00)->C
0bc9 fd cb 09 00 ; RRC  (IY+0x00)->C
; rrc  (IY+0x00)->D
0bce fd cb 0a 00 ; RRC  (IY+0x00)->D
; rrc  (IY+0x00)->E
0bd3 fd cb 0b 00 ; RRC  (IY+0x00)->E
; rrc  (IY+0x00)->H
0bd8 fd cb 0c 00 ; RRC  (IY+0x00)->H
; rrc  (IY+0x00)->L
0bdd fd cb 0d 00 ; RRC  (IY+0x00)->L
; rrc  (IY+0x00)
0be2 fd cb 0e 00 ; RRC  (IY+0x00)
; rrc  (IY+0x00)->A
0be7 fd cb 0f 00 ; RRC  (IY+0x00)->A
; rl   (IY+0x00)->B
0bec fd cb 10 00 ; RL   (IY+0x00)->B
; rl   (IY+0x00)->C
0bf1 fd cb 11 00 ; RL   (IY+0x00)->C
; rl   (IY+0x00)->D
0bf6 fd cb 12 00 ; RL   (IY+0x00)->D
; rl   (IY+0x00)->E
0bfb fd cb 13 00 ; RL   (IY+0x00)->E
; rl   (IY+0x00)->H
0c00 fd cb 14 00 ; RL   (IY+0x00)->H
; rl   (IY+0x00)->L
0c05 fd cb 15 00 ; RL   (IY+0x00)->L
; rl   (IY+0x00)
0c0a fd cb 16 00 ; RL   (IY+0x00)
; rl   (IY+0x00)->A
0c0f fd cb 17 00 ; RL   (IY+0x00)->A
; rr   (IY+0x00)->B
0c14 fd cb 18 00 ; RR   (IY+0x00)->B
; rr   (IY+0x00)->C
0c19 fd cb 19 00 ; RR   (IY+0x00)->C
; rr   (IY+0x00)->D
0c1e fd cb 1a 00 ; RR   (IY+0x00)->D
; rr   (IY+0x00)->E
0c23 fd cb 1b 00 ; RR   (IY+0x00)->E
; rr   (IY+0x00)->H
0c28 fd cb 1c 00 ; RR   (IY+0x00)->H
; rr   (IY+0x00)->L
0c2d fd cb 1d 00 ; RR   (IY+0x00)->L
; rr   (IY+0x00)
0c32 fd cb 1e 00 ; RR   (IY+0x00)
; rr   (IY+0x00)->A
0c37 fd cb 1f 00 ; RR   (IY+0x00)->A
; sla  (IY+0x00)->B
0c3c fd cb 20 00 ; SLA  (IY+0x00)->B
; sla  (IY+0x00)->C
0c41 fd cb 21 00 ; SLA  (IY+0x00)->C
; sla  (IY+0x00)->D
0c46 fd cb 22 00 ; SLA  (IY+0x00)->D
; sla  (IY+0x00)->E
0c4b fd cb 23 00 ; SLA  (IY+0x00)->E
; sla  (IY+0x00)->H
0c50 fd cb 24 00 ; SLA  (IY+0x00)->H
; sla  (IY+0x00)->L
0c55 fd cb 25 00 ; SLA  (IY+0x00)->L
; sla  (IY+0x00)
0c5a fd cb 26 00 ; SLA  (IY+0x00)
; sla  (IY+0x00)->A
0c5f fd cb 27 00 ; SLA  (IY+0x00)->A
; sra  (IY+0x00)->B
0c64 fd cb 28 00 ; SRA  (IY+0x00)->B
; sra  (IY+0x00)->C
0c69 fd cb 29 00 ; SRA  (IY+0x00)->C
; sra  (IY+0x00)->D
0c6e fd cb 2a 00 ; SRA  (IY+0x00)->D
; sra  (IY+0x00)->E
0c73 fd cb 2b 00 ; SRA  (IY+0x00)->E
; sra  (IY+0x00)->H
0c78 fd cb 2c 00 ; SRA  (IY+0x00)->H
; sra  (IY+0x00)->L
0c7d fd cb 2d 00 ; SRA  (IY+0x00)->L
; sra  (IY+0x00)
0c82 fd cb 2e 00 ; SRA  (IY+0x00)
; sra  (IY+0x00)->A
0c87 fd cb 2f 00 ; SRA  (IY+0x00)->A
; sll  (IY+0x00)->B
0c8c fd cb 30 00 ; SLL  (IY+0x00)->B
; sll  (IY+0x00)->C
0c91 fd cb 31 00 ; SLL  (IY+0x00)->C
; sll  (IY+0x00)->D
0c96 fd cb 32 00 ; SLL  (IY+0x00)->D
; sll  (IY+0x00)->E
0c9b fd cb 33 00 ; SLL  (IY+0x00)->E
; sll  (IY+0x00)->H
0ca0 fd cb 34 00 ; SLL  (IY+0x00)->H
; sll  (IY+0x00)->L
0ca5 fd cb 35 00 ; SLL  (IY+0x00)->L
; sll  (IY+0x00)
0caa fd cb 36 00 ; SLL  (IY+0x00)
; sll  (IY+0x00)->A
0caf fd cb 37 00 ; SLL  (IY+0x00)->A
; srl  (IY+0x00)->B
0cb4 fd cb 38 00 ; SRL  (IY+0x00)->B
; srl  (IY+0x00)->C
0cb9 fd cb 39 00 ; SRL  (IY+0x00)->C
; srl  (IY+0x00)->D
0cbe fd cb 3a 00 ; SRL  (IY+0x00)->D
; srl  (IY+0x00)->E
0cc3 fd cb 3b 00 ; SRL  (IY+0x00)->E
; srl  (IY+0x00)->H
0cc8 fd cb 3c 00 ; SRL  (IY+0x00)->H
; srl  (IY+0x00)->L
0ccd fd cb 3d 00 ; SRL  (IY+0x00)->L
; srl  (IY+0x00)
0cd2 fd cb 3e 00 ; SRL  (IY+0x00)
; srl  (IY+0x00)->A
0cd7 fd cb 3f 00 ; SRL  (IY+0x00)->A
; bit  0x00, (IY+0x00)
0cdc fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0cdf fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0ce2 fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0ce5 fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0ce8 fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0ceb fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0cee fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x00, (IY+0x00)
0cf1 fd cb 40 00 ; BIT  0x00, (IY+0x00)
; bit  0x01, (IY+0x00)
0cf4 fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0cf7 fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0cfa fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0cfd fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0d00 fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0d03 fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0d06 fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x01, (IY+0x00)
0d09 fd cb 48 00 ; BIT  0x01, (IY+0x00)
; bit  0x02, (IY+0x00)
0d0c fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d0f fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d12 fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d15 fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d18 fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d1b fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d1e fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x02, (IY+0x00)
0d21 fd cb 50 00 ; BIT  0x02, (IY+0x00)
; bit  0x03, (IY+0x00)
0d24 fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d27 fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d2a fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d2d fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d30 fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d33 fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d36 fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x03, (IY+0x00)
0d39 fd cb 58 00 ; BIT  0x03, (IY+0x00)
; bit  0x04, (IY+0x00)
0d3c fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d3f fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d42 fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d45 fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d48 fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d4b fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d4e fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x04, (IY+0x00)
0d51 fd cb 60 00 ; BIT  0x04, (IY+0x00)
; bit  0x05, (IY+0x00)
0d54 fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d57 fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d5a fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d5d fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d60 fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d63 fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d66 fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x05, (IY+0x00)
0d69 fd cb 68 00 ; BIT  0x05, (IY+0x00)
; bit  0x06, (IY+0x00)
0d6c fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d6f fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d72 fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d75 fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d78 fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d7b fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d7e fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x06, (IY+0x00)
0d81 fd cb 70 00 ; BIT  0x06, (IY+0x00)
; bit  0x07, (IY+0x00)
0d84 fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d87 fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d8a fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d8d fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d90 fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d93 fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d96 fd cb 78 00 ; BIT  0x07, (IY+0x00)
; bit  0x07, (IY+0x00)
0d99 fd cb 78 00 ; BIT  0x07, (IY+0x00)
; res  0x00, (IY+0x00)->B
0d9c fd cb 80 00 ; RES  0x00, (IY+0x00)->B
; res  0x00, (IY+0x00)->C
0d9f fd cb 81 00 ; RES  0x00, (IY+0x00)->C
; res  0x00, (IY+0x00)->D
0da2 fd cb 82 00 ; RES  0x00, (IY+0x00)->D
; res  0x00, (IY+0x00)->E
0da5 fd cb 83 00 ; RES  0x00, (IY+0x00)->E
; res  0x00, (IY+0x00)->H
0da8 fd cb 84 00 ; RES  0x00, (IY+0x00)->H
; res  0x00, (IY+0x00)->L
0dab fd cb 85 00 ; RES  0x00, (IY+0x00)->L
; res  0x00, (IY+0x00)
0dae fd cb 86 00 ; RES  0x00, (IY+0x00)
; res  0x00, (IY+0x00)->A
0db1 fd cb 87 00 ; RES  0x00, (IY+0x00)->A
; res  0x01, (IY+0x00)->B
0db4 fd cb 88 00 ; RES  0x01, (IY+0x00)->B
; res  0x01, (IY+0x00)->C
0db7 fd cb 89 00 ; RES  0x01, (IY+0x00)->C
; res  0x01, (IY+0x00)->D
0dba fd cb 8a 00 ; RES  0x01, (IY+0x00)->D
; res  0x01, (IY+0x00)->E
0dbd fd cb 8b 00 ; RES  0x01, (IY+0x00)->E
; res  0x01, (IY+0x00)->H
0dc0 fd cb 8c 00 ; RES  0x01, (IY+0x00)->H
; res  0x01, (IY+0x00)->L
0dc3 fd cb 8d 00 ; RES  0x01, (IY+0x00)->L
; res  0x01, (IY+0x00)
0dc6 fd cb 8e 00 ; RES  0x01, (IY+0x00)
; res  0x01, (IY+0x00)->A
0dc9 fd cb 8f 00 ; RES  0x01, (IY+0x00)->A
; res  0x02, (IY+0x00)->B
0dcc fd cb 90 00 ; RES  0x02, (IY+0x00)->B
; res  0x02, (IY+0x00)->C
0dcf fd cb 91 00 ; RES  0x02, (IY+0x00)->C
; res  0x02, (IY+0x00)->D
0dd2 fd cb 92 00 ; RES  0x02, (IY+0x00)->D
; res  0x02, (IY+0x00)->E
0dd5 fd cb 93 00 ; RES  0x02, (IY+0x00)->E
; res  0x02, (IY+0x00)->H
0dd8 fd cb 94 00 ; RES  0x02, (IY+0x00)->H
; res  0x02, (IY+0x00)->L
0ddb fd cb 95 00 ; RES  0x02, (IY+0x00)->L
; res  0x02, (IY+0x00)
0dde fd cb 96 00 ; RES  0x02, (IY+0x00)
; res  0x02, (IY+0x00)->A
0de1 fd cb 97 00 ; RES  0x02, (IY+0x00)->A
; res  0x03, (IY+0x00)->B
0de4 fd cb 98 00 ; RES  0x03, (IY+0x00)->B
; res  0x03, (IY+0x00)->C
0de7 fd cb 99 00 ; RES  0x03, (IY+0x00)->C
; res  0x03, (IY+0x00)->D
0dea fd cb 9a 00 ; RES  0x03, (IY+0x00)->D
; res  0x03, (IY+0x00)->E
0ded fd cb 9b 00 ; RES  0x03, (IY+0x00)->E
; res  0x03, (IY+0x00)->H
0df0 fd cb 9c 00 ; RES  0x03, (IY+0x00)->H
; res  0x03, (IY+0x00)->L
0df3 fd cb 9d 00 ; RES  0x03, (IY+0x00)->L
; res  0x03, (IY+0x00)
0df6 fd cb 9e 00 ; RES  0x03, (IY+0x00)
; res  0x03, (IY+0x00)->A
0df9 fd cb 9f 00 ; RES  0x03, (IY+0x00)->A
; res  0x04, (IY+0x00)->B
0dfc fd cb a0 00 ; RES  0x04, (IY+0x00)->B
; res  0x04, (IY+0x00)->C
0dff fd cb a1 00 ; RES  0x04, (IY+0x00)->C
; res  0x04, (IY+0x00)->D
0e02 fd cb a2 00 ; RES  0x04, (IY+0x00)->D
; res  0x04, (IY+0x00)->E
0e05 fd cb a3 00 ; RES  0x04, (IY+0x00)->E
; res  0x04, (IY+0x00)->H
0e08 fd cb a4 00 ; RES  0x04, (IY+0x00)->H
; res  0x04, (IY+0x00)->L
0e0b fd cb a5 00 ; RES  0x04, (IY+0x00)->L
; res  0x04, (IY+0x00)
0e0e fd cb a6 00 ; RES  0x04, (IY+0x00)
; res  0x04, (IY+0x00)->A
0e11 fd cb a7 00 ; RES  0x04, (IY+0x00)->A
; res  0x05, (IY+0x00)->B
0e14 fd cb a8 00 ; RES  0x05, (IY+0x00)->B
; res  0x05, (IY+0x00)->C
0e17 fd cb a9 00 ; RES  0x05, (IY+0x00)->C
; res  0x05, (IY+0x00)->D
0e1a fd cb aa 00 ; RES  0x05, (IY+0x00)->D
; res  0x05, (IY+0x00)->E
0e1d fd cb ab 00 ; RES  0x05, (IY+0x00)->E
; res  0x05, (IY+0x00)->H
0e20 fd cb ac 00 ; RES  0x05, (IY+0x00)->H
; res  0x05, (IY+0x00)->L
0e23 fd cb ad 00 ; RES  0x05, (IY+0x00)->L
; res  0x05, (IY+0x00)
0e26 fd cb ae 00 ; RES  0x05, (IY+0x00)
; res  0x05, (IY+0x00)->A
0e29 fd cb af 00 ; RES  0x05, (IY+0x00)->A
; res  0x06, (IY+0x00)->B
0e2c fd cb b0 00 ; RES  0x06, (IY+0x00)->B
; res  0x06, (IY+0x00)->C
0e2f fd cb b1 00 ; RES  0x06, (IY+0x00)->C
; res  0x06, (IY+0x00)->D
0e32 fd cb b2 00 ; RES  0x06, (IY+0x00)->D
; res  0x06, (IY+0x00)->E
0e35 fd cb b3 00 ; RES  0x06, (IY+0x00)->E
; res  0x06, (IY+0x00)->H
0e38 fd cb b4 00 ; RES  0x06, (IY+0x00)->H
; res  0x06, (IY+0x00)->L
0e3b fd cb b5 00 ; RES  0x06, (IY+0x00)->L
; res  0x06, (IY+0x00)
0e3e fd cb b6 00 ; RES  0x06, (IY+0x00)
; res  0x06, (IY+0x00)->A
0e41 fd cb b7 00 ; RES  0x06, (IY+0x00)->A
; res  0x07, (IY+0x00)->B
0e44 fd cb b8 00 ; RES  0x07, (IY+0x00)->B
; res  0x07, (IY+0x00)->C
0e47 fd cb b9 00 ; RES  0x07, (IY+0x00)->C
; res  0x07, (IY+0x00)->D
0e4a fd cb ba 00 ; RES  0x07, (IY+0x00)->D
; res  0x07, (IY+0x00)->E
0e4d fd cb bb 00 ; RES  0x07, (IY+0x00)->E
; res  0x07, (IY+0x00)->H
0e50 fd cb bc 00 ; RES  0x07, (IY+0x00)->H
; res  0x07, (IY+0x00)->L
0e53 fd cb bd 00 ; RES  0x07, (IY+0x00)->L
; res  0x07, (IY+0x00)
0e56 fd cb be 00 ; RES  0x07, (IY+0x00)
; res  0x07, (IY+0x00)->A
0e59 fd cb bf 00 ; RES  0x07, (IY+0x00)->A
; set  0x00, (IY+0x00)->B
0e5c fd cb c0 00 ; SET  0x00, (IY+0x00)->B
; set  0x00, (IY+0x00)->C
0e5f fd cb c1 00 ; SET  0x00, (IY+0x00)->C
; set  0x00, (IY+0x00)->D
0e62 fd cb c2 00 ; SET  0x00, (IY+0x00)->D
; set  0x00, (IY+0x00)->E
0e65 fd cb c3 00 ; SET  0x00, (IY+0x00)->E
; set  0x00, (IY+0x00)->H
0e68 fd cb c4 00 ; SET  0x00, (IY+0x00)->H
; set  0x00, (IY+0x00)->L
0e6b fd cb c5 00 ; SET  0x00, (IY+0x00)->L
; set  0x00, (IY+0x00)
0e6e fd cb c6 00 ; SET  0x00, (IY+0x00)
; set  0x00, (IY+0x00)->A
0e71 fd cb c7 00 ; SET  0x00, (IY+0x00)->A
; set  0x01, (IY+0x00)->B
0e74 fd cb c8 00 ; SET  0x01, (IY+0x00)->B
; set  0x01, (IY+0x00)->C
0e77 fd cb c9 00 ; SET  0x01, (IY+0x00)->C
; set  0x01, (IY+0x00)->D
0e7a fd cb ca 00 ; SET  0x01, (IY+0x00)->D
; set  0x01, (IY+0x00)->E
0e7d fd cb cb 00 ; SET  0x01, (IY+0x00)->E
; set  0x01, (IY+0x00)->H
0e80 fd cb cc 00 ; SET  0x01, (IY+0x00)->H
; set  0x01, (IY+0x00)->L
0e83 fd cb cd 00 ; SET  0x01, (IY+0x00)->L
; set  0x01, (IY+0x00)
0e86 fd cb ce 00 ; SET  0x01, (IY+0x00)
; set  0x01, (IY+0x00)->A
0e89 fd cb cf 00 ; SET  0x01, (IY+0x00)->A
; set  0x02, (IY+0x00)->B
0e8c fd cb d0 00 ; SET  0x02, (IY+0x00)->B
; set  0x02, (IY+0x00)->C
0e8f fd cb d1 00 ; SET  0x02, (IY+0x00)->C
; set  0x02, (IY+0x00)->D
0e92 fd cb d2 00 ; SET  0x02, (IY+0x00)->D
; set  0x02, (IY+0x00)->E
0e95 fd cb d3 00 ; SET  0x02, (IY+0x00)->E
; set  0x02, (IY+0x00)->H
0e98 fd cb d4 00 ; SET  0x02, (IY+0x00)->H
; set  0x02, (IY+0x00)->L
0e9b fd cb d5 00 ; SET  0x02, (IY+0x00)->L
; set  0x02, (IY+0x00)
0e9e fd cb d6 00 ; SET  0x02, (IY+0x00)
; set  0x02, (IY+0x00)->A
0ea1 fd cb d7 00 ; SET  0x02, (IY+0x00)->A
; set  0x03, (IY+0x00)->B
0ea4 fd cb d8 00 ; SET  0x03, (IY+0x00)->B
; set  0x03, (IY+0x00)->C
0ea7 fd cb d9 00 ; SET  0x03, (IY+0x00)->C
; set  0x03, (IY+0x00)->D
0eaa fd cb da 00 ; SET  0x03, (IY+0x00)->D
; set  0x03, (IY+0x00)->E
0ead fd cb db 00 ; SET  0x03, (IY+0x00)->E
; set  0x03, (IY+0x00)->H
0eb0 fd cb dc 00 ; SET  0x03, (IY+0x00)->H
; set  0x03, (IY+0x00)->L
0eb3 fd cb dd 00 ; SET  0x03, (IY+0x00)->L
; set  0x03, (IY+0x00)
0eb6 fd cb de 00 ; SET  0x03, (IY+0x00)
; set  0x03, (IY+0x00)->A
0eb9 fd cb df 00 ; SET  0x03, (IY+0x00)->A
; set  0x04, (IY+0x00)->B
0ebc fd cb e0 00 ; SET  0x04, (IY+0x00)->B
; set  0x04, (IY+0x00)->C
0ebf fd cb e1 00 ; SET  0x04, (IY+0x00)->C
; set  0x04, (IY+0x00)->D
0ec2 fd cb e2 00 ; SET  0x04, (IY+0x00)->D
; set  0x04, (IY+0x00)->E
0ec5 fd cb e3 00 ; SET  0x04, (IY+0x00)->E
; set  0x04, (IY+0x00)->H
0ec8 fd cb e4 00 ; SET  0x04, (IY+0x00)->H
; set  0x04, (IY+0x00)->L
0ecb fd cb e5 00 ; SET  0x04, (IY+0x00)->L
; set  0x04, (IY+0x00)
0ece fd cb e6 00 ; SET  0x04, (IY+0x00)
; set  0x04, (IY+0x00)->A
0ed1 fd cb e7 00 ; SET  0x04, (IY+0x00)->A
; set  0x05, (IY+0x00)->B
0ed4 fd cb e8 00 ; SET  0x05, (IY+0x00)->B
; set  0x05, (IY+0x00)->C
0ed7 fd cb e9 00 ; SET  0x05, (IY+0x00)->C
; set  0x05, (IY+0x00)->D
0eda fd cb ea 00 ; SET  0x05, (IY+0x00)->D
; set  0x05, (IY+0x00)->E
0edd fd cb eb 00 ; SET  0x05, (IY+0x00)->E
; set  0x05, (IY+0x00)->H
0ee0 fd cb ec 00 ; SET  0x05, (IY+0x00)->H
; set  0x05, (IY+0x00)->L
0ee3 fd cb ed 00 ; SET  0x05, (IY+0x00)->L
; set  0x05, (IY+0x00)
0ee6 fd cb ee 00 ; SET  0x05, (IY+0x00)
; set  0x05, (IY+0x00)->A
0ee9 fd cb ef 00 ; SET  0x05, (IY+0x00)->A
; set  0x06, (IY+0x00)->B
0eec fd cb f0 00 ; SET  0x06, (IY+0x00)->B
; set  0x06, (IY+0x00)->C
0eef fd cb f1 00 ; SET  0x06, (IY+0x00)->C
; set  0x06, (IY+0x00)->D
0ef2 fd cb f2 00 ; SET  0x06, (IY+0x00)->D
; set  0x06, (IY+0x00)->E
0ef5 fd cb f3 00 ; SET  0x06, (IY+0x00)->E
; set  0x06, (IY+0x00)->H
0ef8 fd cb f4 00 ; SET  0x06, (IY+0x00)->H
; set  0x06, (IY+0x00)->L
0efb fd cb f5 00 ; SET  0x06, (IY+0x00)->L
; set  0x06, (IY+0x00)
0efe fd cb f6 00 ; SET  0x06, (IY+0x00)
; set  0x06, (IY+0x00)->A
0f01 fd cb f7 00 ; SET  0x06, (IY+0x00)->A
; set  0x07, (IY+0x00)->B
0f04 fd cb f8 00 ; SET  0x07, (IY+0x00)->B
; set  0x07, (IY+0x00)->C
0f07 fd cb f9 00 ; SET  0x07, (IY+0x00)->C
; set  0x07, (IY+0x00)->D
0f0a fd cb fa 00 ; SET  0x07, (IY+0x00)->D
; set  0x07, (IY+0x00)->E
0f0d fd cb fb 00 ; SET  0x07, (IY+0x00)->E
; set  0x07, (IY+0x00)->H
0f10 fd cb fc 00 ; SET  0x07, (IY+0x00)->H
; set  0x07, (IY+0x00)->L
0f13 fd cb fd 00 ; SET  0x07, (IY+0x00)->L
; set  0x07, (IY+0x00)
0f16 fd cb fe 00 ; SET  0x07, (IY+0x00)
; set  0x07, (IY+0x00)->A
0f19 fd cb ff 00 ; SET  0x07, (IY+0x00)->A

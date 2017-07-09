                   ; ORG  0x0100
0100 c3 13 01      ; JP   LABEL_1
                   ; msbt:
                   ; DEFS 0x000e
                   ; LABEL_340:
                   ; DEFS 0x0002
                   ; LABEL_1:
0113 2a 06 00      ; LD   HL, (0x0006)
0116 f9            ; LD   SP, HL
0117 11 da 1d      ; LD   DE, 0x1dda
011a 0e 09         ; LD   C, 0x09
011c cd c6 1d      ; CALL LABEL_2
011f 21 3a 01      ; LD   HL, LABEL_6
                   ; LABEL_5:
0122 7e            ; LD   A, (HL)
0123 23            ; INC  HL
0124 b6            ; OR   (HL)
0125 ca 2f 01      ; JP   Z, LABEL_3
0128 2b            ; DEC  HL
0129 cd da 1a      ; CALL LABEL_4
012c c3 22 01      ; JP   LABEL_5
                   ; LABEL_3:
012f 11 f6 1d      ; LD   DE, 0x1df6
0132 0e 09         ; LD   C, 0x09
0134 cd c6 1d      ; CALL LABEL_2
0137 c3 3a 01      ; JP   LABEL_6
                   ; LABEL_6:
013a 76            ; HALT
                   ; tests:
013b c3 01         ; DEFW 0x01c3
013d 21 02         ; DEFW 0x0221

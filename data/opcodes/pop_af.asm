                   ; ORG  0x0100
0100 01 00 12      ; LD   BC, 0x1200
                   ; again:
0103 c5            ; PUSH BC
0104 f1            ; POP  AF
0105 f5            ; PUSH AF
0106 d1            ; POP  DE
0107 79            ; LD   A, C
0108 e6 f0         ; AND  0xf0
010a bb            ; CP   E
010b c2 1d 01      ; JP   NZ, failed
010e 04            ; INC  B
010f 0c            ; INC  C
0110 20 f1         ; JR   NZ, 0x0101
                   ; success:
0112 df            ; RST  0x18
0113 a5            ; DEFB 0xa5
0114 53 55 43 43 45 53 53 ; DEFB "SUCCESS"
011b 00            ; DEFB 0x00
011c 76            ; HALT
                   ; failed:
011d df            ; RST  0x18
011e a5            ; DEFB 0xa5
011f 46 41 49 4c 45 44 ; DEFB "FAILED"
0125 00            ; DEFB 0x00
0126 76            ; HALT

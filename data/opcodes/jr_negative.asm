                   ; ORG  0x0100
0100 3e 00         ; LD   A, 0x00
0102 c3 10 01      ; JP   jr_neg
0105 3c            ; INC  A
                   ; again:
0106 3c            ; INC  A
0107 3c            ; INC  A
0108 fe 02         ; CP   0x02
010a c2 1d 01      ; JP   NZ, failed
010d c3 12 01      ; JP   success
                   ; jr_neg:
0110 18 f4         ; JR   0x0104
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

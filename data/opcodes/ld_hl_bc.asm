                   ; ORG  0x0100
0100 11 34 12      ; LD   DE, 0x1234
0103 01 ff ff      ; LD   BC, 0xffff
                   ; again:
0106 d5            ; PUSH DE
0107 e1            ; POP  HL
0108 09            ; ADD  HL, BC
0109 df            ; RST  0x18
010a 90            ; DEFB 0x90
                   ; success:
010b df            ; RST  0x18
010c a5            ; DEFB 0xa5
010d 53 55 43 43 45 53 53 ; DEFB "SUCCESS"
0114 00            ; DEFB 0x00
0115 76            ; HALT

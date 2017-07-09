                   ; ORG  0x0d00
0d00 3e 00         ; LD   A, 0x00
0d02 c6 02         ; ADD  A, 0x02
0d04 c6 03         ; ADD  A, 0x03
0d06 c6 06         ; ADD  A, 0x06
0d08 df            ; RST  0x18
0d09 80            ; DEFB 0x80
0d0a 76            ; HALT

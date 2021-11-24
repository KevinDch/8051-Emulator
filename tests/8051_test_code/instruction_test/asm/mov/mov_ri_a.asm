.area HOME (CODE)
.area XSEG (CODE)
.area PSEG (CODE)

MOV R0, #0x16
MOV R1, #0x17

MOV A, #0xFF

MOV @R0, A
MOV @R1, A

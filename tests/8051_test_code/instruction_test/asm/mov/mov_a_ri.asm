.area HOME (CODE)
.area XSEG (CODE)
.area PSEG (CODE)

MOV R0, #0x16
MOV R1, #0x17

MOV 0x16, #0x17
MOV 0x17, #0x18

MOV A, @R0
MOV A, @R1

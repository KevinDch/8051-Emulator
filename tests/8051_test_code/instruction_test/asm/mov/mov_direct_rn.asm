.area CSEG    (CODE)
.area CONST   (CODE)
.area XINIT   (CODE)
.area HOME    (CODE)
.area XSEG    (CODE)
.area PSEG    (CODE)
.area CABS    (ABS,CODE)
.area RSEG    (ABS,DATA)

.org 0x0000

MOV 0x16, R0
MOV 0x17, R1
MOV 0x18, R2
MOV 0x19, R3
MOV 0x1A, R4
MOV 0x1B, R5
MOV 0x1C, R6
MOV 0x1D, R7

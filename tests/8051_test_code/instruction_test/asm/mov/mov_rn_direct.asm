.area CSEG    (CODE)
.area CONST   (CODE)
.area XINIT   (CODE)
.area HOME    (CODE)
.area XSEG    (CODE)
.area PSEG    (CODE)
.area CABS    (ABS,CODE)
.area RSEG    (ABS,DATA)

.org 0x0000

MOV R0, 0x16
MOV R1, 0x17
MOV R2, 0x18
MOV R3, 0x19
MOV R4, 0x1A
MOV R5, 0x1B
MOV R6, 0x1C
MOV R7, 0x1D

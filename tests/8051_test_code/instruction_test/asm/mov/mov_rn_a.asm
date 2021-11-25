.area CSEG    (CODE)
.area CONST   (CODE)
.area XINIT   (CODE)
.area HOME    (CODE)
.area XSEG    (CODE)
.area PSEG    (CODE)
.area CABS    (ABS,CODE)
.area RSEG    (ABS,DATA)

.org 0x0000

MOV A, #0x16

MOV R0, A
MOV R1, A
MOV R2, A
MOV R3, A
MOV R4, A
MOV R5, A
MOV R6, A
MOV R7, A

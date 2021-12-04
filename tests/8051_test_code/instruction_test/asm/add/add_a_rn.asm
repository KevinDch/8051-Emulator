.area CSEG    (CODE)
.area CONST   (CODE)
.area XINIT   (CODE)
.area HOME    (CODE)
.area XSEG    (CODE)
.area PSEG    (CODE)
.area CABS    (ABS,CODE)
.area RSEG    (ABS,DATA)

.org 0x0000

MOV R0, #0x90
MOV R1, #0x91
MOV R2, #0x92
MOV R3, #0x93
MOV R4, #0x94
MOV R5, #0x95
MOV R6, #0x96
MOV R7, #0x97

ADD A, R0
MOV A, #0x00

ADD A, R1
MOV A, #0x00

ADD A, R2
MOV A, #0x00

ADD A, R3
MOV A, #0x00

ADD A, R4
MOV A, #0x00

ADD A, R5
MOV A, #0x00

ADD A, R6
MOV A, #0x00

ADD A, R7

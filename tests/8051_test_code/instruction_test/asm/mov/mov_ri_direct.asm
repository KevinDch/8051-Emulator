.area CSEG    (CODE)
.area CONST   (CODE)
.area XINIT   (CODE)
.area HOME    (CODE)
.area XSEG    (CODE)
.area PSEG    (CODE)
.area CABS    (ABS,CODE)
.area RSEG    (ABS,DATA)

.org 0x0000

MOV R0, #0x16
MOV R1, #0x17

MOV 0x18, #0x18
MOV 0x19, #0x19

MOV @R0, 0x18
MOV @R1, 0x19

.area CSEG    (CODE)
.area CONST   (CODE)
.area XINIT   (CODE)
.area HOME    (CODE)
.area XSEG    (CODE)
.area PSEG    (CODE)
.area CABS    (ABS,CODE)
.area RSEG    (ABS,DATA)

ACALL _start

.org 0x02FF

_start:

MOV A, #0xFF

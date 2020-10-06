.arm 
.text 
.global main  

main: 
STMDB R13!,{R0-R12, R14} 
MOV R6, #00 
LDR R0, =Stor

Loop:
STRB R6,[R0],#4
ADD R6,R6,#1
CMP R6,#6
BNE Loop
LDMIA R13!, {R0-R12, PC}

.data 
Stor:      .skip  24


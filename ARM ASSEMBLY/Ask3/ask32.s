.arm 
.text 
.global main  

main: 
STMDB R13!,{R0-R12, R14} 
MOV R6, #00 
MOV R1, #01
MOV R2, #02
MOV R3, #00
LDR R0, =Stor

Loop:
ADD R3,R1,R2
MOV R1,R2
MOV R2,R3
STRB R3,[R0],#4
ADD R6,R6,#1
CMP R6,#6
BNE Loop
LDMIA R13!, {R0-R12, PC}

.data 
Stor:       .skip 24



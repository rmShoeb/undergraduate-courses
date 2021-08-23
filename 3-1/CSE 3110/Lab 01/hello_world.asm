.MODEL SMALL
.STACK 100H
.DATA
STR DB 'HELLO WORLD$'

.CODE
    MAIN PROC
        LEA DX, STR
        MOV AH, 9
        INT 21H
        
        MOV AH, 4CH
        INT 21H
    MAIN ENDP
    
END MAIN

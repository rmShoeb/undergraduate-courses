INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 200H
.DATA
INPUT1 DB 'THIS IS RUET$'
INPUT2 DB 'RAJSHAHI$'

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        PRINT 'FIRST INPUT'
        LEA DX, INPUT1
        MOV AH, 9
        INT 21H
        CALL NEWLINE
        LEA DX, INPUT2
        INT 21H
        
        PRINT 'ENTER THE POSITION TO MERGE'
        MOV AH, 1
        INT 21H         ;AL HAS THE POSITION
        
        XOR AH, AH
        SUB AX, 30H
        CALL NEWLINE
        
        CALL MERGE
        
        MOV AH, 4CH
        INT 21H
        
        MAIN ENDP
    
    ;CUSTOM PROCEDURES
    NEWLINE PROC        ;PRINTS NEWLINE
        MOV AH, 2
        MOV DX, 0AH
        INT 21H
        MOV DX, ODH
        INT 21H
        
        RET
        NEWLINE ENDP
    
    MERGE PROC
        ;INCOMPLETE
        
        RET
        MERGE ENDP
    END MAIN

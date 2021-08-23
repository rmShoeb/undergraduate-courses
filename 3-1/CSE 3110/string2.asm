INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
INPUT_ARRAY DB 'a', 'b', 'c', 'd', 'e'
            DB 'f', 'g', 'h', 'i', 'j'
            DB 'k', 'l', 'm', 'n', 'o'

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        PRINTN 'INPUT ARRAY:'
        CALL PRINT_ARRAY
        
        PRINT 'ENTER ROW NUMBER TO BE CHANGED'
        MOV AH, 1
        INT 21H
        MOV BL, AL
        ;HAVE TO MULTIPLY BL BY 5
        MOV AL, 5
        SUB BL, 30H
        MUL BL
        MOV BL, AL
        XOR BH, BH  ;NOW BX HAS 5 TIMES OF WHAT AL HAD
        CALL NEWLINE
        
        CALL REPLACE_WITH_STAR
        PRINTN 'OUTPUT:'
        CALL PRINT_ARRAY
        
        MOV AH, 4CH
        INT 21H
        
        MAIN ENDP
    
    ;CUSTOM PROCEDURES
    REPLACE_WITH_STAR PROC
        MOV CX, 5
        MOV AL, 2AH
        ;LEA SI, INPUT_ARRAY
        MOV SI, 0
        REPLACE_ONE_CHARACTER:
            MOV INPUT_ARRAY[BX][SI], AL
            ;MOV [INPUT_ARRAY+BX+SI], AL
            INC SI
            LOOP REPLACE_ONE_CHARACTER
        RET
        REPLACE_WITH_STAR ENDP
    
    PRINT_ARRAY PROC
        LEA SI, INPUT_ARRAY
        MOV BH, 0
        MOV AH, 2
        MOV CX, 15
        PRINT_SINGLE_CHARACTER:
            MOV DL, [SI]
            INT 21H
            INC SI
            INC BH
            CMP BH, 5
            JE GOTO_NEWLINE
            CMP BH, 10
            JE GOTO_NEWLINE
            CMP BH, 15
            JE GOTO_NEWLINE
            PRINT_SPACE:
                MOV DL, 20H
                INT 21H
                JMP END_LOOP
            GOTO_NEWLINE:
                CALL NEWLINE
            END_LOOP:
                LOOP PRINT_SINGLE_CHARACTER
        RET
        PRINT_ARRAY ENDP
    
    NEWLINE PROC
        MOV AH, 2
        MOV DX, 0AH
        INT 21H
        MOV DX, 0DH
        INT 21H
        
        RET
        NEWLINE ENDP
    
    END MAIN

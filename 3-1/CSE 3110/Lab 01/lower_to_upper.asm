.MODEL SAMLL
.STACK 100H
.DATA
INPUT_MSG DB 'ENTER A LOWERCASE LETTER: $'
OUTPUT_MSG DB 'The uppercase letter: $'
ERROR_MSG DB 'INPUT IS NOT CORRECT.$'

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        MOV AH, 9
        LEA DX, INPUT_MSG
        INT 21H      ;print input prompt
        
        MOV AH, 1
        INT 21H      ;taking input
        MOV BL,AL
        
        ;INT 21H      ;to take another input (newline)   
        
        ;to print newline
        MOV AH, 2
        MOV DL, 10
        INT 21H
        MOV DL, 13
        INT 21H
        
        ;CHECKINGS
        CMP BL, 97
        JGE PRINT_LOWER
        
        ;IF NOT LOWER
        ERROR:
            LEA DX, ERROR_MSG
            MOV AH, 9
            INT 21H
            JMP REST
                                  
        PRINT_LOWER:
            LEA DX, OUTPUT_MSG
            MOV AH, 9    
            INT 21H      ;print output prompt
            
            ;PRINTING OUTPUT
            ;MOV BL, AL
            SUB BL, 32
            MOV DL, BL
            MOV AH, 2
            INT 21H
            
        REST:
        
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
    END MAIN
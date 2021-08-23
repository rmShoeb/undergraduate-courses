.MODEL SMALL
.STACK 100H
.DATA
INPUT_MSG DB 'ENTER A STRING (END WITH A *): $'
OUTPUT_MSG DB 'FIRST AND LAST UPPERCASE LETTER: $'
UPPERCASE_COUNTER DB 0                         ;TO FIND FIRST AND LAST UPPERCASE LETTER

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        ;INPUT PROMPT
        MOV AH, 9
        LEA DX, INPUT_MSG
        INT 21H
        
        ;INPUT SECTION
        MOV BL, '*'                  ;TO COMPARE LATER
        INPUT_SECTION:
            MOV AH, 1
            INT 21H
            
            MOV BH, AL
            ;IF INPUT=='*'
            CMP AL, BL               
            JE OUTPUT_SECTION
            ;ELSE IF INPUT>=65 AND INPUT<=90
            MOV AL, BH
            CMP AL, 65
            JB INPUT_SECTION
            MOV AL, BH
            CMP AL, 90
            JA INPUT_SECTION
            ;ELSE
            ;THE INPUT IS UPPERCASE
            CMP UPPERCASE_COUNTER, 0
            JE FIRST_UPPERCASE
            MOV CH, BH
            INC UPPERCASE_COUNTER
            JMP INPUT_SECTION
            FIRST_UPPERCASE:
                MOV CL, BH
                INC UPPERCASE_COUNTER
                JMP INPUT_SECTION
            
        OUTPUT_SECTION:
            ;TO PRINT NEWLINE
            MOV AH, 2
            MOV DL, 10
            INT 21H
            MOV DL, 13
            INT 21H
            
            ;OUTPUT PROMPT
            MOV AH, 9
            LEA DX, OUTPUT_MSG
            INT 21H
            
            ;PRINT OUTPUT
            MOV AH,2
            MOV DL, CL
            INT 21H
            MOV DL, CH
            INT 21H
             
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
    END MAIN

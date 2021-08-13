.MODEL SMALL
.STACK 100H
.DATA
FIRST_INPUT_PROMPT DB 'ENTER THE FIRST HEXADECIMAL NUMBER: $'
FIRST_INPUT_DATA DB 0H
SECOND_INPUT_PROMPT DB 'ENTER THE SECOND HEXADECIMAL NUMBER: $'
SECOND_INPUT_DATA DB 0H
OUTPUT_PROMPT DB 'MULTIPLY RESULT IN BINARY: $'

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        ;FIRST INPUT
        LEA DX, FIRST_INPUT_PROMPT
        MOV AH, 9
        INT 21H
        MOV CX, 2
        MOV AH, 1
        FIRST_INPUT:
            INT 21H
            MOV BL, AL                ;NOT TO LOOSE THE DATA
            CMP AL, 65
            JL DATA_PROCESS_FIRST
            SUB BL, 55                ;TO GET 10-15 FOR A-F
            DATA_PROCESS_FIRST:
                AND BL, 0FH           ;TO LOOSE UNNECESSARY BITS EXCEPT THE LAST 4 BITS
                SHL FIRST_INPUT_DATA, 4
                OR FIRST_INPUT_DATA, BL
            LOOP FIRST_INPUT
        
        ;PRINT NEW LINE
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        
        ;SECOND INPUT
        LEA DX, SECOND_INPUT_PROMPT
        MOV AH, 9
        INT 21H
        MOV CX, 2
        MOV AH, 1
        SECOND_INPUT:
            INT 21H
            MOV BL, AL                ;NOT TO LOOSE THE DATA
            CMP AL, 65
            JL DATA_PROCESS_SECOND
            SUB BL, 55                ;TO GET 10-15 FOR A-F
            DATA_PROCESS_SECOND:
                AND BL, 0FH           ;TO LOOSE UNNECESSARY BITS EXCEPT THE LAST 4 BITS
                SHL SECOND_INPUT_DATA, 4
                OR SECOND_INPUT_DATA, BL
            LOOP SECOND_INPUT
        
        ;MULTIPLICATION PROCESS
        XOR BX, BX                    ;I'LL SAVE THE OUTPUT IN BX AS THE OUTPUT WILL BE IN 16-BIT....CLEARING THE REGISTER FOR THAT
        XOR DX, DX
        MOV CX, 8
        MOV DL, FIRST_INPUT_DATA      ;THERE WILL BE LOTS OF SHIFTING
        MULTIPLY:
            ROR SECOND_INPUT_DATA, 1
            JNC CONTINUE
            OR BX, DX
            CONTINUE:
                SHL DX, 1
                LOOP MULTIPLY
                
        ;PRINT NEW LINE
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        
        ;OUTPUT SEGMENT
        LEA DX, OUTPUT_PROMPT
        MOV AH, 9
        INT 21H
        MOV CX, 16
        MOV AH, 2
        JNC OUTPUT_SECTION
        MOV DL, 0
        INT 21H
        OUTPUT_SECTION:
            ROL BX, 1
            JNC PRINT_ZERO
            PRINT_ONE:
                MOV DL, 31H
                INT 21H
                JMP END_SECTION
            PRINT_ZERO:
                MOV DL, 30H
                INT 21H
            END_SECTION:
                LOOP OUTPUT_SECTION
        
        ;RETURNING CONTROL TO OS
        MOV AH, 4CH
        INT 21H
        
        MAIN ENDP
    END MAIN
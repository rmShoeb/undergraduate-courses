INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
FIRST_INPUT_DATA DW 0H
SECOND_INPUT_DATA DW 0H

.CODE
    MAIN PROC
        ;DATA SEGMENT
        MOV AX, @DATA
        MOV DS, AX
        
        ;INPUT SEGMENT
        ;FIRST INPUT
        ;INPUT PROMPT
        PRINT 'ENTER FIRST HEXADECIMAL VALUE: '
        MOV CX, 4
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
                OR FIRST_INPUT_DATA, BX
            LOOP FIRST_INPUT
        
        CALL NEWLINE
        
        ;SECOND INPUT
        ;INPUT PROMPT
        PRINT 'ENTER SECOND HEXADECIMAL VALUE: '    
        MOV CX, 4
        MOV AH, 1
        MOV DX, 0
        SECOND_INPUT:
            INT 21H
            MOV BL, AL                ;NOT TO LOOSE THE DATA
            CMP AL, 65
            JL DATA_PROCESS_SECOND
            SUB BL, 55                ;TO GET 10-15 FOR A-F
            DATA_PROCESS_SECOND:
                AND BL, 0FH           ;TO LOOSE UNNECESSARY BITS EXCEPT THE LAST 4 BITS
                SHL SECOND_INPUT_DATA, 4
                OR SECOND_INPUT_DATA, BX
            LOOP SECOND_INPUT
        
        ;SUM SEGMENT
        SUM_SEGMENT:
            MOV BX, FIRST_INPUT_DATA
            MOV CX, SECOND_INPUT_DATA
            ADD BX, CX
        
        CALL NEWLINE
        PRINT 'OUTPUT: '
        CALL OUTPUT
        
        ;REVERSE THE SECOND INPUT
        MOV DX, SECOND_INPUT_DATA
        MOV CX, 16
        XOR AX, AX
        XOR BX, BX
        REVERSE:
            SHL DX, 1
            RCL AX, 1
            LOOP REVERSE
        
        REVERSE_SUM:
        
        CALL NEWLINE
        PRINT 'REVERSE OUTPUT: '
        CALL OUTPUT
                        
        ;RETURN CONTROL
        MOV AH, 4CH
        INT 21H
        
        MAIN ENDP   
    
    ;OUTPUT PROCEDURE
    OUTPUT PROC
        MOV CX, 16
        MOV AH, 2
        JNC OUTPUT_SECTION
        MOV DL, 30H
        INT 21H
        OUTPUT_SECTION:
            ROL BX, 1
            JNC PRINT_ZERO
            PRINT_ONE:
                MOV DL, 31H
                INT 21H
                LOOP OUTPUT_SECTION
            PRINT_ZERO:
                MOV DL, 30H
                INT 21H
                LOOP OUTPUT_SECTION   
        RET
        OUTPUT ENDP
    
    ;PRINT NEW LINE PROCEDURE
    NEWLINE PROC
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        RET
        
    END MAIN
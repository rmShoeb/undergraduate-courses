;rmShoeb_CSE_16
;8.7.2019
;this program TAKES A 3-DIGIT DECIMAL NUMBER
;PRINTS ITS EQUIVALENT BINARY IN REVERSE ORDER

INCLUDE 'EMU8086.INC'                               ;TO USE THE PRINT AND PRINTN FUNCTION
.MODEL SMALL
.STACK 100H
.DATA
SUM DB 0H

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        PRINT 'ENTER A 3-DIGIT DECIMAL NUMBER: '
        MOV CX, 3
        INPUT:
            MOV AH, 1
            INT 21H
            SUB AL, 30H
            MOV BL, AL
            MOV AL, 10
            MUL SUM
            ADD BL, AL
            MOV SUM, BL
            LOOP INPUT

;THIS COMMENTED BLOCK IS TO VARIFY THE INPUT        
;        MOV DL, SUM
;        MOV AH, 2
;        INT 21H
        
        PRINTN
        MOV BL, SUM
        PRINT 'EQUIVALENT BINARY IN REVERSE: '
        CALL _PRINT_BINARY_REVERSE_
        
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
    
    _PRINT_BINARY_REVERSE_ PROC
        MOV CX, 8
        MOV AH, 2
        OUTPUT:
            RCR BL, 1
            JC PRINT_ONE
            PRINT_ZERO:
                MOV DL, 30H
                INT 21H
                JMP CONTINUE
            PRINT_ONE:
                MOV DL, 31H
                INT 21H
            CONTINUE:
                LOOP OUTPUT
        
        RET
        _PRINT_BINARY_REVERSE_ ENDP
    
    END MAIN
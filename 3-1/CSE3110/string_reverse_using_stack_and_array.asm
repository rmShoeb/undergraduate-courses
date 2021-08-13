INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    WORD_REVERSE DW 100 DUP(?)

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        PRINT 'ENTER STRING: '
        XOR CX, CX
        MOV SI, 0
        MOV AH, 1
        INPUT:
            INT 21H
            CMP AL, 0DH
            JE END_INPUT
            PUSH AX                     ;PUSH INTO STACK FOR REVERSING WHOLE SENTENCE
            MOV WORD_REVERSE[SI], AX    ;SAVE THE DATA INTO ARRAY FOR WORD BY WORD REVERSE
            INC CX                      ;TO KNOW HOW MANY INPUT THE USER IS GIVING
            INC SI                      ;FOR THE ARRAY POINTER
            JMP INPUT
        END_INPUT:                      ;DOESN'T DO ANYTHING BUT NECESSARY
        
        CALL NEWLINE
        PRINT 'WHOLE SENTENCE IN REVERSE ORDER: '
        MOV AH, 2
        OUTPUT:
            POP DX
            INT 21H
            LOOP OUTPUT
        CALL NEWLINE
        
        MOV CX, SI
        PRINT 'WORD BY WORD REVERSE ORDER: '
        ;CALL WORD_BY_WORD_REVERSE
        MOV SI, 0
        XOR BX, BX
        MOV AH, 2
        REVERSE:
            CMP WORD_REVERSE[SI], 20H
            JNE STACK_PUSH
            MOV DL, 20H
            INT 21H
            STACK_POP:
                POP DX
                INT 21H
                CMP BX, 0H
                JNE STACK_POP
                JE ANOTHER_SECTION
            STACK_PUSH:
                PUSH WORD_REVERSE[SI]
                INC BX
            ANOTHER_SECTION:
                INC SI
            LOOP REVERSE
        
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
    
    NEWLINE PROC
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
        RET
        NEWLINE ENDP
    
    ;WORD_BY_WORD_REVERSE PROC
;        MOV SI, 0
;        XOR BX, BX
;        MOV AH, 2
;        REVERSE:
;            CMP WORD_REVERSE[SI], 20H
;            JNE STACK_PUSH
;            MOV DL, 20H
;            INT 21H
;            STACK_POP:
;                POP DX
;                INT 21H
;                CMP BX, 0H
;                JNE STACK_POP
;                JE ANOTHER_SECTION
;            STACK_PUSH:
;                PUSH WORD_REVERSE[SI]
;                INC BX
;            ANOTHER_SECTION:
;                INC SI
;            LOOP REVERSE
;        RET
;        WORD_BY_WORD_REVERSE ENDP
    
    END MAIN
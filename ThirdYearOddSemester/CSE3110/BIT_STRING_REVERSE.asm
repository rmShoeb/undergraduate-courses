.MODEL SMALL
.STACK 100H
.DATA
INPUT_MSG DB 'ENTER A 8-BIT BINARY STRING: $'
OUTPUT_MSG DB 'THE BIT STRING IN REVERSE: $'

.CODE
    MAIN PROC
        MOV AX, @DATA
        MOV DS, AX
        
        ;INPUT PROMPT
        LEA DX, INPUT_MSG
        MOV AH, 9
        INT 21H
        
        ;TAKING INPUT
        MOV CX, 8               ;TO ITERATE THE LOOP 8 TIMES
        XOR BH, BH              ;TO CLEAR ANY DATA IN BH REGISTER
        MOV AH, 1
        INPUT_SECTION:
            INT 21H             ;TO CALL THE INPUT FUNCTION
            AND AL, 1H          ;TO GET 0 OR 1 FROM INPUT
            SHL BH, 1           ;TO SHIFT THE DATA LEFT BY 1 BIT 
            OR BH, AL           ;DOING OR TRANSFERS THE DATA OF AL INTO THE LSB OF BL
            LOOP INPUT_SECTION  ;KEEP LOOPING
        
        ;REVERSING THE INPUT BIT STRING
        MOV CX, 8               ;TO ITERATE THE LOOP 8 TIMES
        XOR BL, BL              ;TO CLEAR ANY DATA IN BL REGISTER
        PROCESS_SECTION:
            SHR BH, 1           ;SHIFTING THE DATA TO RIGHT IN BH REGISTER BY 1 BIT
            RCL BL, 1           ;ROTATING THE DATA TO RIGHT IN BL REGISTER BY 1 BIT
            LOOP PROCESS_SECTION;KEEP LOOPING
        
        ;OUTPUT PROMPT
        MOV AH, 2
        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H                 ;THESE 5 LINES WILL PRINT A NEW LINE
        LEA DX, OUTPUT_MSG
        MOV AH, 9
        INT 21H                 ;PRINT OUTPUT PROMPT
        
        ;PRINTING OUTPUT
        MOV CX, 8
        MOV AH, 2
        OUTPUT_SECTION:
            ROL BL, 1           ;ROTATE THE DATA TO RIGHT IN BL REGISTER BY 1 BIT AND COPY THE MSB TO LSB
            JC PRINT_ZERO
            PRINT_ONE:
                MOV DL, 31H
                INT 21H
                LOOP OUTPUT_SECTION
            PRINT_ZERO:
                MOV DL, 30H
                INT 21H
                LOOP OUTPUT_SECTION 
        
        MOV AH, 4CH
        INT 21H
    MAIN ENDP
    
END MAIN
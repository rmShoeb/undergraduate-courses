.686									; pentium or below processors
.model flat, c							; flat model means potected mode
										; integrate the C language
; inlude C libraries for use
include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib


.stack 100h

; forward declaration/prototyping
printf PROTO arg1:Ptr Byte, printlist:VARARG
										; one argument of Byte type pointer
										; printlist says that there can more arguments later
scanf PROTO arg2:Ptr Byte, inputlist:VARARG


.data
output_msg_format byte "%s", 0
;output_msg byte "hello world", 0Ah, 0	; 0Ah -> newline, 0 -> end of string

ask_number_msg byte "Enter a number: ", 0
positive_msg byte "The number is positive!", 0Ah, 0
negative_msg byte "The number is negative!", 0Ah, 0
zero_msg byte "The number is zero!", 0Ah, 0

input_format byte "%d", 0
number sdword ?							; memory allocated, data will be stored later
										; sdword -> signed double word


.code
main proc
	; take an input
	INVOKE printf, ADDR output_msg_format, ADDR ask_number_msg
	INVOKE scanf, ADDR input_format, ADDR number
	
	mov eax, number
	cmp eax, 0
	
	JL NEGATIVE
	JE ZERO
	JG POSITIVE
	JMP END_CMP

POSITIVE:
	INVOKE printf, ADDR output_msg_format, ADDR positive_msg
	JMP END_CMP
NEGATIVE:
	INVOKE printf, ADDR output_msg_format, ADDR negative_msg
	JMP END_CMP
ZERO:
	INVOKE printf, ADDR output_msg_format, ADDR zero_msg
END_CMP:
	ret

	; INVOKE printf, ADDR output_msg_format, number
	ret
main endp
end

.686
.model flat, c
include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib

.stack 100h
printf PROTO arg1:Ptr Byte, printlist:VARARG
scanf PROTO arg2:Ptr Sdword, inputlist:VARARG


.data
	input_format byte "%d", 0
	output_format byte "%s %d", 0Ah, 0

	input_msg_format byte "%s", 0

	input_msg_1 byte "A = ", 0
	input_msg_2 byte "B = ", 0
	output_msg byte "Sum is", 0
	
	A dword ?
	B dword ?
	sum dword ?


.code
main PROC
	INVOKE printf, ADDR input_msg_format, ADDR input_msg_1
	INVOKE scanf, ADDR input_format, ADDR A
	INVOKE printf, ADDR input_msg_format, ADDR input_msg_2
	INVOKE scanf, ADDR input_format, ADDR B

	push B
	push A
	call SUM
	pop A
	pop B
	ret
main ENDP

SUM PROC
	push ebp
	mov ebp, esp
	mov edx, [ebp+12]
	add edx, [ebp+8]
	mov sum, edx
	INVOKE printf, ADDR output_format, ADDR output_msg, sum
	pop ebp
	ret
SUM ENDP
END main

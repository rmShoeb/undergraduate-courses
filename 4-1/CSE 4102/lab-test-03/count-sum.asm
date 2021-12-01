.686
.model flat, c

include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib


.stack 100h

printf PROTO arg1:Ptr Byte, printlist:VARARG
scanf PROTO arg2:Ptr Byte, inputlist:VARARG


.data
output_msg_format_1 byte "%s", 0
output_msg_format_2 byte "%d", 0Ah, 0

ask_count_msg byte "Enter the count: ", 0
ask_number_msg byte "Enter number: ", 0
show_out_msg byte "Total: ", 0

input_format byte "%d", 0
count sdword ?
number sdword ?
total sdword 0


.code
main proc
	INVOKE printf, ADDR output_msg_format_1, ADDR ask_count_msg
	INVOKE scanf, ADDR input_format, ADDR count

COUNT_LOOP:
	cmp count, 0
	JE END_COUNT
	INVOKE printf, ADDR output_msg_format_1, ADDR ask_number_msg
	INVOKE scanf, ADDR input_format, ADDR number
	mov eax, number
	add total, eax
	dec count
	JMP COUNT_LOOP

END_COUNT:
	INVOKE printf, ADDR output_msg_format_2, total

	ret
main endp
end

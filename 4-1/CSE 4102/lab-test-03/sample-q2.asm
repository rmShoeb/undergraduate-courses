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

ask_current_msg byte "Current= ", 0
ask_resistance_msg byte "Resistance= ", 0
show_out_msg byte "Voltage= ", 0

input_format byte "%d", 0
I sdword ?
R sdword ?
V sdword 0


.code
main proc
	; get current
	INVOKE printf, ADDR output_msg_format_1, ADDR ask_current_msg
	INVOKE scanf, ADDR input_format, ADDR I
	; get resistance
	INVOKE printf, ADDR output_msg_format_1, ADDR ask_resistance_msg
	INVOKE scanf, ADDR input_format, ADDR R
	
	; calculate voltage
	mov eax, I
	mul R
	mov V, eax
	
	; show result
	INVOKE printf, ADDR output_msg_format_1, ADDR show_out_msg
	INVOKE printf, ADDR output_msg_format_2, V
	ret
main endp
end

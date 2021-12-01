.686
.model flat, c

include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib


.stack 100h

printf PROTO arg1:Ptr Byte, printlist:VARARG
scanf PROTO arg2:Ptr Byte, inputlist:VARARG


.data
output_format byte "%d", 0Ah, 0

I dword 19
R dword 22
V dword 0


.code
main proc
	xor edx, edx
	mov eax, R
	div I

	INVOKE printf, ADDR output_format, eax
	INVOKE printf, ADDR output_format, edx
	ret
main endp
end

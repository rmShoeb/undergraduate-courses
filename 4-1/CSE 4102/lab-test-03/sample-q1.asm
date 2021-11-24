.686
.model flat, c

include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib


.stack 100h

printf PROTO arg1:Ptr Byte, printlist:VARARG
scanf PROTO arg2:Ptr Byte, inputlist:VARARG


.data
output_format byte "%d", 0Ah, 0

I sdword 10
R sdword 20
V sdword 0


.code
main proc
	mov eax, I
	mul R
	mov V, eax
	
	INVOKE printf, ADDR output_format, V
	ret
main endp
end

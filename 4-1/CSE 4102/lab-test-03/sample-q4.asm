.686
.model flat, c

include \masm32\include\msvcrt.inc
includelib \masm32\lib\msvcrt.lib


.stack 100h

printf PROTO arg1:Ptr Byte, printlist:VARARG
scanf PROTO arg2:Ptr Byte, inputlist:VARARG


.data
output_format byte "%d", 0Ah, 0
count sdword 0
a sdword 0			; since a is set to 0 in for loop


.code
main proc
	FOR_LOOP:
		cmp a, 10
		JGE END_LOOP
		; INVOKE printf, ADDR output_format, a
		
		cmp a, 5
		JE IF_BLOCK
		cmp a, 7
		JGE ELSE_IF_BLOCK
		JMP ELSE_BLOCK
		IF_BLOCK:
			inc count
			JMP INCREMENT
		ELSE_IF_BLOCK:
			mov eax, a
			mov count, eax
			inc a
			JMP INCREMENT
		ELSE_BLOCK:
			; the question says-> "count=a--;"
			; this will create an infinite loop
			; to avoid that
			; i have considered
			; count = a-1
			mov eax, a
			dec eax
			mov count, eax
			JMP INCREMENT
		INCREMENT:
			inc a
			JMP FOR_LOOP
		END_LOOP:
		INVOKE printf, ADDR output_format, count
		ret
main endp
end

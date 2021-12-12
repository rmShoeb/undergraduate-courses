.686 ; Pentium processors or below
.model flat c
include include/msvcrt.inc
includelib lib/msvcrt.lib

.stack 100H

printf PROTO arg1:Ptr Byte

.data
msg byte "hello world", 0Ah, 0

.code
main proc
    INVOKE printf, ADDR msg
    ret
main endp
end
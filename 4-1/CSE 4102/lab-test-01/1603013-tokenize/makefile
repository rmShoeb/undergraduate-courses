# files
input = input.txt
output = output.txt

tokenizer: prog.l
	flex prog.l
	gcc lex.yy.c -o prog
	./prog <$(input)> $(output)
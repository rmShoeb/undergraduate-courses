# files
input = input.txt
output = output.txt

tokenizer: prog.l
	flex prog.l

parser: prog.y
	bison -d prog.y
	make tokenizer
	gcc prog.tab.c lex.yy.c -o prog
	./prog <$(input)> $(output)
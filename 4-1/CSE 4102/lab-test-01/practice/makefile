# files
input = input.txt
output = output.txt

tokenizer: practice.l
	flex practice.l

parser: practice.l
	bison -d practice.y
	make tokenizer
	gcc practice.tab.c lex.yy.c -o practice
	./practice <$(input)> $(output)

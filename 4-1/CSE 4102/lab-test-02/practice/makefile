# files
input = input.txt
output = output.txt

tokenize:
	flex lexer.l

parse:
	bison -d parser.y
	make tokenize
	gcc parser.tab.c lex.yy.c -o parser
	./parser <$(input)> $(output)

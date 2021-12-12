# files
input = input.txt
output = output.txt

main: cal.l
	lex cal.l
	gcc lex.yy.c -o cal
	./cal <input.txt> output.txt

main2: cal.l cal.y
	bison -d cal.y
	lex cal.l
	gcc cal.tab.c lex.yy.c -o cal
	./cal <input.txt> output.txt

practice: p.l p.y
	bison -d p.y
	lex p.l
	gcc p.tab.c lex.yy.c -o p
	./p <$(input)> $(output)
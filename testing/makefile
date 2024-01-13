

main: c99.tab.c lex.yy.c driver.o
	gcc $^ -o $@
	

c99.tab.c: c99.y
	bison -d $<

lex.yy.c: c99.l
	flex $<

%.o: %.c
	gcc $< -o $@ -c

clean:
	rm -rf c99.tab.c
	rm -rf c99.tab.h
	rm -rf lex.yy.c
	rm -rf main
	rm *.o
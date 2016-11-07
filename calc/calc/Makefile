YACC	= bison -d -y 
LEX	= flex
CC	= gcc
CPP	= g++
DEFTARGET = calc_def

all: calc_def calc 
test_def: calc_def
	./calc_def < test.good.calc > test.good.defoutput
	-./calc_def < test.bad.calc > test.bad.defoutput
test_parse: calc
	./calc < test.good.calc > test.good.dot
	-./calc < test.bad.calc > test.bad.dot
	dot -Tps test.good.dot > test.good.ps
	ps2pdf test.good.ps test.good.pdf


###############################################
# This part makes your parse tree generator
#

calc: calc.o 
	    $(CPP) calc.o -o calc
calc.o: calc.cpp 
	    $(CPP) -c calc.cpp

################################################
# This part makes the parsing definition
#

$(DEFTARGET): y.tab.o lex.yy.o
	    $(CC) lex.yy.o y.tab.o -o $(DEFTARGET)
y.tab.o: y.tab.c
	    $(CC) -c y.tab.c
y.tab.c: $(DEFTARGET).y
	    $(YACC) $(DEFTARGET).y
y.tab.h: $(DEFTARGET).y
	    $(YACC) $(DEFTARGET).y
lex.yy.o: lex.yy.c y.tab.h
	    $(CC) -c lex.yy.c
lex.yy.c: $(DEFTARGET).l
	    $(LEX) $(DEFTARGET).l

clean:
	rm -f calc calc.o $(DEFTARGET) y.tab.o y.tab.c y.tab.h lex.yy.o lex.yy.c
	rm -f test.good.defoutput test.bad.defoutput test.good.dot test.bad.dot test.good.ps test.good.pdf

submit: calc
	turnin proj1@cs160 .

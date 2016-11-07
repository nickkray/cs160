#
# Makefile for Project 1, Part 1
#

YACC    = bison -d -v
LEX     = flex
CC      = gcc
CPP     = g++ -g

TARGET  = csimple

OBJS += lexer.o parser.o main.o
RMFILES = core.* lexer.cpp parser.cpp parser.hpp parser.output $(TARGET) $(OBJS)

# Dependencies
$(TARGET): parser.cpp lexer.cpp parser.hpp $(OBJS)
	$(CPP) -o $(TARGET) $(OBJS)

# Rules
%.cpp: %.ypp
	$(YACC) -o $(@:%.o=%.d) $<

%.o: %.cpp
	$(CPP) -o $@ -c $<

%.cpp: %.l
	$(LEX) -o$(@:%.o=%.d) $<

# Source
lexer.o: lexer.cpp parser.hpp
lexer.cpp: lexer.l

parser.o: parser.cpp parser.hpp
parser.cpp: parser.ypp

main.o: parser.hpp

clean:
	rm -f $(RMFILES)

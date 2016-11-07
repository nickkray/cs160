#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stack>

#include <string>

using namespace std;


/*** Enums and Print Functions for Terminals and Non-Terminals  **********************/

#define MAX_SYMBOL_NAME_SIZE 25

//all of the terminals in the language
typedef enum {
	T_eof = 0,	// 0: end of file
	T_num,		// 1: numbers
	T_plus,		// 2: +
	T_minus,	// 3: - 
	T_times,	// 4: *
	T_period,	// 5: .
	T_modulo, 	// 6: % 
	T_openparen,	// 7: (
	T_closeparen 	// 8: )
} token_type;

//this function returns a string for the token.  It is used in the parsetree_t
//class to actually dump the parsetree to a dot file (which can then be turned
//into a picture).  Note that the return char* is a reference to a local copy
//and it needs to be duplicated if you are a going require multiple instances
//simultaniously
char* token_to_string(token_type c) {
	static char buffer[MAX_SYMBOL_NAME_SIZE];
	switch( c ) {
		case T_eof: strncpy(buffer,"eof",MAX_SYMBOL_NAME_SIZE); break;
		case T_num: strncpy(buffer,"num",MAX_SYMBOL_NAME_SIZE); break;
		case T_plus: strncpy(buffer,"+",MAX_SYMBOL_NAME_SIZE); break;
		case T_minus: strncpy(buffer,"-",MAX_SYMBOL_NAME_SIZE); break;
		case T_times: strncpy(buffer,"*",MAX_SYMBOL_NAME_SIZE); break;
		case T_period: strncpy(buffer,".",MAX_SYMBOL_NAME_SIZE); break;
		case T_modulo: strncpy(buffer,"%",MAX_SYMBOL_NAME_SIZE); break;
		case T_openparen: strncpy(buffer,"(",MAX_SYMBOL_NAME_SIZE); break;
		case T_closeparen: strncpy(buffer,")",MAX_SYMBOL_NAME_SIZE); break;
		default: strncpy(buffer,"unknown_token",MAX_SYMBOL_NAME_SIZE); break;
	}
	return buffer;
}

token_type char_to_token(char c){
    token_type t = T_eof;
    if (48<=c && c<=57){
        t = T_num;
        char q = c;
        while(isdigit(q)){
            q = getchar();
        }
        ungetc(q, stdin);
    }
    
    switch(c){
        case '+': t = T_plus; break;
        case '-': t = T_minus; break;
        case '(': t = T_openparen; break;
        case ')': t = T_closeparen; break;
        case '%': t = T_modulo; break;
        case '*': t = T_times; break;
        case '.': t = T_period; break;
    }
    return t;
}

//all of the non-terminals in the grammar (you need to add these in
//according to your grammar.. these are used for printing the thing out)
//please follow the convention we set up so that we can tell what the heck you
//are doing when we grade
typedef enum {
	epsilon = 100,
	NT_List,
	NT_Expr,
    NT_ExprP,
    NT_Term,
    NT_TermP,
    NT_Fact,
    NT_ListP
	//WRITEME: add symbolic names for you non-terminals here
} nonterm_type;

//this function returns a string for the non-terminals.  It is used in the parsetree_t
//class to actually dump the parsetree to a dot file (which can then be turned
//into a picture).  Note that the return char* is a reference to a local copy
//and it needs to be duplicated if you are a going require multiple instances
//simultaniously. 
char* nonterm_to_string(nonterm_type nt)
{
	static char buffer[MAX_SYMBOL_NAME_SIZE];
	switch( nt ) {
		  case epsilon: strncpy(buffer,"e",MAX_SYMBOL_NAME_SIZE); break;
		  case NT_List: strncpy(buffer,"List",MAX_SYMBOL_NAME_SIZE); break;
		  case NT_Expr: strncpy(buffer,"Expr",MAX_SYMBOL_NAME_SIZE); break;
          case NT_ExprP: strncpy(buffer,"ExprP",MAX_SYMBOL_NAME_SIZE); break;
		  case NT_TermP: strncpy(buffer,"TermP",MAX_SYMBOL_NAME_SIZE); break;
		  case NT_Term: strncpy(buffer,"Term",MAX_SYMBOL_NAME_SIZE); break;
 		  case NT_Fact: strncpy(buffer,"Factor",MAX_SYMBOL_NAME_SIZE); break;
          case NT_ListP: strncpy(buffer,"ListP",MAX_SYMBOL_NAME_SIZE); break;
		  //WRITEME: add the other nonterminals you need here		
		  default: strncpy(buffer,"unknown_nonterm",MAX_SYMBOL_NAME_SIZE); break;
		}
	return buffer;
}

/*** Scanner Class ***********************************************/

class scanner_t {
  public:

	//eats the next token and prints an error if it is not of type c
	void eat_token(token_type c);

	//peeks at the lookahead token
	token_type next_token();

	//return line number for errors
	int get_line();

	//constructor - inits g_next_token
	scanner_t();
    
    token_type g_next_token;
    
    int lineNumber;

  private:

	//WRITEME: Figure out what you will need to write the scanner
	//and to implement the above interface.  It does not have to
	//be a state machine or anything fancy.  Just read in the
	//characters one at a time (using getchar would be a good way)
	//and group them into tokens.  All of the tokens in this calculator
	//are trivial except for the numbers, so it should not be that bad
	//(10 lines or so)

	//This is a bogus member for implementing a useful stub, it should
	//be cut out once you get the scanner up and going.
	token_type bogo_token;

	//error message and exit if weird character
	void scan_error(char x);
	//error message and exit for mismatch
	void mismatch_error(token_type c);

};

token_type scanner_t::next_token()
{
	//WRITEME: replace this bogus junk with code that will take a peek
	//at the next token and return it to the parser.  It should _not_
	//actually consume a token - you should be able to call next_token()
	//multiple times without actually reading any more tokens in
    
	//if ( bogo_token!=T_plus && bogo_token!=T_eof ) return T_plus;
	//else return bogo_token;
    
    return g_next_token;
}

void scanner_t::eat_token(token_type c)
{
	//if we are supposed to eat token c, and it does not match
	//what we are supposed to be reading from file, then it is a 
	//mismatch error ( call - mismatch_error(c) )

	//WRITEME: cut this bogus stuff out and implement eat_token
	//if ( rand()%10 < 8 ) bogo_token = T_plus;
	//else bogo_token = T_eof;
    
    
    if(next_token() != c)
        mismatch_error(c);
    char ch = getchar();
    while(ch == '\n' || ch == ' '){
        if(ch == '\n')
            lineNumber++;
        ch = getchar();
    }
    
    g_next_token = char_to_token(ch);

}

scanner_t::scanner_t()
{
    g_next_token = char_to_token(getchar());
    lineNumber = 1;
}

int scanner_t::get_line()
{
    return lineNumber;
}

void scanner_t::scan_error (char x)
{
	printf("scan error: unrecognized character '%c'\n",x);  
	exit(1);

}

void scanner_t::mismatch_error (token_type x)
{
	printf("syntax error: found %s ",token_to_string(next_token()) );
	printf("expecting %s - line %d\n", token_to_string(x), get_line());
	exit(1);
}


/*** ParseTree Class **********************************************/

//just dumps out the tree as a dot file.  The interface is described below
//on the actual methods.  This class is full and complete.  You should not
//have to touch a thing if everything goes according to plan.  While you don't
//have to modify it, you will have to call it from your recursive decent
//parser, so read about the interface below.
class parsetree_t {
  public:
	void push(token_type t);
	void push(nonterm_type nt);
	void pop();
	void drawepsilon();
	parsetree_t();
  private:
	enum stype_t{
		TERMINAL=1,
		NONTERMINAL=0,
		UNDEF=-1
	};

	struct stuple { 
		nonterm_type nt;
		token_type t;
		stype_t stype; 
		int uniq;
	};
	void printedge(stuple temp); //prints edge from TOS->temp
	stack<stuple> stuple_stack;
	char* stuple_to_string(const stuple& s); 
	int counter;
};


//the constructer just starts by initializing a counter (used to uniquely
//name all the parse tree nodes) and by printing out the necessary dot commands
parsetree_t::parsetree_t()
{
	counter = 0;
	printf("digraph G { page=\"8.5,11\"; size=\"7.5, 10\"\n");
}

//This push function taken a non terminal and keeps it on the parsetree
//stack.  The stack keeps trace of where we are in the parse tree as
//we walk it in a depth first way.  You should call push when you start
//expanding a symbol, and call pop when you are done.  The parsetree_t
//will keep track of everything, and draw the parse tree as you go.
//This particular function should be called if you are pushing a non-terminal
void parsetree_t::push(nonterm_type nt)
{
	counter ++;
	stuple temp;
	temp.nt = nt;
	temp.stype = NONTERMINAL;
	temp.uniq = counter;
	printedge( temp );
	stuple_stack.push( temp );
}

//same as above, but for terminals
void parsetree_t::push(token_type t)
{
	counter ++;
	stuple temp;
	temp.t = t;
	temp.stype = TERMINAL;
	temp.uniq = counter;
	printedge( temp );
	stuple_stack.push( temp );
}

//when you are parsing a symbol, pop it.  That way the parsetree_t will
//know that you are now working on a higher part of the tree.
void parsetree_t::pop()
{
	if ( !stuple_stack.empty() ) {
		stuple_stack.pop();
	}

	if ( stuple_stack.empty() ) {
		printf( "}\n" );
	}
}

//draw an epsilon on the parse tree hanging off of the top of stack
void parsetree_t::drawepsilon()
{
	push(epsilon);
	pop();
}

// this private print function is called from push.  Basically it
// just prints out the command to draw an edge from the top of the stack (TOS)
// to the new symbol that was just pushed.  If it happens to be a terminal
// then it makes it a snazzy blue color so you can see your program on the leaves 
void parsetree_t::printedge(stuple temp)
{
	if ( temp.stype == TERMINAL ) {
		printf("\t\"%s%d\" [label=\"%s\",style=filled,fillcolor=powderblue]\n",
		  stuple_to_string(temp),
		  temp.uniq,
		  stuple_to_string(temp));
	} else {
		printf("\t\"%s%d\" [label=\"%s\"]\n",
		  stuple_to_string(temp),
		  temp.uniq,
		  stuple_to_string(temp));
	}

	//no edge to print if this is the first node
	if ( !stuple_stack.empty() ) {
		//print the edge
		printf( "\t\"%s%d\" ", stuple_to_string(stuple_stack.top()), stuple_stack.top().uniq ); 
		printf( "-> \"%s%d\"\n", stuple_to_string(temp), temp.uniq );
	}
}

//just a private utility for helping with the printing of the dot stuff
char* parsetree_t::stuple_to_string(const stuple& s) 
{
	static char buffer[MAX_SYMBOL_NAME_SIZE];
	if ( s.stype == TERMINAL ) {
		snprintf( buffer, MAX_SYMBOL_NAME_SIZE, "%s", token_to_string(s.t) );
	} else if ( s.stype == NONTERMINAL ) {
		snprintf( buffer, MAX_SYMBOL_NAME_SIZE, "%s", nonterm_to_string(s.nt) );
	} else {
		assert(0);
	}

	return buffer;
}


/*** Parser Class ***********************************************/

//the parser_t class handles everything.  It has and instance of scanner_t
//so it can peek at tokens and eat them up.  It also has access to the
//parsetree_t class so it can print out the parse tree as it figures it out.
//To make the recursive decent parser work, you will have to add some
//methods to this class.  The helper functions are described below

class parser_t {
  private:
	scanner_t scanner;
	parsetree_t parsetree;
	void eat_token(token_type t);
	void syntax_error(nonterm_type);

	void List();
	//WRITEME: fill this out with the rest of the 
	//recursive decent stuff (more methods)
    void Expr();
    void Term();
    void ExprP();
    void TermP();
    void Fact();
    void ListP();

  public:	
	void parse();

};


//this function not only eats the token (moving the scanner forward one
//token), it also makes sure that token is drawn in the parse tree 
//properly by calling push and pop.
void parser_t::eat_token(token_type t)
{
	parsetree.push(t);
	scanner.eat_token(t);
	parsetree.pop();
}

//call this syntax error wehn you are trying to parse the
//non-terminal nt, but you fail to find a token that you need
//to make progress.  You should call this as soon as you can know
//there is a syntax_error. 
void parser_t::syntax_error(nonterm_type nt)
{
	printf("syntax error: found %s in parsing %s - line %d\n",
		token_to_string( scanner.next_token()),
		nonterm_to_string(nt),
		scanner.get_line() ); 
	exit(1); 
}


//One the recursive decent parser is set up, you simply call parse()
//to parse the entire input, all of which can be dirived from the start
//symbol
void parser_t::parse()
{
	List();
}


//WRITEME: the List() function is not quite right.  Right now
//it is made to parse the grammar:  List -> '+' List | EOF
//which is not a very interesting language.  It has been included
//so you can see the basics of how to structure your recursive 
//decent code.

//Here is an example
void parser_t::List()
{
	//push this non-terminal onto the parse tree.
	//the parsetree class is just for drawing the finished
	//parse tree, and should in should have no effect the actual
	//parsing of the data
	parsetree.push(NT_List);
	switch(scanner.next_token())
	{
        case T_num:
        case T_openparen:
            Expr();
            eat_token(T_period);
            ListP();
        break;
        default:
			syntax_error(NT_List);
        break;
	}

	//now that we are done with List, we can pop it from the data
	//stucture that is tracking it for drawing the parse tree
	parsetree.pop();
}

void parser_t::ListP(){
    parsetree.push(NT_ListP);
    switch(scanner.next_token()){
        case T_eof:
            eat_token(T_eof);
        break;
        default:
            List();
        break;
    }
    parsetree.pop();
}

void parser_t::Expr(){
    parsetree.push(NT_Expr);
    switch(scanner.next_token()){
        case T_num:
        case T_openparen:
            Term();
            ExprP();
        break;
        default:
            syntax_error(NT_Expr);
        break;
    }
	parsetree.pop();
}

void parser_t::ExprP(){
    parsetree.push(NT_ExprP);
    switch(scanner.next_token()){
        case T_plus:
            eat_token(T_plus);
            Term();
            ExprP();
        break;
        case T_minus:
            eat_token(T_minus);
            Term();
            ExprP();
        break;
        default:
            parsetree.drawepsilon();
        break;
    }
	parsetree.pop();
}

void parser_t::Term(){
    parsetree.push(NT_Term);
    switch(scanner.next_token()){
        case T_num:
        case T_openparen:
            Fact();
            TermP();
            break;
        default:
            syntax_error(NT_Term);
        break;
    }
    parsetree.pop();
}

void parser_t::TermP(){
    parsetree.push(NT_TermP);
    switch(scanner.next_token()){
        case T_times:
            eat_token(T_times);
            Fact();
            TermP();
        break;
        case T_modulo:
            eat_token(T_modulo);
            Fact();
            TermP();
        break;
        default:
            parsetree.drawepsilon();
        break;
    }
	parsetree.pop();
}

void parser_t::Fact(){
    parsetree.push(NT_Fact);
    switch(scanner.next_token()){
        case T_openparen:
            eat_token(T_openparen);
            Expr();
            eat_token(T_closeparen);
        break;
        case T_num:
            eat_token(T_num);
        break;
        default:
            syntax_error(NT_Fact);
        break;
    }
	parsetree.pop();
}




/*** Main ***********************************************/

int main()
{
	parser_t parser;
	parser.parse();
	return 0;
}

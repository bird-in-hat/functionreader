%{
#include <cstdio>
#include <iostream>
#include <map> 

#include "fparser.hh"
#include "optlib.h"

using namespace std;

	// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

extern int line_num;
 
void yyerror(const char *s);

typedef struct {
	double left;
	double right;
} dmn; // domain

typedef struct {
	string funcargs;
	string function;
} fstrings;

map <string, int> intvars;
map <string, int>::iterator ivit;

map <string, double> doublevars;
map <string, double>::iterator dvit;

map <string, fstrings> fnames;
map <string, fstrings>::iterator fnit;

map <string, dmn> domvars;
map <string, dmn>::iterator domvit;

string arguments;
vector<string> variables;
FunctionParser *fp;

%}

%union {
	int ival;
	double dval;
	std::string sval;
}

%token PROGRAMM VAR START END
	
%token FUNCTIONTYPE DOUBLETYPE DOMAINTYPE INTTYPE

%token ENDL

%token DOML DOMR

%token <ival> INTVAL
%token <dval> DOUBLEVAL
%token <sval> STRING
%token <sval> FUNCTIONVAL

%%
prog:
	header var_section body_section{ cout << "Done with a reading program file!" << endl; }
	;
header:
	PROGRAMM STRING ';' ENDLS { cout << "Reading a programm " << $2 << endl; arguments = "";}
	;
var_section:
	VAR var_lines
	;
var_lines:
	var_line
	| var_lines var_line
var_line: // как пройтись по всем vars и args, чтобы добавить их в map?
	vars ':' FUNCTIONTYPE '(' args ')' ';' ENDLS 
	  		{
				for ( int i = 0; i < variables.size(); i++)
					fnames.insert(pair<string, fstrings>(variables[i], { arguments, "" }));			
				arguments = ""; 
				variables.clear();
	  		}
	| vars ':' DOUBLETYPE ';' ENDLS
			{
				for ( int i = 0; i < variables.size(); i++)
					doublevars.insert(pair<string, double>(variables[i], 0.0));
				variables.clear();
			}
	| vars ':' DOMAINTYPE ';' ENDLS
			{
				for ( int i = 0; i < variables.size(); i++)
					domvars.insert(pair<string, dmn>(variables[i], { -1.0, 1.0 }));
				variables.clear();
			}
	| vars ':' INTTYPE ';' ENDLS
			{
				for ( int i = 0; i < variables.size(); i++)
					intvars.insert(pair<string, int>(variables[i], 0));
				variables.clear();
			}
	;
args:
	STRING            { arguments = arguments + " " + $1; }
	| args ',' STRING { arguments = arguments + " " + $3; }
	;
vars:
	STRING            { variables.push_back( $1 ); }
	| vars ',' STRING { variables.push_back( $3 ); }
	;
body_section:
	START body_lines footer
	;
body_lines:
	body_line
	| body_lines body_line
	;
body_line:
	STRING ":=" FUNCTIONVAL ';' ENDLS 
			{ 
				fnit = fnames.find( $1 );
				if (fnit == fnames.end() ) yyerror("No function with this name");
				(fnit->second).function = $3;
			}
	| STRING ":=" DOUBLEVAL ';' ENDLS
			{
				dvit = doublevars.find( $1 );
				if (dvit == doublevars.end() ) yyerror("No double variable with this name");
				dvit->second = $3;
			}
	| STRING ":=" INTVAL ';' ENDLS
			{
				ivit = intvars.find( $1 );
				if (ivit == intvars.end() ) yyerror("No int variable with this name");
				ivit->second = $3;
			}
	| STRING DOML ":=" DOUBLEVAL ';' ENDLS
			{
				domvit = domvars.find( $1 );
				if (domvit == domvars.end() ) yyerror("No domain variable with this name");
				(domvit->second).left = $4;
			}
	| STRING DOMR ":=" DOUBLEVAL ';' ENDLS
			{
				domvit = domvars.find( $1 );
				if (domvit == domvars.end() ) yyerror("No domain variable with this name");
				(domvit->second).right = $4;
			}
	| STRING ":=" STRING '(' STRING ',' STRING ',' STRING ',' STRING ',' STRING ')'	';' ENDLS
	// 1       2     3    4    5     6     7    8    9    10    11    12   13   14   15  16
			{
				FunctionParser fp;
				fnit = fnames.find( $5 );
				if (fnit == fnames.end() ) yyerror("No function with this name");	
				int err = fp.Parse( (fnit->second).function, (fnit->second).funcargs );
				if ( err >= 0 ) yyerror(fp.ErrorMsg());

				domvit = domvars.find( $7 );
				if (domvit == domvars.end() ) yyerror("No domain variable with this name");
				dmn dom = domvit->second;

				dvit = doublevars.find( $9 );
				if (dvit == doublevars.end() ) yyerror("No double variable with this name");
				double r = dvit->second;

				dvit = doublevars.find( $11 );
				if (dvit == doublevars.end() ) yyerror("No double variable with this name");
				double e = dvit->second;

				dvit = doublevars.find( $1 );
				if (dvit == doublevars.end() ) yyerror("No double variable with this name");
				

				ivit = intvars.find( $3 );
				if (ivit == intvars.end() ) yyerror("No int variable with this name");
				double result = 0;
				int niter = 0;

				if ($3.compare("agp")) {
					//result = agp(fp, dom, r, e, niter);
					break;
				}
				if ($3.compare("kushner")) {
					//result = kushner(fp, dom, r, e, niter);
					break;
				}
				dvit->second = result;
				ivit->second = niter;
			}
	;
footer:
	END ENDLS
	;
ENDLS:
	ENDL
	| ENDLS ENDL 
	;
%%

int main(int, char**) {
		// open a file handle to a particular file:
	FILE *myfile = fopen("input.txt", "r");
		// make sure it's valid:
	if (!myfile) {
		cout << "Can't open file!" << endl;
		return -1;
	}
		// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;

		// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	return 0;	
}

void yyerror(const char *s) {
	cout << "Parse error: " << s << endl;
	cout << "Line: " << line_num << endl;
	exit(-1);
}
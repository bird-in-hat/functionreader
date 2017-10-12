%{
#include <cstdio>
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
#include "parser.tab.h"

int line_num = 1;
%}
%%
[ \t] ;
programm        { return PROGRAMM; }
var			    { return VAR; }
begin		    { return BEGIN; }
end             { return END; }

Function	    { return FUNCTION; }
Double 		    { return DOUBLETYPE; }
Int		   	    { return INTTYPE; }
Domain		    { return DOMAIN; }

\.left 		    { return DOML; }
\.right 	    { return DOMR; }

(([a-zA-Z]+)|([-]?[0-9]+\.[0-9]+)|([-]?([0-9]+))|([()\+\-\/\*\^]+))+ {
					yylval.sval = strdup(yytext);
					return FUNCTIONVAL;
				}
[a-zA-Z0-9]+    {
					yylval.sval = strdup(yytext);
					return STRING;
				}	
[-]?[0-9]+\.[0-9]+ { 
					yylval.fval = atof(yytext);
					return DOUBLEVAL; 
				}
[-]?[0-9]+      { 
					yylval.ival = atoi(yytext); 
					return INT; 
				}		
\n              { 
					++line_num; 
					return ENDL; 
				}
%%
/* добавить регулярное выражение для
// x*y + cos(x) и поместить его в соответствии с приоритетом выше или ниже
([a-zA-Z]+) - funcname
([-]?[0-9]+\.[0-9]+) - double
([-]?([0-9]+)) - int
([()\+\-\/\*\^]+) - tokens

\.left -> \[[0-9]+\] return ARRAYINDEX
*/
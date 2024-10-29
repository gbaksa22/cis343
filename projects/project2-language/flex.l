%{
#include <stdlib.h>
#include "bison.tab.h"
%}
 
%%
 
new                                 { return NEW; }
[A-Z][a-z]+.                        { yylval.string = yytext; return STRING; }
#[A-Z][a-z]+.                       { yylval.string = yytext[1]; return CATEGORY; }
[0-9]+.                             { yylval.number = atof(yytext); return AMOUNT; }
[0-9]+\.[0-9]{2}.                   { yylval.number = atof(yytext); return AMOUNT; }
\$income.                           { yylval.string = yytext; return INCOME; }
\$expense.                          { yylval.string = yytext; return EXPENSE; }
\([0-9]{2}-[0-9]{2}-[0-9]{4}\).     { yylval.string = yytext; return DATE; }
\([0-9]{2}\/[0-9]{2}\/[0-9]{4}\).   { yylval.string = yytext; return DATE; }
[A-Za-z ]+(?=\s+done)               { yylval.string = yytext; return DESCRIPTION; }
done                                { return DONE; }
[\t\r\n ]                           { ; }
.                                   { yyerror("Unrecognized character."); }
 
%%
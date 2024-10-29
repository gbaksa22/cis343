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
\$\+.                               { yylval.string = yytext; return INCOME; }
\$expense.                          { yylval.string = yytext; return EXPENSE; }
\$\-.                               { yylval.string = yytext; return EXPENSE; }
\([0-9]{2}-[0-9]{2}-[0-9]{4}\).     { yylval.string = yytext; return DATE; }
\([0-9]{2}\/[0-9]{2}\/[0-9]{4}\).   { yylval.string = yytext; return DATE; }
done                                { return DONE; }
[\t\r\n ]                           { ; }
.                                   { yyerror("Unrecognized character."); }
 
%%
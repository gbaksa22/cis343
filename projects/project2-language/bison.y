%{
#include <stdio.h>
 
void yyerror(const char* s);
 
%}
 
 
%union {
     char* string;
     double number;
}
 
%token NEW DONE INCOME EXPENSE AMOUNT CATEGORY DATE DESCRIPTION 
%type <number> AMOUNT
%type <string> CATEGORY DATE INCOME EXPENSE STRING
 
%%

program: NEW finance_list DONE          { printf("Entry complete.\n"); }

finance_list: entry finance_list
            | entry
;

entry: NEW sign amount category date description DONE
;

sign: INCOME
    | EXPENSE
;

amount: AMOUNT
;

category: CATEGORY
;

date: DATE
;

description: STRING
;

 
%%
 
void yyerror(const char* s){
     fprintf(stderr, "Syntax error: %s\n", s);
}
 
int main(int argc, char** argv){
     yyparse();
}

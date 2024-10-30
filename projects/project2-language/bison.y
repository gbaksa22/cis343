%{
#include <stdio.h>
 
void yyerror(const char* s);
    double net_income = 0.0f;
%}
 
 
%union {
     char* string;
     double number;
}
 
%token NEW DONE INCOME EXPENSE AMOUNT CATEGORY DATE DESCRIPTION 
%type <number> AMOUNT
%type <string> CATEGORY DATE INCOME EXPENSE STRING
 
%%

program: NEW finance_list DONE      { printf("%f\nNet Income:\n", net_income); }

finance_list: entry finance_list
            | entry
;

entry: NEW sign amount category date description DONE
;

sign: INCOME                        {net_income += $3;}
    | EXPENSE                       {net_income -= $3;}
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


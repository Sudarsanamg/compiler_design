%{
#include<stdio.h>
int valid=1;
int count=0;
%}

%token LBRACE RBRACe

%%
program :bracket
    | program bracket
    ;
bracket : LBRACE{count++;}
    |RBRACe {if(count>0){
        count--;
        }
        else{
            yyerror("error");}}
%%
int yyerror()
{
    valid=0;
    printf("ITS invalid");
    return 0;
}
int main()
{
    printf("enter the code\n");
    yyparse();

    if(count ==0)
    {
        printf("valid");
    }
    else{
        printf("invalid");
    }
}

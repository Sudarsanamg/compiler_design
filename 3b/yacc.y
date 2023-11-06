%{
#include<stdio.h>
int valid=1;
%}

%token id num

%%
start :id x

x : num id|num  |  ; 
%%
int yyerror()
{
     valid=0;
     printf("invalid");
     return 0;
}
int main()
{
    printf("enter the identifier:");
    yyparse();
    if(valid)
    {
        printf("\n valid");
    }

}

%{
int comment =0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%
#.* {printf("%s its a header",yytext);}
int |
char |
float |
double {printf("\n%s its a keyword",yytext);}
\{ {printf("\nblock begines");}
\} {printf("\nblock ends");}
{identifier} {printf("\n%s identifier",yytext);}
{identifier}\( {printf("it is a function\n");}
%%

int main(int argc,char **argv)
{
    FILE *f1;
    f1=fopen("var.c","r");
    yyin=f1;
    yylex();
    printf("\n");
    return 0;
}
int yywrap()
{
    return 1;
}
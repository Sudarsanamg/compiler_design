%{
#include "y.tab.h"
%}

%%
[0-9]+  {yylval.intValue=atoi(yytext);return Integer;}
[0-9]*[.][0-9]+ { yylval.floatValue=atof(yytext);return Float;}
. {}
"return 0"   return 0;
%%
int yywrap()
{
    return 1;
}

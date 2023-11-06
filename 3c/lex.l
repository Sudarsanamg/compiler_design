%{
    #include "y.tab.h"
%}

%%
"{" return LBRACE;
"}" return RBRACe;
"return 0;"  return 0;
.  {}
%%

int yywrap()
{
    return 1;
}
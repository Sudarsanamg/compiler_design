%{
#include <stdio.h>
int valid = 1;
%}

%token number
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

result : E {
    printf("the result is: %d\n", $$);
    return 0;
};

E: E '+' E {$$ = $1 + $3;}
 | E '-' E {$$ = $1 - $3;}
 | E '*' E {$$ = $1 * $3;}
 | E '/' E {$$ = $1 / $3;}
 | number  {$$ = $1;}
 | '(' E ')' {$$ = $2;}
 ;

%%

int main() {
    printf("Enter the arithmetic expression: ");
    yyparse();
    if (valid) {
        printf("Valid\n");
    }
}

void  yyerror() {
    valid = 0;
    printf("Error:\n");
}

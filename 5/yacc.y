%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern char* yytext; int
yyparse();
void yyerror(const char* s);
%} %union {
int intValue; float
floatValue;
char* stringValue;}
%token Integer Float Boolean String Character
%type <intValue> Integer Boolean
%type <floatValue> Float
%type <stringValue> String
%%
program: type
| program type;
type: Integer {
printf("Type: Integer, Value: %d\n", $1);}
| Float
{
printf("Type: Float, Value: %f\n", $1);}
| Boolean {
printf("Type: Boolean, Value: %s\n", $1 ? "true" : "false");}
| String {
printf("Type: String, Value: \"%s\"\n", $1);}
| Character {
printf("Type: Character, Value: %s\n", yytext);}
;
%%
int main()
{yyparse(); return 0;
}
void yyerror(const char* s)
{ fprintf(stderr, "Parser error: %s\n", s); exit(1);
}
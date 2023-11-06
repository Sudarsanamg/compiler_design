#ifndef _yy_defines_h_
#define _yy_defines_h_

#define Integer 257
#define Float 258
#define Boolean 259
#define String 260
#define Character 261
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
int intValue; float
floatValue;
char* stringValue;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */

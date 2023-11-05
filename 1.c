#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_operator(char i)
{
    if(i=='+'||i=='-'||i=='*'||i=='/'||i=='^' ||i=='=')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_identifier(char c)
{
    if(c>='a' && c<='z' || c>='A' && c<='Z')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
int is_keyword(char* str)
{
    char keys[4][10]={"int","float","char","double"};

    for(int l=0;l<4;l++)
    {
        if(strcmp(str,keys[l])==0)
        {
            return 1;
        }
    }
    return 0;
}

void analyze(char* code)
{
    int i=0;
    int j;
    int length=strlen(code);
    int tokenlength;
    char* token;
    while(i<length)
    {
        if(is_operator(code[i]))
        {
            printf("\n%c     | operator",code[i]);
            i++;
            continue;
        }
        if(is_identifier(code[i]))
        {
            j=i+1;
            while(j<length && is_identifier(code[j]))
            {
                j++;
            }
            tokenlength=j-i+1;
            token=(char*)malloc(tokenlength*sizeof(char));
            strncpy(token,code+i,tokenlength-1);
            token[tokenlength-1]='\0';  
            //printf("%s",token);
            if(is_keyword(token))
            {
                printf("\n%s     | Keyword",token);

            }
            else{
                printf("\n%s     | Identifier",token);
            }
            free(token);
            i=j;
            continue;
            

        }
        if(isdigit(code[i]))
       {
            j=i+1;
            while(j<length && isdigit(code[j]))
            {
                j++;
            }
            tokenlength=j-i+1;
            token=(char*)malloc(tokenlength*sizeof(char));
            strncpy(token,code+i,tokenlength-1);
            token[tokenlength-1]='\0';  
            //printf("%s",token);
            if(is_keyword(token))
            {
                printf("\n%s     | constant",token);

            }
            else{
                printf("\n%s     | constant",token);
            }
            free(token);
            i=j;
            continue;
       }
        else{
            i++;
        }
    }
    
    
}
int main()
{
    char code[100]; 
    printf("enter the single line of expression:");
    fgets(code,sizeof(code),stdin);
    printf("Token | Type");
    printf("\n____________");
    analyze(code);
    return 0;
}

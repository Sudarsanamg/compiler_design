#include<stdio.h>
#include<string.h>

int main()
{
    char icode[10][10];
    char str[5],opr[5];
    int i=0;

    //get input stop if i enter exit
    do
    {
        /* code */
        scanf("%s",icode[i]);
    } while (strcmp(icode[i++],"exit")!=0);
    i=0;
    do{
    strcpy(str,icode[i]);
    switch (str[3])
    {
    case '+':
        /* code */
        strcpy(opr,"ADD");
        break;
    case '-':
        strcpy(opr,"SUB");
        break;
    case '*':
        strcpy(opr,"MUL");
        break;
    case '/':
        strcpy(opr,"DIV");
        break;
    default:
        break;
    }

    printf("MOV %c  R%d\n",str[2],i);
    printf("%s  %c  R%d\n",opr,str[4],i);
    printf("MOV R%d %c\n",i,str[0]);
    }while (strcmp(icode[++i],"exit") !=0);
    
    
    return 0;
}
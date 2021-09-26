#include<stdio.h>
char *strchr(char *cs,char c)
{
    char *x=cs;
    for(;;++x)
    {
        if(*x=='\0') return NULL;
        if(*x==c) return x;
    }
}
int main()
{
    char a[100],b,*c;
    gets(a);
    scanf("%c",&b);
    c=strchr(a,b);
    if(c==NULL) printf("it is not here");
    else printf("it is the %dth",c-a);
    return 0;
}

#include<stdio.h>
int fun(char a[])
{
    int n=0,i;
    for(i=0; a[i]!='\0'; ++i)
        if(a[i]<='z'&&a[i]>='A') ++n;
        else a[i]='0';
    return n;
}
void main()
{
    char a[100];
    int i,geshu;
    while(gets(a))
    {
    geshu=fun(a);
    for(i=0; a[i]!='\0'; ++i)
    {
        if(a[i]!='0')
            printf("%c",a[i]);
        else ;
    }
    printf("\nit has %d\n",geshu);
    }
}

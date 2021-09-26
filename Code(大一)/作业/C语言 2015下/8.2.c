#include<stdio.h>
#include<string.h>
void fun(char m[])
{//puts(m);
    int a=0,b;
    b=strlen(m)-1;
    for(;a<b;++a,--b)
        {
            m[a]+=m[b];m[b]=m[a]-m[b];m[a]-=m[b];
        }//puts(m);
}
void main()
{
    char a[100];
    gets(a);//puts(a);
    fun(a);
    puts(a);
}

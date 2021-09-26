#include<stdio.h>
#include<string.h>
int fun(char a[])
{
    int j,i,b,c=0;
    for(i=strlen(a)-1;i>=0;--i)
        {if(a[i]<='9'&&a[i]>='0') b=a[i]-'0';
        else if(a[i]>='A'&&a[i]<='F') b=a[i]-'A'+10;
        else b=a[i]-'a'+10;//printf("%d\n",b);
        j=0;
        while(j<strlen(a)-i-1)
        {b*=16;++j;}
        c+=b;//printf("%d\n",c);
        }
        return c;
}
void main()
{
    char a[100];int b;
    gets(a);
    b=fun(a);
    printf("%d\n",b);
}

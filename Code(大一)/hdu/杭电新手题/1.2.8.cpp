#include<stdio.h>
int main()
{
    int i,n,l[26];
    char a[1000];
    while (gets(a))
    {
        for (i=0; i<26; ++i) l[i]=0;
        for (i=0; a[i]!='\0'; ++i)
        {
            n=a[i]-'a';
            if (n>=0&&n<26) ++l[n];
        }
        for (i=0; i<26; ++i)
            printf("%c:%d\n",'a'+i,l[i]);
        printf("\n");
    }
    return 0;
}

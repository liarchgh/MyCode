#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    char s[1000005];
    while(gets(s),strcmp(s,"ENDOFINPUT"))
    {
        gets(s);
        for(int i=0;s[i]!='\0';++i)
        {
            if(s[i]>='A' && s[i]<='E') printf("%c",'V'+s[i]-'A');
            else if(s[i]<='Z' && s[i]>='F') printf("%c",s[i]-5);
            else printf("%c",s[i]);
        }
        putchar('\n');
        gets(s);
    }
    return 0;
}

#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;++i) putchar(s[i]);
    for(int i=l-1;i>=0;--i) putchar(s[i]);
    putchar('\n');
    return 0;
}

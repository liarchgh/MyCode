#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

char s[1000000+5];
int su[10]={0};
int suan(int a);
int main()
{
    char c;
    int sum=0;
    while((c=getchar())!='\n')
    {
        ++sum;
        ++su[c-'0'];
    }
    sum=suan(sum);
    //printf("%d\n",sum);
    while(sum)
    {
        --su[sum%10];
        sum/=10;
    }
    //for(int j=0;j<=9;++j)
        //printf("%d  %d\n",j,su[j]);
    int i;
    for(i=0;(c=getchar())!='\n';++i)
    {
        --su[c-'0'];
        s[i]=c;
    }
    s[i]='\0';
    int an1,an2;
        for(int j=1;j<=9;++j)
        {
            if(su[j])
            {an1=j;--su[j];break;}
        }
    if(s[0]!='0')
    {
        an2=s[0]-'0';
        for(int j=1;s[j]!='\0';++j)
        {
            if((s[j]-'0')!=an2) an2=an2>(s[j]-'0')?(an2-1):an2;
        }
    }
    else an2=0;
    //printf("%d\n",an2);
    printf("%d",an1);
    for(int j=0;j<=an2;++j)
        while(su[j]--)
            printf("%d",j);
    printf("%s",s);
    for(int j=an2+1;j<=9;++j)
        while(su[j]--)
            printf("%d",j);
    return 0;
}

int suan(int a)
{
    int s=0,a1=a,w,x=a,x1=1;
    for(w=0;x;++w)
        {x/=10;x1*=10;}
    x1/=10;
    if(a<x1+w-2)
        return a-w-1;
    else
    {
        return a-w;
    }
}

/*етДњТыецГѓ*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+15;
char s[maxn],sub[maxn],ans[2][maxn];
int cnt[10],len,sublen;
bool jud(int n)
{
    bool ok=1;
    int x=n,k=0;
    while(x)
    {
        if(cnt[x%10]<=0)ok=0;
        cnt[x%10]--;
        x/=10;
        k++;
    }
    if(ok&&len-k==n)
        return 1;
    x=n;
    while(x)
    {
        cnt[x%10]++;
        x/=10;
    }
    return 0;
}
int main()
{
    int i,flag;
    scanf("%s%s",s,sub);
    len=strlen(s);
    sublen=strlen(sub);
    for(i=1;i<sublen;i++)
        if(sub[i]!=sub[i-1])
        {
            if(sub[i]<sub[i-1])flag=-1;
            else flag=1;
            break;
        }
    for(i=0;i<len;i++)
        cnt[s[i]-'0']++;
    for(i=0;i<sublen;i++)
        cnt[sub[i]-'0']--;
    for(i=sublen;i<=len;i++)
        if(jud(i))break;
    for(i=1;i<10;i++)
        if(cnt[i])break;
    if(sub[0]=='0')
    {
        if(i==10)
        {
            puts("0");
            return 0;
        }
        printf("%c",i+'0');
        cnt[i]--;
        while(cnt[0]--)printf("0");
        printf("%s",sub);
        for(int j=1;j<10;j++)
            while(cnt[j]--)printf("%c",j+'0');
        return 0;
    }
    if(i==10)
    {
        printf("%s",sub);
        while(cnt[0]--)printf("0");
        return 0;
    }
    int k=0,x;
    ans[0][k++]=i+'0';
    cnt[i]--;
    for(int j=0;j<10;j++)
    {
        int x=cnt[j];
        if(j==sub[0]-'0')
        {
            if(flag==-1)
            {
                for(int t=0;t<sublen;t++)ans[0][k++]=sub[t];
                while(x>0)ans[0][k++]=j+'0',x--;
            }
            else
            {
                while(x>0)ans[0][k++]=j+'0',x--;
                for(int t=0;t<sublen;t++)ans[0][k++]=sub[t];
            }
        }
        else while(x>0)ans[0][k++]=j+'0',x--;
    }
    cnt[i]++;
    ans[0][k]='\0';
    k=0;
    for(int t=0;t<sublen;t++)ans[1][k++]=sub[t];
    for(int j=0;j<10;j++)
    {
        int x=cnt[j];
        while(x>0)ans[1][k++]=j+'0',x--;
    }
    ans[1][k]='\0';
    puts(strcmp(ans[0],ans[1])<0?ans[0]:ans[1]);
    return 0;
}

#include<set>
#include<cstdio>
#include<string>
using namespace std;

set<string>ans;
int main()
{
    char s[1000],art[1000000];
    while(gets(art),art[0]!='#')
    {
        int t=0;
        for(int i=0;i==0 || art[i-1]!='\0';++i)
        {
            if(art[i]==' '||art[i]=='\0')
            {
                s[t]='\0';
                if(s[0]!='\0')
                ans.insert(s);
                t=0;
            }
            else s[t++]=art[i];
        }
        printf("%d\n",ans.size());
        ans.clear();
    }
    return 0;
}

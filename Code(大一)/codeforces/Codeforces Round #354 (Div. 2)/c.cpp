#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    queue<char>q;
    char s[100000+10];
    int k,n,x=0,ans = -1;
    scanf("%d%d\n",&n,&k);
    gets(s);
    char m[2]={'a','b'};
    for(int j=0;j<2;++j)
    {for(int i=0; i<n; ++i)
    {
        char c=s[i];
        //putchar(c);
        int a=q.size();
        if(a>ans) ans=a;
        //printf("%d\n",a);
        if(c==m[j])
        {
            if(x>=k)
            {
                while(q.front()!=m[j] && !q.empty()) q.pop();
                if(!q.empty())
                {
                    q.pop();
                    --x;
                }
            }
            ++x;
        }
        q.push(c);
        if(q.front() == m[j] && k==0) q.pop();
    }
    x=0;
    int a=q.size();
    if(a>ans) ans=a;
    //queue<char>q;
    while(!q.empty()) q.pop();
    }
    printf("%d\n",ans);
    return 0;
}

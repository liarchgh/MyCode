#include<cstdio>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

char vis[55],ord[15];
stack<string>bac,forw;
int main()
{
    int n,p;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        p=0;
        strcpy(vis,"http://www.lightoj.com/");
        printf("Case %d:\n",i);
        while(1)
        {
            scanf("%s",ord);
            getchar();
            switch(ord[0])
            {
            case 'B':
                if(bac.empty())
                {
                    printf("Ignored\n");
                    break;
                }
                forw.push(vis);
                strcpy(vis,&(bac.top()[0]));
                puts(vis);
                bac.pop();
                break;
            case 'F':
                if(forw.empty())
                {
                    printf("Ignored\n");
                    break;
                }
                bac.push(vis);
                strcpy(vis,&(forw.top()[0]));
                puts(vis);
                forw.pop();
                break;
            case 'V':
                while(!forw.empty()) forw.pop();
                bac.push(vis);
                gets(vis);
                puts(vis);
                break;
            case 'Q':
                p=1;
                break;
            }
            if(p)
            {
                while(!forw.empty()) forw.pop();
                while(!bac.empty()) bac.pop();
                break;
            }
        }
    }
    return 0;
}

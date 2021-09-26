#include<cstdio>
#include<cstring>
using namespace std;

int n,k,w[105],l[105];
int main()
{
    int a1,a2;
    char s1[15],s2[15],c[3]= {'r','p','s'};
    int p=0;
    while(scanf("%d",&n),n)
    {
        if(p)
            putchar('\n');
        else ++p;
        memset(w,0,sizeof(w));
        memset(l,0,sizeof(l));
        scanf("%d",&k);
        for(int i=0; i<n*(n-1)/2*k; ++i)
        {
            scanf("%d%s%d%s",&a1,s1,&a2,s2);
            int ai=0;
            while(c[ai]!=s1[0]) ++ai;
            if(s2[0]==c[(ai+1)%3])
            {
                ++w[a2];
                ++l[a1];
            }
            else if(s2[0]==c[(ai-1+3)%3])
            {
                ++w[a1];
                ++l[a2];
            }
        }
        for(int i=1; i<=n; ++i)
        {
            if(w[i]+l[i]==0)
            {
                printf("-\n");
                continue;
            }
            printf("%.3lf\n",w[i]/(double)(w[i]+l[i]));
        }
    }
    return 0;
}

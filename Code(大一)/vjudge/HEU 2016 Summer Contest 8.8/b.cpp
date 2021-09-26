#include <cstdio>

int main(){
    int n,m,a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&a,&b);
            if(a>b)
            {
                int t=a;
                a=b;
                b=t;
            }
            ans^=b-a-1;
        }
        if(ans) printf("I WIN!\n");
        else printf("BAD LUCK!\n");
    }
    return 0;
}

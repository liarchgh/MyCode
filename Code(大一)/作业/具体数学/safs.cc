#include<cstdio>
unsigned int x[4],y = 9;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        x[0] = x[2] = x[1] = 0;
        x[3] = 1;
        for(int i=0;i<n;++i) x[3]*=y;
        printf("%u%u\n",x[2],x[3]);
    }
    return 0;
}

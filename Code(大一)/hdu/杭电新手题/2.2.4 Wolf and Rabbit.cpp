#include<cstdio>
int zdgys(int m,int n)
{
    return n?zdgys(n,m%n):m;
}
int main()
{
    int m,n,P,q,ct;
    scanf("%d",&P);
    while(P--)
    {
        q=0;ct=0;
        scanf("%d %d",&m,&n);
        if(zdgys(m,n)==1)
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

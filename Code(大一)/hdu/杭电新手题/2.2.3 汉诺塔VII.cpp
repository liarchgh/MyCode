#include<cstdio>
//#include<
char jd;
void pd(int n,int *a,int *b,int *c)
{
    if(!n)
    {
        jd=1;
        return ;
    }
    else if (b[0] && n==b[1])
    {
        jd=0;
        return ;
    }
    else if(a[0] && n == a[1])
    {
        a[1]=a[0]-1;
        pd(n-1,++a,c,b);
    }
    else if (c[0] && n == c[1])
    {
        c[1] = c[0] - 1;
        pd(n-1,b,a,++c);
    }
}
int main()
{
    int t,n,a[70],b[70],c[70];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&a[0]);//printf("1\n");
        for(int i=1; i<=a[0]; ++i) scanf("%d",&a[i]);
        scanf("%d",&b[0]);
        for(int i=1; i<=b[0]; ++i) scanf("%d",&b[i]);
        scanf("%d",&c[0]);
        for(int i=1; i<=c[0]; ++i) scanf("%d",&c[i]);
        pd(n,a,b,c);
        if(!jd)
            printf("false\n");
        else
            printf("true\n");
    }
    return 0;
}

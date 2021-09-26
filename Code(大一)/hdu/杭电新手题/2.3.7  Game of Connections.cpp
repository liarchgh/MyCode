#include<cstdio>
int num[105][2000]= {{1},{1}};
void cheng(int *a,int *b,int *ans)
{
    int l1,l2;
    for(l1=1999; !a[l1]; --l1) ;
    for(l2=1999; !b[l2]; --l2) ;
    for(int i=0; i<=l1; ++i)
        for(int j=0; j<=l2; ++j)
        {
            int d=i+j;
            ans[d]+=a[i]*b[j];
            while(ans[d]>=10000)
            {
                ans[d+1]+=ans[d]/10000;
                ans[d]%=10000;
                ++d;
            }
        }
}
void fun()
{
    for(int i=2; i<104; ++i)
        for(int j=0,m=i-1; j<=m; ++j)
            cheng(num[m-j],num[j],num[i]);
}
int main()
{
    fun();
    int n;
    while(scanf("%d",&n),n!=-1)
    {
        int l=1;
        for(l=1999; !num[n][l]; --l) ;
        printf("%d",num[n][l]);
        if(l)
        {
            while(l-->1)
                printf("%04d",num[n][l]);
            printf("%04d\n",num[n][0]);
        }
        else putchar('\n');
    }
    return 0;
}

#include<cstdio>
#include<cstring>
int main()
{
    int t,n,num[15];
    scanf("%d",&t);
    while(t--)
    {
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int j=1; j<=n; ++j)
        {
            int i=j;
            while(i>=10)
            {
                ++num[i%10];
                i/=10;
            }
            ++num[i];
        }
        for(int i=0; i<9; ++i)
            printf("%d ",num[i]);
        printf("%d\n",num[9]);
    }
    return 0;
}

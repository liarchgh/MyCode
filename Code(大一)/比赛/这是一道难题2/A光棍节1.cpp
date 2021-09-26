#include<cstdio>
#include<cstring>
int main()
{
    int t,n,num;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        scanf("%d",&n);
        for(int j=1; j<=n; ++j)
        {
            int i=j;
            while(i)
            {
                if(i%10 == 1)
                    ++num;
                i/=10;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}

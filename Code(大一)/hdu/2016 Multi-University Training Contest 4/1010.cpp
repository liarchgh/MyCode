//wrong


#include<cstdio>

const int inf= 100005;
    int t,n,s[inf],ze[inf],p[inf];//ze[]��һ��֮���м���0 p[]0��ǰһ�����ߵ�һλ��0�Ƿ�����
int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        memset(ze,0,sizeof(ze));
        memset(p,0,sizeof(p));
        printf("Case #%d: ",i);
        scanf("%d",&n);
        int x=0,ji=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&s[i]);
            if(!s[i])
            {
                ++x;
                if(i==0 || s[i-1]) ji=i;
            }
            else if(i>!s[i-1])
            {
                ze[ji]=ze[]
            }
        }
    }
    return 0;
}

#include<cstdio>
int main()
{
    int t,m=1;;
    char a1[30],a[20][30];
    while(scanf("%d",&t),t)
    {
        printf("SET %d\n",m++);
        for(int i=t/2;i>0;--i)
        {
            scanf("%s%s",a1,a[i]);
            puts(a1);
        }
        if(t&1)
        {
            getchar();
            gets(a1);
            puts(a1);
        }
        for(int i=1;i<=t/2;++i)
            puts(a[i]);
    }
    return 0;
}

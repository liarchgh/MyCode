#include<cstdio>
#include<cstring>

int main()
{
    int n,d[1005],ans;
    char s[1005][20],s1[20];
    while(scanf("%d",&n),n)
    {
        getchar();
        int l = 0;
        ans = 1;
        for(int i=0;i<n;++i)
        {
            d[i] = 1;
            gets(s1);
            int p = 1;
            for(int j=0;j<l;++j)
            {
                if(!strcmp(s1,s[j]))
                {
                    p=0;
                    ++d[j];
                    ans = ans>d[j]?ans:d[j];
                    break;
                }
            }
            if(p)
            {
                strcpy(s[l++],s1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

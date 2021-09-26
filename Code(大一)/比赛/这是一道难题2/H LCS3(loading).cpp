#include<cstring>
#include<cstdio>
int main()
{
    char s1[1000000],s2[1000000];
    do
    {
        gets(s1);
        gets(s2);
        int len1=strlen(s1),len2=strlen(s2);
        int ans=0,p=1;
        for(int i=0; i<len1; ++i)
            for(int j=0; j<len2; j+=ans+1)
            {
                int l1=0,l2=0;
                if(s1[i] == s2[j])
                {
                    for(int m=0; !l1||!l2; ++m)
                    {
                        if(s1[i+m]!=s2[j+m] || i+m>=len1 || j+m>=len2) l1=m;
                        if(s1[i-m]!=s2[j-m] || i-m>=len1 || j-m>=len2) l2=m;
                    }
                    if(l1+l2+1>ans) ans=l1+l2+1;
                }
            }
        printf("%d\n",ans);
    }while(getchar()!=EOF);
    return 0;
}

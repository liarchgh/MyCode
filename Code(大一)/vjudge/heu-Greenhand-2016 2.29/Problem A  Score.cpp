#include<cstdio>
#include<cstring>
int main()
{
    int t,ans,fen[90];
    char s[90];
    scanf("%d\n",&t);
    while(t--)
    {
        ans=0;
        memset(fen,0,sizeof(fen));
        gets(s);
        int len = strlen(s);
        for(int i=0;i<len;++i)
            {
                if(s[i] == 'O')
                    if(!i) fen[i]=1;
                    else fen[i]=fen[i-1]+1;
                ans+=fen[i];
            }
        printf("%d\n",ans);
    }
    return 0;
}

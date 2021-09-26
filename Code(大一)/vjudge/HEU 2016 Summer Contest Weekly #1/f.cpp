#include<cstdio>

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        //printf("%d %d %d\n",a,b,c);
        if(a<b)
        {
            int t=a;
            a=b;
            b=t;
        }
        if(c<=a){printf("0\n");continue;}
        int x=c/a,ans=0;
        if(x*a==c) --x;
        while(x>0)
        {
            if(!((c-a*x)%b)) ++ans;
            --x;
        }
        printf("%d\n",ans);
    }
    return 0;
}

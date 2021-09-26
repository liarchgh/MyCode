#include<cstdio>
#include<cstring>

int w,h,d[25][25],c[25][25];
char cc;
int suan(int a,int b);
int main()
{
    int a,b;
    while(scanf("%d%d",&w,&h),w&&h)
    {
        getchar();
        memset(d,0,sizeof(d));
        for(int i=0; i<h; ++i)
        {
            for(int j=0; j<w; ++j)
            {
                switch(getchar())
                {
                case '.':c[i][j]=1;
                    break;
                case '#':c[i][j]=0;
                    break;
                 case '@':d[i][j]=1;a=i;b=j;
                }
            }
            getchar();
        }
        //printf("%d %d\n",a,b);
        printf("%d\n",suan(a,b));
    }
    return 0;
}

int suan(int a,int b)
{
    int sum=0;
    for(int i=a-1;i<=a+1;++i)
    {
        for(int j=b-1;j<=b+1;++j)
        {
            int r=i-a,t=j-b;
            if(r<0) r=0-r;
            if(t<0) t=0-t;
            if(r+t>1 || r+t==0) continue;
            if(i>=0 && i<h && j>=0 && j<w && !d[i][j] && c[i][j])
            {
                d[i][j]=1;
                //printf("%d %d %d\n",i,j,suan(i,j));
                sum+=suan(i,j);
            }
        }
    }
    return sum+1;
}

#include<cstdio>
int main()
{
    int n,d,t,ans=0,sum=0,p;
    char c;
    scanf("%d%d",&n,&d);
    getchar();
    for(int i=0;i<d;++i)//天数的循环
    {
        p=0;
        for(int j=0;j<n;++j)//对手的循环
        {
            scanf("%c",&c);//注意0 1之间没有空格 得按字符来读
            t=c-'0';
            if(!t) p=1;
        }
        getchar();
        if(p) {++sum;ans=ans>sum?ans:sum;}//每次若成功加一 否则清零 每次判断是否用更新最大值
        else sum=0;
    }
    printf("%d\n",ans);
    return 0;
}

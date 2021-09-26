/*






要用到快速幂






*/
#include<cstdio>
#include<cstring>
__int64 ans=0;//答案 即结果个数(3次方之前的)
const long long mx=1e9+7;//需要取余的数
void pan(char c);//逐位判断
long long jiecheng[6];//存储3的各次方 方便计算
int main()
{
    long long x=3;
    for(int i=0;i<6;++i,x*=x)
        {jiecheng[i]=x%mx;
        //printf("%lld\n",jiecheng[i]);
        }
    char s[100000+8];
    gets(s);
    for(int i=0;i<strlen(s);++i)
        pan(s[i]);
        long long jieguo=1;//最终结果
    //pan()中的ans没有进行次方运算
    for(int i=0;i<=6;++i)
    {
        if((1<<i)&ans) jieguo*=jiecheng[i];
    if(jieguo>=mx) jieguo%=mx;
    }
    printf("%I64d\n",jieguo);
    return 0;
}

void pan(char c)
{
    int t;
    //按情况分类
    if(c>='0' && c<='9')
    {
        t=c-'0';
    }
    else if(c>='A' && c<='Z')
    {
        t=c-'A'+10;
    }
    else if(c>='a' && c<='z')
    {
        t=c-'a'+36;
    }
    else
    {
        switch(c)
        {
            case '-':t=62;break;
            case '_':t=63;
        }
    }
    //printf("%d\n",t);
    for(int i=1;i<64;i<<=1)//化为二进制逐位判断是否为0 若是则ans加1
    {
        if(!(i&t)) {++ans;}
    }
}

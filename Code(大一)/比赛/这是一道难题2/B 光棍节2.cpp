#include<cstdio>
int fun1(int n)
{
    if(n == 1) return 1;
    int j=1;
    for(int i=1;i<n;++i) j*=10;
    int ans=j+j/10*9*(n-1);
    return  ans+fun1(n-1);
}
int fun(char *c,int n)
{
    if(n<=1) return c[0]>=1?1:0;
    int w=1,ans=0;
    for(int i=0;i<n-2;++i) w*=10;
    if('1'==c[0])
        for(int i=1,j=n-1; j>0; --j,i*=10)
        {
            ans+=(c[j]-'0')*i;
            if(1==j) {ans+=fun1(n-1);++ans;}
        }
    else if(c[0]>'1')
        ans+=(n-1)*(c[0]-'0'-1)*w+w*10+fun1(n-1);//printf("%d\n",ans);
    return ans+fun(c+1,n-1);
}
int main()
{
    int t,w;
    char c[15];
    scanf("%d\n",&t);
    while(t--)
    {
        w=0;
        while((c[w]=getchar())!='\n')
            ++w;
        printf("%d\n",fun(c,w));
    }
    return 0;
}
/*�ɹ�
#include<cstdio>
#include<cmath>
int func1(unsigned int n)
 {
     int count = 0;
     int len = (int)log10((double)n);//�ܹ�����λ
     int lenL = -1, lenM = -1, lenR = -1;
     int idxD = -1;
     while( len != -1 )
     {
         lenM = (int)pow(10,(double)len+1);
         lenR = (int)pow(10,(double)len);
         idxD = n%lenM/lenR;//��λ���ø�λ���ּ���1
         count += ( n / lenM) * lenR;
         if( idxD == 1 )//��ǰλ������1��ҪС��
             count += n % lenR + 1;
         else if( idxD > 1 )//����1��ֱ�Ӽ�
             count += lenR;
         len--;
     }
     return count;
 }

int main()
{
    int t,n;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",func1(n));
    }
    return 0;
}

*/

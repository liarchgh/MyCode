#include<stdio.h>
#include<math.h>
#define a (sqrt(5.0)+1.0)/2
int main()
{
    int n,i,j,t,f[21]= {0,1};
    double ans;
    for(i=2; i<21; i++)
        f[i]=f[i-1]+f[i-2];
    while(scanf("%d",&n)!=EOF)
    {
        if(n<21)printf("%d\n",f[n]);
        else
        {
            ans=-0.5*(log10(5.0))+n*log10(a);
            ans-=(int)ans;
            ans=pow(10.0,ans);
            while(ans<1000)ans*=10;
            printf("%d\n",(int)ans);
        }
    }
    return 0;
}

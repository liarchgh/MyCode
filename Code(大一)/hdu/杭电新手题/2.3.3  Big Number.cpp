#include<cstdio>
#include<cmath>
const double pi = 3.14159265;
int main()
{
    int t,a;double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        ans = (a*log(a) - a + 0.5 * log(2*a*pi))/log(10) + 1;
        printf("%d\n",(int)ans);
    }
    return 0;
}

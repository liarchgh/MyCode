#include<cstdio>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;

//int chu(long long a);
int main()
{
    char c[105];
    while(gets(c))
    {
        unsigned long long a,b;
        int d=strlen(c);
        if(d>12)
        {
            printf("TAT\n");
        }
        else
        {
            stringstream ss(c);
            ss>>a;
            b=4;
            int i;
            //if(a>=210066388900) printf("TAT\n");
            if(a!=0)
            {
                for(i=1; i<=5; ++i,b*=b)
                {
                    if(a<b)
                    {
                        printf("%d\n",i);
                        break;
                    }
                }
                if(i==6) printf("TAT\n");
            }
            else printf("TAT\n");
        }
    }
    return 0;
}
/*
int chu(long long a)
{
    if(a!=1)
    {
        //printf("%lld\n",a);
        long long b=sqrt(a);
        return 1+chu(b);
    }
    else return 0;
}
0:1
1:2~3
2:4~15
3:16~255
4:~2^16-1
5:~2^32-1
*/

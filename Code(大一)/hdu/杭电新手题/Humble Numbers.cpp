#include<algorithm>
#include<cstdio>
using namespace std;

long long int n,d[6000] = {1,2,3,4,5,6,7};
int s(int n);
int main()
{
    s(5900);
    while(scanf("%d",&n),n)
    {
        switch(n%10)
        {

        }
        printf("%ld\n",d[n]);
    }
    return 0;
}

int s(int x)
{
    long long int &a = d[x];
    if(a) return a;
    int z[4] = {2,3,5,7};
    long long int m[90] = {0};
    int p = 0;
    for(int i=1;i<=20;++i)
    {
        for(int j=0;j<4;++j)
        {
            m[p++] = s(x-i) * z[j];
        }
    }
    sort(m,m+p);
    for(int i=0;i<p-1;++i)
    {
        if(m[i]<=s(x-1) && m[i+1]>s(x-1)) {return a = m[i+1];}
    }
    printf("shdfsdfh");
    getchar();
}

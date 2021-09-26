#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int max3(int a,int b,int c)
{
    a = a>b?a:b;
    a = a>c?a:c;
    return a;
}
int max2(int a,int b)
{
    a = a>b?a:b;
    return a;
}
int t[100001][11];
int main()
{
    int n,T,x,max;
    while(scanf("%d",&n)&&n)
    {
        memset(t,0,sizeof(t));
        max = 0;
        while(n--)
        {
            scanf("%d %d",&x,&T);
            t[T][x]++;
            max = max>T?max:T;
        }
        for(int i = max-1; i >= 0; i--)
        {
            for(int j = 0; j <= 10; j++)
            {
                if(j==0)t[i][j] += max2(t[i+1][j],t[i+1][j+1]);
                else if(j==10) t[i][j] += max2(t[i+1][j],t[i+1][j-1]);
                else t[i][j] += max3(t[i+1][j-1],t[i+1][j],t[i+1][j+1]);
            }
        }
        cout<<t[0][5]<<endl;
    }
    return 0;
}

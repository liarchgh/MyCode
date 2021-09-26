/*
本题思路很简单：就是用2，3，5，7循环来
求第i个f[i],第i个f[i]必定等于
前i-1个数中其中一个数与｛2，3，5，7｝中
其中一个的乘积，于是答案就出来了～～
--来自csdn

*/
#include<stdio.h>
#include<iostream>
using namespace std;
long long f[5843];
int main()
{
    int prime[4]={2,3,5,7};
    int i,j,k;
    int n;
    f[1]=1;
    for(i=2;i<=5842;i++)
    {
        f[i]=2000000001;
        for(j=0;j<4;j++)
        {
            for(k=i-1;k>=1;k--)
            {
                if(f[k]*prime[j]<=f[i-1])break;
                if(f[k]*prime[j]<f[i])
                   f[i]=f[k]*prime[j];
            }
        }
    }
    while(cin>>n,n)
    {
        cout<<"The "<<n;
        if(n%10==1&&n%100!=11)cout<<"st ";
        else if(n%10==2&&n%100!=12)cout<<"nd ";
        else if(n%10==3&&n%100!=13)cout<<"rd ";
        else  cout<<"th ";
        cout<<"humble number is "<<f[n]<<"."<<endl;

    }
    return 0;
}

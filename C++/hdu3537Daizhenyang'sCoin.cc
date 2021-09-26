#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int C, num = 0;
    int n, a[105];
    while(scanf("%d",&n)!=-1)
    {
        if(!n)
        {
            puts("Yes");
            continue;
        }
        int x=0,i,j,k;
        for(i=0;i<n;i++) scanf("%d",a+i);
        sort(a,a+n);
        n=unique(a,a+n)-a;
        for(i=0;i<n;i++)
        {
            k=0;
            j=a[i];
            while(a[i])
            {
                if(a[i]&1) k++;
                a[i]>>=1;
            }
            if(k&1) x^=2*j;
            else x^=2*j+1;
        }
        if(!x) puts("Yes");
        else puts("No");
    }
    return 0;
}

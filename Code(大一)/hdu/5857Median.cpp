#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
#define Max(a,b) (a>b)?a:b
#define lowbit(x) x&(-x)
int l1,l2,r1,r2,sum;
double a[100005];
double ans(int x)
{
    if(r1<=l2)
    {
        if(x<=r1-l1+1)
        {
            return a[l1+x-1];
        }
        else
        {
            return a[l2+x-1-r1+l1-1];
        }
    }
    else if(r1<=r2)
    {
        if(x<=l2-l1)
        {
            return a[l1+x-1];
        }
        else if(x>r1-l1+1+r1-l2+1)
        {
            return a[l2+x-r1+l1-1-1];
        }
        else
        {
            return a[l2+(x-l2+l1+1)/2-1];
        }
    }
    else
    {
        swap(r1,r2);
        if(x<=l2-l1)
        {
            return a[l1+x-1];
        }
        else if(x>r1-l1+1+r1-l2+1)
        {
            return a[l2+x-r1+l1-1-1];
        }
        else
        {
            return a[l2+(x-l2+l1+1)/2-1];
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf("%lf",&a[i]);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            if(l1>l2)
            {
                swap(l1,l2);
                swap(r1,r2);
            }
            sum=r1-l1+1+r2-l2+1;
            if(sum%2)
            {
                printf("%.1f\n",ans(sum/2+1));
            }
            else
            {
                printf("%.1f\n",(ans(sum/2)+ans(sum/2+1))/2);
            }
        }
    }
}

// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <fstream>

// using namespace std;

// const int mx = 100000;
// int ss[mx + 3];

// double dea(int l1, int r1, int l2, int r2){
// 	if(l1 > l2){
// 		swap(l1, l2);
// 		swap(r1, r2);
// 	}
// 	if(r1 >= l2){
// 		if(r1 < r2) swap(r1, r2);
// 		int ln1 = l2 - l1, ln2 = r2 - l2 + 1, ln3 = r1 - r2, len = ln1 + ln2 * 2 + ln3, pos = len >> 1;
// 		// printf("%d %d %d %d\n", ln1, ln2, ln3, len);
// 		if(len & 1){
// 			if(pos <= ln1) return (double)ss[l1 + pos];
// 			if(pos >=len - ln3 - 1) return (double)ss[l1 + pos - ln2];
// 			int t =(pos - ln1) / 2 + ln1;
// 			return (double)ss[l1 + t];
// 		}
// 		else{
// 			--pos;
// 			if(pos < ln1) return (double)(ss[l1 + pos] + ss[l1 + pos + 1]) / 2;
// 			if(pos >= len - ln3) return (double)(ss[l1 + pos - ln2] + ss[l1 + pos - ln2 + 1]) / 2;
// 			int t = pos - ln1;
// 			if(t & 1){
// 				t = t / 2 + ln1 + l1;
// 				return (double)(ss[t] + ss[t + 1]) / 2;
// 			}
// 			else{
// 				t = t / 2 + ln1 + l1;
// 				return (double)(ss[t]);
// 			}
// 		}
// 	}
// 	int ln1 = r1 - l1 + 1, ln2 = r2 - l2 + 1, len = ln1 + ln2, pos = len >> 1;
// 	if(len & 1){
// 		if(ln1 < ln2){
// 			return (double)ss[l2 + pos - ln1];
// 		}
// 		else{
// 			return (double)ss[l1 + pos];
// 		}
// 	}
// 	else{
// 		if(ln1 == ln2){
// 			return ((double)ss[r1] + ss[l2]) / 2;
// 		}
// 		if(ln1 < ln2){
// 			return ((double)ss[l2 + pos - ln1 - 1] + ss[l2 + pos - ln1]) / 2;
// 		}
// 		else{
// 			return ((double)ss[l1 + pos - 1] + ss[l1 + pos]) / 2;
// 		}
// 	}
// }

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("D:\\in.txt", "r", stdin);
// 	freopen("D:\\out.txt", "w", stdout);
// 	#endif
// 	int t, m, n, l1, r1, l2, r2;
// 	scanf("%d", &t);
// 	while(t--){
// 		scanf("%d%d", &n, &m);
// 		for(int i = 0; i < n; ++i){
// 			scanf("%d", &ss[i]);
// 		}
// 		while(m--){
// 			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
// 			printf("%.1lf\n", dea(l1 - 1, r1 - 1, l2 - 1, r2 - 1));
// 		}
// 	}
// 	return 0;
// }

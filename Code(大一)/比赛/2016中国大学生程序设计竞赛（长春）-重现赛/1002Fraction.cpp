//思路很正确 就是WA 无解啊！？！？！？！？
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>

using namespace std;

const int mx = 13;
int n, a[mx], b[mx];

int gcd(int a, int b){
    while(a){
        int t = b % a;
        b = a;
        a = t;
    }
    return b;
}

pair<int, int> hua(pair<int, int>x){
    int a = gcd(x.first, x.second);
    x.first /= a;
    x.second /= a;
    return x;
}

// pair<int, int> sol(int now){
//     // printf("%d\n", now);
//     if(now >= n - 1){
//         pair<int, int> ss;
//         ss.first = b[now];
//         ss.second = a[now];
//         return ss;
//     }
//     pair<int, int>t = sol(now + 1);
//     t.first += a[now] * t.second;
//     t.second *= b[now];
//     t = hua(t);
//     swap(t.first, t.second);
//     // printf("%d %d\n", t.first, t.second);
//     return t;
// }

int main() {
//#ifndef ONLINE_JDUGE
    //freopen("D:\\in.txt", "r", stdin);
    //freopen("D:\\out.txt", "w", stdout);
//#endif
    int t;
    // printf("%d\n", gcd(6, 5));
    scanf("%d", &t);
    for (int c = 1; c <= t; ++c) {
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[j]);
        }
        for (int j = 0; j < n; ++j) {
            scanf("%d", &b[j]);
        }
        int fz=b[n - 1],fm=a[n - 1], i;  
        for(i=n-2;i >= 0;i--)  
        {  
            fz+=a[i]*fm;  
            fm*=b[i];  
            swap(fz,fm);  
        }  
        i=gcd(fz,fm);  
        fz/=i,fm/=i;  
        printf("Case #%d: ",c);  
        printf("%d %d\n",fz,fm);
    }
    return 0;
}
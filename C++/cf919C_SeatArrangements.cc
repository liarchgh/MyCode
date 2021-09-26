// http://codeforces.com/problemset/problem/919/C
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>

const int mx = 2005;
int n, m, k, col[mx];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
#endif
    scanf("%d%d%d\n", &n, &m, &k);
    memset(col, 0, sizeof(col));
    char c;
    int thisRow = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        thisRow = 0;
        for(int j = 0; j < m; ++j){
            c = getchar();
            if(c == '.'){
                ++thisRow;
                ++col[j];
            }
            else{
                thisRow = 0;
                col[j] = 0;
            }
            if(k > 1 && col[j] >= k){
                ++ans;
            }
            if (thisRow >= k)
            {
                ++ans;
            }
        }
        getchar();
    }
    printf("%d\n", ans);
    return 0;
}

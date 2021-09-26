#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;

struct TimeD{
    int l,r,man;
};

bool cmp(TimeD a, TimeD b){
    if(a.l != b.l){
        return a.l < b.l;
    }
    return a.r < b.r;
}

const int max_n = 20004;
TimeD times[max_n];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < n; ++j){
            TimeD& timed = times[i * n + j ];
            scanf("%d%d", &timed.l, &timed.r);
            timed.man = i;
        }
    }
    sort(times, times + n*2, cmp);
    int lasta = -1, lastb = -1, res = 0;
    for(int i = 0; i < n*2; ++i){
        TimeD& td = times[i];
        int& last = td.man ? lasta : lastb;
        if(last >= 0){
            res += max(0, min(td.r, times[last].r)  - td.l);
        }
        td.man ? (lastb=i) : (lasta=i);
    }
    printf("%d\n", res);
}
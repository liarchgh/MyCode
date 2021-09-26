#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 2000;
int len, sa[mx + 3], rank[mx + 3], k, lg[mx + 3][mx + 3], hg[mx + 3];
char ss[mx  + 3];

bool cmphz(int a, int b){
    if(rank[a] != rank[b]) return rank[a] < rank[b];
    else{
        int la = a + k <= len ? rank[a + k] : -1,
        lb = b + k <= len ? rank[b + k] : -1;
        return la < lb;
    }
}

void calhz(char *ss){
    for(int i = 0; i <= len; ++i){
        sa[i] = i;
        rank[i] = ss[i];
    }
    int rr[mx + 3];
    for(k = 1; k <= len; k *= 2){
        sort(sa, sa + len + 1, cmphz);
        rr[sa[0]] = 0;
        for(int i = 1; i <= len; ++i){
            rr[sa[i]] = rr[sa[i - 1]] + (cmphz(sa[i - 1], sa[i]) ? 1 : 0);
        }
        if(rr[sa[len]] > len) return;
        for(int i = 0; i <= len; ++i){
            rank[i] = rr[i];
        }
    }
}

void calhg(char *ss){
    for(int i = 0; i <= len; ++i){
        rank[sa[i]] = i;
    }
    int h = 0;
    hg[0] = 0;
    for(int i = 0; i < len; ++i){
        if(h > 0) --h;
        int j = sa[rank[i] - 1];
        for(;i + h < len && j + h < len; ++h){
            if(ss[i + h] != ss[j + h]) break;
        }
        hg[i] = h;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\in.txt", "r", stdin);
    freopen("D:\\out.txt", "w", stdout);
    #endif
    gets(ss);
    // for(int i = 0; i < 2; ++i){
    //     for(int j = 0; j < n; ++j){
    //         scanf("%d", &ss[j]);
    //         ss[len * 2 - j - 1] = ss[j];
    //     }
    // }
    int n = strlen(ss);
    for(int i = 0; i < n; ++i){
        ss[n * 2 - i] = ss[i];
    }
    len = n * 2 + 1;
    ss[len] = ss[n] = -1;
    calhz(ss);
    calhg(ss);
    int ans = 0, st;
    for(int i = 0; i <= len; ++i){
        printf("%d\n", hg[i]);
    }
    for(int a = 0; a < n; ++a){
        int i = rank[a], j = rank[len - a - 1],ta = 0xfffffff;
        if(i > j) swap(i, j);
        printf("%d %d\n", i, j);
        for(int b = 1 + i; b <= j; ++b){
            ta = min(ta, hg[b]);
        }
        if(ta > ans) {st = a;ans = ta;}
    }
    printf("%d\n", ans);
    gets(ss);
    printf("%d\n", strlen(ss));
    return 0;
}

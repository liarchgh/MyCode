#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mxk = 105, mxm = 105, mxn = 10005;
int k;
int mov[mxk], num[mxm], sg[mxn];

//经过了改造的sg函数 减少了计算时间
int calSg(int need){
    //若为-1 则需要先计算
    if(sg[need] == -1){
        int mex[mxk];
        memset(mex, 0, sizeof(mex));
        for(int j = 0; j < k && mov[j] <= need; ++j){
            mex[calSg(need - mov[j])] = 1;
        }
        int now = 0;
        for(; now < need && mex[now]; ++now){}
        sg[need] = now;
    }
    return sg[need];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int m;
    while(scanf("%d", &k), k){
        for(int i = 0; i < k; ++i){
            scanf("%d", &mov[i]);
        }
        //要保证mov数组是从小到大的顺序
        sort(mov, mov + k);
        memset(sg, -1, sizeof(sg));
        scanf("%d", &m);
        while(m > 0 && m--){
            int l;
            scanf("%d", &l);
            int x, ans = 0;
            while(l > 0 && l--){
                scanf("%d", &x);
                //需要多少就计算多少
                ans ^= calSg(x);
            }
            if(!ans){
                printf("L");
            }
            else{
                printf("W");
            }
        }
        printf("\n");
    }
    return 0;
}

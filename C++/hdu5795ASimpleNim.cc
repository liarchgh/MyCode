#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const int mx = 60;
int sg[mx];

int calSg(int now){
    if(sg[now] < 0){
        int & re = sg[now];
        re = 0xfffffff;
        set<int> meg;
        meg.insert(0);
        for(int i = 1; i <= now/3; ++i){
            int p = 0;
            for(int j = i; i + j <= now * 2 / 3; ++j){
                int k = now - i - j;
                // cout<<"---"<<i<<' '<<j<<' '<<k<<endl;
                // cout<<"---"<<calSg(i)<<' '<<calSg(j)<<' '<<calSg(k)<<endl;
                // cout<<"---"<<(calSg(i)^calSg(j)^calSg(k))<<endl;
                if(k < j){
                    p = 1;
                    break;
                }
                meg.insert(calSg(i) ^ calSg(j) ^ calSg(k));
            }
            if(p){
                break;
            }
        }
        set<int>::iterator it = meg.begin();
        for(int i = now - 1; true; ++i){
            while(it != meg.end() && i > *it){
                ++it;
            }
            if(it == meg.end() || i != *it){
                re = i;
                break;
            }
        }
    }
    return sg[now];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:out.ls", "w", stdout);
#endif
    // memset(sg, -1, sizeof(sg));
    // sg[0] = 0;
    // for(int i = 1; i < mx; ++i){
    //     cout<<i<<' '<<calSg(i)<<endl;
    // }
    int t, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &x);
        int n, ans = 0;
        while(x--){
            scanf("%d", &n);
            if(n % 8 == 0){
                --n;
            }
            else if(n % 8 == 7){
                ++n;
            }
            ans ^= n;
        }
        if(!ans){
            printf("Second player wins.\n");
        }
        else{
            printf("First player wins.\n");
        }
    }
    return 0;
}

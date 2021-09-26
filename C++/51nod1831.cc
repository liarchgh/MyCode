//一道找规律的题目 不太好 题解什么的都不是很严谨详细 规律：素数除了2、17都是必输态，合数除了16、34、289都是必胜态
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int mxn = 1e9 + 5;
vector<int>su, ans;

void calSu(){
    su.push_back(2);
    int mx = sqrt(mxn);
    for(int i = 3; i < mx; ++i){
        int p = 0;
        for(int j = 0; j < su.size(); ++j){
            if(!(i%su[j])){
                p = 1;
                break;
            }
        }
        if(!p){
            su.push_back(i);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    // cout<<"start"<<endl;
    calSu();
    // for(int i = 1; i < mxn; ++i){
    //     int p = 1;
    //     // for(int j = 0; j < su.size() && su[j] < i; ++j){
    //     //     if(i % su[j] == 0){
    //     //         p = 0;
    //     //         break;
    //     //     }
    //     // }
    //     if(p){
    //         for(int j = 0; j < ans.size(); ++j){
    //             if((j && i % ans[j] == 0) || ans[j] + 1 == i){
    //                 p = 0;
    //                 break;
    //             }
    //         }
    //     }
    //     if(p){
    //         ans.push_back(i);
    //     }
    // }
    // cout <<"size "<<ans.size()<<endl;
    // for(int i = 0; i < ans.size(); ++i){
    //     if(!(ans[i]&1))
    //     cout << ans[i] << endl;
    // }
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ps = 1;
        int sq = sqrt(n);
        for(int i = 0; i < su.size() && su[i] <= sq; ++i){
            if(!(n % su[i])){
                ps = 0;
                break;
            }
        }
        int p = 0;
        if((ps && n!=2 && n!=17) || n==16 || n==34 || n==289){
            printf("NIE\n");
        }
        else{
            printf("TAK\n");
        }
    }
    return 0;
}

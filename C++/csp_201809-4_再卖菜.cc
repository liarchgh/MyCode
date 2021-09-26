#include <cstdio>
#include <iostream>
using namespace std;

const int max_n = 300 + 5, max_price = 100 + 5;
int n,
NowPrices[max_n],
PrePrices[max_n]={0},
HasVis[max_n][max_price*3][max_price*3]={0};

int HandleDFS(int th){
#ifndef ONLINE_JUDGE
    for(int i = 0; i < n-1; ++i){
        printf("%d ", PrePrices[i]);
    }
    printf("%d\n", PrePrices[n-1]);
#endif

    int x=th>0?PrePrices[th-1]:0, y=th>1?PrePrices[th-2]:0;
    if(HasVis[th][x][y]){
        return -1;
    }
    HasVis[th][x][y] = 1;

    if(th >= n){
        if((PrePrices[n-1]+PrePrices[n-2])/2 != NowPrices[n-1]){
            return -1;
        }
        for(int i = 0; i < n-1; ++i){
            printf("%d ", PrePrices[i]);
        }
        printf("%d\n", PrePrices[n-1]);
        return 1;
    }

    int min_price, max_price;
    if(th > 1){
        min_price = NowPrices[th-1]*3 -x-y;
    }
    else if(th == 1){
        min_price = NowPrices[0]*2 - x-y;
    }
    else{
        min_price = 0;
    }
    min_price = max(1, min_price);

    if(th > 1){
        max_price = NowPrices[th-1]*3 -x-y + 2;
    }
    else if(th == 1){
        max_price = NowPrices[0]*2 - x-y +1;
    }
    else{
        max_price = NowPrices[0]*2+1;
    }

    if(max_price < 0){
        return -1;
    }

    for(int i = min_price; i <= max_price; ++i){
        PrePrices[th] = i;
        if(HandleDFS(th+1) > 0){
            return 1;
        }
    }
    return -1;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &NowPrices[i]);
    }
    HandleDFS(0);
    return 0;
}
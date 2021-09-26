#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

const int mxn = 1006;
int sg[mxn], mov[mxn];

//计算每次可以走的步数
void calMov(){
    mov[0] = 1;
    mov[1] = 2;
    for(int i = 2; mov[i - 1] <= mxn; ++i){
        mov[i] = mov[i - 1] + mov[i - 2];
    }
}

//计算不同剩余石子数的sg函数值
void calSg(){
    memset(sg, 0, sizeof(sg));
    int mex[mxn] = {0};
    for(int i = 0; i < mxn; ++i){
        memset(mex, 0, sizeof(mex));
        for(int j = 0; mov[j] <= i; ++j){
            mex[sg[i - mov[j]]] = 1;
        }
        int now = 0;
        for(; now < i && mex[now]; ++now){}
        sg[i] = now;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("D:/in.ls", "r", stdin);
    freopen("D:/out.ls", "w", stdout);
#endif
    calMov();
    calSg();
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c), a || b || c){
        //用nim博弈来做
        if(!(sg[a] ^ sg[b] ^ sg[c])){
            printf("Nacci\n");
        }
        else{
            printf("Fibo\n");
        }
    }
    return 0;
}

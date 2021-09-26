#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int a, b;
    while(~scanf("%d%d", &a, &b)){
        if(a > b) swap(a, b);
        int k = b - a;
        if(a == (int)(k * (pow(5, 0.5) + 1) / 2)){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}

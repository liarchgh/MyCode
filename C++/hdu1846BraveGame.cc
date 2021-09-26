#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        if(n % (m + 1)){
            printf("first\n");
        }
        else{
            printf("second\n");
        }
    }
    return 0;
}

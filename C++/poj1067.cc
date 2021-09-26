#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int x, y;
    while(scanf("%d%d", &x, &y)!=-1){
        if(x > y) swap(x, y);
        int k = y - x;
        if(x == int(k * (1 + sqrt(5)) / 2)){
            printf("0\n");
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}

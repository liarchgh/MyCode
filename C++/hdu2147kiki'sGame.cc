#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int n, m;
    while(scanf("%d%d", &n, &m), n || m){
        if(n & 1 && m & 1){
            printf("What a pity!\n");
        }
        else{
            printf("Wonderful!\n")
        }
    }
    return 0;
}


// // 用来打表找规律 发现坐标都是奇数的地点就会输
// const int mx = 10;
// char gh[mx][mx];

// int main(){
// #ifndef ONLINE_JUDGE
//     freopen("d:/in.ls", "r", stdin);
//     freopen("d:/out.ls", "w", stdout);
// #endif
//     memset(gh, 0, sizeof(gh));
//     for(int i = 0; i < mx; ++i){
//         for(int j = 0; j < mx; ++j){
//             int x = i > 0 ? i - 1 : 0;
//             int y = j > 0 ? j - 1 : 0;
//             if((i != 0 || j != 0) && (!((gh[i][y] || !j) && (gh[x][j] || !i) && gh[x][y]))){
//                 gh[i][j] = 1;
//             }
//             printf("%d", gh[i][j]);
//         }
//         putchar('\n');
//     }
//     for(int i = 0; i < mx; ++i){
//         for(int j = 0; j < mx; ++j){
//             if(!gh[i][j]){
//                 printf("%d %d\n", i + 1, j + 1);
//             }
//         }
//     }
//     return 0;
// }

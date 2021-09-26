//f(n) = f(n - 2) + 1 + (2 ^ (n - 2) - 1) + 1 + (2 ^ (n - 2) - 1)
//正确的是：f(n) = 2 * f(n - 2) + f(n - 1) + 1
//0 1 2 5 10
//难受 总感觉这道题有问题 而且时隔多时又被溢出摆了一道 T^T
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mod = 200907, mx = 3;
int n;

struct mat{
    int num[mx][mx];
    mat(){memset(num, 0, sizeof(num));}
    mat operator*(mat x){
        mat ans;
        for(int i = 0; i < mx; ++i){
            for(int j = 0; j < mx; ++j){
                for(int t = 0; t < mx; ++t){
                    ans.num[i][j] = (ans.num[i][j] + (long long)num[i][t] * x.num[t][j]) % mod;
                }
            }
        }
        return ans;
    }
};

// //快速幂
// int pow(int d, int z){
//     int ans = 1;
//     while(z){
//         if(z & 1){
//             ans = (ans * d) % mod;
//         }
//         z >>= 1;
//         d = (d * d) % mod;
//     }
//     return ans;
// }

// 矩阵快速幂
mat pow(mat d, int z){
    mat ans;
    ans = d;
    --z;
    if(z < 0){
        printf("ERROR\n");
        return d;
    }
    while(z){
        if(z & 1){
            ans = ans * d;
        }
        z >>= 1;
        d = d * d;
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
    #endif
    mat be, ex;
    be.num[0][0] = 2;
    be.num[0][1] = 1;
    be.num[0][2] = 1;
    ex.num[0][0] = 1;
    ex.num[1][0] = 2;
    ex.num[2][0] = 1;
    for(int i = 0; i < mx - 2; ++i){
        ex.num[i][i + 1] = 1;
    }
    ex.num[2][2] = 1;
    // for(int i = 0; i < mx; ++i){
    //     for(int j = 0; j < mx; ++j){
    //         printf("%d ", be.num[i][j]);
    //     }
    //     printf("\n");
    // }
    int k;
    while(scanf("%d", &n), n){
        if(n < mx){
            if(n)
                printf("%d\n",be.num[0][mx - n - 1]);
            else
                printf("0\n");
            continue;
        }
        printf("%d\n", (be * pow(ex, n - mx + 1)).num[0][0]);
    }
    return 0;
}

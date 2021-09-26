#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 10;
int k, m;

struct mat{
    int num[mx][mx];
    mat(){memset(num, 0, sizeof(num));}
    mat operator*(mat x){
        mat ans;
        for(int i = 0; i < mx; ++i){
            for(int j = 0; j < mx; ++j){
                int & d = ans.num[i][j];
                for(int q = 0; q < mx; ++q){
                    d += num[i][q] * x.num[q][j] % m;
                }
                d %= m;
            }
        }
        return ans;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
    #endif
    while(~scanf("%d%d", &k, &m)){
        mat be;
        for(int i = 0; i < mx; ++i){
            scanf("%d", &be.num[i][0]);
        }
        for(int i = 0; i < mx - 1; ++i){
            be.num[i][i + 1] = 1;
        }
        mat ans;
        for(int i = 0; i < mx; ++i){
            ans.num[0][i] = 9 - i;
        }
        if(k < 10){
            printf("%d\n", k % m);
            continue;
        }
        k -= 9;
        while(k){
            if(k & 1){
                ans = ans * be;
            }
            k >>= 1;
            be = be * be;
        }
        printf("%d\n", ans.num[0][0]);
    }
    return 0;
}

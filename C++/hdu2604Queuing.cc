//http://acm.hdu.edu.cn/showproblem.php?pid=2604
//now[i] = now[i - 1] + now[i - 3] + now[i - 4]
//第一次交的时候把be的第一行顺序写反了 傻掉了 矩阵运算都不会了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 4;
int l, mod;

struct mat{
	int num[mx][mx];
	mat(){memset(num, 0, sizeof(num));}
	mat operator*(mat x){
		mat ans;
		for(int i = 0; i < mx; ++i){
			for(int j = 0; j < mx; ++j){
				for(int u = 0; u < mx; ++u){
					ans.num[i][j] = (ans.num[i][j] + num[i][u] * x.num[u][j]) % mod;
				}
			}
		}
		return ans;
	}
};

void sol(mat be, mat ex){
// 	for(int i = 0; i < mx; ++i)
// 	{	for(int j = 0; j < mx; ++j){
// 	printf("%d ", be.num[i][j]);}
// 	printf("\n");
// }
    int k = l;
	if(k < mx){
		printf("%d\n", be.num[0][mx - k - 1]);
		return ;
	}
	k -= mx - 1;
	while(k){
		if(k & 1){
			be = be * ex;
		}
		// printf("---%d\n", k);
		k >>= 1;
		// printf("+++%d\n", k);
		ex = ex * ex;
	// printf("%d\n", be.num[0][0]);
	}
	printf("%d\n", be.num[0][0]);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.ls", "r", stdin);
	freopen("out.ls", "w", stdout);
	#endif
	mat be, ex;
	be.num[0][0] = 6;//2 4 6 9
	be.num[0][1] = 4;
	be.num[0][2] = 2;
	be.num[0][3] = 1;
	for(int i = 0; i < mx; ++i){
		if(i < mx - 1){ex.num[i][i + 1] = 1;}
		if(i != 1){
			ex.num[i][0] = 1;
		}
	}
	while(~scanf("%d%d", &l, &mod)){
		// printf("l is %d mod is %d\n", l, mod);
		sol(be, ex);
	}
	return 0;
}

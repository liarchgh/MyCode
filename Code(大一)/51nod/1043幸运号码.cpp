//不太难 时间上就是暴力过的 只是空间上用滚动数组优化了一下 然而卡在了34行溢出 加个强制类型转换就行了
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 1003, mod = 1000000007;
int dp[2][mx * 9] = {1};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		freopen("D:\\out.txt", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		memset(dp[i&1], 0, sizeof(dp[i&1]));
		for(int j = 0; j <= i * 9; ++j){	
			for(int k = 0; k <= 9 && k <= j; ++k){
				dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][j - k]) % mod;
				 // if(i == 2) printf("%d %d %d\n", j, k, dp[i & 1][j]);
			}
			// if(i == 2){
			// 	printf("%d %d %d\n", i, j, dp[i & 1][j]);
			// }
		}
	}
	long long ans = 0;
	int k = n & 1;
	for(int i = 0; i <= n * 9; ++i){
		ans = (ans + (long long)dp[k][i] * (dp[k][i] - dp[!k][i])) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

//开始训练DP 第一道还是挺简单的
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 5005;
const int inf = 0x7fffffff;
long long h[mx], dp[mx + 1], ma[mx + 1];

long long he(int l, int r) {
	long long s = 0;
	for (int i = l; i <= r; ++i) {
		s += h[i];
	}
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	//printf("%d", inf);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &h[i]);
		dp[i] = inf;
	}
	dp[n] = inf;
	long long t;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			if (j == 0) {
				if (dp[i] > i) {
					dp[i] = i;
					ma[i] = he(0, i);
				}
			}
			else if (dp[i] > dp[j - 1] + i - j && ma[j - 1] <= (t = he(j, i))) {
				dp[i] = dp[j - 1] + i - j;
				ma[i] = t;
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	printf("%I64d\n", dp[i]);
	// }
	printf("%I64d\n", dp[n - 1]);
	return 0;
}

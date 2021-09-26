//记得以前好像做过
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 503;
int dp[mx][mx] = {0};

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			scanf("%d", &dp[i][j]);
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}

//想法来的倒是挺快 然而并没有成功实现 时间复杂度分析错误 以致没有找到优化方法 又是差一点
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mx = 503;
int m, n, rec[mx][mx], sum[mx][mx] = {0};

long long chu(int s, int x) {
	long long ans = 0, tans = 0, t;
	for (int i = 0; i < n; ++i) {
		t = sum[i][x] - sum[i][s] + rec[i][s];
		if (tans > 0) {
			tans += t;
		}
		else tans = t;
		//printf("%d %d %lld\n", s, x, t);
		ans = max(ans, tans);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	// printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &rec[i][j]);
			sum[i][j] = rec[i][j];
			if(j) sum[i][j] += sum[i][j-1];
		}
	}
	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i; j < m; ++j) {
			ans = max(ans, chu(i, j));
		}
	}
	printf("%lld\n", ans);
	return 0;
}

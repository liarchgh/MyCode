//思路很早就想到了 然而对时间复杂度的分析发生了错误 太过于谨慎了 计算得不够仔细 细节忽略了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int mx = 50005;
int zhi[mx], l[mx] = {0}, r[mx] = {0};

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &zhi[i]);
	}
	int x;
	for (int i = 1; i < n; ++i) {
		x = i;
		while (x && zhi[x - 1] >= zhi[i]) {
			x = l[x - 1];
		}
		l[i] = x;

		//printf("%d\n", x);
	}
	r[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		x = i;
		while (x && zhi[x + 1] >= zhi[i]) {
			x = r[x + 1];
		}
		r[i] = x;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, ((long long)r[i] - l[i] + 1) * zhi[i]);
	}
	printf("%lld\n", ans);
	return 0;
}

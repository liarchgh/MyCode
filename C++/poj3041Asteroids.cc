//把有向边当作了无向边 傻掉了 卡了1个小时不止 一行一行比对才发现 T^T
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 1000 + 5;
int map[mx][mx], mark[mx], near[mx], n, k;

int connect(int x) {
	// mark[x] = 1;
	for (int i = 1; i <= n; ++i) {
		if (map[i][x] && !mark[i]) {
			mark[i] = 1;
			if (!near[i] || connect(near[i])) {
				near[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
#endif
	while (scanf("%d%d", &n, &k) != EOF) {
		memset(near, 0, sizeof(near));
		memset(map, 0, sizeof(map));
		int a, b;
		while (k--) {
			scanf("%d%d", &a, &b);
			map[a][b] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			memset(mark, 0, sizeof(mark));
			ans += connect(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}



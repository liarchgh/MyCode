//应该是先读n在初始化len数组 搞反顺序了 难受
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int mx = 205, inf = 0xfffffff;
int n, m, len[mx][mx], visx[mx], visy[mx], linky[mx], lx[mx], ly[mx], slack[mx];

int find_zgl(int x) {
	visx[x] = 1;
	for (int y = 0; y < n; ++y) {
		if (visy[y]) continue;
		int t = lx[x] + ly[y] - len[x][y];
		if (!t) {
			visy[y] = 1;
			if (linky[y] == -1 || find_zgl(linky[y])) {
				linky[y] = x;
				return 1;
			}
		}
		else {
			slack[y] = min(slack[y], t);
		}
	}
	return 0;
}

int KM() {
	memset(linky, -1, sizeof(linky));
	memset(ly, 0, sizeof(ly));
	for (int i = 0; i < n; ++i) {
		lx[i] = -inf;
		for (int j = 0; j < n; ++j) {
			lx[i] = max(lx[i], len[i][j]);
		}
	}
	for (int x = 0; x < n; ++x) {
		for (int i = 0; i < n; ++i) slack[i] = inf;
		while (1) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (find_zgl(x)) break;
			int d = inf;
			for (int i = 0; i < n; ++i) {
				if (!visy[i]) d = min(d, slack[i]);
			}
			for (int i = 0; i < n; ++i) {
				if (visx[i]) lx[i] -= d;
				if (visy[i]) ly[i] += d;
				else slack[i] -= d;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (linky[i] > -1) {
			res += len[linky[i]][i];
			// printf("---%d %d %d\n", linky[i], i, len[linky[i]][i]);
		}
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				len[i][j] = -inf;
			}
		}
		for (int i = 0, a, b, c; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			len[a - 1][b - 1] = max(len[a - 1][b - 1], -c);
		}
		printf("%d\n", -KM());
	}
	return 0;
}

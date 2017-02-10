//第一次少了判断是否有答案 第二次TLE了 很奇怪 原来是少了49行的if条件 但为什么是TLE啊 对了 是因为有些减了d却依然无法找到增广路吧
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 105, inf = 0xfffffff;
int n, m, way[mx][mx], visx[mx], visy[mx], linky[mx], slack[mx], lx[mx], ly[mx];//题目所给标号为1~n 我将他们化为0~n

int find_zgl(int x) {
	visx[x] = 1;
	for (int y = 0; y < n; ++y) {
		if (visy[y]) continue;
		int t = lx[x] + ly[y] - way[x][y];
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
			lx[i] = max(lx[i], way[i][j]);
		}
	}

	for (int x = 0; x < n; ++x) {
		for (int i = 0; i < n; ++i) slack[i] = inf;
		while(1) {
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (find_zgl(x)) break;
			int d = inf;
			for (int i = 0; i < n; ++i)
				if(!visy[i]) d = min(d, slack[i]);
			for (int i = 0; i < n; ++i) {
				if (visx[i]) lx[i] -= d;
				if (visy[i]) ly[i] += d;
				else slack[i] -= d;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if(linky[i] == -1 || way[linky[i]][i] == -inf) return -1;
		res += way[linky[i]][i];
	}
	return -res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
#endif
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				way[i][j] = -inf;
			}
		}
		for (int i = 0, a, b, c; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			way[a - 1][b - 1] = max(way[a - 1][b - 1], -c);
		}
		printf("%d\n", KM());
	}
	return 0;
}
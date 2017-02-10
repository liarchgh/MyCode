//莫名其妙地卡了很久 很奇怪 不过最后还好 自己做出来了 思路倒是简单 最近太懈怠了吧
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 45, dis[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}, change[4] = {1, 0, 3, 2};
int map[mx][mx], mark[mx][mx], near[mx][mx], pre[mx][mx], h, w;

int solve(int x, int y) {
	if (!map[x][y]) return 0;
	int x1, y1;
	for (int i = 0; i < 4; ++i) {
		x1 = x + dis[i][0];
		y1 = y + dis[i][1];
		if (x1 >= 0 && x1 < h && y1 >= 0 && y1 < w)
			if (!mark[x1][y1] && map[x1][y1]) {
				mark[x1][y1] = 1;
				if (near[x1][y1] < 0 || solve(x1 + dis[near[x1][y1]][0], y1 + dis[near[x1][y1]][1])) {
					near[x1][y1] = change[i];
					return 1;
				}
			}
	}
	return 0;
}

int find_num(int x, int y) {
	if (!(x >= 0 && x < h && y >= 0 && y < w)) return 0;
	if (mark[x][y]) return 0;
	mark[x][y] = 1;
	int re = 0;
	if (pre[x][y] >= 0) re += find_num(x + dis[pre[x][y]][0], y + dis[pre[x][y]][1]);
	if(near[x][y] >= 0) re += find_num(x + dis[near[x][y]][0], y + dis[near[x][y]][1]);
	return re +  1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &h, &w);
		getchar();
		memset(near, -1, sizeof(near));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				switch (getchar()) {
				case 'o': map[i][j] = 0;
					break;
				case '*': map[i][j] = 1;
				}
				// printf("%d ", map[i][j]);
			}
			// putchar('\n');
			getchar();
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				memset(mark, 0, sizeof(mark));
				solve(i, j);
			}
		}
		memset(mark, 0, sizeof(mark));
		int ans = 0;
		memset(pre, -1, sizeof(pre));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if(near[i][j] >= 0) pre[i + dis[near[i][j]][0]][j + dis[near[i][j]][1]] = change[near[i][j]];
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				// printf("%d %d ", near[i][j], pre[i][j]);
				if(map[i][j]) ans += (find_num(i, j) + 1) / 2;
				// printf("%d\n",ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

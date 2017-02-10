#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <queue>
#include <utility>

using namespace std;

const int mx = 100 + 5, dis[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char pic[mx][mx];
int n, m;

int dfs(int x, int y) {
	queue<pair<int, int> >q;
	for (int i = 0, x1, y1; i < 4; ++i) {
		x1 = x + dis[i][0];
		y1 = y + dis[i][1];
		if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && pic[x1][y1] == 'a')
			q.push(make_pair(x1, y1));
	}
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0, x1, y1; i < 4; ++i) {
			x1 = x + dis[i][0];
			y1 = y + dis[i][1];
			if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && pic[x1][y1] == 't') ++ans;
		}
	}
	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
	#endif
	while (~scanf("%d%d", &n, &m)) {
		getchar();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				pic[i][j] = getchar();
				// putchar(pic[i][j]);
			}
			getchar();
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (pic[i][j] == 'c') ans += dfs(i, j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

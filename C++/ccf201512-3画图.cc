//挺简单的一道题 就是细节方面恶心人 一边过 写着很慢
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

const int mx = 100 + 5, lin_dis[2][2] = {{0, 1}, {1, 0}}, char_dis[4][2] = {0, 1, 0, -1, 1, 0, -1};
int n, m;
char pic[mx][mx], mark[mx][mx];

void draw_line(int x1, int y1, int x2, int y2) {
	if ((x1 > x2) || (y1 > y2)) {swap (x1, x2); swap (y1, y2);}
	// x1 = x2 = y1 = y2 = 0;
	int dis_num = 1;
	if (y1 != y2) dis_num = 0;
	// printf("----%d %d %d %d\n", x1, y1, x2, y2);
	for (int x = x1, y = y1; x <= x2 && y <= y2; ) {
		// printf("%d %d\n", x, y);
		pic[x][y] = -1;
		x += lin_dis[dis_num][0];
		y += lin_dis[dis_num][1];
	}
}

void draw_char(int x, int y, char c) {
	if (mark[x][y] || x < 0 || x >= n || y < 0 || y >= m ||  pic[x][y] < 0) return;
	pic[x][y] = c;
	mark[x][y] = 1;
	for (int i = 0; i < 4; ++i) {
		int x0 = x + char_dis[i][0], y0 = y + char_dis[i][1];
		if (pic[x0][y0] != pic[x][y]) draw_char(x0, y0, c);
	}
}

int judge_line(int x, int y) { //1：横线 2：竖线 3：加号 4:. 5:pic[x][y]
	if (pic[x][y] > 0) return 5;
	if (pic[x][y] != -1) return 4;
	int ty = 0;
	if ((x - 1 >= 0 && pic[x - 1][y] == -1) || (x + 1 < n && pic[x + 1][y] == -1)) ty = 2;
	if ((y - 1 >= 0 && pic[x][y - 1] == -1) || (y + 1 < m && pic[x][y + 1] == -1)) {
		if (ty) ty = 3;
		else ty = 1;
	}
	// printf("%d %d %d\n", x, y, ty);
	return ty;
}

void solve() {
	// printf("-----%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// printf("-----%d %d\n", m, j);
			switch (judge_line(i, j)) {
			case 1: mark[i][j] = '-';
				break;
			case 2: mark[i][j] = '|';
				break;
			case 3: mark[i][j] = '+';
				break;
			case 4: mark[i][j] = '.';
			break;
			case 5: mark[i][j] = pic[i][j];
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
#endif
	int q;
	scanf("%d%d%d", &m, &n, &q);
	memset(pic, 0, sizeof(pic));
	// printf("-----%d %d\n", n, m);
	// printf("%d %d %d\n", n, m, q);
	for (int i = 0, a, b, c, d; i < q; ++i) {
		// printf("%d\n", i);
		scanf("%d", &a);
		if (a) {
			scanf("%d%d", &b, &a);
			getchar();
			// char c = getchar();
			// putchar(c);
			memset(mark, 0, sizeof(mark));
			draw_char(a, b, getchar());
			// putchar(c);
		}
		else {
			scanf("%d%d%d%d", &b, &a, &d, &c);
			// printf("%d %d\n", a, b);
			draw_line(a, b, c, d);
		}
		// for (int ii = 0; ii < n; ++ii) {
		// 	for (int j = 0; j < m; ++j) {
		// 		putchar(pic[ii][j]);
		// 	}
		// 	putchar('\n');
		// }
	}
	// printf("222222\n");
	// printf("-----%d %d\n", n, m);
	solve();
	// printf("222222\n");
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < m; ++j) {
			putchar(mark[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

//T^T被坑了 输入说的像是单组输入的样子 然而是多组
#include <cstdio>
#include <fstream>

const int mxm = 100000, mxn = 10000;
int n, m, edge[mxm + 3][2], father[mxn + 3], ans[mxm + 3];

int find_father(int x) {
	if (father[x] != x) {
		father[x] = find_father(father[x]);
	}
	return father[x];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
	freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = m - 1; i >= 0; --i) {
			scanf("%d%d", &edge[i][0], &edge[i][1]);
		}
		for (int i = 0; i < n; ++i) {
			father[i] = i;
		}
		int num = n;
		for (int i = 0, a, b; i < m; ++i) {
			a = edge[i][0];
			b = edge[i][1];
			ans[m - i - 1] = num;
			int fa = find_father(a), fb = find_father(b);
			if (fa != fb) {
				--num;
				father[fa] = fb;
			}
		}
		for (int i = 0; i < m; ++i) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}

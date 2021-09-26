#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int m, n, val[100005], du[100000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		memset(du, 0, sizeof(du));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &val[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			--a; --b;
			++du[a];
			++du[b];
		}
		int ans = 0, nj = 0;
		for (int i = 0; i < n; ++i) {
			//printf("%d\n", du[i]);
			if (du[i] & 1) {
				++nj;
				ans ^= val[i];
			}
			else if ((du[i] >> 1) & 1) {
				ans ^= val[i];
			}
		}
		if (nj == 1 || nj > 2) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}

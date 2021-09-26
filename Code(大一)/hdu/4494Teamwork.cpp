//原来是网络流 本来以为只是一个利用set的简单题 做到一半发现不正常 搜一下原来是网络流 T……T 还没学呢
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

const int mxn = 150, mxm = 5;
int n, m, x0, y0, x[mxn + 3], y[mxn + 3];

struct worker {
	int num[maxm + 3], time, x, y;
	bool operator < (worker a) {
		return time < a.time;
	}
};

set<worker>used_worker;

int main() {
	int t, x, y, begin, cost;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &x0, &y0);
		for (int i = 0; i < n; ++i) {
			worker x_wk;
			scanf("%d%d%d%d", &x_wk.x, &x_wk.y, &begin, &cost);
			for (int ii = 0; ii < m; ++ii) {
				scanf("%d", x_wk.num[ii]);
			}
			used_worker.insert(x_wk);
		}
	}
	return 0;
}

//a simple picture question but at first i forget to creat a big enough index
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int mx = 500000, one_cost = 10000;
int n, m, r, father[mx + 3];

struct no {
	int l1, l2, val;
} cost[mx + 3];

bool cmp_co(no a, no b) {
	return a.val > b.val;
}

int fin_fa(int x) {
	if (father[x] == x) {
		return x;
	}
	else {
		father[x] = fin_fa(father[x]);
		return father[x];
	}
}

void link(int a, int b) {
	father[father[a]] = father[b];
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code /in.txt", "r", stdin);freopen("/home/ls/Downloads/Code /out.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &r);
		for (int i = 0; i < n + m; ++i) father[i] = i;
		int re_cost = one_cost * (n + m);
		for (int i = 0; i < r; ++i) {
			scanf("%d%d%d", &cost[i].l1, &cost[i].l2, &cost[i].val);
			cost[i].l2 += n;
		}
		sort(cost, cost + r, cmp_co);
		for (int i = 0; i < r; ++i) {
			if (fin_fa(cost[i].l1) !=  fin_fa(cost[i].l2)) {
				link(cost[i].l1, cost[i].l2);
				re_cost -= cost[i].val;
			}
		}
		printf("%d\n", re_cost);
	}
	return 0;
}

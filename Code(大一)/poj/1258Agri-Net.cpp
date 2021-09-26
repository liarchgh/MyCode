//迭代器 运算符重载 挺好用的 题总的来说和上一题差不多 好要简单一些 我已经陷入用边来排序的深坑当中了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int mx = 103;
int father[mx];
struct ed {
	int l, r, cost;
	bool operator==(ed x) {
		return l == x.l && r == x.r;
	}
};
vector<ed>edge;

bool cmp(ed a, ed b) {
	return a.cost < b.cost;
}

int find_father(int x) {
	if (father[x] != x) {
		father[x] = find_father(father[x]);
	}
	return father[x];
}

void unite(int a, int b) {
	father[father[a]] = father[b];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
	freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
	int n;
	while (scanf("%d", &n) != EOF) {
		edge.clear();
		for (int i = 0, p = 0; i < n; ++i) {
			ed x;
			for (int j = 0; j < n; ++j) {
				x.l = min(i, j);
				x.r = max(i, j);
				scanf("%d", &x.cost);
				if (i >= j) {continue;}
				edge.push_back(x);
			}
		}
		sort(edge.begin(), edge.end(), cmp);
		for (vector<ed>::iterator it = edge.begin() + 1, tt; it != edge.end(); ++it) {
			tt = it - 1;
			if (*tt == *it) {
				edge.erase(tt);
				--it;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) father[i] = i;
		for (int i = 0; i < edge.size(); ++i) {
			if (find_father(edge[i].l) != find_father(edge[i].r)) {
				unite(edge[i].l, edge[i].r);
				ans += edge[i].cost;
			}
			// printf("%d\n", edge[i].cost);
		}
		printf("%d\n", ans);
	}
	return 0;
}

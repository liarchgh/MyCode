#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

const int mxn = 1000000, mxr = 50000, inf = 0xffffff;
int n, r;
struct edge {
	int l, r, dis;
} ed[mxr + 3];
vector<pair<int, int> >d[mxn + 3], fa[mxn];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

bool cmpedge(edge a, edge b) {
	return a.dis < b.dis;
}

int main() {
#ifndef ONLINE_JDUGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
	freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
	// scanf("%d", &n);
	// printf("%d\n", n);
	scanf("%d%d", &n, &r);
	for (int i = 0, a, b, l; i < r; ++i) {
		scanf("%d%d%d", &a, &b, &l);
		d[a].push_back(pair<int, int>(b, l));
		d[b].push_back(pair<int, int>(a, l));
		ed[i].l = a;
		ed[i].r = b;
		ed[i].dis = l;
	}
	for (int i = 0; i < n; ++i) {
		sort(d[i].begin(), d[i].end(), cmp);
	}
	sort(ed, ed + r, cmpedge);
	while (1) {
		bool end = false;
		for (int i = 0; i < r; ++i) {
			if ((fa[ed[i].r].first == inf) && (fa[ed[i].l].first != inf)) {
				fa[ed[i].r].first = ed[i].l;
				fa[ed[i].r].second = fa[ed[i].l].second + ed[i].dis;
				end = true;
			}
			else if ((fa[ed[i].l].first == inf) && (fa[ed[i].r].first != inf)) {
				fa[ed[i].l].first = ed[i].r;
				fa[ed[i].l].second = fa[ed[i].r].second + ed[i].dis;
				end = true;
			}
		}
		if(end) break;
	}
	int ans = inf, now = n - 1;
	while(now){
		ans = min(ans, d[now][1].second + fa[fa[now].first].second)
	}
	return 0;
}
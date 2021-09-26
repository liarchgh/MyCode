// http://poj.org/problem?id=1743
// 三元运算符又忘记加括号了T^T
//写了一上午加一晚上 细节之处太多了 思路通的比较快 调试了一天 好累啊！！！
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 20000;
int ss[mx + 3], len, sa[mx + 3], rank[mx + 3], hg[mx + 3], k;

bool cmphz(int a, int b) {
	if (rank[a] != rank[b]) {
		return rank[a] < rank[b];
	}
	else {
		int la = a + k <= len ? rank[a + k] : -1,
		    lb = b + k <= len ? rank[b + k] : -1;
		return la < lb;
	}
}

void calhz(int *ss, int *sa, int *rank) {
	for (int i = 0; i <= len; ++i) {
		sa[i] = i;
		rank[i] = (i < len) ? ss[i] : -1;
	}
	int rr[mx + 3];
	for (k = 1; k <= len; k *= 2) {
		sort(sa, sa + len + 1, cmphz);
		rr[sa[0]] = 0;
		for (int i = 1; i <= len; ++i) {
			rr[sa[i]] = rr[sa[i - 1]] + (cmphz(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for (int i = 0; i <= len; ++i) {
			rank[i] = rr[i];
		}
		// if (rr[sa[len]] >= len) break;
	}
}

void calhg(int *ss, int *sa, int *rank) {
	for (int i = 0; i <= len; ++i) {
		rank[sa[i]] = i;
	}
	// for(int i = 0; i <= len; ++i){
	// 	printf("%d %d\n", i, rank[i]);
	// }
	// printf("%d\n",rank[0]);
	int h = 0;
	hg[0] = 0;
	// printf("%d\n",rank[0]);
	for (int i = 0; i < len; ++i) {
		// if(!rank[i]) continue;
		if (h > 0) --h;
		// printf("%d\n",h);
		int j = sa[rank[i] - 1];
		for (; i + h < len && j + h < len; ++h) {
			// printf("%d %d %d\n", sa[8], sa[9], ss[i + h]);
			if (ss[j + h] != ss[i + h]) break;
		}
		hg[rank[i]] = h;
	}
}

bool cheak(int ans) {
	for (int i = 1; i <= len; ++i) {
		if (hg[i] >= ans) {
			int in = sa[i - 1], ax = sa[i - 1], j;
			for (j = i; j < len && hg[j] >= ans; ++j) {
				in = min(in, sa[j]);
				ax = max(ax, sa[j]);
			}
			if (ax - in >= ans) return true;
			i = j - 1;
			// printf("%d\n", i);
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	int n, c, d, md;
	while (scanf("%d", &n), n) {
		d = -100;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &c);
			ss[i] = c - d;
			if (c - d < md) {
				md = c - d;
			}
			d = c;
		}
		for (int i = 0; i < n; ++i) {
			ss[i] -= md;
		}
		// sort(ss, ss + n);
		// for (int i = 0; i < n; ++i) {
		// 	printf("%d\n", ss[i]);
		// }
		len = n;
		calhz(ss, sa, rank);
		ss[len] = -1;
		calhg(ss, sa, rank);
		// for (int i = 0; i <= len; ++i) {
		// 	printf("%d %d\n", i, sa[i]);
		// }
		int a = 0, b = len - 1;
		while (a < b - 1) {
			int mid = (a + b) / 2 ;
			// printf("%d %d\n", mid, (a + b) & 1);
			if (cheak(mid)) {
				a = mid;
			}
			else {
				b = mid - 1;
			}
		}
		// printf("%d\n", cheak(5));
		if(cheak(b)) a = b;
		if(a + 1 < 5){
			printf("0\n");
			continue;
		}
		printf("%d\n", a + 1);
	}
	return 0;
}
//i don't masnage the 48th's "i" well
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 10003, inf = 0x7fffffff;
int n, ml, md, d[mx];
struct ed {
	int l, r, len;
} mll[mx], mdd[mx];

bool cmpl(ed a, ed b) {
	return a.l < b.l;
}

bool cmpd(ed a, ed b) {
	return a.r > b.r;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code /in.txt", "r", stdin); freopen("/home/ls/Downloads/Code /out.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &ml, &md);
	for (int i = 0; i < ml; ++i) {
		scanf("%d%d%d", &mll[i].l, &mll[i].r, &mll[i].len);
		--mll[i].l;
		--mll[i].r;
	}
	for (int i = 0; i < md; ++i) {
		scanf("%d%d%d", &mdd[i].l, &mdd[i].r, &mdd[i].len);
		--mdd[i].l;
		--mdd[i].r;
	}
	sort(mll, mll + ml, cmpl);
	sort(mdd, mdd + md, cmpd);
	for (int i = 0; i < n; ++i) {
		d[i] = inf;
	}
	d[0] = 0;
	for (int p = 1; p;) {
		p = 0;
		// for (int i = 0; i < n; ++i)
		// 	{printf("%d ", d[i]);}
		for (int i = 0; i < n - 1; ++i) {
			if (d[i] > d[i + 1]) {
				p = 1;
				d[i] = d[i + 1];
			}
		}
		for (int i = 0; i < ml; ++i) {
			if (d[mll[i].r] > d[mll[i].l] + mll[i].len) {
				p = 1;
				d[mll[i].r] = d[mll[i].l] + mll[i].len;
			}
		}
		for (int i = 0; i < md; ++i) {
			if (d[mdd[i].l] > d[mdd[i].r] - mdd[i].len) {
				p = 1;
				d[mdd[i].l] = d[mdd[i].r] - mdd[i].len;
			}
		}
		// printf("12121212 %d\n", n);
		// for (int i = 0; i < n; ++i)
		// 	{printf(" %d", d[i]);}
		// putchar('\n');
	}
	int res = d[n - 1] - d[0];
	if (d[0] < 0) res = -1;
	else if (d[n - 1] == inf) res = -2;
	printf("%d\n", res);
	return 0;
}

// //http://poj.org/problem?id=3415
// #include <cstdio>
// #include <iostream>
// #include <fstream>
// #include <cstring>
// #include <algorithm>

// using namespace std;

// const int mx = 200000;//mx为数组大小
// int len, k, rank[mx + 4], sa[mx + 4], hg[mx + 4];
// char ss[mx + 3], *rev;//rev为比较时的数组 ss为原数组 sa[i]为排第i名(从0开始)的串的起始位置 rank[i]为从i起始的串的排名

// bool cmp(int a, int b) {//比较 a严格小于b返回true
// 	if (k == 1) {
// 		return rev[a] < rev[b];
// 	}
// 	if (rank[a] != rank[b]) {
// 		return rank[a] < rank[b];
// 	}
// 	else {
// 		int ra = a + k <= len ? rank[a + k] : -1,
// 		    rb = b + k <= len ? rank[b + k] : -1;
// 		return ra < rb;
// 	}
// }

// void calhz(char *so, int *sa) {//so是原数组 sa是排名数组 sa[i]是排第i名的串的起始地址 len为总的串的长度
// 	int rr[mx * 2 + 4];
// 	for (int i = 0; i <= len; ++i) {
// 		sa[i] = i;
// 		rank[i] = so[i];
// 	}
// 	rev = so;
// 	for (k = 1; k <= len; k <<= 1) {
// 		sort(sa, sa + len + 1, cmp);
// 		rr[sa[0]] = 0;
// 		for (int i = 1; i <= len; ++i) {
// 			rr[sa[i]] = rr[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
// 		}
// 		for (int i = 0; i <= len; ++i) {
// 			rank[i] = rr[i];
// 		}
// 		if (rank[sa[len]] >= len) return;
// 	}
// }

// void calhg(char *so, int *sa) {
// 	for (int i = 0; i <= len; ++i) {
// 		rank[sa[i]] = i;
// 	}
// 	int h = 0;
// 	hg[0] = 0;
// 	for (int i = 0; i < len; ++i) {
// 		int j = sa[rank[i] - 1];
// 		if (h > 0) --h;
// 		for (; i + h <= len && j + h <= len; ++h) {
// 			if (so[i + h] != so[j + h]) break;
// 		}
// 		hg[rank[i]] = h;
// 	}
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("D:\\in.txt", "r", stdin);
// 	freopen("D:\\out.txt", "w", stdout);
// #endif
// 	int tk;
// 	while (scanf("%d\n", &tk), tk) {
// 		gets(ss);
// 		int ln1 = strlen(ss);
// 		ss[ln1] = -1;
// 		gets(ss + ln1 + 1);
// 		len = strlen(ss);
// 		ss[len] = -2;
// 		calhz(ss, sa);
// 		calhg(ss, sa);
// 		int a = 0, b = 0, l1, l2, *cheng;
// 		long long ans = 0;
// 		for (int i = 0; i <= len; ++i) {
// 			printf("%d %d\n", i, hg[i]);
// 			if (hg[i] >= tk) {
// 				l1 = sa[i - 1], l2 = sa[i];
// 				if (l2 > ln1) cheng = &a;
// 				else cheng = &b;
// 				if (l1 > l2) swap(l1, l2);
// 				// printf("%d\t%d\t%d\n", l1, l2, hg[i]);
// 				if (l1 < ln1 && l2 > ln1 && l2 < len) {
// 					ans += (hg[i] - tk + 1) * *cheng;
// 					if (cheng == &a) b += hg[i] - tk + 1;
// 					else a += hg[i] - tk + 1;
// 					// printf("a\t%d\n", a);
// 				}
// 			}
// 			else {
// 				l1 = sa[i];
// 				a = b = 0;
// 				if (l1 > ln1) {
// 					b = 1;
// 				}
// 				else a = 1;
// 			}
// 		}
// 		printf("%lld\n", ans);
// 	}
// 	return 0;
// }


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 100005
#define LL long long
#define maxn 200005
using namespace std;
//以下为倍增算法求后缀数组
int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];
int cmp(int *r, int a, int b, int l)
{return r[a] == r[b] && r[a + l] == r[b + l];}
void da(const char *r, int *sa, int n, int m) {
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++) Ws[i] = 0;
	for (i = 0; i < n; i++) Ws[x[i] = r[i]]++;
	for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < n; i++) wv[i] = x[y[i]];
		for (i = 0; i < m; i++) Ws[i] = 0;
		for (i = 0; i < n; i++) Ws[wv[i]]++;
		for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	return;
}
int sa[maxn], Rank[maxn], height[maxn];
//求height数组
void calheight(const char *r, int *sa, int n) {
	int i, j, k = 0;
	for (i = 1; i <= n; i++) Rank[sa[i]] = i;
	for (i = 0; i < n; height[Rank[i++]] = k)
		for (k ? k-- : 0, j = sa[Rank[i] - 1]; r[i + k] == r[j + k]; k++);
	return;
}
char str[maxn], ch[maxn];
int k;
int s[maxn][2];
LL tot, top;
int main() {
	while (scanf("%d", &k) != EOF && k) {
		int l1, l2;
		scanf("%s%s", str, ch);
		l1 = strlen(str); l2 = strlen(ch);
		str[l1] = '@';
		for (int i = l1 + 1; i <= l1 + l2; i++)
			str[i] = ch[i - l1 - 1];
		int n = l1 + l2 + 1;
		str[n] = '\0';
		da(str, sa, n + 1, 130);
		calheight(str, sa, n);
		tot = top = 0;
		LL sum = 0;
		for (int i = 1; i <= n; i++) {
			if (height[i] < k) top = tot = 0;
			else {
				int cnt = 0;
				if (sa[i - 1] < l1) cnt++, tot += height[i] - k + 1;
				while (top > 0 && height[i] <= s[top - 1][0]) {
					top--;
					tot -= s[top][1] * (s[top][0] - height[i]);
					cnt += s[top][1];
				}
				s[top][0] = height[i]; s[top++][1] = cnt;
				if (sa[i] > l1) sum += tot;
			}
		}
		tot = top = 0;
		for (int i = 1; i <= n; i++) {
			if (height[i] < k) top = tot = 0;
			else {
				int cnt = 0;
				if (sa[i - 1] > l1) cnt++, tot += height[i] - k + 1;
				while (top > 0 && height[i] <= s[top - 1][0]) {
					top--;
					tot -= s[top][1] * (s[top][0] - height[i]);
					cnt += s[top][1];
				}
				s[top][0] = height[i]; s[top++][1] = cnt;
				if (sa[i] < l1) sum += tot;
			}
		}
		printf("%I64d\n", sum);
	}
	return 0;
}

//第一道用后缀数组解的题 还行 不太难 照着书上敲的 自己改了一些
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int mx = 200000;
int n, len, ss[mx + 4], rev[mx * 2 + 4], k, rr[mx * 2 + 4], sa[mx * 2 + 4];//len为计算后缀数组时排序的总字符串的长度 n为初始字符串的长度 k为排序时每个元素的长度 rr记录上一次相应位置字符的排名

void reverse(int *be, int *end, int *go) {
	for (int *p = end - 1; p != be - 1; --p) {
		go[end - p - 1] = *p;
	}
}

bool cmp(int a, int b) {
	if (k == 1) {
		return rev[a] < rev[b];
	}
	int l = k >> 1;
	if (rr[a] != rr[b]) {
		return rr[a] < rr[b];
	}
	else {
		int ra = a + l <= len? rr[a + l]: -1,
		rb = b + l <= len? rr[b + l]: -1;
		return ra < rb;
	}
}

void calhz(int *so, int *sa) {
	int rank[mx * 2 + 4];
	for (int i = 0; i <= len; ++i) {
		sa[i] = i;
		rr[i] = i < len? so[i]: -1;
	}
	for (k = 1; k <= len; k <<= 1) {
		sort(sa, sa + len + 1, cmp);
		rank[sa[0]] = 0;
		for(int i = 1; i <= len; ++i){
			rank[sa[i]] = rank[sa[i-1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for(int i = 0; i <= len; ++i){
			rr[i] = rank[i];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &ss[i]);
	}
	reverse(ss, ss + n, rev);
	len = n;
	calhz(rev, sa);
	// for(int i = 0; i < n; ++i){
	// 	printf("%d\n", rev[i]);
	// }
	// for(int i = 0; i < n; ++i){
	// 	printf("%d %d\n", i, sa[i]);
	// }
	int p1, p2;
	for(int i = 0; i <= n; ++i){
		p1 = n - sa[i];
		// printf("%d %d\n", p1, sa[i]);
		if(p1 >= 1 && p1 <= n - 2) break;
	}
	int m = n - p1;
	reverse(ss + p1, ss + n, rev);
	reverse(ss + p1, ss + n, rev + m);
	len = m << 1;
	calhz(rev, sa);
	for(int i = 0; i <= (m << 1); ++i){
		p2 = p1 + m - sa[i];
		if(p2 - p1 >=1 && p2 <= n - 1) break;
	}
	reverse(ss, ss + p1, rev);
	reverse(ss + p1, ss + p2, rev + p1);
	reverse(ss + p2, ss + n, rev + p2);
	// printf("%d %d\n", p1, p2);
	for(int i = 0; i < n; ++i){
		printf("%d\n", rev[i]);
	}
	return 0;
}

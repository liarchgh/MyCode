//http://poj.org/problem?id=2774
//判断最长公共字串 直接用高度数组做就行 顺便不出一下自己的模板
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 100000;
int len, k, rank[mx * 2 + 4], sa[mx * 2 + 4], hg[mx * 2 + 4];
char ss[mx * 2 + 3], *rev;

bool cmp(int a, int b) {//比较 a严格小于b返回true
	if (k == 1) {
		return rev[a] < rev[b];
	}
	int l = k >> 1;
	if (rank[a] != rank[b]) {
		return rank[a] < rank[b];
	}
	else {
		int ra = a + l <= len? rank[a + l]: -1,
		rb = b + l <= len? rank[b + l]: -1;
		return ra < rb;
	}
}

void calhz(char *so, int *sa) {//so是原数组 sa是排名数组 sa[i]是排第i名的串的起始地址 len为总的串的长度
	int rr[mx * 2 + 4];
	for (int i = 0; i <= len; ++i) {
		sa[i] = i;
		rank[i] = so[i];
	}
	for (k = 1; k <= len; k <<= 1) {
		sort(sa, sa + len + 1, cmp);
		rr[sa[0]] = 0;
		for(int i = 1; i <= len; ++i){
			rr[sa[i]] = rr[sa[i-1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for(int i = 0; i <= len; ++i){
			rank[i] = rr[i];
		}
		if(rank[sa[len]] >= len) return;
	}
}

void calhg(char *so, int *sa){
	for(int i = 0; i <= len; ++i){
		rank[sa[i]] = i;
	}
	int h = 0;
	hg[0] = 0;
	for(int i = 0; i < len; ++i){
		int j = sa[rank[i] - 1];
		if(h > 0) --h;
		for(;i + h <= len && j + h <= len; ++h){
			if(so[i + h] != so[j + h]) break;
		}
		hg[rank[i]] = h;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
	#endif
	rev = ss;
	gets(ss);
	int l1 = strlen(ss);
	ss[l1] = -1;
	gets(ss + l1 + 1);
	len = strlen(ss);
	// puts(ss);
	ss[len] = -2;
	int l2 = len - l1 - 1;
	calhz(ss, sa);
	calhg(ss, sa);
	int ans = 0, t1, t2;
	for(int i = 1; i <= len; ++i){
		t1 = sa[i - 1], t2 = sa[i];
		if(t1 > t2) swap(t1, t2);
		if(t1 < l1 && t2 > l1 && t2 <= len){
			// printf("%d\n", hg[i]);
			ans = max(ans, hg[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 100000;//mx为数组大小
int len, k, rank[mx + 4], sa[mx + 4], hg[mx + 4];
char ss[mx + 3], *rev;//rev为比较时的数组 ss为原数组 sa[i]为排第i名(从0开始)的串的起始位置 rank[i]为从i起始的串的排名

bool cmp(int a, int b) {//比较 a严格小于b返回true
	if (k == 1) {
		return rev[a] < rev[b];
	}
	if (rank[a] != rank[b]) {
		return rank[a] < rank[b];
	}
	else {
		int ra = a + k <= len ? rank[a + k] : -1,
		    rb = b + k <= len ? rank[b + k] : -1;
		return ra < rb;
	}
}

void calhz(char *so, int *sa) {//so是原数组 sa是排名数组 sa[i]是排第i名的串的起始地址 len为总的串的长度
	int rr[mx * 2 + 4];//rr为rank的中间过渡数组
	for (int i = 0; i <= len; ++i) {
		sa[i] = i;
		rank[i] = so[i];
	}
	rev = so;
	for (k = 1; k <= len; k <<= 1) {
		sort(sa, sa + len + 1, cmp);
		rr[sa[0]] = 0;
		for (int i = 1; i <= len; ++i) {
			rr[sa[i]] = rr[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		for (int i = 0; i <= len; ++i) {
			rank[i] = rr[i];
		}
		if (rank[sa[len]] >= len) return;
	}
}


int main() {
// #ifndef ONLINE_JDUGE
// 	freopen("D:\\in.txt", "r", stdin);
// 	freopen("D:\\out.txt", "w", stdout);
// #endif
	int k;
	gets(ss);
	len = strlen(ss);
	ss[len] = -1;
	scanf("%d", &k);
	int sta = 1, l;
	calhz(ss, sa);
	int ex[mx + 3], now = 0;
	while(1){
		if(sa[now] + ex[now] == len){
			++now;
			--k;
		}
		if(!k){
			break;
		}
	}
	// printf("%d %d\n", sa[sta], l);
	return 0;
}
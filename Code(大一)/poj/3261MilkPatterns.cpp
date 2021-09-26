//A了 WA了好大一段时间 原来是59行循环条件写错了 应该是<=len 原来是<len 没有考虑到hg[0]是ss[len]的高度
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 20000;
int len, tk, ss[mx + 3], sa[mx + 3], rank[mx + 3], k, hg[mx + 3];

bool cmphz(int a, int b){
	if(rank[a] != rank[b]) return rank[a] < rank[b];
	else{
		int la = a + k <= len ? rank[a + k] : -1,
		lb = b + k <= len ? rank[b + k] : -1;
		return la < lb;
	}
}

void calhz(int * ss){
	for(int i = 0; i <= len; ++i){
		sa[i] = i;
		rank[i] = ss[i];
	}
	int rr[mx + 3];
	for(k = 1; k <= len; k *= 2){
		sort(sa, sa + len +1, cmphz);
		rr[sa[0]] = 0;
		for(int i = 1; i <= len; ++i){
			rr[sa[i]] = rr[sa[i - 1]] + (cmphz(sa[i - 1], sa[i]) ? 1 : 0);
		}
		if(rr[sa[len]] > len) return;
		for(int i = 0; i <= len; ++i){
			rank[i] = rr[i];
		}
	}
}

void calhg(int *ss){
	int h = 0;
	hg[0] = 0;
	for(int i = 0; i <= len; ++i){
		rank[sa[i]] = i;
	}
	for(int i = 0; i < len; ++i){
		if(h > 0) --h;
		int j = sa[rank[i] - 1];
		for(; i + h < len && j + h < len; ++h){
			if(ss[i + h] != ss[j + h]) break;
		}
		hg[rank[i]] = h;
	}
}

bool jud(int x){
	int t = 1;
	for(int i = 1; i <= len; ++i){
		if(hg[i] >= x){
			++t;
		}
		else t = 1;
		if(t >= tk) return true;
	}
	return false;
}

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("D:\\in.txt", "r", stdin);
	// freopen("D:\\out.txt", "w", stdout);
	// #endif
	int n;
	scanf("%d%d", &n, &tk);
	len = n;
	for(int i = 0; i < n; ++i){
		scanf("%d", &ss[i]);
	}
	ss[n] = -1;
	// printf("%d\n", len);
	calhz(ss);
	calhg(ss);
	// for(int i = 0; i <= len; ++i){
	// 	printf("%d %d\n", i, hg[i]);
	// }
	int a = 0, b = len, mid;
	while(a < b - 1){
		mid = (a + b) >> 1;
		if(jud(mid)){
			a = mid;
		}
		else{
			b = mid - 1;
		}
	}
	if(jud(b)){
		a = b;
	}
	printf("%d\n", a);
	return 0;
}

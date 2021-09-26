//书上说是要用后缀数组加高度数组来做 我直接用DP过了一遍-_- 再试试后缀数组吧 后缀数组卡在了奇怪的地方 38行用了条件判断符 没想到要加空格 找了半个下午 优先级不够熟练啊 得时常记得加括号啊
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int mx = 10000;
char ss[mx * 2 + 3];
int rank[mx * 2 + 3], hg[mx * 2 + 3], len, lcp[mx * 2 + 3], sa[mx * 2 + 3], k;

bool cmp(int a, int b){
	// if(k == 1){
	// 	return ss[a] < ss[b];
	// }
	if(rank[a] != rank[b]) return rank[a] < rank[b];
	else{
		int la = a + k <= len ? rank[a + k] : -1,
		lb = b + k <= len ? rank[b + k] : -1;
		return la < lb;
	}
}

void calhz(char *so, int *sa, int *rank){
	for(int i = 0; i <= len; ++i){
		sa[i] = i;
		rank[i] = i >= len ? -1 : so[i];
		// printf("\t%d\n", rank[i]);
	}
	int rr[mx * 2 + 3];
	for(k = 1; k <= len; k <<= 1){
		sort(sa, sa + len + 1, cmp);
		rr[sa[0]] = 0;
		int m = 0;
		for(int i = 1; i <= len; ++i){
			rr[sa[i]] = rr[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1:0);
			m = max(m, rr[sa[i]]);
		}
		for(int i = 0; i <= len; ++i){
			rank[i] = rr[i];
		}
		if(m >= len) break;
	}
}

void calhg(int &ans, int l1, int l2){
	for(int i = 0; i < len; ++i){
		rank[sa[i]] = i;
	}
	int h = 0;
	lcp[0] = 0;
	for(int i = 0; i < len; ++i){
		if(rank[i] - 1 < 0) continue;
		int j = sa[rank[i] - 1];
		if(h > 0) --h;
		for(; h + j < len && i + h < len; ++h){
			if(ss[h + j] != ss[i + h]) break;
		}
		lcp[i] = h;
		// printf("%d\n", h);
		int a = i, b =j;
		if(a > b){
			swap(a, b);
		}
		if(a < l1 && b > l1){
			ans = max(ans, h);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(ss);
		int l1 = strlen(ss);
		ss[l1] = ' ' - 1;
		gets(ss + l1 + 1);
		//puts(ss);
		int ln = strlen(ss), l2 = ln - l1 - 1;
		len = ln;
		calhz(ss, sa, rank);
		int ans = 0;
		// for(int i = 0; i < len; ++i){
		// 	printf("%d %d %d\n", i, sa[i], sa[i] - l1 - 1);
		// }
		calhg(ans, l1, l2);
		printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
		// for(int i = 0; i < len; ++i){
		// 	printf("%d\n", lcp[i]);
		// }
	}
	return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 10000;
char s1[mx + 3], s2[mx + 3];
int dp[mx + 3];

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("D:\\in.txt", "r", stdin);
	// freopen("D:\\out.txt", "w", stdout);
	// #endif
	int t, ans;
	scanf("%d", &t);getchar();
	while(t--){
		memset(dp, 0, sizeof(dp));
		ans = 0;
		gets(s1);
		gets(s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		for(int i = 0; i < l1; ++i){
			for(int j = l2 - 1; j >= 0; --j){
				if(s1[i] == s2[j]){
					dp[j] = max(dp[j], dp[j - 1] + 1);
				}
				else{
					dp[j] = 0;
				}
				ans = max(ans, dp[j]);
			}
		}
		printf("Nejdelsi spolecny retezec ma delku %d.\n", ans);
	}
	return 0;
}
*/

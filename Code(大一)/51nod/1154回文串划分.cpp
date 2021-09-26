#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

const int mx = 5005;
char ss[mx], is_hui[mx][mx] = {0};
int len, dp[mx];

void dfs(int l, int r){
	if(ss[l] == ss[r]){
		// printf("%d %d\n", l, r);
		is_hui[l][r] = 1;
		if(l && r < len)
			dfs(l-1, r+1);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
	#endif
	memset(dp, 0x7f, sizeof(dp));
	gets(ss);
	len = strlen(ss);
	for(int i = 0; i < len; ++i){
		dfs(i,i);
		dfs(i, i+1);
	}
	for(int i = 0; i < len; ++i){
		for(int j = 0; j <= i; ++j){
			if(is_hui[j][i]){
				if(j)
					dp[i] = min(dp[i], dp[j-1] + 1);
				else dp[i] = 1;
			}
		}
		// printf("%d %d\n", i, dp[i]);
	}
	printf("%d\n", dp[len-1]);
	return 0;
}

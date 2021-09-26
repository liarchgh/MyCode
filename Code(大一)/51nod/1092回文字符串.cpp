//easy
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

const int mx = 1004;
int dp[mx][mx];
char ss[mx];

int cha(int l, int r){
	if(l >= r){
		return 0;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	int &ans = dp[l][r];
	ans = 0xfffffff;
	if(ss[l] == ss[r]) ans = min(ans, cha(l+1, r-1));
	ans = min(ans, cha(l, r-1) + 1);
	ans = min(ans, cha(l+1, r) + 1);
	//printf("\t%d %d %d\n", l, r, ans);
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	gets(ss);
	int len = strlen(ss);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cha(0, len-1));
	return 0;
}

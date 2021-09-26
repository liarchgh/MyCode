#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int mx = 105;
int n, num[mx], dp[mx][mx], sum[mx][mx] = {0};

int cha(int l, int r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l >= r){
		dp[l][r] = 0;
		return 0;
	}
	int x = 0xfffffff;
	for(int i = l; i < r; ++i){
		x = min(x, cha(l, i) + cha(i + 1, r));
	}
	sum[l][r] = sum[l][l] + sum[l + 1][r];
	x += sum[l][r];
	dp[l][r] = x;
	//printf("%d %d %d\n", l, r, x);
	return x;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
		dp[i][i] = 0;
		sum[i][i] = num[i];
	}
	printf("%d\n",cha(0, n-1));
	return 0;
}

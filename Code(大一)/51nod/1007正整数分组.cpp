#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int mx = 10005;
int dp[mx] = {1}, num[105];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	int n, a, ans, sum = 0;;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
		sum += num[i];
	}
	ans = sum;
	for(int i = 0; i < n; ++i){
		for(int j = mx - 1; j >= 0; --j){
			if(dp[j]){
				dp[j + num[i]] = 1;
				ans = min(ans, abs(sum - (j + num[i]) * 2));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

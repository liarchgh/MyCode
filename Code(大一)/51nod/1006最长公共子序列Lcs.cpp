#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int mx = 1005, inf = 0xfffffff;
string s1, s2, ans = "";
int dp[mx][mx] = {0};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		freopen("D:\\out.txt", "w", stdout);
	#endif
	cin >> s1 >> s2;
	int len1 = s1.size(), len2 = s2.size();
	for(int i = 0; i < len1; ++i){
		for(int j = 0; j < len2; ++j){
			int &d = dp[i][j];
			if(i != 0 ){
				d = max(d, dp[i-1][j]);
			}
			if(j != 0){
				d = max(d, dp[i][j-1]);
			}
			if(s1[i] == s2[j]){
				if(i == 0 || j == 0){
					d = 1;
				}
				else d = max(d, dp[i-1][j-1] + 1);
			}
			//printf("%d %d %d\n", i, j, d);
		}
	}
	for(int i = len1-1,j = len2-1; i >= 0 && j >= 0 && dp[i][j]; ){
		//printf("%d %d\n", i, j);
		getchar();
		if(s1[i] == s2[j] && (dp[i][j] == 1 || dp[i][j] == dp[i-1][j-1]+1)){
			ans = s1[i] + ans;
			--i;--j;
			continue;
		}
		if(i!=0 && dp[i-1][j] == dp[i][j]){
			--i;
			continue;
		}
		if(j!=0 && dp[i][j-1] == dp[i][j]){
			--j;
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}

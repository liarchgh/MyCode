//GOD 在小地方卡了半个多小时 就是dp[0][i] && s1[0] == s2[i]的情况 其实很简单 直接等于i-1就行了
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int mx = 1005, inf = 0xfffffff;
int dis[1001][1001];
string s1, s2;
int dp[mx][mx];

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	cin >> s1 >> s2;
	int len1 = s1.length(), len2 = s2.length();
	for (int i = 0; i <= len1; ++i) {
		for (int j = 0; j <= len2; ++j) {
			dp[i][j] = inf;
		}
	}
	for (int i = 0; i < len1; ++i) {
		for (int j = 0; j < len2; ++j) {
			if (!(i + j)) {
				if (s1[0] == s2[0]) {
					dp[0][0] = 0;
				}
				else dp[0][0] = 1;
			}
			if (i) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
			else if(s1[i] == s2[j]) dp[i][j] = j;
			if (j) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
			else if(s1[i] == s2[j]) dp[i][j] = i;
			if (i && j) {
				if(s1[i] == s2[j])
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
				else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			}
			//printf("%d %d %d\n", i, j, dp[i][j]);
		}
	}
	printf("%d\n", dp[len1 - 1][len2 - 1]);
	//getchar();
	//getchar();
	return 0;
	// string a, b;
 //    cin >> a >> b;
 //    int la = a.length(), lb = b.length();
 //    for(int i = 0; i <= la; ++i) dis[0][i] = i;
 //    for(int i = 0; i <= lb; ++i) dis[i][0] = i;
 //    for(int i = 1; i <= la; ++i) {
 //        for(int j = 1; j <= lb; ++j) {
 //            if(a[i-1] == b[j-1]) {
 //                dis[i][j] = dis[i-1][j-1];
 //            } else {
 //                dis[i][j] = min(min(dis[i-1][j], dis[i][j-1]), dis[i-1][j-1]) + 1;
 //            }
 //            printf("%d %d %d\n", i-1, j-1, dis[i][j]);
 //        }
 //    }
 //    printf("%d\n", dis[la][lb]);
    return 0;
}

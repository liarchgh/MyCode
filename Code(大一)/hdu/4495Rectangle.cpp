#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 500, wei = 123;
unsigned long long i_hash[mx + 3][mx + 3][2], chengfang[mx + 3] = {1};
int ans, tong[mx + 3][mx + 3], dp[mx + 3][mx + 3], danceng[mx + 3][mx + 3];
char ss[mx + 3][mx + 3];

void zhuan(int & a, int & b){
	char s1[a + 1][b + 1];
	for(int i = 1; i <= a; ++i){
		for(int j = 1; j <= b; ++j){
			s1[i][j] = ss[i][j];
		}
	}
	for(int i = 1; i <= a; ++i){
		for(int j = 1; j <= b; ++j){
			ss[b - j + 1][i] = s1[i][j];
		}
	}
	swap(a, b);
}

bool jud(int i, int j, int mid){
	return i_hash[i][j][1] - i_hash[i - mid][j][1] * chengfang[mid] == i_hash[i][j][0] - i_hash[i][j - mid][0] * chengfang[mid];
}

void sol(int &h, int &l){
	memset(i_hash, 0, sizeof(i_hash));
	memset(dp, 0, sizeof(dp));
	memset(danceng, 0, sizeof(danceng));
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= l; ++j){
			i_hash[i][j][0] = i_hash[i][j - 1][0] * wei + ss[i][j];
			i_hash[i][j][1] = i_hash[i - 1][j][1] * wei + ss[i][j];
		}
	}
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= l; ++j){
			int mil = 0, mal = min(i, j), mid;
			while(mil < mal){
				mid = (mil + mal) / 2;
				if(jud(i, j, mid)){
					mil = mid + 1;
				}
				else{
					mal = mid;
				}
			}
			if(jud(i, j, mil)) ++mil;
			danceng[i][j] = mil - 1;
		}
	}
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <=l; ++j){
			dp[i][j] = min(dp[i - 1][j - 1] + 2, danceng[i][j]);
			ans = max(dp[i][j], ans);
			// printf("%d %d %d %llu %llu %c\n", i, j, danceng[i][j], i_hash[i][j][0], i_hash[i][j][1], ss[i][j]);
			// putchar(ss[i][j]);
		}
		// putchar('\n');
	}
		// putchar('\n');
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
	freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
	#endif
			// printf("%d\n", mx);
	for(int i = 1; i <= mx; ++i){
		chengfang[i] = chengfang[i - 1] * wei;
	}
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d%d", &n, &m);
		getchar();
		for(int i = 1; i <= n; ++i){
			scanf("%s", ss[i] + 1);
		}
		for(int i = 0; i < 4; ++i){
			sol(n, m);
			zhuan(n, m);
		}
		printf("%d\n", (1 + ans) * ans / 2);
	}
	return 0;
}

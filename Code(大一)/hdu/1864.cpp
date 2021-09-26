//http://acm.hust.edu.cn/vjudge/contest/126446#problem/P

#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 33;
int n, m, keyong, q;
int co[mx];
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	double q1;
	while (scanf("%lf%d", &q1, &n), n) {
		//printf("        11111\n");
		q = q1 * 100;
		keyong = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &m);
			double co1 = 0;
			int p = 0;
			for (int j = 0; j < m; ++j) {
				getchar();
				double a;
				switch (getchar()) {
				case 'A':
				case 'B':
				case 'C': getchar();
					scanf("%lf", &a);
					co1 += a;
					break;
				default : getchar(); scanf("%lf", &a); p = 1;
				}
			}
			if (!p) {
				co[keyong++] = co1 * 100;
			}
			//printf("\t%d\n", n);
		}
		int dp[q+1] = {0};//dp[j] 表示前i张可用的发票 最大限度j时的最大报销金额
		for(int i = 0; i < keyong; ++i){
			for(int j = q; j >= co[i]; --j){
				dp[j] = max(dp[j], dp[j-co[i]] + co[i]);
			}
		}
		double ans = (double)dp[q]/100;
		printf("%.2lf\n", ans);
	}
	return 0;
}

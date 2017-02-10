//大水题 敲一遍就过了 连Debug都没有
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	freopen("D://in.txt", "r", stdin);
	freopen("D://out.txt", "w", stdout);
	int n, x;
	while(scanf("%d", &n) != EOF){
		int ans = 0;
		while(n--){
			scanf("%d", &x);
			ans += x & 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

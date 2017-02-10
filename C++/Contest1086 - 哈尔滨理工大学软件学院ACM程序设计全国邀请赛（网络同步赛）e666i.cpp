//一开始没有考虑存在相同数字的情况 想当然地认为不会有 WA了两次
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 100000 + 5;
int se[mx];

int main(){
	freopen("D://in.txt", "r", stdin);
	freopen("D://out.txt", "w", stdout);
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF){
		int ans = 0;
		for(int i = 0; i < n; ++i) scanf("%d", &se[i]);
		sort(se, se + n);
		for(int i = 0; i < n; ++i){
			int * ax = lower_bound(se, se + n, se[i] + k);
			while(ax != se + n && se[i] + k == *ax) {++ans;++ax;}
		}
		printf("%d\n", ans);
	}
	return 0;
}

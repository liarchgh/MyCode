//自己独立做出来的 挺高兴的 51的4级算法题了 总的来说思路挺流畅的 不过最后卡了一会儿 是在23行的 + mod 上 没注意到可能为负值 不过还是靠自己找出来了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int mod = 1000000007, mx = 100005;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	int n, a, vis[mx] = {0}, rem[mx] = {0};
	long long ans = 0, befa = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a);
		if(vis[a]){
			ans = ans * 2 - rem[a] + mod;
		}
		else{
			ans = ans * 2 + 1;
		}
		ans %= mod;
		vis[a] = 1;
		rem[a] = befa;
		befa = ans;
	//printf("%d %d %d\n", i, a, ans);
	}
	printf("%lld\n", ans);
	return 0;
}

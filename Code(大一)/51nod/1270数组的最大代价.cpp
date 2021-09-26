//最近ONLINE_JUDGE经常写错 已经两次了 得细心点了
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	int n, a, ans[2] = {0}, bef, b;
	scanf("%d%d", &n, &bef);
	--bef;
	for(int i = 1; i < n; ++i){
		scanf("%d", &a);
		--a;
		b = ans[1];
		ans[1] = max(ans[0] + a, ans[1] + abs(a - bef));
		ans[0] = max(ans[0], b + bef);
		bef = a;
	//printf("\t%d %d\n", ans[0], ans[1]);
	}
	printf("%d\n", max(ans[0], ans[1]));
	return 0;
}

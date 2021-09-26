#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int mx = 400005;
int so[mx], n, mark[mx], sum[mx] = {0};
vector<int>li[mx];

void chu(int x, int fa){
	int a = 0, su = 0;
	for(vector<int>::iterator it = li[x].begin(); it != li[x].end(); ++it){
		if(*it == fa) continue;
		chu(*it, x);
		a = max(a, sum[*it]);
		sum[x] += sum[*it];
	}
	++sum[x];
	// printf("%d %d\n", x, a);
	if(a * 2 <= n+1 && (n-sum[x]) * 2 <= n+1){
		mark[x] = 1;
	}
	else mark[x] = 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		freopen("D:\\out.txt", "w", stdout);
	#endif
	int a, b;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &a, &b);
		--a;--b;
		li[a].push_back(b);
		li[b].push_back(a);
	}
	chu(0, 0);
	// for(int i = 0; i < n; ++i)
	// 	printf("%d %d\n", i, li[i].size());
	for(int i = 0; i < n; ++i){
		printf("%d", mark[i]);
		if(i == n-1) putchar('\n');
		else putchar(' ');
	}
	return 0;
}

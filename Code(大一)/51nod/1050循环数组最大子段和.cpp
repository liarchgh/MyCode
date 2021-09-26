//感觉不错 自己想出来的 看了网上的思路 是一样的 有点进步了
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mx = 50005;
int ss[mx];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &ss[i]);
		sum += ss[i];
	}
	long long a = 0, b = 0, anx = 0, ann = 0xfffffffffffffff;
	for(int i = 0; i < n; ++i){
		if(a < 0){
			a = ss[i];
		}
		else a += ss[i];
		if(b > 0){
			b = ss[i];
		}
		else b += ss[i];
		anx = max(a, anx);
		ann = min(b, ann);
	}
	printf("%lld\n", max(anx, sum - ann));
	return 0;
}

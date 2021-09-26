
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mx = 2003;
const long long mod = 1000000007;
long long num, types[25][mx] = {1};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
	#endif
	scanf("%lld", &num);
	types[1][1] = 1;
	for(int i = 2; i < 25; ++i){
		for(int j = 1; j <= num; ++j){
			for(int k = 0; k < j; ++k){
				types[i][j] += types[i-1][k] * types[i-1][j-k-1];
				if(i > 1){
					types[i][j] += (types[i-1][k] * types[i-2][j-k-1]) * 2;
				}
				types[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < 25; ++i){
		ans = (ans + types[i][num]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

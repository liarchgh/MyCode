#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
const long long mod = 1000000007;

long long suan(long long lit, long long x){
	if(x < 0) return 0;
	if(x == lit) return 1;
	long long re = 0;
	for(long long i = lit; i <= x/2; ++i){
		re += suan(i, x-i);
		re %= mod;
	}
	++re;
	re %= mod;
	//printf("%lld %lld %lld\n", lit, x, re);
	return re;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
	#endif
	long long num;
	scanf("%lld", &num);
	printf("%lld\n", suan(1, num));
	return 0;
}

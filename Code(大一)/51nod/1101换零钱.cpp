#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int mx = 100005, mod = 1000000007;
int mon[mx] = {1}, jia[13] = {1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 13; ++i){
		for(int j = 0; j < n; ++j){
			if(mon[j] && j+jia[i] <= n){
				mon[j+jia[i]] += mon[j];
				mon[j+jia[i]] %= mod;
			}
		}
	}
	printf("%d\n", mon[n]);
	return 0;
}

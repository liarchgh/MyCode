#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

const long long mod = 1000000007;
int n, m, k;

long long chu(){
	long long ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		if(n < m * k + m){
			printf("0\n");
		}
		else{
			printf("%lld\n",chu());
		}
	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 100000;
char ss[mx + 3];
long long int q[mx + 3];

int main(){
	int t;
	for(int i = 1; i <= mx; ++i){
		q[i] = q[i - 1] + i;
		// if(i >= mx - 100) printf("%d\n", q[i]);
	}
	scanf("%d", &t);getchar();
	while(t--){
		gets(ss);
		int len = strlen(ss), tn = 0;
		long long ans = 0;
		for(int i = 0; i < len; ++i){
			if(ss[i] == 'q'){
				++tn;
			}
			else if(tn){
				ans += q[tn];
				tn = 0;
			}
		}
		if(tn) ans += q[tn];
		printf("%I64d\n", ans);
	}
	return 0;
}

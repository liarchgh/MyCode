#include <cstdio>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

const long long inf = 1000000000;
int ans[810005];

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("D:\\in.txt", "r", stdin);
	// freopen("D:\\out.txt", "w", stdout);
	// #endif
	long long int t;
	int r = 0;
	for(int i = 0; i <= 30; ++i){
		for(int j = 0; j < 20; ++j){
			for(int k = 0; k < 14; ++k){
				for(int l = 0; l < 12; ++l){
					long long c;
					t = pow(7, l) * pow(5, k) * pow(3, j) * pow(2, i);
					if(t > inf) continue;
					//printf("%d %d %d %d %d \n", i, j, k, l, t);
					ans[r++] = t;
					//printf("%d\n" ,t);
					//cout << r << endl;
				}
			}
		}
	}
	int a;
	sort(ans, ans + r);
	//cout << r << endl;
	//printf("%d\n", r);
	// for(int i = 0; i < r; ++ i) printf("%d\n", ans[i]);
	cin >> t;
	//printf("%lld\n", t);
	while(t--){
		scanf("%d", &a);
		printf("%d\n", *lower_bound(&ans[1], ans + r, a));
	}
	return 0;
}

#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int arr[50005], dp[50005];
vector<int>mx;

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if(mx.empty() || a > mx[mx.size()-1]){
			mx.push_back(a);
		//printf("%d\n", i);
		}
		else if(a < mx[mx.size()-1]){
			vector<int>::iterator x = upper_bound(mx.begin(), mx.end(), a);
			*x = a;
		}
	}
	printf("%d\n", mx.size());
	// printf("%d\n",LIS(arr,sizeof(arr)/sizeof(int)));
	return 0;
}

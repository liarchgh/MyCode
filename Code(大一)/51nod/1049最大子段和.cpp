#include <cstdio>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		freopen("D:\\out.txt", "w", stdout);
	#endif
	long long int n, ss[50005], sum[50005], ans = 0;
	scanf("%I64d", &n);
	for(long long int i = 0; i < n; ++i){
		scanf("%I64d", &ss[i]);
		sum[i] = ss[i];
		if(i && sum[i-1] > 0){
			sum[i] += sum[i-1];
		}
		ans = max(ans, sum[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}

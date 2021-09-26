#include <cstdio>
#include <algorithm>

using namespace std;

const int mx = 100002, mod = 10007;
int a[mx];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans = (ans + (long long)a[i] * a[n - 1 -i]) % mod;
		// /printf("%I64d\n", ans);
	}
	printf("%I64d\n", ans);
	return 0;
}

#include <cstdio>
#include <cstring>

using namespace std;

const int mx = 200000 + 4;
char ss[mx];
long long ssn[mx] = {0};

int main(){
	// freopen("D://out.txt", "w", stdout);
	int t, n;
	for(int i = 1; i <= mx; ++i){
		ssn[i] = ssn[i - 1] + i;
		// printf("%lld\n", ssn[i]);
	}
	scanf("%d", &t);
	while(t--){
		long long ans = 0;
		scanf("%d\n", &n);
		gets(ss);
		int num = 0;
		for(int i = 0; ss[i] != '\0'; ++i){
			char c = ss[i];
			if(c == '6'){
				++num;
			}
			else{
				if(num){
					ans += ssn[num];
					num = 0;
				}
			}
		}
		if(num) ans += ssn[num];
		printf("%lld\n", ans);
	}
	return 0;
}

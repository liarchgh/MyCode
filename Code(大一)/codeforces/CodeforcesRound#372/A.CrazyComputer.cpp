#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
	int n, c, be, a, ans = 1;
	scanf("%d%d%d", &n, &c, &be);
	for(int i = 1; i < n; ++i){
		scanf("%d",&a);
		if(a - be <= c){
			++ans;
			be = a;
		}
		else{
			be = a;
			ans = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

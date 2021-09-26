//感觉东北赛好水啊
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    // #ifndef ONLINE_JDUGE
    // freopen("D:\\in.txt", "r", stdin);
    // freopen("D:\\out.txt", "w", stdout);
    // #endif
    long long int t, a, b;
    scanf("%lld", &t);
    for(long long int th = 1; th <= t; ++th){
    	printf("Case #%d:\n", th);
    	scanf("%lld%lld", &a, &b);
    	if(a > b){
    		swap(a, b);
    	}
    	if(a == b){
    		printf("1\n%lld %lld\n", a, b);
    	}
    	else{
    		printf("2\n%lld %lld\n%lld %lld\n", a, b, b, a);
    	}
    }
    return 0;
}
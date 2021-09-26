#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    #ifndef ONLINE_JDUGE
    freopen("D:\\in.txt", "r", stdin);
    freopen("D:\\out.txt", "w", stdout);
    #endif
    int ans[25]={0}, a = 0, b = 0;
    for(int i = 1; i < 22; ++i){
    	if(i < a + b){
    		ans[i] = ans[i-1] + 1;
    	}
    	else{
    		b = a;
    		a = i;
    		ans[i] = ans[i-1];
    		// cout << i << " " << ans[i] << endl;
    	}
    }
    int n, t;
    scanf("%d" ,&t);
    for(int i = 1; i <= t; ++i){
    	scanf("%d", &n);
    	printf("Case #%d: %d\n", i, ans[n]);
    }
    return 0;
}
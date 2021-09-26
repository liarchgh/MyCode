//http://bestcoder.hdu.edu.cn/contests/contest_chineseproblem.php?cid=727&pid=1002
//直接暴力过 还错了3 4次
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 100000;
int ss[mx + 3], len, ts[mx + 3];

bool pan(int *a, int *b, int l){
	for(int i = 0; i < l; ++i){
		if(*(a + i) != *(b + i)) return false;
	}
	return true;
}

bool jud(int x){
	for(int i = 0; i < len; ++i){
		ts[i] = ss[i];
	}
	int num = len / x;
	for(int i = 0; i < num; ++i){
		sort(ts + i * x, ts + (i + 1) * x);
		if(i > 0){
			if(!pan(ts + (i - 1) * x, ts + i * x, x)){
				// printf("%d %d\n", x, i);
				return false;
			}
		}
	}
	return true;
}

void sol(){
	for(int t = 1; t < len; ++t){
		if(!(len % t) && jud(t))
		{printf("%d ", t);}
	}
	printf("%d\n", len);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &len);
		for(int i = 0; i < len; ++i){
			scanf("%d", &ss[i]);
		}
		sol();
	}
	return 0;
}

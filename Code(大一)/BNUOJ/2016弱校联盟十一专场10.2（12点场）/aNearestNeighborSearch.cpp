#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

int p[3], c[2][3], pan[3];

void so2(){
	int x;
	for(x = 0; x < 3; ++x){
		if(!pan[x]) break;
	}
	long long l = min(abs(p[x] - c[0][x]), abs(p[x] - c[1][x]));
	printf("%lld\n", l * l);
}

void so1(){
	int x1 = -1, x2;
	for(int i = 0; i < 3; ++i){
		if(!pan[i]){
			if(x1 == -1) x1 = i;
			else x2 = i;
		}
	}
	long long int l1 = min(abs(p[x1] - c[0][x1]), abs(p[x1] - c[1][x1])), l2 = min(abs(p[x2] - c[0][x2]), abs(p[x2] - c[1][x2]));
	printf("%lld\n", l1 * l1 + l2 * l2);
}

void so0(){
	long long int l[3];
	for(int i = 0; i < 3; ++i)
		l[i] = min(abs(p[i] - c[0][i]), abs(p[i] - c[1][i]));
	printf("%lld\n", l[0] * l[0] + l[1] * l[1] + l[2] * l[2]);
}

int main() {
#ifndef ONLINE_JDUGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	// printf("0\n");
	for (int i = 0; i < 3; ++i) {
		scanf("%d", &p[i]);
	}
	int n = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &c[i][j]);
			if (i > 0) {
				if (c[0][j] > c[1][j]) {
					swap(c[0][j], c[1][j]);
				}
				if(p[j] >= c[0][j] && p[j] <= c[1][j]){
					++n;
					pan[j] = 1;
				}
				else{
					pan[j] = 0;
				}
			}
		}
	}
	switch(n){
		case 3:printf("0\n");return 0;
		case 2:so2();return 0;
		case 1:so1();return 0;
		case 0:so0();return 0;
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

const int mx = 33;
int siz, mat[2][mx][mx], ans, t;

int main() {
	// #ifndef ONLINE_JUDGE
	// freopen("C:\\in.txt", "r", stdin);
	// freopen("C:\\out.txt", "w", stdout);
	// #endif
	while (scanf("%d", &siz), siz) {
		ans = t = 0;
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < siz; ++i) {
				for (int j = 0; j < siz; ++j) {
					scanf("%d", &mat[k][i][j]);
					if(k && mat[1][i][j] == mat[0][i][j]) ++ans;
				}
			}
		}
		t = max(t, ans);
		ans = 0;
		// for(int i = 0; i < 2; ++i){
		// 	for(int j = 0; j < siz; ++j){
		// 		for(int k = 0; k < siz; ++k){
		// 			printf("%d\t", mat[i][j][k]);
		// 		}
		// 		putchar('\n');
		// 	}
		// 	putchar('\n');
		// }
		for(int i = 0; i < siz; ++i){
			for(int j = 0; j < siz; ++j){
				int x = siz - j - 1, y = i;
				if(mat[0][i][j] == mat[1][x][y]) ++ans;
			}
		}
		t = max(t, ans);
		ans = 0;
		for(int i = 0; i < siz; ++i){
			for(int j = 0; j < siz; ++j){
				int x = siz - i - 1, y = siz - j - 1;
				if(mat[0][i][j] == mat[1][x][y]) ++ans;
			}
		}
		t = max(t, ans);
		ans = 0;
		for(int i = 0; i < siz; ++i){
			for(int j = 0; j < siz; ++j){
				int x = j, y = siz - i - 1;
				if(mat[0][i][j] == mat[1][x][y]) ++ans;
			}
		}
		t = max(t, ans);
		ans = 0;
		// if(siz == 1 && ans) printf("1\n");
		// else 
			printf("%d\n", t);
	}
	return 0;
}

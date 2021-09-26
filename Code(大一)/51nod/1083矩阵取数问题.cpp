#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int mx = 505;
int mat[mx][mx];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &mat[i][j]);
			if (i + j == 0) continue;
			if (i == 0) {
				mat[i][j] += mat[i][j - 1];
			}
			else if (j == 0) mat[i][j] += mat[i - 1][j];
			else mat[i][j] += max(mat[i - 1][j], mat[i][j - 1]);
		}
	}
	printf("%d\n", mat[n-1][n-1]);
	return 0;
}

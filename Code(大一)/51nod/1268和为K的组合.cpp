#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[22], n, k;

bool jia(int w) {
	int sum = 0;
	for (int i = 0; w; ++i) {
		if (w & 1) {
			sum += a[i];
			if (sum == k) {
				return true;
			}
		}
		w >>= 1;
	}
	if (sum == k) {
		return true;
	}
	return false;
}

int main() {
// #ifndef ONLIN_JUDGE
// 	freopen("D:\\in.txt", "r", stdin);
// 	freopen("D:\\out.txt", "w", stdout);
// #endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < (1 << n); ++i) {
			//printf("%d\n", i);
		if (jia(i)) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}

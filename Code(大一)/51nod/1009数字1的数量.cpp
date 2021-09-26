//这题的细节 真是TMD地做够了 调了好久T^T
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("C:\\in.txt", "r", stdin);
	freopen("C:\\out.txt", "w", stdout);
#endif
	int n, b, ans = 0, a = 1, before = -1;
	scanf("%d", &n);
	int qian = n / 10;
	b = n % 10;
	if (b >= 1) {
		ans += qian + 1;
	}
	else {
		ans += qian;
	}
	n /= 10;
	while (n) {
		qian /= 10;
		a *= 10;
		if(before == -1) before = b;
		else {before = before + b * a / 10;//printf("       %d %d\n",before, b);
	}
		b = n % 10;
		n /= 10;
		//printf("%d %d %d\n", a, b, ans);
		if (qian)
			{ans += qian * a;
			}
		//printf("%d %d %d\n", before, b, ans);
			//printf("%d\n", ans);
		if (1 == b) {
			ans += before + 1;
			//printf("%d %d\n", before, ans);
		}
		else {
			if (b) {
				ans += a;
			}
		}
		//printf("%d %d %d\n", a, b, ans);
	}
	printf("%d\n", ans);
	return 0;
}

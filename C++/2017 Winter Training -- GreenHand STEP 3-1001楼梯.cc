#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 100005;
int ans[mx] = {0, 1, 1};

void fin() {
	for (int i = 3; i < mx; ++i) {
		ans[i] = (ans[i - 1] + ans[i - 3]) % 10007;
	}
}

int main() {
	int n;
	fin();
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", ans[n]);
	}
	return 0;
}
/*
楼梯
TimeLimit: 1 Second   MemoryLimit: 32 Megabyte
Totalsubmit: 35   Accepted: 10
Description

21B有N级台阶，你非常不喜欢2这个数字，所以你一次可以登上一级台阶或三级台阶。
你现在来到第一级台阶上，走到第N级台阶共有多少种走法？
Input

输入包含多组数据。（不超过50组）
每组数据包含一个正整数N(1<=N<=10^5)，代表21B台阶的级数。
Output

你走到第N级台阶的走法数。由于结果可能很大，请将结果对10007取模。

Sample Input

1
2
20270
Sample Output

1
1
3108
Source

yuiouiop
*/
//才开始感觉蛮难的 后来用了结构体 写的代码、考虑的数组少了些 感觉还可以 不过后来忘记考虑多组输入了 WA了几次
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int mx = 504;

struct no {
	vector<int>next;
	int in;
}node[mx];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("D://in.txt", "r", stdin); freopen("D://out.txt", "w", stdout);
#endif
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i <= n; ++i) {node[i].next.clear();node[i].in = 0;}
		for (int a, b; m--;) {
			scanf("%d%d", &a, &b);
			++node[b].in;
			node[a].next.push_back(b);
		}
		int num = 0;
		while (1) {
			for (int i = 1; i <= n; ++i) {
				if (!node[i].in) {
					printf("%d", i);
					--node[i].in;
					for (int j = 0; j < node[i].next.size(); ++j) {
						--node[node[i].next[j]].in;
					}
					if (++num < n) {
						putchar(' ');
					}
					else {
						putchar('\n');
					}
					break;
				}
			}
			if (num >= n) break;
		}
	}
	// getchar();getchar();
	return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <cstdlib>
// #include <cstdio>
// #include <string>
// #include <cstring>
// #include <ctime>
// #include <iomanip>
// #include <cmath>
// #include <set>
// #include <stack>

// using namespace std;

// struct typeNode {
// 	int in;
// 	vector<int> from;
// 	vector<int> to;
// } node[505];

// vector<int> req;
// vector<int> res;
// int main() {
// 	int n = 0, m = 0;
// 	while (cin >> n >> m) {
// 		req.clear();
// 		res.clear();
// 		for (int i = 1; i <= n; i++) {
// 			node[i].to.clear();
// 			node[i].from.clear();
// 			node[i].in = 0;
// 		}
// 		for (int i = 1; i <= m; i++) {
// 			int a = 0, b = 0;
// 			cin >> b >> a;
// 			node[b].to.push_back(a);
// 			node[a].from.push_back(b);
// 			node[a].in++;
// 		}
// 		bool flag = true;
// 		while (flag) {
// 			flag = false;
// 			for (int i = 1; i <= n; i++) {
// 				if (node[i].in == 0) {
// 					res.push_back(i);
// 					node[i].in--;
// 					flag = true;
// 					for (int j = 0; j < node[i].to.size(); j++) {
// 						node[node[i].to[j]].in--;
// 					}
// 					break;
// 				}
// 			}
// 		}
// 		for (int i = 0; i < res.size(); i++) {
// 			cout << res[i];
// 			if (i != res.size() - 1) {
// 				cout << " ";
// 			}
// 		}
// 		cout << endl;
// 	}
// 	return 0;
// }
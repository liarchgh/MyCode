#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int mx_ch = 20, mx_dic = 10005;
char dic[mx_dic][mx_ch], ss[mx_ch];
int num_dic;

int solve(char * a, char * b, int tim) {
	if (tim > 1) return -1;
	if (*a == '\0' && *b == '\0') {
		if (!tim) return 1;
		else return 0;
	}
	if (*a == '\0' || *b == '\0') return -1;
	if (*a == *b) return solve(a + 1, b + 1, tim);
	return max(max(solve(a + 1, b, tim + 1), solve(a, b + 1, tim + 1)), solve(a + 1, b + 1, tim + 1));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D://in.ls", "r", stdin);
	freopen("D://out.ls", "w", stdout);
#endif
	for (num_dic = 0; gets(ss), ss[0] != '#'; ++num_dic) {
		strcpy(dic[num_dic], ss);
	}
	while (gets(ss), ss[0] != '#') {
		vector<int>ans;
		int a = 555;
		for (int i = 0; i < num_dic; ++i) {
			a = solve(dic[i], ss, 0);
			if (a > 0) {
				printf("%s is correct", ss);
				break;
			}
			else if (!a) {
				ans.push_back(i);
			}
		}
		if (a != 1) {
			printf("%s:");
			if (!a) {
				// printf("+++++%d\n", ans.size());
				for (int i = 0; i < ans.size(); ++i) {
					printf(" %s", dic[ans[i]]);
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
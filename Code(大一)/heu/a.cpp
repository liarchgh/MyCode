#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;

string name[10005];
map<string, int>m;
bool cmp(string a, string b) {
	if (m[a] < m[b]) return true;
	if (m[a] > m[b]) return false;
	return a < b;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	int t, n, k;
	scanf("%d", &t);
	//while (scanf("%d", &t) != EOF) {
		while (t--) {
			m.clear();
			scanf("%d%d", &n, &k);
			for (int i = 0; i < n; ++i) {
				cin >> name[i];
				m[name[i]]++;
			}
			int longest = 0, a = 0;;
			for (int i = 0; i < n; ++i) {
				if (m[name[i]] >= k) ++a;
				else a = 0;
				longest = max(longest, a);
			}
			sort(name, name + n, cmp);
			int pe = 0;
			for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
				if (it->second >= k) ++pe;
			}
			printf("%d %d\n", longest, pe);
			for (int i = 0; i < n; ++i) {
				if (m[name[i]] >= k) {
					cout << name[i] << " " << m[name[i]] << endl;
					m[name[i]] = -1;
				}
			}
		}
	//}
	return 0;
}
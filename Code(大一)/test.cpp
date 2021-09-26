#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int mx = 30, inf = 0x7fffffff;
struct cost {
	int l, r, val;
	bool operator== (cost b) {
		if (l == b.l && r == b.r) {
			return true;
		}
		else return false;
	}
};
vector<cost> road;
int father[mx], money;

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);//freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
	int n;
	while (scanf("%d\n", &n), n) {
		money = 0;
		road.clear();
		cost x;
		char c;
		for (int i = 1; i < n; ++i) {
			while(c = getchar(), c < 'A' || c > 'Z') ;
			int l = c - 'A', num;
			scanf("%d", &num);
			for (int ii = 0, r, val; ii < num; ++ii) {
				while(c = getchar(), c < 'A' || c > 'Z') ;
				scanf("%d", &val);
				r = c - 'A';
				x.l = l;
				x.r = r;
				x.val = val;
				if (l > r) swap(x.l, x.r);
				road.push_back(x);
				printf("%d %d %d\n", x.l, x.r, x.val);
			}
		}
	}
	return 0;
}




// 9
// A 2 B 12 I 25
// B 3 C 10 H 40 I 8
// C 2 D 18 G 55
// D 1 E 44
// E 2 F 60 G 38
// F 0
// G 1 H 35
// H 1 I 35
// 3
// A 2 B 10 C 40
// B 1 C 20
// 0

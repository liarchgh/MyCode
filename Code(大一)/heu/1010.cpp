#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

map<int, int>m1, m2;
struct no {
	int x, y;
} note[100005];
bool cmp1(no x, no y) {
	return x.x <= y.x;
}

bool cmp2(no x, no y) {
	return x.y <= y.y;
}

double ceju(no x, no y) {
	return sqrt((double)(x.x - y.x) * (x.x - y.x) + (double)(x.y - y.y) * (x.y - y.y));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
#endif
	int t;
	while (scanf("%d", &t) != EOF) {
		m1.clear(); m2.clear();
		for (int i = 0; i < t; ++i) {
			scanf("%d%d", &note[i].x, &note[i].y);
			m1[note[i].x] = note[i].y;
			m2[note[i].y] = note[i].x;
		}
		double ans = 1e10;
		//printf("%lf\n",ans);
		sort(note, note + t, cmp1);
		for (int i = 1; i < t; ++i) {
			int a = ceju(note[i], note[i - 1]);
			ans = min(ans, ceju(note[i], note[i - 1]));
			for (int j = 1; j < a; ++j) {
				if (m1[note[i].x + j] > 0) {
					no b;
					b.x = note[i].x + j;b.y = m1[note[i].x + j];
					ans = min(ans, ceju(note[i], b));
				}
				if(m2[note[i].y + j] > 0){
					no b;
					b.y = note[i].y + j;b.x = m2[note[i].y + j];
					ans = min(ans, ceju(note[i], b));
				}
			}
		}
		sort(note, note + t, cmp2);
		for (int i = 1; i < t; ++i) {
			int a = ceju(note[i], note[i - 1]);
			ans = min(ans, ceju(note[i], note[i - 1]));
			for (int j = 1; j < a; ++j) {
				if (m1[note[i].x + j] > 0) {
					no b;
					b.x = note[i].x + j;b.y = m1[note[i].x + j];
					ans = min(ans, ceju(note[i], b));
				}
				if(m2[note[i].y + j] > 0){
					no b;
					b.y = note[i].y + j;b.x = m2[note[i].y + j];
					ans = min(ans, ceju(note[i], b));
				}
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}

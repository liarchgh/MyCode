#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		freopen("D:\\out.txt", "w", stdout);
	#endif
	int t, x, y, z;
	while (scanf("%d", &t) != EOF) {
		while (t--) {
			scanf("%d%d%d", &x, &y, &z);
			if(x^y^z){
				printf("Mr.Z\n");
			}
			else printf("Mr.Y\n");
		}
	}
	return 0;
}
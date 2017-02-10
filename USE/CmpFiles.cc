#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	fstream f1, f2;
	char c1, c2;
	f1.open("1.cc", ios::in);
	f2.open("2.cc", ios::in);
	int a = 1;
	while (!f1.eof()) {
		if (f2.eof()) {
			printf("2nd file ends on %d th line.\n", a); getchar(); getchar();
			return 0;
		}
		f1 >> c1; f2 >> c2;
		if(c1 == '\n' || c2 == '\n') ++a;
		if (c1 != c2) {
			printf("Differ on %d th line.\n", a); getchar(); getchar();
			return 0;
		}
	}
	if (!f2.eof()) {
		printf("1st file ends on %d th line.\n", a); getchar(); getchar();
		return 0;
	}
	printf("YES\n");
	getchar(); getchar();
	return 0;
}

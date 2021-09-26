#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 100005;
int tr[mx << 1];

int gcd(int x, int y){
	if(!x) return y;
	if(!y) return x;
	while(y){
		int t = x % y;
		x =y;
		y = t;
	}
	return x;
}

void pushup(int x){
	tr[x] = gcd(tr[x << 1], tr[x << 1 | 1]);
}

void build(int l, int r, int x){
	if(l == r){
		scanf("%d", &tr[x]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, x << 1);
	build(mid + 1, r, x << 1 | 1);
	pushup(x);
	//printf("%d\n", x);
}

int cha(int l, int r, int x,int ql, int qr){
	if(l > qr || r < ql){
		return 0;
	}
	if(l >= ql && r <= qr){
		return tr[x];
	}
	int mid = (l + r) >> 1;
	return gcd(cha(l, mid, x << 1, ql, qr),cha(mid + 1, r, x << 1 | 1, ql, qr));
}

int main(){
	#ifndef ONLIN_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		//freopen("D:\\out.txt", "w", stdout);
	#endif
	int n, q, l, r;
	scanf("%d%d", &n, &q);
	//printf("%d\n", n);
	build(1, n, 1);
	for(int i = 0; i < q; ++i){
		scanf("%d%d", &l, &r);
		printf("%d\n", cha(1, n, 1, l, r));
	}
	return 0;
}

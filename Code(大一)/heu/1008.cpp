#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int tree[100005], l, n, dir;

int cha(int l, int r, int now, int x, int dir){
	if(!tree[now] == 0) return -1;
	if(l == r){
		if(tree[now]){
			return abs(now - x);
		}
		return -1;
	}
	int mid = (l+r)/2;
	if(x < mid){
		int d =  cha(l, mid+1, now<<1, x, dir);
		if(d > 0) return d;
		if(dir > 0){
			d = cha(mid+1, r, now<<1|1, x, dir);
			return d;
		}
		return -1;
	}
	else if(x > mid){
		int d = cha(mid+1, r, now<<1|1, x, dir);
		if(d > 0) return d;
		if(dir < 0){
			d = cha(l, mid, now<<1, x, dir);
		}
		return -1;
	}
}

void push(int x){
	tree[x] = tree[x<<1] + tree[x<<1|1];
}

void jia(int l, int r, int now, int x){
	if(l > x || r < x) return;
	if(l == r){
		if(now == x) tree[x] = 1;
		return;
	}
	int mid = (l+r)/2;
	jia(l, mid, now<<1, x);
	jia(mid+1, r, now<<1|1, x);
	push(x);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("D:\\in.txt", "r", stdin);
		freopen("D:\\out.txt", "w", stdout);
	#endif
	int t;
	while(scanf("%d", &t) != EOF){
		while(t--){
			int x = 0;
			scanf("%d%d", &l, &n);
			memset(tree, 0, sizeof(tree));
			dir = 1;
			int a, b, dis = 0;
			while(n--){
				scanf("%d", &a);
				if(a){
					int d = cha(1, l, 1, x, dir);
					if(d < 0){
						dir = -dir;
						d = cha(1, l, 1, x, dir);
					}
					if(d > 0){
						dis += d;
					}
				}
				else{
					scanf("%d", &b);
					jia(1, l, 1, b);
				}
			}
		}
	}
	return 0;
}

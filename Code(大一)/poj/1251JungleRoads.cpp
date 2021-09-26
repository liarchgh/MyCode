//程序过是过了 但是不知道为什么 原来那种一位一位严格来读的过程会出错 明明都是按位数的啊 最后只能换了一种方法 好像其他人也有这个问题 看到解析也说用scanf会出错
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int mx = 30, inf = 0x7fffffff;
struct cost{
	int l, r, val;
	bool operator== (cost b){
		if(l == b.l && r == b.r){
			return true;
		}
		else return false;
	}
};
vector<cost> road;
int father[mx], money;

bool cmp(cost a, cost b){
	return a.val < b.val;
}

int find_father(int x){
	if(father[x] != x){
		father[x] = find_father(father[x]);
	}
	return father[x];
}

void unit(int a, int b){
	father[father[a]] = father[b];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);//freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
	#endif
	int n;
	while(scanf("%d\n", &n), n){
		// printf("%d\n", n);
		money = 0;
		road.clear();
		cost x;
		char c;
		// getchar();
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
				// printf("%d %d %d\n", x.l, x.r, x.val);
			}
		}
		sort(road.begin(), road.end(), cmp);
		for(int i = 0; i < n; ++i){
			father[i] = i;
		}
		for(vector<cost>::iterator t, it = road.begin() + 1; it != road.end(); ++it){
			t = it - 1;
			if(*t == *it){
				road.erase(t);
				--it;
			}
		}
		for(int i = 0; i < road.size(); ++i){
			if(find_father(road[i].l) != find_father(road[i].r)){
				unit(road[i].l, road[i].r);
				money += road[i].val;
			}
		}
		printf("%d\n", money);
	}
	return 0;
}

// 216
// 30

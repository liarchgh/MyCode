//直觉告诉我不用二分图算法也能过 为了练习还是用吧 之后再验证
//终归还是忍不住试了一下 果然是WA了
//隔了一夜总算看懂了 原来是把每个点都分成两个点 一个只能出 一个只能入 就分成两队点了 就变成二分图了 去掉根节点后 就用匈牙利算法找出剩下的边中可以选上的有几条
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx=505;
int n,m,g[mx][mx],out[mx],in[mx],link[mx],vis[mx];

bool find(int u, int x){
	for(int i = 0; i < n; ++i){
		if(i == u || !g[x][i] || vis[i]) continue;
		vis[i] = 1;
		if(link[i] == -1 || find(u, link[i])){
			link[i] = x;
			return true;
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("C:\\in.txt", "r", stdin);
		freopen("C:\\out.txt", "w", stdout);
	#endif
	//printf("1111\n");
	int a,b;
	scanf("%d%d", &n, &m);
	memset(g, 0, sizeof(g));
	memset(out, 0, sizeof(out));
	memset(in, 0, sizeof(in));
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &a, &b);
		g[a-1][b-1] = 1;
		++out[a-1];
		++in[b-1];
	}
	int ans=0xfffffff,ans1;
	for(int i = 0; i < n; ++i){//将i当作根节点
		ans1 = 0;
		int s = out[i] + in[i] - g[i][i];//s为根节点已经有的边
		ans1 += n*2-1-s;
		int you = 0;
		memset(link, -1, sizeof(link));
		for(int j = 0; j < n; ++j){
			if(j == i) continue;
			memset(vis, 0, sizeof(vis));
			if(find(i, j)) ++you;
		}
		ans1 += m-s-you;
		ans1 += n-1-you;
		ans = min(ans, ans1);
	}
	/*
	int u = 0;
	for(int i = 1; i < n; ++i){
		if(out[i] + in[i] > out[u] + in[u]){
			u=i;
		}
	}
	int gt[mx][mx],outt[mx],inn[mx],ans=0xfffffff,ans1,jia;
	for(int i = 0; i < n; ++i){//总条数sum-out[i]-in[i] 
		memcpy(gt, g, mx * mx);
		memcpy(outt, out, mx);
		memcpy(inn, in, mx);
		ans1=0;
		ans1 += n*2-1-out[i]-in[i];
		for(int j = 0; j < n; ++j){
			inn[j] -= g[i][j];
			outt[j] -= g[j][i];
		}
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				if(g[j][k]){
					if(inn[k]>1 || outt[j]>1){
						g[j][k] = 0;
						--inn[k];--outt[j];
					}
				}
				if(g[k][j]){
					if(inn[j]>1 || outt[k]>1){
						g[k][j] = 0;
						--inn[j];--outt[k];
					}
				}
			}
		}
		jia = 0;
		for(int j = 0; j < n; ++j){
			jia += 2-inn[j]-outt[j];
		}
		ans1 += jia/2;
		ans = min(ans,ans1);
	}
	//以上注释的是失败的代码 T^T */
	printf("%d\n", ans);
	return 0;
}

/* 
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 505;

int n, m, g[N][N], ind[N], out[N], v[N], p[N];


void init () {
	memset(g, 0, sizeof(g));
	memset(ind, 0, sizeof(ind));
	memset(out, 0, sizeof(out));

	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a][b] = 1;
		out[a]++; ind[b]++;
	}
}

bool find (int r, int u) {
	for (int i = 1; i <= n; i++) {
		if (i == r || !g[u][i]) continue;
		if (v[i]) continue;
		v[i] = 1;
		if (p[i] == -1 || find(r, p[i])) {
			p[i] = u;
			return true;
		}
	}
	return false;
}

int handle(int r) {//除掉根结点r后还需要的边
	int ans = 0;
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++) {
		if (i == r) continue;
		memset(v, 0, sizeof(v));
		if (find(r, i)) ans++;
	}
	return ans;
}

int solve (int r) {//把r结点作为根节点u时的情况
	int s = ind[r] + out[r] - g[r][r];//s为当前根节点相连的边数 
	int ans = 2 * n - 1 - s;//此时ans为还需与根节点相连的边数
	int f = handle(r);
	ans = ans + m - s - f;//m-s为不与根节点相连的边数
	ans = ans + n - 1 - f;//除去根节点后共需要存在n-1条边
	return ans;
}

int main () {
	init();
	int ans = 1 << 30;
	for (int i = 1; i <= n; i++) ans = min(ans, solve(i));
	printf("%d\n", ans);
	return 0;
}
 */
 
 
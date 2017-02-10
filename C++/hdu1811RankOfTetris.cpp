#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

const int mx = 504;
int n, num;
struct no{
	int in;
	vector<int>next;
	void clear(){in = 0;next.clear();}
}node[mx];

vector<int>stk;

int dfs(){
	if(stk.size() >= n){
		++num;
		return 0;
	}
	for(int i = 0; i < n; ++i){
		if(!node[i].in){
			stk.push_back(i);
			--node[i].in;
			for(int j = 0; j < node[i].next.size(); ++j){
				--node[node[i].next[j]].in;
			}
			dfs();
			if(num >= 2) return 0;
			stk.erase(stk.end() - 1);
			++node[i].in;
			for(int j = 0; j < node[i].next.size(); ++j){
				++node[node[i].next[j]].in;
			}
		}
	}
	return 0;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("D://in.txt", "r", stdin);freopen("D://out.txt", "w", stdout);
	#endif
	int m;
	while(scanf("%d%d", &n, &m) != EOF){
		num = 0;
		stk.clear();
		for(int i = 0; i < n; ++i) {node[i].clear();}
		for(int a, b; m--;){
			scanf("%d ", &a);
			char c = getchar();
			scanf("%d\n", &b);
			// printf("%d %c %d\n", a, c, b);
			if(c == '<') {node[b].next.push_back(a);++node[a].in;}
			else {
				if(c != '>' && a < b) swap(a, b);
				node[a].next.push_back(b);++node[b].in;
			}
		}
		dfs();
		switch(num){
			case 0:printf("CONFLICT\n");break;
			case 1:printf("OK\n");break;
			default:printf("UNCERTAIN\n");
		}
	}
	return 0;
}

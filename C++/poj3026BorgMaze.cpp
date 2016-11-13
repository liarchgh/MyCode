#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

const int mx = 55, inf = 0x7fffffff;
char maze[mx][mx];
int dis[mx], num, ;//dis -1 has been in,num is the number of point including starting point
struct w{
	int x, y;
	w(int a, int b){x = a;y = b;}
}wei[mx];
queue<pair<w, int> >q;

void find_dis(int now){
	while(!q.empty()) q.pop();
	q.push({wei[now],0});
	while(!q.empty()){
		now = q.front().first;
		int th = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i){
			q.push({now})
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
	freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	while(n--){
		int cal, row, stc, str;
		char c;
		num = 1;
		scanf("%d%d\n", &cal, &row);
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < cal; ++j){
				maze[i][j] = getchar();
				if(maze[i][j] == 'S'){
					maze[i][j] = 100;
					wei[0].x = i;
					wei[0].y = j;
				}
				else if(maze[i][j] == 'A'){
					maze[i][j] = 100 + num;
					wei[num].x = i;
					wei[num++].y = j;
				}
			}
			getchar();
		}
		for(int i = 1; i < num; ++i){
			dis[i] = inf;
		}
		dis[0] = 0;
		int now = 0, ans = 0;
		while(1){
			find_dis(now);
			for(int i = 0; i < n; ++i){
				if(dis[i] < 0 || dis[i] == inf) continue;
				if(dis[now] < 0){
					now = i;
				}
				else if(dis[i] < dis[now]){
					now = i;
				}
			}
			if(dis[now] < 0) break;
			ans += dis[now];
			dis[now] = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

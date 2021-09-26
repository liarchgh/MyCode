#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

const int mxtr = 200, mxp = 40000;
struct no{
	int x, y;
	void f(int a, int b){x = a; y = b;}
}pri, sol[mxp], hat;
int h, w, pr[2], num, tran[5][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0}};
char g[mxtr + 3][mxtr + 3];

int main(){
    #ifndef ONLINE_JDUGE
    freopen("D:\\in.txt", "r", stdin);
    freopen("D:\\out.txt", "w", stdout);
    #endif
    char c;
    num = 0;
    scanf("%d%d\n", &h, &w);
    for(int i = 0; i < h; ++i){
    	for(int j = 0; j < w; ++j){
    		c = getchar();
    		switch(c){
				case '@':pri.f(i, j);g[i][j] = 1;break;
				case '$':sol[num++].f(i, j);g[i][j] = 1;break;
				case '%':hat.f(i, j);
				case '.':g[i][j] = 1;break;
				case '#':g[i][j] = 0;
    		}
    	}
    	getchar();
    }
    queue<no>q;
    for(int i = 0; i < num; ++i){
    	q.push(sol[i]);
    }
    q.push(pri);
    while(!q.empty()){
    	no t = q.front();
    	q.pop();
    	for(int i = 0; i < 5; ++i){
    		
    	}
    }
    return 0;
}
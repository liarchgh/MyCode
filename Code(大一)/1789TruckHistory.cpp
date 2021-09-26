#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int mx = 2003;
char ss[mx][mx];
vector<pair<int,int> >edge[mx];

int main(){
	int n;
	while(scanf("%d\n", &n), n){
		for(int i = 0; i < n; ++i){
			gets(ss[i]);
			for(int j = i - 1; j >= 0; --j){
				int len = 0;
				for(int k = 0; k < 7; ++k){
					if(ss[i][k] != ss[j][k]){
						++len;
					}
					edge[i].push_back({j, len});
					edge[j].push_back({i, len});
				}
			}
		}
		queue
	}
	return 0;
}

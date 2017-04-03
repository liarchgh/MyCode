#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int mxn = 10000 + 5, mxm = 100000 + 5;
int n, m, fa[mxn];
vector<int>lukou[mxn];

int find_fa(int x){
    if(fa[fa[x]] != fa[x]){
        fa[x] = find_fa(fa[x]);
    }
    return fa[x];
}

int main(){
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        fa[i] = i;
    }
    for(int i = 0, a, b; i < m; ++i){
        scanf("%d%d", &a, &b);
        if(find_fa(a) != find_fa(b)){
            fa[fa[a]] = fa[b];
        }
        lukou[a].push_back(b);
        lukou[b].push_back(a);
    }
    int is_open = 1;
    for(int i = 1; i < n; ++i){
        if(find_fa(i) != find_fa(i + 1)){
            is_open = 0;
            break;
        }
    }
    if(!is_open){
        printf("-1\n");
        return 0;
    }
    for(int i = 1, a, b; i <= n; ++i){
        sort(lukou[i].begin(), lukou[i].end());
    }
    int odd = 0, begin = -1;
    for(int i = 1; i <= n; ++i){
        if(lukou[i].size() & 1){
            ++odd;
            if(begin < 0){
                begin = i;
            }
        }
    }
    if(odd > 2){
        printf("-1\n");
        return 0;
    }
    if(begin < 0){
        begin = 1;
    }
    int now = begin, last = -1;
    printf("%d", begin);
    while(1){
        if(last > 0){
            printf(" %d", now);
            for(vector<int>::iterator it =lukou[now].begin(); it != lukou[now].end(); ++it){
                if(*it == last){
                    lukou[now].erase(it);
                    break;
                }
            }
        }
        if(!lukou[now].size()){
            printf("\n");
            return 0;
        }
        last = now;
        now = lukou[now][0];
        lukou[last].erase(lukou[last].begin());
    }
    return 0;
}

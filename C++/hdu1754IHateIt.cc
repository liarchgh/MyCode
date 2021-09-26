//一道简单的实验zkw线段树的题目 居然卡了一两天 就是因为多组输入。。。气死了
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int mxn = 21;
int tree[1 << (mxn + 1)], treeSize;

inline void Maintain(int x){
    // tree[x] = tree[x << 1] + tree[x << 1 | 1];
    tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
}
inline void Build(int n){
    memset(tree, 0, sizeof(tree));
    int & m = treeSize;
    for(m = 1; m < n; m <<= 1);
    for(int i = m + 1; i <= m + n; ++i){
        scanf("%d", &tree[i]);
    }
    for(int i = m - 1; i; --i){
        Maintain(i);
    }
}
inline void Update(int pos, int v){
    pos += treeSize;
    tree[pos] = v;
    for(pos >>= 1; pos; pos >>= 1){
        Maintain(pos);
    }
}
inline int Sum(int l, int r){
    int ans = 0;
    for(l = l + treeSize - 1, r = r + treeSize + 1;
        l^r^1; l >>= 1, r >>= 1){
        if(~l & 1){
            // ans += tree[l ^ 1];
            ans = max(ans, tree[l ^ 1]);
        }
        if(r & 1){
            ans = max(ans, tree[r ^ 1]);
            // ans += tree[r ^ 1];
        }
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    int n, mm, l, r;
    while(scanf("%d %d", &n, &mm) != EOF){
        Build(n);
        while(getchar() != '\n') ;
        while(mm--){
            // printf("-=-=%d\n", mm);
            switch(getchar()){
                case 'Q':
                scanf("%d%d", &l, &r);
                printf("%d\n", Sum(l, r));
                // printf("+++%d %d\n", l, r);
                break;
                case 'U':
                scanf("%d%d", &l, &r);
                Update(l, r);
                // printf("+++%d %d\n", l, r);
            }
            if(mm){
                while(getchar() != '\n') ;
            }
        }
    }
    return 0;
}

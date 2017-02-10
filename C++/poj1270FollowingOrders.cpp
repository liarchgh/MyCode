//思路还好 静下心来一会就完成了 初始化有些恶心人了 一大堆东西 WA了一次 刚开始看题时感觉有些难呢 做了发现挺简单的 基本没怎么调试
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int mx = 504;
int num = 0;
char order[300];

vector<int>stak;

struct no {
    int in;
    vector<int>next;
    void clear(){
        in = 0;
        next.clear();
    }
} node[mx];
map<char, int>zhuan;

void dfs() {
    if (stak.size() >= num) {
        for (int i = 0; i < stak.size(); ++i) {
            printf("%c", order[stak[i]]);
        }
        putchar('\n');
        return;
    }
    for (int i = 0; i < num; ++i) {
        if (!node[i].in) {
            stak.push_back(i);
            --node[i].in;
            for (int j = 0; j < node[i].next.size(); ++j) --node[node[i].next[j]].in;
            dfs();
            stak.erase(stak.end() - 1);
            ++node[i].in;
            for (int j = 0; j < node[i].next.size(); ++j) ++node[node[i].next[j]].in;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("D://in.txt", "r", stdin); freopen("D://out.txt", "w", stdout);
#endif
    int p = 0;
    while (1) {
        char c;
        num = 0;
        zhuan.clear();
        for (; (c = getchar()) != '\n';) {
            if (c == EOF) return 0;
            if (c != ' ') {
                if (zhuan.find(c) == zhuan.end()) {
                    order[num++] = c;
                }
            }
        }
        for(int i = 0; i < num; ++i){
            node[i].clear();
        }
        sort(order, order + num);
        for (int i = 0; i < num; ++i) zhuan[order[i]] = i;
        for (char c, a = -1; (c = getchar()) != '\n';) {
            if (c == EOF) return 0;
            if (c != ' ')
                if (a == -1) a = c;
                else {
                    node[zhuan[a]].next.push_back(zhuan[c]);
                    ++node[zhuan[c]].in;
                    a = -1;
                }
        }
        if (p) putchar('\n');
        else p = 1;
        dfs();
    }
    return 0;
}

// //
// // main.cpp
// // poj1270
// //
// // Created by Candy on 9/11/16.
// //

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int N=30,M=55;
// char s[105];
// int a[N],num=0,n=0,id[N];
// int ch[N][N],topo[N],ind[N];

// void print(){
//     for(int i=1;i<=n;i++) printf("%c",(char)topo[i]+'a'-1);
//     printf("\n");
// }
// void dfs(int d){ //printf("dfs %d\n",d);
//     if(d==n+1){print();return;}
//     for(int i=1;i<=n;i++)
//         if(ind[i]==0){
//             ind[i]--; topo[d]=a[i];
//             for(int j=1;j<=ch[i][0];j++) ind[ch[i][j]]--;
//             dfs(d+1);
//             for(int j=1;j<=ch[i][0];j++) ind[ch[i][j]]++;
//             ind[i]++;
//         }
// }
// int main(int argc, const char * argv[]) {
//     while(fgets(s,105,stdin)){ //printf("p %s\n",s);
//         n=0;
//         memset(topo,0,sizeof(topo));
//         memset(ch,0,sizeof(ch));
//         memset(ind,0,sizeof(ind));
//         int len=strlen(s); //printf("len %d\n",len);
//         for(int i=0;i<len;i++)
//             if(s[i]>='a'&&s[i]<='z') a[++n]=s[i]-'a'+1;
//         sort(a+1,a+1+n);
//         for(int i=1;i<=n;i++) id[a[i]]=i;

//         fgets(s,105,stdin);
//         len=strlen(s);
//         int last=0;
//         for(int i=0;i<=len;i++)
//             if(s[i]>='a'&&s[i]<='z'){
//                 int t=s[i]-'a'+1;
//                 t=id[t];
//                 if(last==0) last=t;
//                 else{ch[last][++ch[last][0]]=t;ind[t]++;last=0;}
//             }
//         dfs(1);
//         printf("\n");
//     }
//     return 0;
// }

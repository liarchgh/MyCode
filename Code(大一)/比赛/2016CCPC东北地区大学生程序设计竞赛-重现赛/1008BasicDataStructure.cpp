#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <deque>

using namespace std;

const int inf = 100005;
int dis;//dis是方向1是从左边加0是从右边加
deque<int>q, q0[2];//q0为具上一个0之间的距离

void q_push(int x) {
    if (dis) {
        q.push_front(x);

    }
    else {
        q.push_back(x);
    }
    if (x) {
        if (q0[dis].empty() || q0[dis].back() == inf)
            q0[dis].push_back(inf);
        else {
            q0[dis].push_back(q0[dis].back() + 1);
        }
        q0[!dis].push_front(inf);
    }
    else {
        q0[dis].push_back(0);
        q0[!dis].push_front(0);
        for(deque<int>::iterator it = q0[!dis].begin() + 1; *it != 0 && it != q0[!dis].end(); ++it){
            *it = *(it - 1) + 1;
        }
    }
}

void q_pop() {
    if(q.empty()){
        return ;
    }
    if (dis) {
        q.pop_front();
    }
    else {
        q.pop_back();
    }
    if(q.empty()){
        return ;
    }
    q0[dis].pop_back();
    if(!q0[!dis].front()){
        q0[!dis].pop_front();
        if(q0[!dis].empty()) return ;
        for(deque<int>::iterator it = q0[!dis].begin(); *it != 0; ++it){
            *it = inf;
        }
    }
    else q0[!dis].pop_front();
}

void q_query(){
    if(q.empty()){
        printf("Invalid.\n");
        return ;
    }
    if(q0[dis].back() != inf){
        printf("%d\n", (!(q0[dis].back() & 1)) ^ (q0[dis].size() == q0[dis].back() + 1));
    }
    else{
        printf("%d\n", (q0[dis].size() & 1));
    }
}

int main() {
// #ifndef ONLINE_JDUGE
//     freopen("D:\\in.txt", "r", stdin);
//     // freopen("D:\\out.txt", "w", stdout);
// #endif
    int t, n, tx;
    char que[15];
    scanf("%d\n", &t);
    for (int th = 1; th <= t; ++th) {
        dis = 0;
        q.clear();
        q0[0].clear();
        q0[1].clear();
            // printf("%d\n", th);
        printf("Case #%d:\n", th);
        scanf("%d", &n);
        while (n--) {
            scanf("%s", que);
            // puts(que);
            switch (que[0]) {
            case 'P':
                if (que[1] == 'U') {
                    scanf("%d", &tx);
                    // printf("%d\n", tx);
                    q_push(tx);
                }
                else {
                    q_pop();
                }
                break;
            case 'Q': q_query();break;
            case 'R': dis = !dis;
            }
        }
    }
    return 0;
}
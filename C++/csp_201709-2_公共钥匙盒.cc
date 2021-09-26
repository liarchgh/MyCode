#include <cstdio>
#include <algorithm>
using namespace std;

struct Commit{
    int time, keyNum;
    void set(int t, int k){
        time = t;
        keyNum = k;
    }
};

bool cmpCom(Commit x, Commit y){
    if(x.time != y.time){
        return x.time < y.time;
    }
    if(x.keyNum * y.keyNum > 0){
        return x.keyNum < y.keyNum;
    }
    return x.keyNum > y.keyNum;
}

const int max_k = 2000 + 4;
int n, k;
Commit coms[max_k];
int Pos2Key[max_k];

void HandleCommit(Commit com){
    if(com.keyNum < 0){
        for(int i = 0; i < n; ++i){
            if(Pos2Key[i] == -com.keyNum){
                Pos2Key[i] = -1;
                return;
            }
        }
    }
    else{
        for(int i = 0; i < n; ++i){
            if(Pos2Key[i] < 0){
                Pos2Key[i] = com.keyNum;
                return;
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        Pos2Key[i] = i+1;
    }
    for(int i = 0, t0, t1, key; i < k; ++i){
        scanf("%d%d%d", &key, &t0, &t1);
        t1 += t0;
        coms[i*2].set(t0, -key);
        coms[i*2+1].set(t1, key);
    }
    sort(coms, coms + k * 2, cmpCom);

    for(int i = 0; i < k * 2; ++i){
        HandleCommit(coms[i]);
    }

    for(int i = 0; i < n-1; ++i){
        printf("%d ", Pos2Key[i]);
    }
    printf("%d\n", Pos2Key[n-1]);
}
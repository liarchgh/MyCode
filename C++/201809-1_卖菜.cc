#include <cstdio>
#include <fstream>

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    int pc[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &pc[i]);
    }
    printf("%d ", (pc[0]+pc[1])/2);
    for(int i = 1; i < n-1; ++i){
        printf("%d ", (pc[i-1] + pc[i] + pc[i+1]) / 3);
    }
    printf("%d\n", (pc[n-1] + pc[n-2]) / 2);
}
#include <cstdio>

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
    #endif
    int t;
    scanf("%d", &t);
    while(t--){
        int n, count = 0, ans = 1;
        scanf("%d", &n);
        for(int i = 0, x; i < n; ++i){
            scanf("%d", &x);
            if(!i){
                ans = x;
            }
            else{
                ans ^= x;
            }
            count += x > 1;
        }
        if((count < 1 && !ans) || (count == 1) || (ans && count >= 2)){
            printf("John\n");
        }
        else{
            printf("Brother\n");
        }
    }
    return 0;
}
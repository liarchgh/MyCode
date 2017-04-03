//http://118.190.20.162/view.page?gpid=T52

#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 1000 + 5;
int num[mx], n;

int main(){
    freopen("in.ls", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int small = 0, big = 0;
    for(int i = 0; i < n; ++i){
        if(num[i] < num[n / 2]) ++small;
        else if(num[i] > num[n / 2]) ++big;
    }
    int ans;
    if(small == big) ans = num[n / 2];
    else ans = -1;
    printf("%d\n", ans);
    return 0;
}


#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int main(){
    int t,n;
    long long a[305];
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        printf("Case #%d:\n",i);
        scanf("%d",&n);
        for(int j=0;j<n;++j){
            scanf("%lld",&a[j]);
        }
    }
    return 0;
}

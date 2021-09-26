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

int t,n,a[15],ans,sum;
int main() {
    scanf("%d",&t);
    for(int i=1; i<=t; ++i) {
        printf("Case #%d: ",i);
        scanf("%d",&n);
        sum=0;
        for(int j=0; j<n; ++j) {
            scanf("%d",&a[j]);
            sum+=a[j];
            }
        ans=0;
        int pre=-1,mx=-1,premx;
        while(ans<sum) {
            if(mx!=-1) {
                pre=premx;
                --a[premx];
                if(a[mx]>a[premx]) {
                    for(int j=0; j<n; ++j) {
                        if(a[j]>a[premx] && j!=mx) premx=j;
                        }
                    }
                else {
                    if(a[mx]<a[premx]){
                        int t=mx;
                        mx=premx;
                    }
                    }
                }
            --sum;
            ++ans;
            }
        }
    return 0;
    }

#include <cstdio>
#include <algorithm>

using namespace std;

int n,wb,w[105],val[105],d[10005]= {0};
int main() {
    scanf("%d%d",&n,&wb);
    for(int i=0; i<n; ++i) {
        scanf("%d%d",&w[i],&val[i]);
        }
    for(int j=0; j<n; ++j) {
        for(int i=wb; i>0; --i) {
                if(i>=w[j])
                    d[i]=max(d[i],val[j]+d[i-w[j]]);
            }
        }
    printf("%d\n",d[wb]);
    return 0;
    }

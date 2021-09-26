//01±³°ü
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n,m,w[3500][2],d[13000]= {0};
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i) {
        scanf("%d%d",&w[i][0],&w[i][1]);
        }
    for(int j=0; j<n; ++j) {
        for(int i=m; i>=0; --i) {
            if(i>=w[j][0])
                d[i]=max(d[i],d[i-w[j][0]]+w[j][1]);
            }
        }
    printf("%d\n",d[m]);
    return 0;
    }

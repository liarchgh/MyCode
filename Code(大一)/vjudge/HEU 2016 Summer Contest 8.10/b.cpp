#include <cstdio>
#include <cstring>

int n,m,x1,x2,y1,y2,u[5005],l[5005],num[5005];
int pan(int x,int y,int xx,int yy) {
    if(-x*yy+y*xx>0) return 1;
    else return 0;
    }
void jia(int x,int y) {
    for(int i=0; i<n; ++i) {
        if(pan(x-l[i],y-y2,u[i]-l[i],y1-y2)) {
            ++num[i];
            return;
            }
        }
        ++num[n];
    }
int main() {
    int x,y,p=0;
    while(scanf("%d",&n),n) {
            if(p)
                printf("\n");
                else{
                    p=1;
                }
        memset(num,0,sizeof(num));
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(int i=0; i<n; ++i) {
            scanf("%d%d",&u[i],&l[i]);
            }
        for(int i=0; i<m; ++i) {
            scanf("%d%d",&x,&y);
            jia(x,y);
            }
        for(int i=0; i<=n; ++i) {
            printf("%d: %d\n",i,num[i]);
            }
        }
    return 0;
    }

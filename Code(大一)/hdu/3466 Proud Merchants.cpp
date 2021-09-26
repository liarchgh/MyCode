//总是WA 上网找了解析 原来要按q-p从小到大排序 下面说的有误  应该是前边的q-p更大
//A：p1,q1   B: p2,q2，先选A，则至少需要p1+q2的容量，而先选B则至少需要p2+q1，如果p1+q2>p2+q1，那么要选两个的话的就要先选A再              选B，公式可换成q1-p1 < q2-p2，就按这样的方法排序最后的顺序就是最优的顺序。
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,d[5005];
struct no{
    int p,q,v;
}a[505];
bool cmp(no x,no y){
    return (x.q-x.p)>(y.q-y.p);
}
int main(){
    int ans;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&m);
        memset(d,0,sizeof(d));ans=0;
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&a[i].p,&a[i].q,&a[i].v);
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;++i){
            for(int j=a[i].q;j<=m;++j){
                d[j-a[i].p]=max(d[j-a[i].p],d[j]+a[i].v);
                ans=max(ans,d[j-a[i].p]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

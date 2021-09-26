#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int t,n,m;
pair<int ,int >co[105][105];
double fanhui(int x,int y){
    long long kuan = co[x][y].first,cost = co[x][y].second,t;
    for(int i = 0; i < n; ++i){
        if(i == x) continue;
        t = 0xfffffffffffffff;
        for(int j = 1; j <= co[i][0].first; ++j){
            if(co[i][j].first >= co[x][y].first){
                t = min(t, (long long)co[i][j].second);
            }
        }
        cost += t;
    }
    double a = kuan;
    a /= cost;
    return a;
}
int main(){
    //first为带宽 second为花费
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &m);
            co[i][0].first=m;
            for(int j = 1; j <= m; ++j){
                scanf("%d%d", &co[i][j].first, &co[i][j].second);
            }
            //sort(co[i]+1,co[i]+m+1);
        }
        double ans=0;
        long long cost,kuan;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= co[i][0].first; ++j){
                ans=max(ans,fanhui(i,j));
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}

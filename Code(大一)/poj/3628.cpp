//�������� Ȼ������ֱ�ӱ�����-_-  �������ϵĴ������ʱ�临�Ӷ�ҲҪ�ﵽ1<<n�ļ���
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,b,h[25],ans=0xfffffff,d[1100005]={0};
int main(){
    scanf("%d%d",&n,&b);
    for(int i=0;i<n;++i){
        scanf("%d",&h[i]);
        for(int j=1;j<(1<<n);++j){
            if(j&(1<<i)){
                d[j]+=h[i];
            }
        }
    }
    for(int j=0;j<(1<<n);++j){
        if(d[j]>=b) ans=min(ans,d[j]-b);
        if(!ans) break;
    }
    printf("%d\n",ans);
    return 0;
}

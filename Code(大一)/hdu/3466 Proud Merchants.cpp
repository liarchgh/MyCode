//����WA �������˽��� ԭ��Ҫ��q-p��С�������� ����˵������  Ӧ����ǰ�ߵ�q-p����
//A��p1,q1   B: p2,q2����ѡA����������Ҫp1+q2������������ѡB��������Ҫp2+q1�����p1+q2>p2+q1����ôҪѡ�����Ļ��ľ�Ҫ��ѡA��              ѡB����ʽ�ɻ���q1-p1 < q2-p2���Ͱ������ķ�����������˳��������ŵ�˳��
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

//��һ����ϣ����Ŀ ���� ����ϸ�� ��ȻҪͨ���������������� 26��Ӧ���� i<n-1 һ��ʼд��n
#include <cstdio>
#include <cstring>

using namespace std;

char ss[16000005];
int xu[150],vis[16000005];
int bas;
int main(){
    int n,nc;
    scanf("%d%d",&n,&nc);getchar();
    gets(ss);
    memset(xu,-1,sizeof(xu));
    int len=strlen(ss);
    for(int i=0,th=0;th<nc && i<len;++i){
        if(xu[ss[i]]==-1){
            xu[ss[i]]=th++;
            //printf("%d\n",th);
        }
    }
    long long t=0;
    int ans=0;
    bas=1;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<len;++i){
        if(i<n-1){
            t=t*nc+xu[ss[i]];
            bas*=nc;
        }
        else{
            t=t%bas;
            t=t*nc+xu[ss[i]];
            if(!vis[t]){
                ++ans;
                vis[t]=1;
            }
            //printf("%d\n",t);
        }
    }
    printf("%d",ans);
    return 0;
}

//Ӧ�����׵�KMP�㷨���� �о����������������������һ�� ������ ֻ����next������󷨾������� û�� �ֿ�����ô��next����ѭ����� ���� ��һ�㶼���а�
#include <cstdio>

int n,m,b[10005],a[1000005],k,next[10005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;++i){
            scanf("%d",&b[i]);
        }
        next[0]=0;
        int q,p=0;
        for(q=1;q<m;++q){
            while(p>0 && b[p]!=b[q]){
                p=next[p-1];
            }
            if(b[p]==b[q]) ++p;
            next[q]=p;
        }
        p=1;q=0;
        for(int i=0;i<n;++i){
            while(q>0 && b[q]!=a[i]) q=next[q-1];
            if(b[q]==a[i]) ++q;
            if(q==m){
                    printf("%d\n",i-m+2);
                p=0;break;
            }
        }
        if(p) printf("-1\n");
    }
    return 0;
}

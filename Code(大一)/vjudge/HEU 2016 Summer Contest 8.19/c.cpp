//�ҹ���  ����ÿ��n ֱ�����һ��1 �������n-1��0  �Լ�û�ҳ��� ֱ�ӱ��� �����ô����� �����ֲ������а�
#include <cstdio>

int ans[1000005];
int main(){
    int n,t;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        printf("1");
        while(--n){printf("0");}
        putchar('\n');
    }
    return 0;
}

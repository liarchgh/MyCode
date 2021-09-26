//找规律  对于每个n 直接输出一个1 后面跟着n-1个0  自己没找出来 直接暴力 都想用大数了 对数字不够敏感啊
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

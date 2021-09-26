//！！！位运算符的优先级比关系运算符的优先级要低
#include <cstdio>

int a[20000],p;
int t;
bool pan(int c){
    //printf("%d\n",t);
    for(int i=0;i<t;++i){
            //printf("%c   ",a[i]^c);
        if(((a[i]^c)<'A') || ((a[i]^c)>'Z')) return false;
    }
    return true;
}
int main(){
    //printf("%d %d\n",'A','Z');
    //for(int i='A';i<='Z';++i) p^=i;
        while(scanf("%d",&t)!=EOF){
        for(int i=0;i<t;++i){
            scanf("%d",&a[i]);
            //printf("%d  ",a[i]);
        }
        for(p='A';p<='Z';++p){
            if(pan(p)) break;
        }
            //printf("%c\n",p);
        //if(pan('B')) printf("11111111\n");
        for(int i=0;i<t;++i){
            putchar(a[i]^p);
        }
        putchar('\n');
        }
    return 0;
}

#include <cstdio>

int main(){
    int n,a[100005];
//    su[0]=2;
//    for(int i=3;i<=40000;++i){
//        int p=1,ii;
//        for(ii=0;su[ii];++ii){
//            if(!(i%su[ii])){
//                p=0;break;
//            }
//        }
//        if(p) {su[ii]=i;
//        }//printf("%d\n",ii);}
//    }
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        while(!(a[i]&1)) a[i]>>=1;
        while(!(a[i]%3)) a[i]/=3;
    }
    for(int i=1;i<n;++i){
        if(a[i]!=a[0]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

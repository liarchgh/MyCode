//应该是首道矩阵快速幂的题目 不难 细节处理 14行的a1忘记乘以3 失败啊
#include <cstdio>

using namespace std;

const int mod=1000000007;
void chuan(long long int *p,long long int *q){
    long long int t1[9],t2[9];
    for(int i=0;i<9;++i) {t2[i]=q[i];t1[i]=p[i];}
    for(int i=0;i<9;++i){
        int a1=i/3,a2=i%3;
        long long sum=0;
        for(int j=0;j<3;++j){
            sum+=(t1[a1*3+j]*t2[j*3+a2]);
        }
        p[i]=sum%mod;
    }
}

int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);--n;
        long long int ju[9]={1,2,3,4,5,6,7,8,9},ans[9]={1,1,1};
//        while(n--){
//            chuan(ans,ju);
//
//        }
        while(n){
            if(n&1){
                chuan(ans,ju);
            }
            chuan(ju,ju);
            n>>=1;
        }
        printf("%lld\n",(ans[0]+ans[1]+ans[2])%mod);
    }
    return 0;
}

//12   15   18
//5     7     9
//1     2     3
//198 243 288
//122 160 198
//87   117 147
//729
//
//1 1 1
//0 0 0
//0 0 0
//126 153 180
//72   87   102
//30   36   42
//459


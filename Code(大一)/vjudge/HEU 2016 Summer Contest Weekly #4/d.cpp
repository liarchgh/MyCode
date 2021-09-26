#include <cstdio>
#include <map>

using namespace std;

struct qk{
    int v[6]={0};
    bool operator<(const qk & ct) const   // 两个const是必需的。
    {
        for(int i=0;i<6;++i){
            if(v[i]<ct.v[i]) return true;
            else if(v[i]>ct.v[i]) return false;
        }
        return false;
    }
}u[15505];
map < qk,int > m ;
int num=0;
void yuchuli(int th,int sheng,qk a){
    if(th>=5){
        a.v[5]=sheng;
        m[a]=num;
        u[num++]=a;
        return;
    }
    for(int i=0;i<=sheng;++i){
        a.v[th]=i;
        yuchuli(th+1,sheng-i,a);
    }
}
int main(){
    char c;
    qk a;
    yuchuli(0,15,a);
//    for(int t=0;t<=15503;++t){
//        for(int i=0;i<5;++i){
//                printf("%d ",u[t].v[i]);
//            }
//            printf("%d\n",u[t].v[5]);
//    }
int ths=1;
    while((c=getchar())!=EOF){
        switch(c){
        case 'm':
            printf("Case %d: ",ths++);
            for(int i=0;i<6;++i) scanf("%d",&a.v[i]);
            getchar();
            printf("%d\n",m[a]);
            break;
        case 'u':
            int t;
            printf("Case %d: ",ths++);
            scanf("%d",&t);getchar();
            for(int i=0;i<5;++i){
                printf("%d ",u[t].v[i]);
            }
            printf("%d\n",u[t].v[5]);
            break;
        case 'e':
            return 0;
        }
    }
    return 0;
}

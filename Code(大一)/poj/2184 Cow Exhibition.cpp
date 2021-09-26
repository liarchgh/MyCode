//简单的01背包 s有负值 很容易想到转移原点 然而却卡了很长时间 原来是20行的循环变量的初始化没有搞清楚 注意注意！！！
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int di=100000;
const int chu=-200000;
int main() {
    int n,s,f,ds[200005],ans=di;
    for(int i=0; i<200005; ++i) ds[i]=-200000;
    //printf("%d\n",ds[5]);
    scanf("%d",&n);
    ds[di]=0;
    for(int i=0; i<n; ++i) {
        scanf("%d%d",&s,&f);
        int p=1;
        if(s<0) p=-1;
        for(int i=100000+100000*p-s; i>=0 && i<=200002 && i+s>=0 && i+s<=200002; i-=p) {
            if(ds[i]!=chu)  {
                ds[i+s]=max(ds[i+s],ds[i]+f);
                if((i+s>=di && ds[i+s]>=0) &&(ds[i+s]+i+s>ds[ans]+ans)) ans=i+s;
                //printf("         %d %d\n",ds[i],i);
                }
            }
        }
    printf("%d\n",ds[ans]+ans-di);
    return 0;
    }

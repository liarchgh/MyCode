#include <cstdio>
#include <cstring>

using namespace std;

int s1[29],s2[29];
int main(){
    int t;char c;
    scanf("%d",&t);getchar();
    while(t--){
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        while((c=getchar())!='\n') ++s1[c-'a'];
        while((c=getchar())!='\n') ++s2[c-'a'];
        int ans=0;
        for(int i=0;i<29;++i) ans+=(s1[i]-s2[i])<0?s2[i]-s1[i]:s1[i]-s2[i];
        printf("%d\n",ans);
    }
    return 0;
}

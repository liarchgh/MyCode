#include <cstdio>
#include <cstring>

int d[60];
int zhao(int x){
    if(d[d[x]]!=d[x]) d[x]=zhao(x);
    return d[x];
}
int main() {
    int n,a[4],p;
    char s[9];
    while(scanf("%d",&n)!=EOF) {
        p=0;
        getchar();
        for(int i=0; i<=55; ++i) d[i]=i|1;
        for(int i=0; i<n; ++i) {
            scanf("%s",s);//getchar();
            //puts(s);
            if(p) continue;
            for(int ii=0; ii<4; ++ii) {
                if(s[ii<<1]=='0') a[ii]=-1;
                else a[ii]=(s[ii<<1]-'A')*2;
                if(s[ii<<1+1]=='+') a[ii]+=1;
                }
            int sta=0,bi;
            while(a[sta]==-1) ++sta;
            bi=zhao(a[sta]);
            for(int sss=sta+1; sss<4; ++sss) {
                if(a[sss]==-1) continue;
                int st1=zhao(a[sss]);
                if(bi==st1 && !(a[sta]==bi && a[sss]==bi)) {
                    p=1;
                    gets(s);
                    break;
                    }
                d[st1]=bi;
                }
                if(p) break;
            }
        if(p) printf("unbounded\n");
        else printf("bounded\n");
        }
    return 0;
    }

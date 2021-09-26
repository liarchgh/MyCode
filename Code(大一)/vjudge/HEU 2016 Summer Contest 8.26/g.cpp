#include <cstdio>
#include <cstring>

using namespace std;

char ss[1000005];
int nex[1000005];
int main(){
    while(gets(ss)){
        int len=strlen(ss),k=0;
        nex[0]=0;
        for(int q=1;q<len;++q){
            while(k>0 && ss[q]!=ss[k]) k=nex[k-1];
            if(ss[q]==ss[k]) ++k;
            nex[q]=k;
        }
        //printf("   %d\n",nex[len-1]);
        if(nex[len-1]){
            len-=nex[len-1];
            int j=len-nex[len-1];
            if(len%j) printf("%d\n",len);
            else printf("%d\n",j);
        }
        else {
            printf("%d\n",len);
        }
    }
    return 0;
}

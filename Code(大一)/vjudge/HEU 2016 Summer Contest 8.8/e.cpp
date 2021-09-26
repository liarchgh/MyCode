#include <cstdio>

int main(){
    int a,b,win;
    while(scanf("%d%d",&a,&b),a&&b){
        win=0;
        if(a<b){
            int t=a;
            a=b;
            b=t;
        }
        while(1)
        {
            win=!win;
            if(a%b==0 || a>b*2){
                break;
            }
            int t=a%b;
            a=b;b=t;
        }
        if(win) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}

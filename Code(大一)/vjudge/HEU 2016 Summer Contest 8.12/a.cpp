//为什么不能用long long
#include<cstdio>

int main(){
    unsigned int r;int x,y;
    scanf("%x,%d,%d",&r,&x,&y);
    if(!(r&(1<<y))) r+=(1<<y);
    --y;
    if(!(r&(1<<y))) r+=(1<<y);
    --y;
    if(r&(1<<y)) r-=(1<<y);
    if(r&(1<<x)) r-=(1<<x);
    printf("%x\n",r);
    return 0;
}

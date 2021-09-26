#include<cstdio>

int tian(int n);
int main()
{
    int y;
    scanf("%d",&y);
    int t=0,a=y;
    while(!t || t%7!=0 || tian(a)!=tian(y))
    {
        t+=tian(y++);
        //printf("%d  %d\n",t,y);
    }
    printf("%d\n",y);
    return 0;
}

int tian(int n)
{
    if(!(n%400)) return 366;
    if(!(n%4) && n%100) return 366;
    return 365;
}

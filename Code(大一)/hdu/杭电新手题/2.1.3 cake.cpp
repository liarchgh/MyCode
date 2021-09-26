#include<stdio.h>
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int a1=a,a2=b;
        while(a2){
            int j=a2;
            a2=a1%a2;
            a1=j;
        }
        printf("%d\n",a+b-a1);
    }
    return 0;
}

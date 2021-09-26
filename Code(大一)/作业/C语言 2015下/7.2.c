#include<stdio.h>
int jiecheng(int n)
{
    int i,m=1;
    for(i=1;i<=n;++i)
        m*=i;
    return m;
}
void main()
{
    int m,n,jieguo;
    scanf("%d%d",&m,&n);
    jieguo=jiecheng(m)/jiecheng(n);
    printf("½á¹ûÎª%d¡£",jieguo);
}

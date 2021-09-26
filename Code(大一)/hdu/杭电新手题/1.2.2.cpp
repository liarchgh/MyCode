#include<stdio.h>
int main()
{
    int t,n,m,i,j,a,s;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        s=0;
        scanf("%d %d",&n,&m);
        for(j=0; j<n*m; j++)
        {
            scanf("%d",&a);
            if(a) s++;
        }
        printf("%d\n",s);
    }
}

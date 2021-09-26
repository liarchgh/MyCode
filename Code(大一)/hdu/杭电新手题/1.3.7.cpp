#include <stdio.h>
void paixu(int *b,int n)
{
    int i,j;
    for(j=0; j<n-1; ++j)
        for(i=0; i<n-1; ++i)
            if(b[i]>b[i+1])
            {
                b[i]=b[i+1]+b[i];
                b[i+1]=b[i]-b[i+1];
                b[i]=b[i]-b[i+1];
            }
}
int main()
{
    int t,j,n,i,*p;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    {
        scanf("%d",&t);
        int a[t];
        for(j=0;j<t;++j)
            scanf("%d",&a[j]);
        paixu(a,t);
        for(j=0; j<t; ++j)
        {
            if(a[j]!=a[j-1]||!j)
            {
                printf("%d",a[j]);
                if(j<t-1) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

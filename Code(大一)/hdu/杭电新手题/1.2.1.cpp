#include<stdio.h>
int main()
{
    int n,i,j,m;
    scanf("%d",&n);
    while(n!=0)
    {
        int a[n];
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(i=0; i<n; i++)
        {
            m=0;
            for(j=0; j<n; j++)
            {
                if (a[i]=a[j])
                    m+=1;
            }
            if (m/2)
            {
                printf("%d\n",a[i]);
                break;
            }
        }
        scanf("%d",&n);
    }
    return 0;
}

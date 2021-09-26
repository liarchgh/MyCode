#include<cstdio>

int main()
{
    int a[400000]={0},t,n;
    for(int i=2;i*i<=1000000000;++i)
    {
        int j;
        for(j=0;a[j];++j)
        {
            if(!(i%a[j]))
            {
                j=-1;break;
            }
        }
        if(j!=-1) {a[j]=i;}
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int p=0;
        if(n==4)
        {
            printf("2\n");
            continue;
        }
        for(int i=0;a[i] && a[i]<n;++i)
        {
            if(!(n%a[i]))
            {
                printf("0\n");p=1;break;
            }
        }
        if(!p) printf("%d\n",n-1);
    }
    return 0;
}

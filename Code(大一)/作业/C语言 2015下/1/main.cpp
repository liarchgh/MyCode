#include<stdio.h>
int main()
{
    char a[1000];
    int b[1000],i,k,n,j,m,w;
    while(gets(a)&&a[0]!='\0')/////////////////////////////////////////printf("%s",a);
    {n=0;k=0;////////////////printf("2");
        for(i=0;'\0'!=a[i-1]; ++i)
        {printf("2");
            if('\0'==a[i]||'5'==a[i]&&'5'!=a[i-1])
            {
                b[n]=0;
                for(j=1; j<=i-k; ++j)
                {
                    w=1,m=1;
                    while(m<j)
                    {
                        w*=10;
                        ++m;
                    }
                    b[n]+=(a[i-j]-'0')*w;
                }
                ++n;
            }
            if(a[i]!='\0')
            {if('5'==a[i]&&'5'!=a[i+1]) k=i+1;
        }}
        ////////////////printf("%d",n);
        for(j=0;j<n-1;++j)
        for(i=0; i<n-1; ++i)
        {
            if(b[i]>b[i+1])
            {
                b[i]=b[i+1]+b[i];
                b[i+1]=b[i]-b[i+1];
                b[i]=b[i]-b[i+1];
            }
        }
       //////printf("2");
        for(i=0; i<n; ++i)
        {
            printf("%d",b[i]);
            if(i<n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

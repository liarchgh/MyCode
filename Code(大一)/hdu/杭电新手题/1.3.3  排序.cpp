#include<stdio.h>
int main()
{
    char a[1000];
    int b[1000],i,k=0,n,j,m,w;
    while(gets(a))/////////////////////////////////////////printf("%s",a);
    {n=0;k=0;////////////////printf("2");
        for(i=0;'\0'!=a[i-1]||0==i; ++i)
        {///////printf("2");
            if('\0'==a[i]||'5'==a[i]&&'5'!=a[i-1]&&i!=0)
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
        {if(b[i]==b[i-1]) continue;
            printf("%d",b[i]);
            if(i<n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

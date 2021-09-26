#include<stdio.h>
void main()
{
    int i,n,s[100],*p,m;
    for(n=1;n<=1000;++n)
    {
        //printf("%d\n",n);
        p=s;
        m=0;
        for(i=1;i<=n/2;++i)
            if(0==n%i) {*p=i;p++;}
        *p=0;//printf("%d\n",n);
        for(i=0;s[i]!=0;++i) m+=s[i];
        if(n==m)
            {
                printf("%d its factors are",n);
                for(i=0;s[i]!=0;++i)
                    printf(" %d",s[i]);
                printf("\n");
            }
    }

}

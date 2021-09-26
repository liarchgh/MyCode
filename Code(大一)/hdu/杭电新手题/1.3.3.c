#include<stdio.h>
#include<string.h>
int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    char a[1001];
    int i,j,k,l,len;
    while(scanf("%s",a)!=EOF)
    {
        int b[1001]= {0};
        l=0;
        j=0;
        len=strlen(a);
        for(i=0; i<len; i++)
        {
            if(a[i]!='5')
            {
                b[j]=b[j]*10+(a[i]-'0');
                l=1;
            }
            else
            {
                if(l==1)
                {
                    j++;
                }
                l=0;
            }
        }
        if(l)j++;
        len=j;
        qsort(b, len, sizeof(int), comp);
        for(i=0; i<len-1; i++)
        {
            printf("%d ",b[i]);
        }
        printf("%d\n",b[len-1]);
    }
    return 0;
}

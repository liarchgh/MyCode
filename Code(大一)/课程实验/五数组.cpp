#include<stdio.h>
int main()
{
    int i,a[5]= {1,2,3,4,5},b[5];
    for(i=0; i<5; ++i)
    {
        b[4-i]=a[i];
        printf("%2d",a[i]);
    }
    printf("\n");
    for(i=0; i<5; ++i)
        printf("%2d",b[i]);
    return 0;
}

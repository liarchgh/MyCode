#include<stdio.h>
void main()
{
    int z=1,i,j,a[7][7];
    for (i=0; i<7; ++i)
    {
        for (j=0; j<7; ++j,++z)
            printf("%3d",a[i][j]=z);
        printf("\n");
    }
    for (z=0,i=0; i<7; ++i)
        z+=a[i][i];
    printf("ºÍÎª%d\n",z);
}

#include<stdio.h>
void main()
{
    int i,z=0,f=0;
    while(scanf("%d",&i),i!=0)
        if(i>0) ++z;
        else ++f;
    printf("��%d������,��%d������.",z,f);
}

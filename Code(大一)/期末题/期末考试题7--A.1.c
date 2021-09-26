#include<stdio.h>
void main()
{
    int i,a=0,t;
    FILE *p;//printf("1");
    p=fopen("7.txt","r");
    //printf("1");
    for(i=0;i<200;++i)
    {
        fscanf(p,"%d",&t);
        a+=t;
    }//printf("1");
    a/=200;
    printf("the average is %d.",a);
}

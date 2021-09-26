#include<stdio.h>
void main()
{
    int a;
    FILE *p;
    p=fopen("ken.txt","w");
    for(a=0; a<=200; ++a)
        fprintf(p,"%d%c\n",a,a);
    fclose(p);
}

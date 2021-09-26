#include<stdio.h>
//#include<string.h>
int main()
{
    int i,j;
    char a[80];
    for(j=0;a[j-1]!='#';++j)
       a[j]=getch();printf("1");
    for(j=0;a[j]!='#';++j)
    {printf("2");
        if (a[j]=='!') printf("%%21");
        else if (a[j]==' ') printf("%%20");
        else if (a[j]=='$') printf("%%24");
        else if (a[j]=='%') printf("%%25");
        else if (a[j]=='(') printf("%%28");
        else if (a[j]==')') printf("%%29");
        else if (a[j]=='*') printf("%%2a");
        else printf("%c",a[j]);
    }printf("3");
    printf("\n");
    return 0;
}

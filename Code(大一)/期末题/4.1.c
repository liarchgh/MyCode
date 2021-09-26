#include<stdio.h>
void main()
{
    int a=0,b;
    while(1)
    {
        b=2*a*(2*a+2);
        if(1369==b)
            {printf("the answers are %d and %d",a*2,a*2+2);break;}
        if(1368<b)
            {printf("there isn't answer");break;}
        ++a;
    }
}

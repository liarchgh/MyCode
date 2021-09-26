#include<stdio.h>
int main()
{
    char z;
    long long int a,b,c;
    while(1)
    {
        printf("write the fuhao:");
        scanf("%c",&z);
        if(z=='0') return 0;
        printf("then write the two numbers:\n");
        scanf("%d %d",&a,&b);
        getchar();
        switch(z)
        {
            case '*':c=a*b;break;
            case '/':c=a/b;break;
            case '+':c=a+b;break;
            case '-':c=a-b;break;
            default:printf("it is wrong\n");continue;
        }
        printf("=%d\n",c);
    }
    return 0;
}

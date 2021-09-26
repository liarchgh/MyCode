#include<cstdio>
int main()
{
    float a,sum=0;
    for(int i=0;i<12;++i)
    {
        scanf("%f",&a);
        sum+=a;
    }
    printf("$%.2f\n",sum/12);
    return 0;
}
/*
0
0
0
0
0
0
0
0
0
0
0
*/

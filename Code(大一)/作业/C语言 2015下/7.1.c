#include<stdio.h>
int maxgongyue(int a,int b)
{
    int i;
    for(i=a/2;;--i)
        if(b%i==0&&a%i==0) return i;
}
void main()
{
    int m,n,a,b;
    scanf("%d%d",&a,&b);
    n=maxgongyue(a,b);
    m=a*b/n;//a*b����a��b�����Լ������С�������ĳ˻�
    printf("��С��������%d,���Լ����%d��",m,n);
}

#include<cstdio>

int k;
int jian(int m,int n,int x);//m��ƻ�� n������ �ϸ�����x�� ��һ����������x
int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        k=jian(m,n,1);
        printf("%d\n",k);
    }
    return 0;
}

int jian(int m,int n,int x)//m��ƻ�� n������
{
    if(m==0) return 1;
    if(n==0)
        {
            return 0;
    }
    if(m<x) return 0;
    int sum=0;
    for(int i=x;i<=m;++i)
    {
        sum+=jian(m-i,n-1,i);
    }
    return sum;
}

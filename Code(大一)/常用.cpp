//��С��������
void paixu(int *b,int n)
{int i,j;
    for(j=0;j<n-1;++j)
    for(i=0;i<n-1;++n)
    if(b[i]>b[i+1])
    {b[i]=b[i+1]+b[i];
    b[i+1]=b[i]-b[i+1];
    b[i]=b[i]-b[i+1];}
}
//�����Լ��
int maxgongyue(int a,int b)
{
    int i;
    for(i=a/2;;--i)
        if(b%i==0&&a%i==0) return i;
}
//����n�Ľ׳�
int jiecheng(int n)
{
    int i,m=1;
    for(i=1;i<=n;++i)
        m*=i;
    return m;
}

#include<cstdio>
#include<algorithm>
using namespace std;

int a[9][9];//����
int pan(int n);//�ð�λ��n����ʾ�������̵�λ��ѡ�� ���ÿ��һ��
//���Ϊ��λ���������һλ ������
int qu(int n,int x);//ȡn�ĵ�xλ
int jia(int n,int i,int x);//��n�ڵ���xλ��Ϊi
int main()
{
    int k;
    scanf("%d",&k);
    for(int o=0; o<k; ++o)
    {
        for(int u=1; u<=8; ++u)
            for(int i=1; i<=8; ++i)
                {scanf("%d",&a[u][i]);
                //printf("%d\n",a[u][i]);
                }
        printf("%5d\n",pan(0));
    }
    return 0;
}

int pan(int n)
{
    int b[10]= {0},sum=0;
    for(int i=1; i<=8; ++i)
        {
            b[i]=qu(n,i);
            //printf("%d\n",b[i]);
        }
    int x=1;
    while(b[x]) ++x;
    for(int i=1; i<=8; ++i)
    {
        int p=0;
        for(int j=1; j<x; ++j)
        {
            if(b[j]==i) {p=1;break;}
            if(b[j]-i == j-x || b[j]-i == x-j) {p=1;break;}
        }
        if(p) continue;
        if(x==8) sum=max(sum,a[i][x]);
        else sum=max(sum,pan(jia(n,i,9-x))+a[i][x]);
    }
    return sum;
}

int qu(int n,int x)
{
    x=8-x;
    int z=1;
    while(x--) z*=10;
    return n/z%10;
}

int jia(int n,int i,int x)
{
    //printf("%d %d %d\n",n,i,x);
    while(--x) i*=10;
    //printf("%d\n",i);
    return n+i;
}

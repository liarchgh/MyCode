#include<cstdio>
#include<utility>
using namespace std;

int suan(int first,int t,int wei);//firstΪ��һλ tΪ���ڵ��ӱ����� x��ʣ�»�δ�����λ��
int ans=0,n,m,x;
pair<int,int>weishu;
pair<int,int>pan(int n,int m);//����n��m��λ��
int main()
{
    scanf("%d%d",&n,&m);
    --n,--m;
    weishu=pan(n,m);
    int len=weishu.first + weishu.second;
    if(len>7)
    {
        printf("0\n");
        return 0;
    }
    //printf("%d\n",len);
    x=len;//for(x=2; x<=len; ++x)
    {
        suan(-1,-1,x);
    }
    printf("%d\n",ans);
    return 0;
}

pair<int,int>pan(int n,int m)
{
    int a1=0,a2=0;
    while(n)
    {
        ++a1;
        n/=7;
    }
    while(m)
    {
        ++a2;
        m/=7;
    }
    //printf("%d %d\n",a1,a2);
    if(!a1) a1=1;
    if(!a2) a2=1;
    return make_pair(a1,a2);
}

int pan1(int t,int j)//�ж�t���Ƿ�������j
{
    //if((!t) && (!j)) return 1;
    while(t)
    {
        if(j==t%10) return 1;
        t/=10;
    }
    return 0;
}

pair<int,int>fen(int t,int a1,int a2)//������tǰa1λ�ͺ�a2λ�ֿ�
{
    int t1=0,t2=0;
    while(a2--)
    {
        t2=t2*10+t%10;
        t/=10;
    }
    while(a1--)
    {
        t1=t1*10+t%10;
        t/=10;
    }
    int a=0,b=0;
    for(t=1;t1>0;t*=7,t1/=10) a+=t1%10*t;
    for(t=1;t2>0;t*=7,t2/=10) b+=t2%10*t;
    //printf("%d %d\n",a,b);
    return make_pair(a,b);
}
int suan(int first,int t,int wei)
{
    if(!wei)
    {
        //for(int i=1; i<x; ++i)
        {
            pair<int,int>f=fen(t,weishu.first,weishu.second);

            if(f.first<=n && f.second<=m) {++ans;
            //printf("%d %d %d\n",first,f.first,f.second);
            }
        }
        return 0;
    }
    for(int j=0; j<7; ++j)
    {
        if(wei==x) first=j;
        //printf("%d",first);
        else if((first==j)) continue;
        if(t==-1) suan(first,j,wei-1);
        else if(!pan1(t,j)) suan(first,t*10+j,wei-1);
    }
    //printf("%d\n",wei);
    return 0;
}

/*






Ҫ�õ�������






*/
#include<cstdio>
#include<cstring>
__int64 ans=0;//�� ���������(3�η�֮ǰ��)
const long long mx=1e9+7;//��Ҫȡ�����
void pan(char c);//��λ�ж�
long long jiecheng[6];//�洢3�ĸ��η� �������
int main()
{
    long long x=3;
    for(int i=0;i<6;++i,x*=x)
        {jiecheng[i]=x%mx;
        //printf("%lld\n",jiecheng[i]);
        }
    char s[100000+8];
    gets(s);
    for(int i=0;i<strlen(s);++i)
        pan(s[i]);
        long long jieguo=1;//���ս��
    //pan()�е�ansû�н��дη�����
    for(int i=0;i<=6;++i)
    {
        if((1<<i)&ans) jieguo*=jiecheng[i];
    if(jieguo>=mx) jieguo%=mx;
    }
    printf("%I64d\n",jieguo);
    return 0;
}

void pan(char c)
{
    int t;
    //���������
    if(c>='0' && c<='9')
    {
        t=c-'0';
    }
    else if(c>='A' && c<='Z')
    {
        t=c-'A'+10;
    }
    else if(c>='a' && c<='z')
    {
        t=c-'a'+36;
    }
    else
    {
        switch(c)
        {
            case '-':t=62;break;
            case '_':t=63;
        }
    }
    //printf("%d\n",t);
    for(int i=1;i<64;i<<=1)//��Ϊ��������λ�ж��Ƿ�Ϊ0 ������ans��1
    {
        if(!(i&t)) {++ans;}
    }
}

#include<cstdio>
int main()
{
    int n,d,t,ans=0,sum=0,p;
    char c;
    scanf("%d%d",&n,&d);
    getchar();
    for(int i=0;i<d;++i)//������ѭ��
    {
        p=0;
        for(int j=0;j<n;++j)//���ֵ�ѭ��
        {
            scanf("%c",&c);//ע��0 1֮��û�пո� �ð��ַ�����
            t=c-'0';
            if(!t) p=1;
        }
        getchar();
        if(p) {++sum;ans=ans>sum?ans:sum;}//ÿ�����ɹ���һ �������� ÿ���ж��Ƿ��ø������ֵ
        else sum=0;
    }
    printf("%d\n",ans);
    return 0;
}

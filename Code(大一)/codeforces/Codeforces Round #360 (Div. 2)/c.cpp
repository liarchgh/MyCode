#include<cstdio>
#include<vector>
using namespace std;

const int mx=10e5+5;
vector<int> a[mx];//��̬���������
int m,n,d[mx]= {0},sum[3]= {0},geshu=0;
int cha(int x,int vx);//����ֵΪ1��ʾ�ɹ� 0��ʾʧ�� �����x��ֵΪvx
int main()
{
    int c,b;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&c,&b);
        if(a[c].empty()) ++geshu;//����Ľ�㻹û�����Ļ� �ܽ����+1
        if(a[b].empty()) ++geshu;
        a[c].push_back(b);//������Է����ӽڵ��������Լ�
        a[b].push_back(c);
    }
    int p=1;
    for(int i=1; i<=n; ++i)//ע�� �п����ж������
    {
        if(!d[i] && a[i].size())
            if(!cha(i,1))
            {
                p=0;break;
            }
    }
    if(!p) printf("-1\n");//����һ���ڵ�����㼯1 ��ʼ
    else
    {
        int c[3]= {0};
        for(int j=1; j<=2; ++j)
        {
            printf("%d\n",sum[j]);//������˽�㼯�Ľڵ����
            int i;
            for(i=1; i<=n; ++i)//һ��һ���ڵ�ɨ
                if(d[i]==j)
                {
                    ++c[j];
                    if(c[j]>=sum[j]) break;//�������һ�����˳�ѭ��
                    printf("%d ",i);
                }
            printf("%d\n",i);
        }
    }
    return 0;
}

int cha(int x,int vx)
{
    if(!d[x])//��û�и�ֵ
    {
        d[x]=vx;
        ++sum[vx];//��㼯����+1
        vector<int>::iterator it;
        for(it=a[x].begin(); it!=a[x].end(); ++it)//���������ӽڵ�
        {
            if(!cha(*it,3-vx))
                return 0;
        }
        return 1;
    }
    else//��ֵ����
    {
        if(vx!=d[x]) return 0;
        else return 1;
    }
}

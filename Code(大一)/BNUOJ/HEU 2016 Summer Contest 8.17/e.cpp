//��˵�����prim�㷨 ֱ����һ������ÿ��ֱ�Ӵ浱ǰ��������·���е�Ҫ��ֵ ֮��ÿ�θ���ʱ�ҳ���ֵ������������δ�߹��ڵ�
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double inf=2005.0;
int n,coor[1005][2],vis[1005];
double d[1005];
double dis(int x,int y) {
    double an=(coor[x][0]-coor[y][0])*(coor[x][0]-coor[y][0])+(coor[x][1]-coor[y][1])*(coor[x][1]-coor[y][1]);
    return sqrt(an);
    }
int main() {
    int aaa=1;
    while(scanf("%d",&n),n) {
        for(int i=0; i<n; ++i) {
            vis[i]=0;
            scanf("%d%d",&coor[i][0],&coor[i][1]);
            d[i]=dis(0,i);
            }
        vis[0]=1;//d[1]=inf;
        int mxin;
        for(int iii=1; iii<=n; ++iii) {
                mxin=1;//ע�������ѭ��ʽ�ĳ�ʼ�� ����ʼ����λ��
            for(int i=1; i<n; ++i) {
                if(vis[i]) continue;
                //if(iii==1 && i==1) continue;
                if(!mxin) {
                    mxin=i;
                    }
                else if(d[i]<d[mxin]) {//��дΪ���ں�
                    mxin=i;
                    }
                }
                //printf("     %d\n",mxin);
                vis[mxin]=1;
                if(mxin==1) break;
                for(int i=1;i<n;++i){
                    if(vis[i]) continue;
                    double a=max(d[mxin],dis(mxin,i));
                    d[i]=min(d[i],a);
                }
            }
            printf("Scenario #%d\nFrog Distance = %.3lf\n\n",aaa,d[1]);
            ++aaa;
        }
    return 0;
    }
//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//pair<int ,int> a[200];            //����n��ʯͷ������
//double lowcost[200],closet[200];//Prim�㷨�ر���lowcost[i]��ʾi���뼯�ϵ�������룬closet[i]��ʾi���뼯������ĵ�
//double map[200][200];            //����֮��ľ���
//int main()
//{
//    int n;
//    int k=1;
//    while(cin>>n,n)
//    {
//        int i,j;
//        for (i = 0 ;i < n ; i++ )
//            cin>>a[i].first>>a[i].second;    //����n��������꣬��0��ʼ��Ҳ����˵��Ŀ�����0-1����СFrog Distance
//        memset(lowcost,0,sizeof(lowcost));    //����
//        for ( i = 0 ; i < n ; i ++ )
//        {
//            for ( j = 0 ; j < n ; j ++ )
//            {//����������ľ��룬���浽map��
//                map[i][j]=1.0*sqrt(pow(1.0*abs(a[i].first-a[j].first),2)+pow(1.0*abs(a[i].second-a[j].second),2));
//            }
//        }
//        double ans=0.0;//��Ҫ��Ĵ𰸣���ʼ��Ϊ0
//        for ( i = 0 ; i< n ; i++ )
//        {//��0���뼯�ϣ���㵽���ϵľ����ʱ�ǵ㵽0�ľ���
//            lowcost[i]=map[0][i];
//            closet[i]=0;
//        }
//
//        for ( i = 0 ; i < n - 1 ; i ++ )
//        {
//            double mindis=1.0*(1<<20);        //�㵽������С���룬��ʼ��Ϊ���
//            int minone;                        //��������С�����Ӧ�ĵ�
//            for ( j = 0 ; j < n ; j ++ )
//            {
//                if(lowcost[j]&&mindis>lowcost[j])
//                {//j�㲻�ڼ����У�����j�����ϵľ������С���뻹С���������С����
//                    mindis=lowcost[j];
//                    minone=j;
//                }
//            }
//            if(ans<mindis)        //����𰸲����ȸ��µ���С�����
//                ans=mindis;        //���´�
//            lowcost[minone]=0.0;//���õ��뼯��
//            if(minone==1)        //����ĵ���1����ˮ���彭�ҵ��˴�
//                break;
//            for ( j = 0 ; j < n ; j ++ )
//            {//���¸��㵽���ϵ���С����
//                if(map[j][minone]<lowcost[j])
//                {//���minone��ĳ��j�ľ����ԭ����j�����ϵľ���ҪС������¸õ㵽���ϵľ���Ϊ�ĵ㵽minone�ľ���
//                    lowcost[j]=map[j][minone];
//                    closet[j]=minone;
//                }
//            }
//        }
//        cout<<"Scenario #"<<k<<endl;
//        printf("Frog Distance = %.3f\n\n",ans);
//        k++;
//    }
//    return 0;
//}

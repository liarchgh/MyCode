//Wrong Answer
#include<cstdio>
#include<cmath>
#include<utility>
#include<algorithm>
#define M_PI 3.141592653589

using namespace std;

const int inf=105;
int n;
double ji[inf],ox,oy;//记录每个点以中心为原点的极坐标值中的角度 ox,oy为中心坐标
pair<int,int>di[inf];//记录每个点的笛卡尔坐标系坐标 初始坐标
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&di[i].first,&di[i].second);
        }
        if(n<3 || (di[0].first-di[1].first)*(di[1].second-di[2].second)==(di[1].first-di[2].first)*(di[0].second-di[1].second))
        {
            printf("NO\n");
            continue;
        }
        int a1=2*(di[0].first-di[1].first),a2=2*(di[0].second-di[1].second),
        a3=di[0].first*di[0].first-di[1].first*di[1].first+di[0].second*di[0].second-di[1].second*di[1].second,
        b1=2*(di[1].first-di[2].first),b2=2*(di[1].second-di[2].second),
        b3=di[1].first*di[1].first-di[2].first*di[2].first+di[1].second*di[1].second-di[2].second*di[2].second;
        double d=a1*b2-a2*b1,dx=a3*b2-a2*b3,dy=a1*b3-a3*b1;
        ox=dx/d;oy=dy/d;//printf("%lf %lf\n",ox,oy);
        int p=0;double biao=(di[0].first-ox)*(di[0].first-ox)+(di[0].second-oy)*(di[0].second-oy);
        for(int i=0;i<n;++i)
        {
            double q=(di[i].first-ox)*(di[i].first-ox)+(di[i].second-oy)*(di[i].second-oy)-biao;
            if(q<0) q=-q;
            //printf("%lf\n",(di[i].first-ox)*(di[i].first-ox)+(di[i].second-oy)*(di[i].second-oy));
            if(q>0.00001)
            {
                p=1;break;
            }
        }
        if(p)
        {
            printf("No\n");
            continue;
        }
        for(int i=0;i<n;++i)
        { //printf("%llf %llf %d %d\n",ox,oy,di[i].first,di[i].second);
            ji[i]=atan2((di[i].second-oy),(di[i].first-ox));
        }
        sort(ji,ji+n);
        double v=ji[1]-ji[0];
        //for(int i=0;i<n;++i)
        //printf("%f\n",ji[i]);
        for(int i=0;i<n;++i)
        {//printf("%lf %lf\n",ji[i],v);
            double q=(ji[(i+1)%n]-ji[i]);
            if(q<0) q=-q;
            while(q>M_PI) q-=M_PI;
            q-=v; if(q<0) q=-q;
            if(q>0.001){p=1;break;}
        }
        if(p)
        {
            printf("No\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}

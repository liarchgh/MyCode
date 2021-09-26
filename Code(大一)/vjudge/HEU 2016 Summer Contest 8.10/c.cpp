#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct dot {
    double x,y;
    };
struct lin {
    dot l,r;
    };
bool cmp(dot a,dot b) {
    if(a.x<b.x) return true;
    else if(a.x>b.x) return false;
    else if(a.y<b.y) return true;
    return false ;
    }
bool cmp1(dot a,dot b) {
    if((abs(a.x-b.x)>1e-8 || abs(a.y-b.y)>1e-8))
        return false;
    return true;
        }
dot d[205];
lin line[105];
int n;
bool jiao(lin a,lin b) {
    lin t=a;
    a=b;
    b=t;
    if(((a.l.x-b.l.x) * (b.r.y-b.l.y) - (a.l.y-b.l.y) * (b.r.x-b.l.x)) * ((a.r.y-b.l.y) * (b.r.x-b.l.x) - (a.r.x-b.l.x) * (b.r.y-b.l.y)) > -(1e-8)) return true;
    return false;
    }
bool pan(int a,int b) {
    lin t;
    t.l=d[a];
    t.r=d[b];
    for(int i=0; i<n; ++i) {
        if(!jiao(t,line[i])) return false;
        }
    return true;
    }
int main() {
    int t,p;
    scanf("%d",&t);
    while(t--) {
        p=0;
        scanf("%d",&n);
        for(int i=0; i<n; ++i) {
            cin>>d[i<<1].x>>d[i<<1].y>>d[i<<1|1].x>>d[i<<1|1].y;
            line[i].l.x=d[i<<1].x;
            line[i].l.y=d[i<<1].y;
            line[i].r.x=d[i<<1|1].x;
            line[i].r.y=d[i<<1|1].y;
            }
        sort(d,d+n,cmp);
        for(int i=0; i<(n<<1)-1; ++i) {
            if(cmp1(d[i],d[i+1])) continue;
            for(int j=i+1; j<(n<<1); ++j) {
                if(pan(i,j)) {
                    p=1;
                    break;
                    }
                }
            if(p) break;
            }
        if(p) printf("Yes!\n");
        else printf("No!\n");
        }
    return 0;
    }
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<cmath>
//#include<iostream>
//using namespace std;
//#define eps 1e-8
//#define MAXN (200+10)
//struct P
//{
//	long double x,y;
//	P(){}
//	P(long double _x,long double _y):x(_x),y(_y){}
//}a[MAXN*2];
//struct V
//{
//	long double x,y;
//	V(){}
//	V(long double _x,long double _y):x(_x),y(_y){}
//	V(P a,P b):x(b.x-a.x),y(b.y-a.y){}
//};
//struct S
//{
//	P A,B;
//	S(P _A,P _B):A(_A),B(_B){}
//	S(){}
//};
//double operator*(V a,V b)
//{
//	return a.x*b.y-b.x*a.y;
//}
//bool corr(P A,P B,P C,P D)
//{
//	V AB=V(A,B),AC=V(A,C),AD=V(A,D);
//	return ((AC*AB)*(AB*AD)>-eps);
//}
//bool fabs (double a,double b)
//{
//	if (abs(a-b)<eps) return 1 ;return 0;
//}
//bool fabs(P A,P B)
//{
//	return (fabs(A.x,B.x)&&fabs(A.y,B.y));
//}
//int t,n;
//int main()
//{
////	freopen("poj3304.in","r",stdin);
//	scanf("%d",&t);
//	while (t--)
//	{
//		cin>>n;
//		bool flag=0;
//		for (int i=1;i<=2*n;i++) cin>>a[i].x>>a[i].y;
//		for (int i=1;i<2*n&&!flag;i++)
//		{
//			for (int j=i+1;j<=2*n;j++)
//			{
//				if (fabs(a[i],a[j])) continue;
//				S l=S(a[i],a[j]);
//				int k;
//				for (k=1;k<=n;k++)
//				{
//					if (!corr(l.A,l.B,a[k*2-1],a[k*2])) break;
//				//	cout<<k;
//				}
//				if (k==n+1) {cout<<"Yes!\n"; flag=1;break;}
//			}
//		}
//
//		if (!flag) cout<<"No!\n";
//	}
//	return 0;
//}

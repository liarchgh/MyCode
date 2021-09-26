#include <cstdio>
#include <utility>
#include <iostream>

using namespace std;

pair<int ,int>point[1000005];
int sum;
int main() {
    int t;
    char c,pre;
    scanf("%d",&t);
    getchar();
    point[0]= make_pair(0,0);
    while(t--) {
        sum=0;
        pre=0;
        pair<int,int>po= make_pair(0,0);
        while((c=getchar())!='5') {
            if(pre==0) pre=c;
            else if(pre!=c) {
                ++sum;
                point[sum]=po;
                pre=c;
                }
            switch(c) {
                case '1':
                    --po.first;
                    --po.second;
                    break;
                case '2':
                    --po.second;
                    break;
                case '3':
                    ++po.first;
                    --po.second;
                    break;
                case '4':
                    --po.first;
                    break;
                case '6':
                    ++po.first;
                    break;
                case '7':
                    --po.first;
                    ++po.second;
                    break;
                case '8':
                    ++po.second;
                    break;
                case '9':
                    ++po.first;
                    ++po.second;
                    break;
                }
            //printf("%d %d\n",po);
            }
        getchar();
        long long s=0;
        for(int i=1; i<sum; ++i) {
            double l=(long long)point[i].first*point[i+1].second-(long long)point[i].second*point[i+1].first;
            s+=l;
            //printf("%d %d\n",point[i],point[i].second);
            }
        if(s<0) s=-s;
        if (s/2*2!=s)
			cout<<s/2<<".5"<<endl;
		else
			cout<<s/2<<endl;
        //cout<<s<<endl;
        }
    return 0;
    }
//#include <iostream>
//#include <cmath>
//#include <string>
//using namespace std;
//
//long long dot[10][2]={{0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};
//string step;
//
//long long Area(long long x1, long long y1, long long x2, long long y2){
//	return x1*y2-x2*y1;
//}
//
//int main()
//{
//	int t;
//	cin>>t;
//	for (int i=0; i!=t; i++)
//	{
//		long long x1,x2,y1,y2;
//		long long area=0;
//
//		cin>>step;
//
//		x1=dot[(int)step[0]-48][0];
//		y1=dot[(int)step[0]-48][1];
//		if (step.length()!=1)
//		{
//			for (int j=1; j!=step.length()-1; j++)
//			{
//				x2=x1;
//				y2=y1;
//				x1+=dot[(int)step[j]-48][0];
//				y1+=dot[(int)step[j]-48][1];
//				area+=Area(x1,y1,x2,y2);
//			}
//		}
//		area=(area>0 ? area:(-area));
//		if (area/2*2!=area)
//			cout<<area/2<<".5"<<endl;
//		else
//			cout<<area/2<<endl;
//	}
//	return 0;
//}

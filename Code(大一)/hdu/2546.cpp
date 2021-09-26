//14行的排序是关键 不过心里还是不踏实 总感觉有疏漏
//下面的注释里附上了网上的代码 确实和我思路不一样 是先用5元来买最贵的菜 然后算m-5元时买剩下的菜的最大花销 转化为了普通的01背包 我还是有欠缺啊啊啊啊！！！！
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n,m,co[1005],d[1005];
    while(scanf("%d",&n),n) {
        memset(d,0,sizeof(d));
        for(int i=0; i<n; ++i) {
            scanf("%d",&co[i]);
        }
        sort(co,co+n);
        scanf("%d",&m);
        if(m<5) {
            printf("%d\n",m);
            continue;
        }
        int ans=0;
        for(int j=0;j<=n;++j) {
            ans=max(ans,d[m]);
            if(j==n) break;
            ans=max(ans,d[m-5]+co[j]);
            for(int i=m;i>=co[j];--i){
                if(d[i-co[j]]<=m-5){
                    d[i]=max(d[i],d[i-co[j]]+co[j]);
                }
            }
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
//#include <iostream>
//#include <string.h>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n,m;
//	while(cin>>n&&n){
//		int price[1010];
//		memset(price,0,sizeof(price));
//		for(int i=1;i<=n;i++)
//			cin>>price[i];
//		sort(price+1,price+n+1);
//		int max=price[n];
//		//背包容量m-5，物品数量n-1
//		cin>>m;
//		if(m<5)	cout<<m<<endl;
//		else
//		{
//		int f[1010];//f[j]表示买前i件物品，预算为j时的最大花销
//		memset(f,0,sizeof(f));
//		for(int i=1;i<=n-1;i++)
//			for(int j=m-5;j>=price[i];j--)
//					if(f[j]<f[j-price[i]]+price[i])
//						f[j]=f[j-price[i]]+price[i];
//		 cout<<m-max-f[m-5]<<endl;
//		}
//	}
//	return 0;
//}

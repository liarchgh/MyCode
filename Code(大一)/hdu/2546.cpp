//14�е������ǹؼ� �������ﻹ�ǲ�̤ʵ �ܸо�����©
//�����ע���︽�������ϵĴ��� ȷʵ����˼·��һ�� ������5Ԫ�������Ĳ� Ȼ����m-5Ԫʱ��ʣ�µĲ˵������ ת��Ϊ����ͨ��01���� �һ�����Ƿȱ����������������
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
//		//��������m-5����Ʒ����n-1
//		cin>>m;
//		if(m<5)	cout<<m<<endl;
//		else
//		{
//		int f[1010];//f[j]��ʾ��ǰi����Ʒ��Ԥ��Ϊjʱ�������
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

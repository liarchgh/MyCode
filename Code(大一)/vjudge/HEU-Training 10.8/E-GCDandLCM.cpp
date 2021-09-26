//训练时思路有了偏差 其实当初已经接近了 然而 就是那一点点啊 第一遍写了之后WA了 不知道为什么 瞎调了一会儿过了 应该不是大问题
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <cmath>

using namespace std;

int su[10000] = {2}, num;

void sol(int g, int l) {
	map<int, int>ans;
	ans.clear();
	if (l % g) {
		printf("0\n");
		return;
	}
	int m = l / g;
	int ma = sqrt(m);
	for (int i = 0; su[i] <= ma;) {
		if (m % su[i]) {
			++i;
		}
		else {
			m /= su[i];
			++ans[su[i]];
		}
	}
	if(m > 1){
		ans[m] = 1;
	}
	if(ans.empty()){
		printf("1\n");
		return;
	}
	int zongshu = 1;
	for (map<int, int>::iterator it = ans.begin(); it != ans.end(); ++it) {
		zongshu *= 6 * it->second;
		// printf("%d\n", zongshu);
	}
	printf("%d\n", zongshu);
}

void da() {
	num = 1;
	for (int i = 2; i < 100000; ++i) {
		int p = 1;
		for (int j = 0; j < num; ++j) {
			if (!(i % su[j])) {p = 0; break;}
		}
		if (p) {
			su[num++] = i;
		}
	}
	// printf("%d\n",num);
}

int main() {
// #ifndef ONLINE_JDUGE
// 	// freopen("D:\\in.txt", "r", stdin);
// 	// freopen("D:\\out.txt", "w", stdout);
// 	freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
// 	freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
// #endif
	da();
	int t, g, l;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &g, &l);
		sol(g, l);
	}
	return 0;
}

// #include<iostream>
// #include<cstring>
// #include<string>
// #include<algorithm>
// using namespace std;
// const int maxn=1e7+5;
// bool vis[maxn];
// int  prime[maxn/10],factor[maxn],len=0;

// void is_prime()//素数打表
// {
//     for(int i=2;i<maxn;i++)
//     {
//         if(!vis[i])
//         {
//             prime[len++]=i;
//             for(int j=i+i;j<maxn;j+=i)
//             {
//                 vis[j]=1;
//             }
//         }
//     }
// }

// void getprimefactor(int nn)//得到素数幂指数
// {
//     int cas=0;
//     for(int i=0;i<len&&prime[i]*prime[i]<=nn;i++)
//     {
//             while(nn%prime[i]==0)
//             {
//                 factor[cas]++;
//                 nn/=prime[i];
//             } 
//           if(factor[cas])
//           cas++;
//     }
//     if(nn>1)
//     factor[cas]=1;
// }

// int main()
// {
//     is_prime(); 
//     int t,g,l;
//      scanf("%d",&t);
//      while(t--)
//      {
//         memset(factor,0,sizeof(factor));
//         int sum=1;
//         scanf("%d %d",&g,&l);
//         if(l%g)
//         {
//             printf("0\n");
//             continue;
//          }
//          int k=l/g;
//          getprimefactor(k);

//          for(int i=0;;i++)
//          {
//             if(!factor[i])
//             break;
//             sum*=factor[i];
//             sum*=6;
//          }
//          printf("%d\n",sum);
//       } 
//       return 0;
// }
#include <cstdio>

int t,n,a[100005],sum[100005],x1,x2,dis;
int zhao(int x) { //将x2的所在树更新为x1的子节点
    if(a[x]!=x) a[x]=zhao(a[x]);
    return a[x];
    }
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        if(n==1) {
            printf("1\n");
            continue;
            }
        for(int i = 0; i <=n; ++i) {
            a[i]=i;
            sum[i]=0;
            }
        for(int i = 1; i < n; ++i) {
            scanf("%d%d%d",&x1,&x2,&dis);
            if(!dis && zhao(x1)!=zhao(x2))
                a[zhao(x1)]=a[zhao(x2)];
            }
        for(int i=1; i <=n; ++i) {
            a[i]=zhao(i);
            }
        for(int i=1; i<=n; ++i) {
            ++sum[a[i]];
            }
            for(int i=1; i<=n; ++i) {
            sum[i]=sum[a[i]];
            }
        int ans=-1;
        for(int i=1; i<=n; ++i) {
            if(sum[i])
            {
                if(ans==-1) ans=sum[i];
                else ans=ans^sum[i];
            }
            //printf("%d\n",sum[i]);
            }
            printf("%d\n",ans);
        }
    return 0;
    }

////kengkeng
//#include <ios>
//#include <map>
//#include <set>
//#include <list>
//#include <cmath>
//#include <ctime>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <bitset>
//#include <cctype>
//#include <cerrno>
//#include <cfloat>
//#include <cstdio>
//#include <cwchar>
//#include <iosfwd>
//#include <limits>
//#include <locale>
//#include <memory>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <ciso646>
//#include <climits>
//#include <clocale>
//#include <complex>
//#include <csetjmp>
//#include <csignal>
//#include <cstdarg>
//#include <cstddef>
//#include <cstdlib>
//#include <cstring>
//#include <cwctype>
//#include <fstream>
//#include <iomanip>
//#include <istream>
//#include <numeric>
//#include <ostream>
//#include <sstream>
//#include <utility>
//#include <iostream>
//#include <iterator>
//#include <valarray>
//#include <algorithm>
//#include <exception>
//#include <stdexcept>
//#include <streambuf>
//#include <functional>
//#define Maxn 100005
//#define Maxm 5005
//#define INF 0xffff;
//#define ll long long
//#define Exit exit(0);
//#define Mod 1000000007
//#define PI  3.1415926535898
//#define Pause system("pause");
//#define lson l, mid, rt << 1
//#define rson mid + 1, r, rt << 1|1
//#define debug puts("here is a BUG");
//#define Clear(name, num) memset(name, num, sizeof(name))
//using namespace std;
//
//int father[Maxn];
//
//int find_set(int n) {
//
//    return father[n] == n?n:father[n] = find_set(father[n]);
//}
//
//int main(){
//    int i, t, j, k, m, n;
//    ll res, ans, key, len;
//    int year, mon, day;
//    //char str[Maxn];
//    //int num[Maxm];
//    int sum[Maxn];
////#ifndef ONLINE_JUDGE
////    freopen("F://input.txt","r",stdin);
////#endif // ONLINE_JUDGE
//    int u, v,w;
//    int T;
//    while(~scanf("%d", &T)) {
//        while(T--) {
//            scanf("%d",&n);
//            Clear(sum, 0);
//            for(int i = 1; i <= n; i++) {
//                father[i]=i;
//            }
//
//            for(i = 1; i <= n-1; i++) {
//                scanf("%d%d%d",&u,&v,&w);
//                if(w == 0) {
//                    if(find_set(u) != find_set(v)) {
//                        father[find_set(u)] = find_set(v);
//                    }
//                }
//            }
//            for(i = 1; i <= n; i++) {
//                sum[find_set(i)]++;
//            }
//            for(i = 1; i <= n; i++) {
//                sum[i] = sum[find_set(i)];
//            }
//            res = sum[1];
//            for(i = 2; i <= n; i++) {
//                res =res ^ sum[i];
//                printf("%d\n",sum[i]);
//            }
//            cout << res << endl;
//            }
//    }
//return 0;
//}

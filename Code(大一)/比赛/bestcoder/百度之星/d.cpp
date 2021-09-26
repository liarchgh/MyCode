#include<iostream>
#include<memory.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
typedef long long LL;
using namespace std;
const LL maxn=1e5+10;
char s[maxn];
map<string,int>q;
int main()
{
    int n;
    scanf("%d",&n);
    q.clear();
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        sort(s,s+len);
        printf("%d\n",q[s]++);
    }
    return 0;
}

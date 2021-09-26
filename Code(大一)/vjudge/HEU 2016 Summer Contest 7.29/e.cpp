#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct line
{
    int wei,i;
};
line q[20005];//用于区间离散化 wei为其所在位置 i为其实第几张海报的点 从1开始记录海报 从下标为0开始存 左端点为负 右端点为正
int qj[10005][2];//存入每个海报的区间 从下标为0开始存
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&qj[i][0],&qj[i][1]);
            q[i*2].wei=qj[i][0];q[i*2].i=-i-1;
            q[i*2+1].wei=qj[i][1];q[i*2+1].i=i+1;
        }
        sort(q,q+2*n,cmp);
    }
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::sort;

int n,ans;
const int maxn = 20001;
int POST[maxn][2];
bool vis[maxn];

struct line {
	int val;
	int num;
}Line[maxn];

int dat[4*maxn];

bool cmp(const line & a , const line & b) {
	return a.val < b.val;
}

void init(int cnt) {
	int t = cnt;
	int k = 1;
	while( k < t)
		k *= 2;
	for(int i = 1 ; i <= 2*k - 1 ; i ++)
		dat[i] = 0;
}

void update(int fr , int to , int L , int R , int k , int po) {
	if(to < L || fr > R)
		return;
	else if(fr <= L && to >= R)
		dat[k] = po;
	else
	{
		if(dat[k] > 0)
		{
			dat[2*k] = dat[2*k+1] = dat[k];
			dat[k] = 0;
		}
		int mid = (L+R)>>1;
		update(fr,to,L,mid,2*k,po);
		update(fr,to,mid+1,R,2*k+1,po);
	}
}

void search(int k) {
	if(dat[k])
	{
        if(!vis[dat[k]])
		{
            vis[dat[k]] = true;
            ans++;
        }
        return ;
      }
      search(2*k);
      search(2*k+1);
}

int main() {
	int C;
	scanf("%d",&C);
	while(C--)
	{
		// 输入并离散化
		scanf("%d",&n);
		for(int i = 0 ; i < n ; i ++)
		{
			scanf("%d%d",&POST[i][0],&POST[i][1]);
			Line[2*i].num = -(i+1);
			Line[2*i].val = POST[i][0];
			Line[2*i+1].num = i+1;
			Line[2*i+1].val = POST[i][1];
		}
		sort(Line,Line+2*n,cmp);

		int tmp = Line[0].val, cnt = 1;
		for(int i = 0 ; i < 2*n ; i ++)
		{
			if(Line[i].val != tmp)
			{
				tmp = Line[i].val;
				cnt ++;
			}
			if(Line[i].num < 0)
				POST[-Line[i].num-1][0] = cnt;
			else
				POST[Line[i].num-1][1] = cnt;
		}

		init(cnt);
		for(int i = 0 ; i < n ; i ++)
			update(POST[i][0],POST[i][1],1,cnt,1,i+1);

		memset(vis,0,sizeof(vis));
		ans = 0;

		search(1);
		printf("%d\n",ans);
	}
	return 0;
}
*/

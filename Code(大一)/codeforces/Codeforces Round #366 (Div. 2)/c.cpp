#include <cstdio>
#include <queue>

using namespace std;

int main(){
    //printf("111111\n");
    int n,q,a[300005]={0},read[300005]={0},x,y,has_read=0,num=0,done[300005]={0};
    queue<int>qu;
    scanf("%d%d",&n,&q);
    for(int i=0;i<q;++i)
    {
        scanf("%d%d",&x,&y);
        switch(x)
        {
        case 1:
            ++a[y];
            ++num;
            qu.push(y);
            break;
        case 2:num-=a[y]-read[y];
            read[y]=a[y];
            break;
        case 3:
            int t=y-has_read;
            while(!qu.empty() && t-->0){
                ++has_read;
                x=qu.front();
                qu.pop();
                ++done[x];
                if(done[x]>read[x])
                {
                    ++read[x];
                    --num;
                }
            }
            break;
        }
        printf("%d\n",num);
    }
    return 0;
}
//#include<cstdio>
//#include<queue>
//using namespace std;
//const int maxn = 300005;
//int needread[maxn];
//int readed[maxn];
//int cnt[maxn];
//int main()
//{
//    int n,q,type,num,pop_cnt = 0;
//    queue<int> que;
//    scanf("%d %d", &n, &q);
//    int ans = 0;
//    while (q--)
//    {
//        scanf("%d %d", &type, &num);
//        if (type == 1)
//        {
//            ans++;
//            needread[num]++;
//            que.push(num);
//        }
//        else if (type == 2)
//        {
//            ans -= needread[num] - readed[num];
//            readed[num] = needread[num];
//        }
//        else
//        {
//            int t = num - pop_cnt;
//            while (!que.empty() && t > 0)
//            {
//                t--;
//                int cur = que.front();
//                que.pop();
//                pop_cnt++;
//                cnt[cur]++;
//                if (cnt[cur] > readed[cur])
//                {
//                    ans --;
//                    readed[cur] ++;
//                }
//            }
//        }
//        printf("%d\n",ans);
//    }
//    return 0;
//}

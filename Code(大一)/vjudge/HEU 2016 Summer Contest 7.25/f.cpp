#include<cstdio>
#include<deque>
using namespace std;

deque<int>dq;
int main()
{
    int t,n,m,x;
    char ord[15];
    scanf("%d",&t);
    for(int i=1; i<=t; ++i)
    {
        printf("Case %d:\n",i);
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%s",ord);
            switch(ord[4])
            {
            case 'L':
                scanf("%d",&x);
                if(dq.size()==n) printf("The queue is full\n");
                else
                {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n",x);
                }
                break;
            case 'R':
                scanf("%d",&x);
                if(dq.size()==n) printf("The queue is full\n");
                else
                {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n",x);
                }
                break;
            case 'e':
                if(dq.empty()) printf("The queue is empty\n");
                else
                {
                    printf("Popped from left: %d\n",dq.front());
                    dq.pop_front();
                }
                break;
            case 'i':
                if(dq.empty()) printf("The queue is empty\n");
                else
                {
                    printf("Popped from right: %d\n",dq.back());
                    dq.pop_back();
                }
                break;
            }
        }
        dq.clear();
    }
    return 0;
}

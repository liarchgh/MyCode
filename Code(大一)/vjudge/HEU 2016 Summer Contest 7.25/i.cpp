#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>d;
int main()
{
    int s,n,m,a;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        s=n+m;
        while(s--)
        {
            scanf("%d",&a);
            d.push_back(a);
        }
        sort(d.begin(),d.end());
        a=0;
        //printf("%d  ",d.size());
        for(int i=0; i<d.size(); ++i)
        {
            if(i && d[i]==d[i-1])
            {
                d.erase(d.begin()+i);
                --i;
            }
        }
        for(int i=0; i<d.size()-1; ++i) printf("%d ",d[i]);
        printf("%d\n",d[d.size()-1]);
        d.clear();
    }
    return 0;
}

#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<int>a;
    for(int x=2;x<=100;++x)
    {
        if(a.empty()) a.push_back(x);
        else
        {
            int p=1;
            for(vector<int>::iterator it=a.begin();it!=a.end();++it)
            {
                if(!(x%(*it))) {p=0;break;}
            }
            if(p) a.push_back(x);
        }
    }
    printf("%d\n",a.size());
    return 0;
}

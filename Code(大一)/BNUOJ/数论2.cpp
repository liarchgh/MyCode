#include<algorithm>
#include<cstdio>
using namespace std;
int in[40005],su[250005]={0};
void dabiao()
{
    for(int i=2;i<250005;++i)
    {
        if(!su[i])
            for(int j=i*2;j<250005;j+=i)
                su[j]=1;
    }
}
int main()
{
    dabiao();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int a=0;
        scanf("%d",&in[a++]);
        while(getchar()!='\n')
            scanf("%d",&in[a++]);
        sort(in,in+a);

    }
}

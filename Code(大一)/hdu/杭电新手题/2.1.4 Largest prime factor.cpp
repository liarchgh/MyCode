#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=1000000;
int x[MAX];
int main()
{
	int n,m,i,j,sum;
	memset(x,0,sizeof(x));
	x[1]=0;
	sum=0;
	for(i=2;i<MAX;i++)
	{
		if(!x[i])
		{
			++sum;
			for(j=i;j<MAX;j+=i)
			x[j]=sum;
		}
	}
	while(scanf("%d",&n)!=EOF)
	printf("%d\n",x[n]);
	return 0;
}

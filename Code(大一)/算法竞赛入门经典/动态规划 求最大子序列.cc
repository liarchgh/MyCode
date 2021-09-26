#include<cstdio>
int main()
{
	int m,sum,n,T;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&m);
			sum+=m;
			if(0>sum) sum=0;
		}
		printf("The most big sum is %d.\n",sum);
	}
	return 0;
}
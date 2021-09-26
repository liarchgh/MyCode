#include<stdio.h>
int main()
{
	int t,n,i,j,k,h;
	scanf("%d",&t);
	for(i=0;i<t;++i)
	{
		scanf("%d",&n);
		int a[n][2];
		//printf("AE");
		for (j=0;j<n;++j)
		{
			scanf("%d %d",&a[j][0],&a[j][1]);
		}
		//printf("BE");
		for(j=0;j<n;++j)
		for(k=0;k<n-1;++k)
		{	
		   if(a[k][0]>a[k+1][0]) 
			{
				a[k][0]+=a[k+1][0];
				a[k+1][0]=a[k][0]-a[k+1][0];
				a[k][0]=a[k][0]-a[k+1][0];
				a[k][1]+=a[k+1][1];
				a[k+1][1]=a[k][1]-a[k+1][1];
				a[k][1]=a[k][1]-a[k+1][1];
			}
		
		}
		//printf("CE");
		for(j=0;j<n;++j)
		{
			for(k=0;k<a[j][1];++k)
			{
				printf(">+");
				for(h=0;h<a[j][0]-2;++h)
				{printf("-");
				}
				printf("+>\n");
			}
			if(j<n-1) printf("\n");
		}
	}
	return 0;
}

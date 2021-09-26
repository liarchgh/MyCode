#include<stdio.h>
int main()
{int d,e,f,sum,p,q,i,j;
	scanf("%d%d%d",&d,&e,&f);
	int a[100][100],b[100][100],mul[100][100];
	for(i=0;i<d;++i)
	for(j=0;j<e;++j)
	scanf("%d",&a[i][j]);	
	for(i=0;i<e;++i)
	for(j=0;j<f;++j)
	scanf("%d",&b[i][j]);
									//		for(i=0;i<d;++i)
									//	for(j=0;j<e;++j)	printf("%d",a[i][j]);
									//		for(i=0;i<e;++i)
									//	for(j=0;j<f;++j)
									//	printf("%d",b[i][j]);
	for(p=0;p<d;++p)
	for(q=0;q<f;++q)
	{sum=0;
	for(i=0;i<e;++i)
		sum+=a[p][i]*b[i][q];
	mul[p][q]=sum;
	}
	for(p=0;p<d;++p)
	{for(q=0;q<f;++q)
	printf("%d",mul[p][q]);
	printf("\n");
	}
return 0;}

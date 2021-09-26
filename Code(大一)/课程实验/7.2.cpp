#include<atdio.h>
int jiecheng(int a)
{
	int b=1,i;
	for(i=1;i<=a;++i)
	{
		b*=i;
	}
	return b;
}
int main()
{
	int s,a,b;
	scanf("%d%d",&a,&b);
	s=jiecheng(a)/jiecheng(b);
	printf("%d",s);
	return 0;
}

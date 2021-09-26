#include<stdio.h>
int gong(int a,int b)
{
	int c;
	if(a<b) c=a;
	else c=b;
	for(;;--c)
	if(0==a%c&&0==b%c) break;
	return c;
}
int main()
{
	int a,b,s;
	scanf("%d%d",&a,&b);
	s=gong(a,b);
	printf("%d",s);
	return 0;
}

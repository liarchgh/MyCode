#include<stdio.h>
void main()
{
	int p,a,b,a1,b1,n=1,i,z=0,s;
	scanf("%d",&s);
	for(z=0;;z++)
	{if(s/n==0) break;
	n=n*10;
	}
	if(z%2==0)
	{for(n=0;n<z/2;n++){
		a=z/2+n+1;b=z/2-n;a1=1;b1=1;
		for(i=1;i<a;i++)
			a1=a1*10;
		for(i=1;i<b;i++)
			b1=b1*10;
		if(s/a1%10==s/b1%10)
			p=1;
		else {p=0;break;}
	}
	}else 
	{for(n=0;n<(z+1)/2;n++)
	{
		a=(z+1)/2+n;
		b=(z+1)/2-n;
		a1=1;
		b1=1;
		for(i=1;i<a;i++)
			a1=a1*10;
		for(i=1;i<b;i++)
			b1=b1*10;
		if(s/a1%10==s/b1%10)
			p=1;
		else {p=0;break;}
		
		
	}}
	if(p)
		printf("是对称数");
	else 
		printf("不是对称数");
	}
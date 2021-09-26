#include<stdio.h>
void main()
{int i,n,a,b,c;a=b=c=0;
for(i=0;i<20;i++)
scanf("%d",&n);
if(n>0&&n<=30) a++;
else if(n>=31&&n<=60) b++;
else if(n>=61&&n<=90) c++;
else;
printf("1~30的数有%d个\n31~60的数有%d个\n61~90的数有%d个\n",a,b,c);
}

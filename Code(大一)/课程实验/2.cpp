#include<stdio.h>
void main()
{int n,s;
for(s=100;s<1000;s++)
{n=s/11;
if(n==s%10*(s%10)+(s/10%10)*(s/10%10)+s/100*(s/100))
printf("%d\n",s);}	}
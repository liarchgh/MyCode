#include <stdio.h>
int main()
{int m;
scanf("%d",&m);
int a[m],b[m],i;
for(i=0;i<m;i++)
scanf("%d %d",&a[i],&b[i]);
for(i=0;i<m;i++)
printf("%d\n",a[i]+b[i]);
	return 0;
}
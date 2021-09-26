#include<stdio.h>
int main()
{
	int i,m,sum;
	char a[100];
	gets(a);
	for(m=0;;++m)
		if (a[m]=='\0') break;
	for(i=0;i<m;++i)
		if (a[i]<='Z') a[i]+=32;
	puts(a);return 0;
}
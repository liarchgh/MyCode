#include<stdio.h>
double cha(int n)
{double s=0;int a;
for (a=1;a<n;a++)
    s=s+1/a;
    return s;
	}
void main()
	{double s;
	s=cha(50)+cha(100);
	printf("%8.2f",s);
		}

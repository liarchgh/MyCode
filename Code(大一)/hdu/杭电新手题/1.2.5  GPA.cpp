#include<stdio.h>
int main()
{
    char a,b;
    int i,n=0,ai;
    while(1)
    {b=' ';n=0;
        for(i=ai=0; b!='\n'; ++i)
        {
            if(scanf("%c",&a)==EOF) {n=2;break;}b=getchar();//printf("%c",a);
            if (a=='A') ai+=4;
            else if (a=='B') ai+=3;
            else if (a=='C') ai+=2;
            else if (a=='D') ai+=1;
            else if (a=='F') ai+=0;
            else n=1;
        }if (n==2) {break;}
        if (n) printf("Unknown letter grade in input\n");
        else printf("%.2f\n",(double)(ai)/i);
        i=ai=0;
    }
    return 0;
}

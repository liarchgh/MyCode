/*#include<cstdio>

int main()
{
    int t,ty,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&ty,&n,&m);
        int x=(n-1)*2/3-(m-1)/3;
        int y=n-1-x*2,c,d;
        switch(ty)
        {
        case 1:
            c=n>m?n:m;
            d=n+m-c;
            --c;--d;
            if(c%2)
                if(d%2) printf("B\n");
                else printf("G\n");
            else printf("G\n");
            break;

        case 2:
            if(n<=2 || m<=2) printf("B\n");
                else printf("G\n");
            break;

        case 3:
            if(2*y+x!=m-1) printf("D\n");
            else if((x+y)%2) printf("B\n");
            else printf("G\n");
            break;

        case 4:
            printf("B\n");
            break;
        }
    }
    return 0;
}*/

#include<cstdio>

int main()
{
    int t,ty,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&ty,&n,&m);
        int x=(n-1)*2/3-(m-1)/3;
        int y=n-1-x*2,c;
        switch(ty)
        {
        case 1:
            c=n>m?n:m;
            --c;
            if(c%2) printf("B\n");
            else printf("G\n");
            break;

        case 2:
            printf("G\n");
            break;

        case 3:
            if(2*y+x!=m-1 || 2*x+y!=n-1 || x<0 || y<0) printf("D\n");
            else if((x+y)%2) printf("B\n");
            else printf("G\n");
            break;

        case 4:
            if(n!=m) printf("G\n");
            else printf("B\n");
            break;
        }
    }
    return 0;
}

#include<cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y,ta;
        scanf("%d%d%d",&x,&y,&ta);
        y-=ta;
        if(x>y) printf("do not advertise\n");
        else if(x == y) printf("does not matter\n");
        else printf("advertise\n");
    }
    return 0;
}

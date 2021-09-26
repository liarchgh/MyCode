#include<cstdio>

int main() {
    int t;
    scanf("%d",&t);
    for(int i=1;i<t;++i)
    {
        if(i&1) printf("I hate that ");
        else printf("I love that ");
    }
    if(t&1)
    printf("I hate it\n");
    else printf("I love it\n");
    return 0;
    }

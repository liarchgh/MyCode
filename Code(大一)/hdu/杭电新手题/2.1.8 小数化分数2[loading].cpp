#include<cmath>
#include<cstdio>
#include<cstring>
const int maxn = 33000;
int su[maxn],sushu[10000];
void dabiao()
{
    memset(su,0,sizeof(su));
    for(int i=2;i<=maxn;++i)
        if(!su[i])
            for(int j=2*i;j<=maxn;j+=i)
                su[j]=1;
    int m=0;
    for(int j=2;j<maxn;++j)
        if(!su[j]) sushu[m++]=j;
}
void huajian(int &a,int &b)
{
    if(b%a==0)
    {
        b/=a;a=1;
    }
    else
    {
        int c=sqrt(a),d=sqrt(b);
        for(int i=0; sushu[i]<=c && sushu[i]<=d; ++i)
            while(!(a%sushu[i] || b%sushu[i]))
                a%=sushu[i],b%=sushu[i];
    }
}
int main()
{
    dabiao();
    int t;
    char shu[15];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        int ok=0,i,a[2]={0,0};
        scanf("0.%s",shu);getchar();
        int l=0,r;
        for(i=0;shu[i]!='\0';++i)
        {
            if(shu[i]=='(') {l=i;ok=1;}
            if(shu[i]==')') r=i;
        }
        if(!ok) l=i;
        for(int j=0;j<l;++j)
            {
                a[0]=a[0]*10+shu[j]-'0';
            }
        if(l!=i)
        {
           for(int j=l+1;j<r;++j)
            {
                a[0]=a[0]*10+shu[j]-'0';
                a[1]=a[1]*10+9;
            }
        }
        else a[1]=1;
        int j=0;
        while(!(shu[j]-'0') && j<l) ++j;
        for(;j<l;++j)
            a[1]*=10;
        huajian(a[0],a[1]);
        printf("%d/%d\n",a[0],a[1]);
    }
    return 0;
}

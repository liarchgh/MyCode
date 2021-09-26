#include<stdio.h>
int fun(int a[100],int m,int n)
{
    int i,sum=0;
    for(i=0;i<m;++i)
    {
        sum+=(a[i*n+0]+a[i*n+(n-1)]);printf("%d\n",sum);
    }
    for(i=0;i<n;++i)
    {
        sum+=(a[i]+a[(m-1)*n+i]);printf("%d\n",sum);
    }
    sum-=(a[0]+a[(m-1)*n+n-1]+a[(m-1)*n+0]+a[n-1]);printf("%d\n",sum);
    return sum;
}
void main()
{
    int j,i,m,n;
    scanf("%d*%d",&m,&n);
    int a[m][n];
    for(i=0;i<m;++i)
    for(j=0;j<n;++j){
    scanf("%d",&a[i][j]);printf("%d\n",a[i][j]);}
    i=fun(a,m,n);
    printf("%d\n",i);
}

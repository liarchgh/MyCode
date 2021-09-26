#include<cstdio>
int main(){
    int i,j,t,n,o,m,z,b[5005];
    scanf("%d",&t);
    for(o=0;o<t;++o){
        scanf("%d",&n);
        if(n==0) {printf("0\n");continue;}
        int a[n][2];
        for(i=0;i<n;++i){
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        for(i=0;i<n-1;++i){
            m=i;
            for(j=i+1;j<n;++j)
                if(a[m][0]>a[j][0]) m=j;
                else if((a[m][0]==a[j][0])&&a[m][0]<a[j][0])
                    m=j;
            if(m!=i){
                    z=a[m][0];a[m][0]=a[i][0];a[i][0]=z;
                    z=a[m][1];a[m][1]=a[i][1];a[i][1]=z;
        }}
        b[0]=0;m=1;
        for(i=1;i<n;++i){
            for(j=0;j<m;++j){
                if(a[i][1]>=a[b[j]][1]){
                    b[j]=i;j=-1;break;
                    }
                }
                if(j!=-1) {
                    ++m;b[m-1]=i;
                }
            }
            printf("%d\n",m);
        }
    return 0;
}


//ǣ��������ѧ֪ʶ ��֪���ò��ü�ס ��
//t=n/2;nΪ����ʱ �������������� 2*t*t+2*t �� 2*t*t+2*t
//        nΪż��ʱ �������������� t*t-1 �� t*t+1
#include <cstdio>

int main(){
    long long n,a,b,t;
    scanf("%I64d",&n);
    if(n==1 || n==2){
        printf("-1\n");return 0;
    }
    t=n>>1;
    if(n&1){
        a=2*t*t+2*t;
        b=a+1;
    }
    else{
        a=t*t-1;
        b=t*t+1;
    }
    if(b*b==a*a+n*n){
        printf("%I64d %I64d\n",a,b);
    }
    else    printf("-1\n");
    return 0;
}

//Ӧ���й�ʣ�ඨ��
//n �� b1 mod a1,n �� b2 mod a2,n �� b3 mod a3
//�����a2*a3*x1 �� 1 mod a1,a1*a2*x2 �� 1 mod a3,a1*a3*x3 �� 1 mod a2�е�x1,x2,x3
//Ȼ��x1=a2*a3*x1,x2=a1*a2*x2,x3=a1*a3*x3
//n����Сֵ����(x1*b1+x2*b2+x3*b3) mod lcm(b1*b2*b3)
//�⼯����n+x*lcm(b1*b2*b3),x��N
#include<cstdio>

const int T=21252;
int main()
{
    long long int p,e,i,d,ca=1;
    while(scanf("%lld%lld%lld%lld",&p,&e,&i,&d),d!=-1||e!=-1||i!=-1||d!=-1)
    {

        long long ans=(5544*p+14421*e+1288*i)%(23*28*33);
        ans=(ans-d+23*28*33)%(23*28*33);
        if(!ans) ans=23*28*33;
        printf("Case %lld: the next triple peak occurs in %lld days.\n",ca++,ans);
    }
    return 0;
}

#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int>ph;
map<int,int>ma;
int main()
{
    int t;
    char m[10][3]={{},{},
        {'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},
        {'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
        ma['1']=1;ma['0']=0;
    for(int i=2;i<=9;++i)
    {
        ma[i+'0']=i;
        for(int j=0;j<3;++j)
            {ma[m[i][j]]=i;
            //printf("%c %d",m[i][j],ma[m[i][j]]);
            }
    }
    scanf("%d",&t);
    getchar();
    if(t==0) return 0;
    int num;
    char c;
    while(t--)
    {
        num=0;
        for(int i=0;i<7;++i)
        {
            c=getchar();
            if(c=='-') {--i;continue;}
            num=num*10+ma[c];
        //cout<<num<<endl;
        }
        while(getchar()!='\n');
        ph.push_back(num);
    }
    sort(ph.begin(),ph.end());
    int sum=1,p=0;
            int a1,a2,a,b1,b2;
             //for(vector<int>::iterator it=ph.begin();it!=ph.end();++it) printf("%d    ",*it);
    for(vector<int>::iterator it=ph.begin();it!=ph.end();++it)
    {
        //printf("           %d",*it);
        if(it!=ph.end()-1 && *it==*(it+1))
        {
            ++sum;
        }
        else if(sum>1)
        {
            b1=b2=a1=a2=0;a=*it;
            for(int i=1;i<=4;++i)
            {
                a2=a2*10+a%10;
                a/=10;
            }
            for(int i=1;i<=4;++i)
            {
                b2=b2*10+a2%10;
                a2/=10;
            }
            for(int i=1;i<=3;++i)
            {
                a1=a1*10+a%10;
                a/=10;
            }
            for(int i=1;i<=3;++i)
            {
                b1=b1*10+a1%10;
                a1/=10;
            }
            printf("%03d-%04d",b1,b2);
             if(sum>1 && !p) ++p;
             printf(" %d\n",sum);
            sum=1;
        }
    }
    if(!p) printf("No duplicates. \n");
    return 0;
}

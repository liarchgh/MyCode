//һ����ά�������� Ȼ���տ�ʼû������ ��������Ϊ����λ�������ռ� ������һ��������һ���������Ƕ�ά���� �е�low
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int d[1605][1605]= {1};
int main() {
    int n,a,sum=0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&a);
        sum+=a;
        for(int ii=501; ii>=0; --ii) {
            for(int j=501; j>=0; --j) {
                if(d[ii][j]) {
                    d[ii+a][j]=d[ii][j+a]=1;
                    }
                }
            }
        }
    int ans=0;
    double p=(double)(sum)/2;
    for(int ii=501; ii>0; --ii) {
        for(int j=501; j>0; --j) {
            if(ii && j && sum-ii-j && ((ii+j)<<1)>sum && abs(ii-j) < sum-ii-j && d[ii][j]) {
                ans=max(ans,(int)sqrt(p*(p-ii)*(p-j)*(p-sum+ii+j)*10000));
        //printf("%d %d %d\n",ii,j,ans);
                }
            }
        }
        if(ans)
        printf("%d\n",ans);
        else printf("-1\n");
    return 0;
    }

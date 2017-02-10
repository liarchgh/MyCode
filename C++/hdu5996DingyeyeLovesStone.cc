//����Կ��������� Ȼ���þ�û���� �������ǲ����� �����ᡣ�������������nim ��������������-_-
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 100000 + 5;
int fa[mx], dep[mx];

int main()
{
    //freopen("in.cc", "r", stdin);
    //freopen("out.cc", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        dep[0] = 0;
        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; ++i)
        {
            scanf("%d", &fa[i]);
            dep[i] = dep[fa[i]] + 1;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int a;
            scanf("%d", &a);
            if(dep[i] % 2)
            {
                ans ^= a;
            }
        }
        if(ans) printf("win\n");
        else printf("lose\n");
    }
    return 0;
}

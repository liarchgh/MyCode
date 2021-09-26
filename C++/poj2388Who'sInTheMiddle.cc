//直接用STL做的 毫无问题
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 10000 + 5;
int milk[mx];

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; ++i){
        scanf("%d", &milk[i]);
    }
    sort(milk, milk + num);
    printf("%d\n", milk[num / 2]);
    return 0;
}

//http://118.190.20.162/view.page?gpid=T51
//这题做着有些讨厌人啊 细节处理不到位就死定了
#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

const double fee[7] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
const int line[7] = {0, 1500, 4500, 9000, 35000, 55000, 80000}, num_line = 7, do_begin = 3500;

int main(){
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
    int t, th;
    scanf("%d",&t);
    if(t <= do_begin){
        printf("%d\n", t);
        return 0;
    }
    t -= do_begin;
    double s = t;
    for(th = 0; th < num_line - 1; ++th){
        if((line[th + 1] - line[th]) * fee[th] + s >= line[th + 1]){
            s += (line[th + 1] - line[th]) * fee[th];
        }
        else{
            break;
        }
//        printf("%.0f %.0f\n", s, (line[th + 1] - line[th]) * fee[th]);
    }
//        printf("%.0f %.0f\n", s, (s - line[th]) / (1 - fee[th]));
    s = line[th] + (s - line[th]) / (1 - fee[th]);
//        printf("%.0f %.0f\n", s, (s - line[th]) / (1 - fee[th]));
    printf("%.0f\n", s + do_begin);
    return 0;
}


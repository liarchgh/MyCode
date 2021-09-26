#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

const int mx = 15;

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    //直接通过数组来存储 减少代码量
    int order[2][14] = {{15, 5, 6, 3, 4, 11, 12, 13, 14, 7, 8, 9, 10, 1},
        {15, 3, 4, 5, 6, 11, 12, 13, 14, 9, 10, 7, 8, 2}},
        val[14] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 1},
        num[mx + 1];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int sum = 0, mark = 0, cur = 1, beg[2] = {0, 0};
        int src[2] = {0, 0};
        for(int j = 1; j <= mx; ++j){
            scanf("%d", &num[j]);
            sum += num[j];
        }
        while(sum > 0){
            cur = !cur;
            //beg数组存放两个人分别走到哪一个图了
            //mark存放alice比bob多的步数
            while(beg[cur] < mx - 1 && !num[order[cur][beg[cur]]]){
                ++beg[cur];
            }
            if(beg[cur] < mx - 1){
                int now = beg[cur];
                mark += val[now] * (cur?-1:1);
                --num[order[cur][now]];
                mark += - 2 * cur + 1;
                //对sum的控制折磨了我一下午 应该确定占过一张图后才减一 之前直接在while语句中使用自减一一直wrong 还找不出来错 难受
                --sum;
            }
            // for(int i = 0; i < mx - 1; ++i){
            //     if(num[order[cur][i]] == 0) continue;
            //     if(val[i]
            // }
        }
        printf("Case #%d: ", i + 1);
        if(mark > 0){
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}

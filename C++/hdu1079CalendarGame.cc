#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
using namespace std;

const int target = 20011104;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31,
    31, 30, 31, 30, 31};

map<int, int>sg;
//0为必败 1为必胜

void format(int& y, int& m, int& d){
    //第一遍交的时候闰年判断错误T^T
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
        day[2] = 29;
    }
    else{
        day[2] = 28;
    }
    while(m <= 12 && d > day[m]){
        d -= day[m];
        ++m;
    }
    while(m > 12){
        ++y;
        m -= 12;
    }
    // cout<<"for:"<<y<<' '<<m<<' '<<d<<endl;
}

int calSg(int y, int m, int d){
    format(y, m, d);
    int key = y * 10000 + m * 100 + d;
    if(sg.find(key) != sg.end()){
        return sg[key];
    }
    if(key > target){
        sg[key] = 1;
        return 1;
    }
    if(key == target) return sg[key]=0;
    set<int>meg;
    meg.insert(calSg(y, m, d + 1));
    if(day[m + 1 % 13] >= d){
        meg.insert(calSg(y, m + 1, d ));
    }
    // for(set<int>::iterator it = meg.begin(); it != meg.end(); ++it){
    //     cout<<*it<<endl;
    // }
    if(meg.find(0) != meg.end()){
        sg[key] = 1;
    }
    else{
        sg[key] = 0;
    }
    return sg[key];
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
#endif
    //输出找错
    // int y = 1998, m = 1, d = 1;
    // for(; y <= 2001; ++d){
    //     format(y, m, d);
    //     cout<<y<<' '<<m<<' '<<d<<' '<<
    //         calSg(y, m, d)<<endl;
    // }
    int t;
    scanf("%d", &t);
    while(t--){
        int y, m, d;
        scanf("%d%d%d", &y, &m, &d);
        if(calSg(y, m, d) > 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

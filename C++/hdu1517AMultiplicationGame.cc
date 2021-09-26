#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
/*
const int mxn = 30, mxm = 8, muler[mxm] = {2, 3, 4, 5, 6, 7, 8, 9};
int n;

int calSg(int now){
    if(now >= n) return 0;
    set<int>meg;
    for(int i = 0; i < mxm; ++i){
        meg.insert(calSg(now * muler[i]));
    }
    set<int>::iterator it = meg.begin();
    for(int i = 0; i <= n + 1; ++i){
        while(it != meg.end() && *it < i){
            ++it;
        }
        if(it == meg.end() || *it != i) return i;
    }
}
*/
int main(){
    #ifndef ONLINE_JUDGE
    freopen("d:/in.ls", "r", stdin);
    freopen("d:/out.ls", "w", stdout);
    #endif // ONLINE_JUDGE
    /*
    n = 500;//n/16~n/8
    for(n = 1; n < 1000; ++n){
        cout<<n<<'\t'<<calSg(1)<<endl;
    }
    */
    //18^x*9+1~18^x*18�Ǳذ�̬
    double n;//���λ��ڳ����ж�ʧ��Ϣ
    while(~scanf("%lf", &n)){
        while(n > 18){
            n /= 18;
        }
        if(n<=9){
            printf("Stan wins.\n");
        }
        else{
            printf("Ollie wins.\n");
        }
    }
    return 0;
}

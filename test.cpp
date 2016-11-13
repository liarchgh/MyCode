#include <map>
#include <cstdio>

using namespace std;

int main(){
   map<int,int>a;
   a[1] = a.size();
   printf("%d\n", a[1]);
   return 0;
}
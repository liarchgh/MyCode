//ɵ���� ��һ��len1 len2 û���ñ��������� ֱ�ӵ���strlen()���� ֱ�ӳ�ʱ ������bug
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 200000;
char s1[mx], s2[mx];

int main(){
	while(~scanf("%s%s", s1, s2)){
		int len, cha = 0, len1 = strlen(s1), len2 = strlen(s2);
		for(len = 0; len < len1 && len + cha < len2; ++len){
			if(s1[len] != s2[len + cha]){
				--len;
				++cha;
			}
		}
		if(len == len1){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	//system("pause");
	return 0;
}

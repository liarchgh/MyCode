#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int mx = 10001;
char ss[mx + 3];

void sol(int th, char * s, int len){
	if(!len){
		printf("%d\n", th);
		return;
	}
	while(*s == '0') {++s;--len;}
	char st[len + 3];
	strncpy(st, s, len / 2 + (len & 1));
	int l, r;
	for(l = len / 2, r = len / 2 + (!(len & 1)); r < len; ++r,--l){
		st[r] = st[l];
	}
	while(l < r){
		if(s[r] < st[r]){
			st[l] = st[r] = s[r];
			break;
		}
		--r;++l;
	}
	for(int i = 0; i < len; ++i){
		s[i] = s[i] - st[i] + '0';
	}
	sol(th + 1, s + l + 1, len - l - 1);
	s[len] = '\0';
	puts(s);
}

int main(){
    #ifndef ONLINE_JDUGE
    freopen("D:\\in.txt", "r", stdin);
    freopen("D:\\out.txt", "w", stdout);
    #endif
    int t;
    scanf("%d\n", &t);
    for(int i = 1; i <= t; ++i){
    	printf("Case #%d:\n", i);
    	gets(ss);
    	sol(0, ss, strlen(ss));
    }
    return 0;
}
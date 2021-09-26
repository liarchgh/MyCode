//思路很正确 只是数组开小了 T^T
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int num = 26;
char ss[50005];
int shu[num];

bool pan(int st){
	memset(shu, 0, sizeof(shu));
	int loa = 0, has = 0;
	for(int i = st; i < st + num; ++i){
		if(ss[i] == '?'){
			++loa;
		}
		else{
			if(!shu[ss[i] - 'A']) ++has;
			++shu[ss[i] - 'A'];
			if(shu[ss[i] - 'A'] >= 2) return false;
		}
	}
	// /printf("%d %d\n", has, loa);
	if(has + loa == num){
		for(int i = st; i < st + num; ++i){
			if(ss[i] == '?'){
				char j;
				for(j = 'A'; j <= 'Z'; ++j){
					if(!shu[j - 'A']){
						++shu[j - 'A'];
						break;
					}
				}
				ss[i] = j;
			}
		}
		return true;
	}
	return false;
}

void chu(){
	for(int i = 0; i < strlen(ss); ++i){
		if(ss[i] == '?') ss[i] = 'A';
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("D:\\in.txt", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);
	#endif
	gets(ss);
	int len = strlen(ss);
	for(int i = 0; i <= len - num; ++i){
		//printf("%d\n", i);
		if(pan(i)){
			chu();
			puts(ss);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

#include <cstdio>
#include <stdlib.h>

using namespace std;

struct man{
	int num;//, password;
	man * next;
	man(int x, man * p){num = x;next = p;}
};

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	man * point = NULL, * head = NULL;
	for(int i = n; i >= 1; --i){
		// man* now = new man(i + 1, point);
		man* now = (man*)malloc(sizeof(man));
		now->num = i;
		now->next = point;
		point = now;
		if(i == 1){
			head->next = now;
			head = head->next;
		}
		else if(head == NULL){
			head = now;
		}
		//printf("%d\n", point->num);
	}
	point = head;
	while(head != NULL){
		int num = m;
		man * fr = point;
		while(--num){
			fr = point;
			point = point->next;
		}
		man* del = point;
        if(del == head) head = head->next;
		printf("%d\n", point->num);
		point = point->next;
		if(fr == point) {printf("%d\n", point->num);break;}
		free(del);
		fr->next = point;
	}
	return 0;
}

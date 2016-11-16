#include <cstdio>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct man {
	int num;//, password;
	man * next;
	// man(int x, man * p) {num = x; next = p;}
};

man * build(int n) {
	if (n < 1) return NULL;
	man * head = (man*)malloc(sizeof(man)), * p = NULL;
	head->num = n;
	head->next = NULL;
	p = head;
	for (int i = n - 1; i >= 1; --i) {
		// man* now = new man(i + 1, point);
		man* now = (man*)malloc(sizeof(man));
		now->num = i;
		now->next = p;
		p = now;
		//printf("%d\n", point->num);
	}
	head->next = p;
	return head;
}

void kill(man * point, int m) {
	if(m <= 0){
		printf("No man will die.\n");
	}
	if(point == NULL){
		printf("There is no man.\n");
		return ;
	}
	man* del;
	while (point->next != point) {
		int num = m;
		while (--num) point = point->next;
		del = point->next;
		point->next = point->next->next;
		printf("%d\n", del->num);
		free(del);
	}
	printf("%d\n", point->num);
	free(point);
}

int main() {
	freopen("/home/ls/Downloads/MyCode/in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	kill(build(n), m);
	return 0;
}


// #include <cstdio>
// #include <stdlib.h>

// using namespace std;

// struct man{
// 	int num;//, password;
// 	man * next;
// 	man(int x, man * p){num = x;next = p;}
// };

// int main(){
// 	int n, m;
// 	scanf("%d%d", &n, &m);
// 	man * point = NULL, * head = NULL;
// 	for(int i = n; i >= 1; --i){
// 		// man* now = new man(i + 1, point);
// 		man* now = (man*)malloc(sizeof(man));
// 		now->num = i;
// 		now->next = point;
// 		point = now;
// 		if(i == 1){
// 			head->next = now;
// 			head = head->next;
// 		}
// 		else if(head == NULL){
// 			head = now;
// 		}
// 		//printf("%d\n", point->num);
// 	}
// 	point = head;
// 	while(head != NULL){
// 		int num = m;
// 		man * fr = point;
// 		while(--num){
// 			fr = point;
// 			point = point->next;
// 		}
// 		man* del = point;
//         if(del == head) head = head->next;
// 		printf("%d\n", point->num);
// 		point = point->next;
// 		if(fr == point) {printf("%d\n", point->num);break;}
// 		free(del);
// 		fr->next = point;
// 	}
// 	return 0;
// }
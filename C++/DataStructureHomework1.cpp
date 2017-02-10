#include <cstdio>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct man {
	int num;
	man * next;
};

man * build(int n) {
	if (n < 1) return NULL;
	man * head = (man*)malloc(sizeof(man)), * p = NULL;
	head->num = n;
	head->next = NULL;
	p = head;
	for (int i = n - 1; i >= 1; --i) {
		man* now = (man*)malloc(sizeof(man));
		now->num = i;
		now->next = p;
		p = now;
	}
	head->next = p;
	return head;
}

void kill(man * point, int m) {
	if(m <= 0){
		printf("没有人会出队列！\n");
	}
	if(point == NULL){
		printf("队列中没有人！\n");
		return ;
	}
	man* del;
	int th;
	for (th = 1; point->next != point;) {
		int num = m;
		while (--num) point = point->next;
		del = point->next;
		point->next = point->next->next;
		printf("第%d个出队列的人的编号是%d。\n", th++, del->num);
		free(del);
	}
	printf("第%d个出队列的人的编号是%d。\n", th, point->num);
	free(point);
}

int main() {
	int n, m;
	printf("请输入队列中的总人数：\n");
	scanf("%d", &n);
	printf("请输入出队列的周期：\n");
	scanf("%d", &m);
	kill(build(n), m);
	getchar();
	getchar();
	return 0;
}

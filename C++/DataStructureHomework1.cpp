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
		printf("û���˻�����У�\n");
	}
	if(point == NULL){
		printf("������û���ˣ�\n");
		return ;
	}
	man* del;
	int th;
	for (th = 1; point->next != point;) {
		int num = m;
		while (--num) point = point->next;
		del = point->next;
		point->next = point->next->next;
		printf("��%d�������е��˵ı����%d��\n", th++, del->num);
		free(del);
	}
	printf("��%d�������е��˵ı����%d��\n", th, point->num);
	free(point);
}

int main() {
	int n, m;
	printf("����������е���������\n");
	scanf("%d", &n);
	printf("����������е����ڣ�\n");
	scanf("%d", &m);
	kill(build(n), m);
	getchar();
	getchar();
	return 0;
}

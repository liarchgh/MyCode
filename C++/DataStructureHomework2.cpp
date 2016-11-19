#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <ctime>

using namespace std;

const char huf_file[3][15] = {"\\HufTree.dat", "\\HufCode.txt", "\\CodeFile.dat"};
const int len_way = 200;

struct HTNode {
	int weight, parent, lchild, rchild;
	void ch(int w, int x, int y, int z) {
		weight = w;
		parent = x;
		lchild = y;
		rchild = z;
	}
};
struct JyTree {
	int x;
	JyTree * lchild, * rchild;
	JyTree(int a, JyTree *q, JyTree * w) {
		x = a;
		lchild = q;
		rchild = w;
	}
};

void cut_way(char * p) {
	char * st = p - 1;
	while (*(p + 1) != '\0') ++p;
	while (p != st && *p == '\\') *(p--) = '\0';
}

void cat_way(char * p) {
	cut_way(p);
	int i = 2;
	for (char * q = p + len_way * 3; q > p; q -= len_way, --i) {
		strcpy(q, p);
		strcat(q, &huf_file[i][0]);
		//puts(q);
		// long long now = time(NULL);
		// while(time(NULL) - now < 6) ;
	}
}

void HuffmanCoding(HTNode * &HT, char * * &HC, int * w, int n) {
	if (n <= 1) {
		return ;
	}
	int m = 2 * n - 1;
	HT = (HTNode *)malloc((m + 1) * sizeof(HTNode));//略去0位置
	int i = 1;
	HTNode * p = HT + 1;
	for (; i <= n; ++i, ++p, ++w) (*p).ch(*w, 0, 0, 0);
	for (; i <= m; ++i, ++p) (*p).ch(0, 0, 0, 0);
	// for (i = 1; i <= m; ++i) printf("---%c %d\n", i - 1, HT[i].weight);
	for (i = n + 1; i <= m; ++i) {
		int s1 = 0, s2 = 0;
		for (int j = 1; j < i; ++j) {
			if (!HT[j].parent)
				if (!s1) s1 = j;
				else if (!s2 || HT[s1].weight >= HT[j].weight) {
					s2 = s1;
					s1 = j;
				}
		}
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	// for(int i = 0, s1 = 0, s2; i <= m; ++i){
	// 	if(!HT[i].parent){
	// 		if(!s1) s1 = i;
	// 		else s2 = i;
	// 	}
	// 	if(i >= m){
	// 		HT[0].lchild = s1;
	// 		HT[0].rchild = s2;
	// 	}
	// }
	HC = (char * *)malloc((n + 1) * sizeof(char *));//HC从下标1开始使用 HC[i]从下标0开始使用
	char * cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) {
		int st = n - 1;
		for (int c = i, f = HT[i].parent; f; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) cd[--st] = '0';
			else cd[--st] = '1';
		}
		HC[i] = (char *)malloc((n - st) * sizeof(char));
		strcpy(HC[i], &cd[st]);
		// printf("%c %s\n", i - 1, HC[i]);
		// if (i - 1 == 'a' || i - 1 == 's' || i - 1 == 'd') {
		// 	long long now = time(NULL);
		// 	while (time(NULL) - now < 5) {}
		// }
	}
	free(cd);
}

void yasuo() {
	char in[len_way], out[4][len_way];
	printf("请输入需要压缩的文件的路径：\n");
	scanf("%s", in);
	printf("请输入相关文件的存放路径：\n");
	scanf("%s", out[0]);
	printf("压缩中......\n");
	cat_way((char *)out);
	freopen(in, "r", stdin);
	int w[270] = {0};
	int num = 0;
	for (char c; (c = getchar()) != EOF;) {
		++w[c];
		++num;
	}
	// for(int i = 0; i < 256; ++i) printf("%c %d\n", i, w[i]); getchar();
	HTNode * HT;
	char * * HC;
	HuffmanCoding(HT, HC, w, 256);
	cout << 1 << endl;
	freopen(out[1], "w", stdout);
	// printf("下标\t权值\t父母节点\t左子节点\t右子节点\n");
	for (int i = 0; i <= 2 * 256 - 1; ++i) {
		printf("%d\t%d\t%d\t%d\t%d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	freopen(out[2], "w", stdout);
	for (int i = 1; i <= 256; ++i) {
		printf("%s\n", HC[i]);
		// printf("%d\t%c\t%s\n", i - 1, i - 1, HC[i]);
	}
	// printf("ASCII码\t字符\t哈夫曼编码\n");
	freopen(in, "r", stdin);
	freopen(out[3], "w", stdout);
	// for(int i = 0; i <= 256 * 2 + 1; ++i){
	// 	printf("%d %c %d %d %d\n", i, i, HT[i].parent, HT[i].lchild, HT[i].rchild);
	// }
	for (char c; (c = getchar()) != EOF;) {
		// putchar(c);
		printf("%s", HC[c + 1]);
	}
	putchar(EOF);
}

void jieya() {
	char in[4][len_way], out[len_way];
	printf("请输入需要解压的相关文件的路径：\n");
	scanf("%s", in[0]);
	printf("请输入解压文件的存放路径：\n");
	scanf("%s", out);
	printf("解压中......\n");
	cat_way((char *)in);
	//cout << "kai" << endl;
	freopen(in[2], "r", stdin);
	// scanf("ASCII码\t字符\t哈夫曼编码\n");
	JyTree head(-999, NULL, NULL), * p;
	// while(getchar() != '\t') ;while(getchar() != '\t') ;
	for (int i = 0; i < 256; ++i) {
		p = &head;
		// while (getchar() != '\t') ; getchar(); getchar();
		for (char c; (c = getchar()) != '\n';) {
			if (c == '1') {
				if (p -> rchild == NULL) {
					p -> rchild = (JyTree *)malloc(sizeof(JyTree));
					p -> rchild-> lchild = p -> rchild-> rchild = NULL;
					p -> rchild-> x = -999;
				}
				p = p -> rchild;
			} else {
				if (p -> lchild == NULL) {
					p -> lchild = (JyTree *)malloc(sizeof(JyTree));
					p -> lchild -> lchild = p -> lchild -> rchild = NULL;
					p -> lchild -> x = -999;
				}
				p = p -> lchild;
			}
		}
		p -> x = i;
	}
	p = &head;
	freopen(in[3], "r", stdin);
	freopen(out, "w", stdout);
	for (char c; (c = getchar()) != EOF;) {
		// cout << c << endl;
		if (c == '0') p = p -> lchild;
		else p = p -> rchild;
		if (p -> x != -999) {
			putchar(p -> x);
			p = &head;
		}
	}
}

int main() {
	char op;
	//while
	(printf("请选择需要的功能:\n0：压缩文件\n1：解压文件\n2：-->退出<--\n"), op = getchar(), op != '2');
	{
		getchar();
		switch (op) {
		case '0':
			yasuo();
			break;
		case '1':
			jieya();
			break;
		default:
			printf("非法输入，请重新尝试！\n");
		}
	}
	// printf("程序运行结束\n");
	return 0;
}

/*
0
D:\in.txt
D:\

D:\\CodeFile.dat
D:\\HufCode.txt
D:\\HufTree.dat

1
D:\
D:\out.txt

*/

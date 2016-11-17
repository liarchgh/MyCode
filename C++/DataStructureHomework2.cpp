#include <cstdio>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

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

void HuffmanCoding(HTNode * &HT, char * * &HC, int * w, int n) {
	if (n <= 1) {
		return ;
	}
	int m = 2 * n + 1;
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
				else if (HT[s1].weight >= HT[j].weight) {
					s2 = s1;
					s1 = j;
				}
		}
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	HC = (char * *)malloc((n + 1) * sizeof(char *));//HC从下标1开始使用 HC[i]从下标0开始使用
	char * cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i) {
		int st = n - 1;
		for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) cd[--st] = '0';
			else cd[--st] = '1';
		}
		HC[i] = (char *)malloc((n - st) * sizeof(char));
		strcpy(HC[i], &cd[st]);
	}
	free(cd);
}

void yasuo() {
	char in[200], out[200];
	printf("请输入需要压缩的文件的路径：\n");
	cin >> in;
	printf("请输入压缩文件的存放路径：\n");
	cin >> out;
	cout << "压缩中......" << endl;
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
	//cout << 1 << endl;
	freopen(out, "w", stdout);
	for (int i = 1; i <= 256; ++i) {
		printf("%s\n", HC[i]);
	}
	freopen(in, "r", stdin);
	for (char c; (c = getchar()) != EOF;) {
		printf("%s", HC[c + 1]);
	}
	putchar(EOF);
}

void jieya() {
	char in[200], out[200];
	printf("请输入需要解压的文件的路径：\n");
	scanf("%s", in);
	printf("请输入解压文件的存放路径：\n");
	scanf("%s", out);
	printf("解压中......\n");
	freopen(in, "r", stdin);
	//cout << "kai" << endl;
	// freopen(out, "w", stdout);
	JyTree head(-1, NULL, NULL), * p;
	for (int i = 0; i < 256; ++i) {
		p = &head;
		for (char c; (c = getchar()) != ' ';) {
			if (c == '1') {
				if (p -> rchild == NULL) {
					p -> rchild = (JyTree *)malloc(sizeof(JyTree));
					p -> rchild-> lchild = p -> rchild-> rchild = NULL;
					p -> rchild-> x = -1;
				}
				p = p -> rchild;
			} else {
				if (p -> lchild == NULL) {
					p -> lchild = (JyTree *)malloc(sizeof(JyTree));
					p -> lchild -> lchild = p -> lchild -> rchild = NULL;
					p -> lchild -> x = -1;
				}
				p = p -> lchild;
			}
		}
		p -> x = i;
	}
	p = &head;
	for (char c; (c = getchar()) != EOF;) {
		// cout << c << endl;
		if (c == '0') p = p -> lchild;
		else p = p -> rchild;
		if (p -> x >= 0) {
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
D:\\in.txt
D:\\out.txt

D:\\CodeFile.dat
D:\\HufCode.txt
D:\\HufTree.dat

1
D:\\out.txt
D:\\in.txt

*/

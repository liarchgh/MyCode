#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#define ONLINE_JUDGE
using namespace std;
const int mxq = 35;
int ans[mxq][5];
char name[105];

int main()
{
//#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
//#endif // ONLINE_JUDGE
  int num_q, num_m;
  scanf("%d", &num_q);
  memset(ans, 0, sizeof(ans));
  char c;
  for(int i = 0, x; i < num_q; ++i)
  {
  scanf("%d ", &x);
  while((c = getchar()) != '\n')
  {
  ans[i][c - 'A'] = 1;
  ++ans[i][4];
  }
  }
  scanf("%d\n", &num_m);
  for(int i = 0, x; i < num_m; ++i)
  {
  gets(name);
  printf("%s: ", name);
  int rig, wro, fen = 0;//rig此题选对的个数 wro此题选错的个数
  char c;
  for(int j = 0; j < num_q; ++j)
  {
  rig = wro = 0;
  scanf("%d ", &x);
  while((c = getchar()) != '\n')
  {
  if(ans[j][c - 'A']) ++rig;
  else ++wro;
  //printf("%c\n", c);
  }
  if(!(wro + rig)) continue;
  if(wro) fen += 0;
  else if(rig < ans[j][4]) fen += 3;
  else fen += 6;
  }
  printf("%d\n", fen);
  }
  return 0;
}

/*
Judge Answers
TimeLimit: 1 Second   MemoryLimit: 32 Megabyte
Totalsubmit: 64   Accepted: 18
Description

Little Huang has an elder brother called Big Huang, working as a physics teacher in Harbin Engineering High School. The school did a practice test yesterday. Big Huang is responsible for judging the choices. But number of students is too large, it's impossible to finish the work before the deadline. So, he wants a program to do the job.
Here is the rule of judging choices:
Each question has four choices, while its correct answer contains at least one choice. Score for one question is 6.
Let's assume that the answer of a question is "AB". If the student's answer is totally right, which should be "AB", he can get full mark. If the answer is nothing like "", or contains at least one wrong choice like "ABC", "AC", "C", he can't get any score. Other situations he can get half mark, which is 3.
Input

Input contains only one test case.
The first line is a positive integer n less than 30, shows there are n questions in total. Next n lines are the correct answer. Each line begins with the number i, from 1 to n. Then a space and the answer without being separated.
The (n+2)th line is a positive integer m no more than 10,000, represents the number of students. There are m groups of answers following. Each group starts with the student's name and ends with his answer. The form of answer is the same as the correct answers'.
You may assume that all answers are strings only contains the four characters or nothing, while its length is no more than 4. The names of student are simple, while they may include spaces. The length of each name is no more than 100.
If you are confused about the input, come to the Sample Input for help.
Output

For each student, print a line in this form "name: score".
Sample Input

2
1 A
2 CD
4
Huang Yuhe
1 C
2 BCD
Xu Rongchen
1 A
2 CD
Li Haixiao
1 B
2 C
Yuan Kengkeng
1
2

Sample Output

Huang Yuhe: 0
Xu Rongchen: 12
Li Haixiao: 3
Yuan Kengkeng: 0
Hint

Think clearly the way to judge for each answer. I think you have done well in string processing because you are here. This is the final challenge of strings for today. If you find out your program is doing wrong, just relax and try to find bugs. Other hints have been given before.
Source

yrc
*/
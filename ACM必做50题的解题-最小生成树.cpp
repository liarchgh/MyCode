﻿POJ 1251 Jungle Roads


小感：
第一次做图论题目，而且一次就AC了，挺兴奋的，呵呵。当然，还有很多不是非常明白的地方，对算法很细节的执行还没有非常明白~还有就是，Prim算法的过程好像是选出一个点后，找该点与剩下的点的权值的最小值，而不是所有在U中的点与V - U中的点的最小值。开始时觉得应该是所有U中的与V - U中最小的值的~还得再看看~
这里用了Prim求最小生成树，图是用邻接矩阵表示的，算法复杂度为O(n2)，其实看书上的例子，是用邻接表实现的，而且用到了最小堆求权值最小的边，最后的复杂度为O(elog2e)，e为边数。总的过程是从V - U中选出到U中权值最小的点，并加到U，之后更新lowcost，被更新的lowcost只是在V - U中的。
还有就是关于scanf，开始时用，可是在输入的时候有问题，不知道怎么回事~看别人也都说scanf会RE等的，于是用了cin，结果0MS就可以过了~还有，也看到有人说用了26时，RE了，所以我就改成27了，也不知道26到底会不会错~

#include <iostream>
#define MAX 27
#define MAXCOST 101
using namespace std;

int vertices[MAX], lowcost[MAX], minv, totalcost;
int edges[MAX][MAX];
bool visited[MAX];

int prim(int vertex_num, int v)
{
  totalcost = 0;
  visited[v] = true;
  for (int i = 0; i < vertex_num; i++)
    lowcost[i] = edges[v][i];
  for (int i = 1; i < vertex_num; i++)
  {
    minv = MAXCOST;
    //for选出从U中顶点到V-U中顶点的最小权值，每次从第一个开始

    //这样如果碰到边界顶点时，可以回到另外的点

    for (int j = 0; j < vertex_num; j++)
      if (visited[j] == false && lowcost[j] < minv) //lowcost[j]是从顶点v到顶点j的权值
      {
        minv = lowcost[j];
        v = j;
      }
    visited[v] = true;
    totalcost += minv;
    for (int j = 0; j < vertex_num; j++)
      if (visited[j] == false && edges[v][j] < lowcost[j])
        lowcost[j] = edges[v][j];
  }
  return totalcost;
}

int main()
{
  int num, degree, cost;
  char vertex;
  while (cin >> num)
  {
    if (num == 0) break;
    for (int i = 0; i < num; i++) vertices[i] = i;
    for (int i = 0; i < num; i++)
      for (int j = 0; j < num; j++)
        edges[i][j] = MAXCOST;
    for (int i = 0; i < num; i++) visited[i] = false;
    for (int i = 0; i < num - 1; i++)
    {
      cin >> vertex >> degree;
      for (int j = 0; j < degree; j++)
      {
        cin >> vertex >> cost;
        edges[i][vertex - 'A'] = cost;
        edges[vertex - 'A'][i] = cost;
      }
    }
    cout << prim(num, 0) << endl;
  }
  return 0;
}




POJ 1258 Agri - Net

Slyar: 简单介绍一下题意。农民要建立互联网络，目的使村庄里所有的农民连上网，并且总费用最小。多组数据，每组数据给出一个n，然后给出n * n大小的无向图的邻接矩阵表示，值表示边权。要求输出最小生成树的权值和。

这次用朴素的Prim写。

Prim详见 http://www.slyar.com/blog/prim-simplicity-c.html


#include <stdio.h>
#include <stdlib.h>

#define MAX 101
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

int Prim(int graph[][MAX], int n)
{
  int lowcost[MAX];
  int mst[MAX];
  int i, j, min, minid, sum = 0;
  for (i = 2; i <= n; i++)
  {
    lowcost[i] = graph[1][i];
    mst[i] = 1;
  }
  mst[1] = 0;
  for (i = 2; i <= n; i++)
  {
    min = MAXCOST;
    minid = 0;
    for (j = 2; j <= n; j++)
    {
      if (lowcost[j] < min && lowcost[j] != 0)
      {
        min = lowcost[j];
        minid = j;
      }
    }
    sum += min;
    lowcost[minid] = 0;
    for (j = 2; j <= n; j++)
    {
      if (graph[minid][j] < lowcost[j])
      {
        lowcost[j] = graph[minid][j];
        mst[j] = minid;
      }
    }
  }
  return sum;
}

int main()
{
  int i, j, k, m, n;
  int cost;

  while (scanf("%d", &n) != EOF)
  {
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        graph[i][j] = MAXCOST;
      }
    }
    for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
      {
        scanf("%d", &graph[i][j]);
      }
    }
    cost = Prim(graph, n);
    printf("%d\n", cost);
  }

  return 0;
}



poj 1789 Truck History 最小生成树

题意：n的卡车，每辆车拥有唯一的7位车牌号。两两之间车牌号的有几位不相同就表示有多大的差别，即两代之间的距离有多远，求联通所有带的最短距离和。

题解：理解题意后不难发现就是一个简单的最小生成树。

和原来低效的prim写法不同的是用mdis [i]来更新到每个点的最小边，这样可以省去一层循环。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99999

int n, dis[2010][2010], in[2010], dif, ans, mdis[2010];
char a[2010][7];

void prim()
{
  int i, j, k, min, v;
  ans = 0;
  memset(in, 0, sizeof(in));
  in[1] = 1 ;
  for (i = 1; i <= n; i++)
    mdis[i] = dis[1][i];
  for (i = 1; i < n; i++)
  {
    min = MAX;
    for (j = 1; j <= n; j++)
      if (!in[j] && mdis[j] < min)
      {
        v = j;
        min = mdis[j];
      }

    ans += min;
    if (!in[v]) in[v] = 1;
    for (k = 1; k <= n; k++)
      if (!in[k] && mdis[k] > dis[v][k])
        mdis[k] = dis[v][k];
  }

}
int main()
{
  int i, j, k;

  while (scanf("%d", &n), n)
  {
    getchar();
    for (i = 1; i <= n; i++)
    {
      gets(a[i]);

      for (j = 1; j < i; j++)
      {
        dif = 0;
        for (k = 0; k < 7; k++)
          if (a[i][k] != a[j][k])
            dif++;
        dis[i][j] = dis[j][i] = dif;
      }
      dis[i][i] = MAX;
    }
    prim();
    printf("The highest possible quality is 1/%d.\n", ans);
  }
}


poj 2485 Highways

一看就知是最小生成树，开始的时候用Kruskal出问题，改用Prim过了POJ，现在回过头来用Kruskal算法做，也好，又过了。发出来，或许也会有像我这样曾经被这个问题搞郁闷的朋友。问题抽象一个下就是求Kruskal算法中最后加入的那条边的长度，同样是Prim算法中加入的边的最长的那条。

prim解法：

#include <iostream>
using namespace std;

int highway[501][501];
int lowcost[501], n;

int prim()
{
  for (int i = 1; i <= n; i++)
    lowcost[i] = highway[1][i];
  int ans = 0, nextVex, minEdge;
  for (int i = 1; i < n; i++) {
    minEdge = 999999999;
    nextVex = 1;
    for (int j = 1; j <= n; j++) {
      if ((lowcost[j] < minEdge) && (lowcost[j] > 0)) {
        minEdge = lowcost[j];
        nextVex = j;
      }
    }
    if (minEdge > ans)
      ans = minEdge;
    lowcost[nextVex] = 0;
    for (int j = 1; j <= n; j++) {
      if (lowcost[j] > highway[nextVex][j]) {
        lowcost[j] = highway[nextVex][j];
      }
    }
  }
  return ans;
}
int main()
{
  int tcase;
  scanf("%d", &tcase);
  while (tcase--)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        scanf("%d", &highway[i][j]);
    printf("%d\n", prim());
  }
  return 0;
}


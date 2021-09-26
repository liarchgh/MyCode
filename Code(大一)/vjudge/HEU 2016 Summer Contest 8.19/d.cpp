//�Ҳ���һ��BFS���� ��Ȼ�� ˼·����F��Jһ���� һ��һ�ֵ��� ����Ϊ�ջ��ܳ�ȥ�˾�ͣ ��������˼·��̫һ�� -_- ���һ������56�е��Լ� WA�˺þ� ����ѧ���ҳ���94�еĴ������� ����ѧ���� ԭ������F��J���е�ʱ������ F�յ�һ����֮���ͣ���� ��ʵӦ�ü����ߵ�
#include <cstdio>
#include <queue>

using namespace std;

const int tr[4][2]= {{0,-1},{0,1},{1,0},{-1,0}};
int t,g[1005][1005],a[1000005],b[1000005];
int main() {
    scanf("%d",&t);
    int num;
    while(t--) {
        int r,c;
        num=0;
        queue<pair<int,int> >q;
        scanf("%d%d",&r,&c);
        getchar();
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                switch(getchar()) {
                    case '#':
                        g[i][j]=-1;
                        break;
                    case 'J':
                        g[i][j]=0;
                        q.push({i,j});
                        break;
                    case 'F':
                        g[i][j]=-1;
                        a[num]=i;
                        b[num++]=j;
                        break;
                    case '.':
                        g[i][j]=0;
                        break;
                    }
                }
            getchar();
            }
        for(int i=0; i<num; ++i) {
            q.push({a[i],b[i]});
            }
        int p=0;
        while(!q.empty()) {
//            for(int i=0; i<r; ++i) {
//                for(int j=0; j<c; ++j) {
//                    printf("%d\t",g[i][j]);
//                    }
//                putchar('\n');
//                }
//            putchar('\n');
            int x=q.front().first,y=q.front().second;
            q.pop();
            int v=g[x][y];
            if(v==-2) {
                ++g[x][y];
                continue;
                }
            //printf("%d %d\n",x,y);
            if(v>=0) ++v;
            for(int i=0; i<4; ++i) {
                int t1=x+tr[i][0],t2=y+tr[i][1];
                if(t1>=r || t1<0 || t2>=c || t2<0) {
                    if(v>=0) {
                        printf("%d\n",v);
                        p=1;
                        break;
                        }
                    else {
                        continue;
                        }
                    }
                int &d=g[t1][t2];
                if(d==-1 || d==-2) continue;
                if(d) {
                    if(v==-1) {
                        d=-2;
                        q.push({t1,t2});
                        }
                    }
                else {
                    d=v;
                    q.push({t1,t2});
                    }
                }
            if(p) break;
            }
        if(!p) {
            printf("IMPOSSIBLE\n");
            }
        }
    return 0;
    }
/*
1
13 6
##..#.
......
....#.
.#..#.
##....
...#F.
.#.J.#
.#....
......
....#.
#....#
.##...
...##.

*/

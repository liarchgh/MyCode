//��ʼ������25-29�е����� һֱû�ҵ��������� ����������� �����Լ��ڽ��������»���Ե����п�ͷ���������� ɵ����
#include <cstdio>
#include <fstream>

using namespace std;

const int mx = 35;
int matrix[2][mx][mx];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cc", "r", stdin);
    freopen("out.cc", "w", stdout);
#endif // ONLINE_JUDGE
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &matrix[0][i][j]);
            if(i > 1 && matrix[0][i][j] == matrix[0][i - 1][j] && matrix[0][i][j] == matrix[0][i - 2][j])
            {
                matrix[1][i - 2][j] = matrix[1][i - 1][j] = matrix[1][i][j] = 0;
                if(j > 1 && matrix[0][i][j] == matrix[0][i][j - 1] && matrix[0][i][j] == matrix[0][i][j - 2])
                {
                    matrix[1][i][j - 2] = matrix[1][i][j - 1] = matrix[1][i][j] = 0;
                }
            }
            else if(j > 1 && matrix[0][i][j] == matrix[0][i][j - 1] && matrix[0][i][j] == matrix[0][i][j - 2])
            {
                matrix[1][i][j - 2] = matrix[1][i][j - 1] = matrix[1][i][j] = 0;
            }
            else matrix[1][i][j] = matrix[0][i][j];
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            printf("%d", matrix[1][i][j]);
            if(j < m - 1) putchar(' ');
            else putchar('\n');
        }
    }
    return 0;
}

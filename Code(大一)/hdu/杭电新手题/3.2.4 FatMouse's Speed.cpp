#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct
{
    int w,s;
    int len,index;
    int before;
}mice;
int cmp(const void *a,const void *b)
{
    mice c = *(mice *)a;
    mice d = *(mice *)b;
    if(c.w==d.w)
    return d.s - c.s;
    else return c.w - d.w;
}
int main()
{
    mice m[10001];
    int i = 1,flag,max=0,f[1001];
    while(cin>>m[i].w>>m[i].s)
    {
        m[i].index = i;
        m[i].len=0;
        m[i].before=0;
        i++;
    }
    //cout<<i<<endl;
    qsort(m,i-1,sizeof(m[1]),cmp);
    for(int j = 1;j < i ;j++)
    {
        for(int k = 1; k< j;k++)
        {
            if(m[j].w>m[k].w&&m[j].s<m[k].s)
            {
                if(m[j].len<m[k].len+1)
                {
                    m[j].len = m[k].len+1;
                    m[j].before = k;
                    if(m[j].len>=max)
                    {
                        max = m[j].len;
                        flag = j;
                    }
                }

            }
        }
    }
    cout<<max+1<<endl;
    f[1] = m[flag].index;
    i=2;
     while(m[flag].before!=0)
    {
        flag = m[flag].before;
        f[i] = m[flag].index;
        i++;
    }
    for(int j = i-1 ; j >=1 ; j--)
    {
        cout<<f[j]<<endl;
    }
   // for(int j = 1 ; j < i ;j++)
   // cout<<m[j].index<<" "<<m[j].w<<" "<<m[j].s<<endl;
    return 0;
}

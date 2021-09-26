#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)

int wa[maxn], wb[maxn], wv[maxn], ws[maxn];

int c0(int *r, int a, int b)
{
    return r[a] == r[b]
           && r[a + 1] == r[b + 1]
           && r[a + 2] == r[b + 2];
}//判断r数组a和b两个三个字符的字符串是否相等

int c12(int k, int *r, int a, int b)
{
    if (k == 2)
        return r[a] < r[b]
               || r[a] == r[b]
               && c12(1, r, a + 1, b + 1);
               //k = 2 时判断r数组中a是否小于等于b处的三个字符的字符串
    else
        return r[a] < r[b]
               || r[a] == r[b]
               && wv[a + 1] < wv[b + 1];
               //k != 2 时
}

void sort(int *r, int *a, int *b, int n, int m)//n是原字符串的长度
{
    int i;
    for (i = 0; i < n; i++)
        wv[i] = r[a[i]];
    //wv数组存了a数组相应名次的元素位置 wv[i]名次为i的元素的下标
    for (i = 0; i < m; i++)
        ws[i] = 0;
    //ws初始化为0
    for (i = 0; i < n; i++)
        ws[i] += ws[i - 1];
    //全是0啊 什么意义 除非n>m
    for (i = n - 1; i >= 0; i--)
        b[--ws[wv[i]]] = a[i];
    //貌似b数组存的是相应名次的数据元素 b[i]为排名为i的a中的元素
    return;
}

void dc3(int *r, int *sa, int n, int m)
{
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    //tb表示模3为1的后缀个数 rn为要处理的新字符串
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++)
        if (i % 3 != 0)
            wa[tbc++] = i;
        //将长度模3不为0的字符串存入wa tbc为新字符串的个数
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    //以上是基数排序
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc)
        dc3(rn, san, tbc, p);
    else
        for (i = 0; i < tbc; i++)
            san[rn[i]] = i;
    for (i = 0; i < tbc; i++)
        if (san[i] < tb)
            wb[ta++] = san[i] * 3;
    if (n % 3 == 1)
        wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++)
        wv[wb[i] = G(san[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++)
        sa[p] = wa[i++];
    for (; j < tbc; p++)
        sa[p] = wb[j++];
    return;
}

/*

各个参数的作用和前面的倍增算法一样，不同的地方是r数组和sa数组的大小都要是3*n，这为了方便下面的递归处理，不用每次都申请新的内存空间。函数中用到的变量：

    int i,j,*rn=r+n,*san=sa+n,ta=0,tb=(n+1)/3,tbc=0,p;

　　rn数组保存的是（1）中要递归处理的新字符串，san数组是新字符串的sa。变量ta表示起始位置模3为0的后缀个数，变量tb表示起始位置模3为1的后缀个数，已经直接算出。变量tbc表示起始位置模3为1或2的后缀个数。先按（1）中所说的用基数排序把3个字符“合并 ”成一个新的字符。为了方便操作，先将r[n]和r[n+1]赋值为0。

　　代码：

    r[n]=r[n+1]=0;
    for(i=0;i<n;i++) if(i%3!=0) wa[tbc++]=i;
    sort(r+2,wa,wb,tbc,m);
    sort(r+1,wb,wa,tbc,m);
    sort(r,wa,wb,tbc,m);

　　其中sort函数的作用是进行基数排序。代码：

    void sort(int *r,int *a,int *b,int n,int m)
    {
        int i;
        for(i=0;i<n;i++) wv[i]=r[a[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) b[--ws[wv[i]]]=a[i];
        return;
    }

　　基数排序结束后，新的字符的排名保存在 wb数组中。

　　跟倍增算法一样，在基数排序以后，求新的字符串时要判断两个字符组是否完全相同。代码：

    for(p=1,rn[F(wb[0])]=0,i=1; i<tbc;i++)
    rn[F(wb[i])]=c0(r,wb[i-1],wb[i])?p-1:p++;

　　其中 F(x)是计算出原字符串的 suffix(x)在新的字符串中的起始位置，c0函数是比较是否完全相同，在开头加一段代码：

    #define F(x) ((x)/3+((x)%3==1?0:tb))
    inline int c0(int *r,int a,int b)
    {return r[a]==r[b]&&r[a+1]==r[b+1]&&r[a+2]==r[b+2];}

　　接下来是递归处理新的字符串，这里和倍增算法一样，可以加一个小优化，如果p等于tbc，那么说明在新的字符串中没有相同的字符，这样可以直接求出san数组，并不用递归处理。代码：

    if(p<tbc) dc3(rn,san,tbc,p);
    else for(i=0;i<tbc;i++) san[rn[i]]=i;

　　然后是第（2）步，将所有起始位置模3等于0的后缀进行排序。其中对第二关键字的排序结果可以由新字符串的sa直接计算得到，没有必要再排一次。代码：

    for(i=0;i<tbc;i++) if(san[i]<tb) wb[ta++]=san[i]*3;
    if(n%3==1) wb[ta++]=n-1;
    sort(r,wb,wa,ta,m);
    for(i=0;i<tbc;i++) wv[wb[i]=G(san[i])]=i;

　　要注意的是，如果n%3==1，要特殊处理suffix(n-1)，因为在san数组里并没有suffix(n)。G(x)是计算新字符串的suffix(x)在原字符串中的位置，和F(x)为互逆运算。在开头加一段：

    #define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)。

　　最后是第（3）步，合并所有后缀的排序结果，保存在sa数组中。代码：

    for(i=0,j=0,p=0;i<ta && j<tbc;p++)
    sa[p]=c12(wb[j]%3,r,wa[i],wb[j])?wa[i++]:wb[j++];
    for(;i<ta;p++) sa[p]=wa[i++];
    for(;j<tbc;p++) sa[p]=wb[j++];

　　其中c12函数是按（3）中所说的比较后缀大小的函数，k=1是第一种情况，k=2是第二种情况。代码：

    int c12(int k,int *r,int a,int b)
    {if(k==2) return r[a]<r[b]||r[a]==r[b]&&c12(1,r,a+1,b+1);
    else return r[a]<r[b]||r[a]==r[b]&&wv[a+1]<wv[b+1];}

*/
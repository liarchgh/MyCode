#include<cstring>
#include<cstdio>
int main()
{
    int k,m;
    while(scanf("%d",&k),k)
    {
        int wh,ok,judg,pan[2*k];
        for(int i=1;;++i)
        {
            wh=0;
            memset(pan,0,sizeof(pan));
            for(ok=k;ok>0;--ok)
            {
                int j=wh+i;
                do
                {
                    ++wh;
                    if(pan[wh%(2*k)])
                        ++j;
                }
                while(wh<j);
                if(wh%(2*k)<=k && wh%(2*k)) break;
                pan[wh%(2*k)]=1;
            }
            if(!ok) {printf("%d\n",i);break;}
        }
    }
    return 0;
}

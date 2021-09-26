#include<stdio.h>
#include<string.h>
int main()
{
    int j,ad,n,i;
    char a[18],b[12];
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    { scanf("%s",a);
        for(j=0;j<18;++j)
            a[j]=a[j]-'0';
        ad=a[0]*10+a[1];//printf("%s\n",b);
        switch(ad)
        {
        case 33:
            strcpy(b,"Zhejiang");//printf("%s\n",b);
            break;
        case 11:
            strcpy(b,"Beijing");
            break;
        case 71:
            strcpy(b,"Taiwan");
            break;
        case 81:
            strcpy(b,"Hong Kong");
            break;
        case 82:
            strcpy(b,"Macao");
            break;
        case 54:
            strcpy(b,"Tibet");
            break;
        case 21:
            strcpy(b,"Liaoning");
            break;
        case 31:
            strcpy(b,"Shanghai");
        default:
            ;
        }
        printf("He/She is from %s,and his/her birthday is on %d%d,%d%d,%d%d%d%d based on the table.\n",b,a[10],a[12],a[13],a[14],a[10],a[9],a[8],a[7]);
    }
}//330000198910120036

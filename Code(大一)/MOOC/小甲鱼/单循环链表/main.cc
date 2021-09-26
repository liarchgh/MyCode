#include<cstdio>
#include<cstdlib>
//#include"ds_init.cc"
//#include"ds_delete.cc"
//#include"ds_search.cc"
//#include"ds_insert.cc"

typedef struct CLinkList
{
    int data;
    struct CLinkList *next;
}node;
//定义链表





void ds_insert(node **pNode, int i)
{
    node *temp;
    node *target;
    node *p;
    int item;
    int j=1;

    printf("输入要插入的值:");
    scanf("%d",&item);

    if(i == 1)
    //将第一个和其他分开
    {
        temp = (node *)malloc(sizeof(struct CLinkList));
        //开辟空间

        if(!temp)
            exit(0);
        //失败退出

        temp->data = item;

        for(target = (*pNode);target->next !=(*pNode);target = target->next);
        temp->next = (*pNode);
        target->next = temp;
        //链式结构插入

        *pNode = temp;
        //*pNode必须一直指向第一个节点
    }
    else
    {
        target = *pNode;
        for(;j<(i-1);++j)
        {
            target = target->next;
        }
        //找到要插入的上一个位置

        temp = (node *)malloc(sizeof(struct CLinkList));
        if(!temp)
            exit(0);

        temp->data = item;
        p = target->next;
        target->next = temp;
        temp->next = p;
        //链式插入
    }
}

int ds_search(node *pNode, int elem)
{
    node *target;
    int i = 1;
    for(target = pNode; target->data != elem && target->next != pNode;++i)
    {
        target = target->next;
    }
    //从头节点开始查找，向下走，走到头遍是不存在
    if(target->next == pNode)
        return -1;
        //不存在
    else
        return i;
}

void ds_delete(node **pNode,int i)
{
    node *target;
    node *temp;
    int j = 1;

    if(i == 1)
    {
        for(target = *pNode; target->next != *pNode;target = target->next);
        //找到终端点

        temp = *pNode;
        //用“temp”指向要删除节点，方便下面删除，节约内存
        *pNode = (*pNode)->next;
        target->next = *pNode;
        //直接越过
        free(temp);
        //释放
    }
    else
    {
        target = *pNode;
        for(;j<i-1;++j)
        {
            target = target->next;
        }
        //用“target”找到前一个
        temp = target->next;
        target->next = temp->next;
        //越过
        free(temp);
        //释放
    }
}


void ds_init(node **pNode)
//头节点地址的地址
{
    int item;//输入的值
    node *temp;
    node *target;
    printf("请输入节点值，输入0完成初始化\n");
    while(1)
    {
        scanf("%d",&item);
        if(item == 0)
            return;
            if((*pNode) == NULL)
            //目前还没有节点
            {
                *pNode = (node*)malloc(sizeof(struct CLinkList));
                //构建新节点
                if(!(*pNode))
                    exit(0);
                    //分配失败便退出
                (*pNode)->data = item;
                (*pNode)->next = *pNode;
            }
            else
            {
                for(target = (*pNode);target->next != (*pNode);target = target->next);
                //寻找终端节点,target便是终端节点
                temp = (node *)malloc(sizeof(struct CLinkList));
                if(!temp)
                    exit(0);
                temp->data = item;
                temp->next = *pNode;
                //*pNode表示头节点地址，其是指针型指针
                target->next = temp;
            }
    }
}














void ds_traverse(node *pNode)
{
    node *temp;
    temp = pNode;
    printf("************链表中的元素************\n");

    do
    {
        printf("%-4d ",temp->data);
    }while((temp = temp->next) != pNode);

    printf("\n");
}

int main()
{
    node *pHead = NULL;
    char opp = 1;
    int find;

    printf("1.初始化链表 \n\n2.插入节点 \n\n3.删除节点 \n\n4.返回节点位置 \n\n5.遍历链表 \n\n0.退出\n");
    while(opp != '0')
    {
        scanf("%c",&opp);
        switch(opp)
        {
            case '1':
                ds_init(&pHead);
                printf("\n");
                ds_traverse(pHead);
                break;

            case '2':
                printf("输入需要插入节点的位置:");
                scanf("%d",&find);
                ds_insert(&pHead, find);
                printf("在位置%d插入值后:\n", find);
                ds_traverse(pHead);
                printf("\n");
                break;

            case '3':
                printf("输入需要删除的结点位置:");
                scanf("%d", &find);
                ds_delete(&pHead, find);
                printf("删除第%d个结点后:\n", find);
                ds_traverse(pHead);
                printf("\n");
                break;

            case '4':
                printf("所要查找的结点的值:");
                scanf("%d", &find);
                printf("元素%d所在位置: %d\n", find, ds_search(pHead, find));
                printf("\n");
                break;

            case '5':
                ds_traverse(pHead);
                printf("\n");
                break;

            case '0':
                exit(0);
        }
    }
    return 0;
}

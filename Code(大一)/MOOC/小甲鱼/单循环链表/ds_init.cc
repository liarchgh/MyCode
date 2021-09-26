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

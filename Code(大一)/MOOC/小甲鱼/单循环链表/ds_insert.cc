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
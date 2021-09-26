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

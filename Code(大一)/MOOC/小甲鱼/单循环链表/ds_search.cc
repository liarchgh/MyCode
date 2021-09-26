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
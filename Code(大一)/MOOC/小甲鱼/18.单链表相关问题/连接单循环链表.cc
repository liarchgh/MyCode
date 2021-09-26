LinkList Connect(LinkList A,LinkList B)
{
    LinkList p = A->next;
    //p指向A的头节点
    A->next = B->next->next;
    //A的尾指针指向B链表的第一个节点(不是头节点)
    free(B->next);
    //释放B的头节点
    B->next = p;
    //B的尾指针指向A的头节点
    return B;
    //B的指针成为整个链表的尾指针
}
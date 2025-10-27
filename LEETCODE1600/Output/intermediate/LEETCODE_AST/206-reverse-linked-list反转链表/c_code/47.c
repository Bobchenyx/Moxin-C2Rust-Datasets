c []
struct ListNode *reverseList(struct ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    
    if (!head->next)
    {
        return head;
    }
    struct ListNode *lNew = reverseList(head->next);

    //此处注意，因为只有一个节点的时候就返回了，但是返回时，head节点是返回链的上一个节点
    head->next->next = head; //将当前节点的作为下一个节点的next节点
    head->next = NULL;       //将取下的节点断开原链，不然回形成环

    return lNew;
}
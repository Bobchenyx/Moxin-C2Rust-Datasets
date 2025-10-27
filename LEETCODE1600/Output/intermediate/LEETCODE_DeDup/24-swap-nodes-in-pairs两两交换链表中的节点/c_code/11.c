struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode temp_node = {0,NULL};
    struct ListNode* temp = &temp_node;//哑节点
    struct ListNode* next = NULL;
    struct ListNode* res = temp;
    temp->next = head;
    //如果只输入[1]，不会进入下面的while循环。如果没有一开始连接到首个节点，将会输出temp->next即为NULL;
    while(head && head->next)//偶数个head=NULL;奇数个则head->next=NULL;
    {
        //交换两个节点位置，并将节点联通
        next = head->next;
        temp->next = next;
        head->next = next->next;
        next->next = head;
        //移动至下一个需要交换的节点
        temp = head;
        head = head->next;
    }
    return res->next;
}
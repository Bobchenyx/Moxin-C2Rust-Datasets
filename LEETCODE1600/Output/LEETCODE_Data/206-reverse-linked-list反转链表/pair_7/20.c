c []
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL){
        return  head;
    }
    struct ListNode *pre = NULL; // 代表被拆下节点反向连接成的新链表
    struct ListNode *dismount; // 代表将要被拆下的节点
    struct ListNode *cur = head;
    while (cur) {
        dismount = cur;
        cur = cur->next;
        dismount->next = NULL;
        if(pre==NULL){
            pre = dismount;
        }else{
            dismount->next = pre;
            pre = dismount;
        }
    }
    return pre;
}
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *res = NULL, *cur = head;
    while (cur){            //cur代表本次循环要处理的节点，此时head已提取至cur中
        head = head->next;  //head推进至下一个待处理节点
        cur->next = res;    //将新链表接在cur的后面，此时cur成为新链表的头
        res = cur;          //res也成为了新链表的头
        cur = head;         //cur提取旧链表中的head，进入下一轮处理
    }
    return res;
}
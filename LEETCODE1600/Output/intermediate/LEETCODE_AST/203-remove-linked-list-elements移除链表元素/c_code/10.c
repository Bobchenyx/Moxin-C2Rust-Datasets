struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode* p = head;
    if(p){
         //val在头部
        while (p->val == val){
            if(p->next==NULL){
                return NULL;
            }
            p = p->next;
        }
        head = p;
        //val在中间和尾部
        while(p!=NULL){
            if(p->val == val){
                p = head;
            }
            if(p->next!=NULL&&p->next->val == val){
                p->next = p->next->next;
            }
            p = p->next;
        }
    }
        return head;
}
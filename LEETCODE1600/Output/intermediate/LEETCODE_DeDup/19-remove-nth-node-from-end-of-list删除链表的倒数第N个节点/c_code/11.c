struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
       struct ListNode* fast=head;
       struct ListNode* slow=head;
       //让fast指针先走n步
       while(n--)
       {
           if(fast->next)
            fast=fast->next;
           else
            return head->next;
       }
       //俩个指针一起走
       while(fast->next)
       {
           fast=fast->next;
           slow=slow->next;
       }
       //此时slow指向倒数第n-1个结点
       slow->next=slow->next->next;
       return head;
}
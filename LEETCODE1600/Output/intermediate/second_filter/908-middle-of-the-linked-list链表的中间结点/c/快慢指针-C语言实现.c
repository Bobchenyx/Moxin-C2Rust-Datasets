执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户  
内存消耗 :6.9 MB, 在所有 C 提交中击败了41.05%的用户  

struct ListNode* middleNode(struct ListNode* head){
    if(head == NULL)return;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
//迭代法
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    while(cur){
        next = cur->next;//放在此处，相当于确保了一定有cur->next  
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
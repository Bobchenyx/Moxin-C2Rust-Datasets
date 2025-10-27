执行用时 :4 ms, 在所有 C 提交中击败了88.91%的用户  
内存消耗 :7.1 MB, 在所有 C 提交中击败了79.70%的用户  


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head == NULL)return head;
    struct ListNode* header = (struct ListNode*)malloc(sizeof(struct ListNode));
    header->next = head;
    struct ListNode* curr = head;
    struct ListNode* pre = header;
    int length = 0;
    while(curr){
        curr = curr->next;
        length++;
    }
    curr = head;
    n = length - n;
    while(n > 0){
        pre = curr;
        curr = curr->next;
        n--;
    }
    pre->next = curr->next;
    free(curr);
    return header->next;
}
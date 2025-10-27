struct ListNode *slow = head, *fast = head->next; //上来就多走一步
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
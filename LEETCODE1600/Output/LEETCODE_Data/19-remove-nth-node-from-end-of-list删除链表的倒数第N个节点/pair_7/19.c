class Solution {
private:
    int m=0;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return head;
        head->next=removeNthFromEnd(head->next,n);
        return ++m==n?head->next:head;
    }
};
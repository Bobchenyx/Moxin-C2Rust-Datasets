/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    if(!head)
        return 0;
    static int div=1;
    int ans;
    ans=getDecimalValue(head->next);
    ans+=div*(head->val);
    div*=2;
    return ans;
}
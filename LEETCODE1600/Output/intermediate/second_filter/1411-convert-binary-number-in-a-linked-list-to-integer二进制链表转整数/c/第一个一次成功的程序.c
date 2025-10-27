/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int cnt=0,sum=0;
    struct ListNode* p=head;
    while(p)
    {
        cnt++;
        p=p->next;
    }
    while(head&&cnt>=0)
    {
        sum+=(head->val)*(int)pow(2,cnt-1);
        cnt--;
        head=head->next;
    }
    return sum;
}
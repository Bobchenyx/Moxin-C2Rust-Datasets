/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n) return head;
    struct ListNode *pre,*ppre,*p;
    struct ListNode dummy;
    dummy.next=head;
    pre=&dummy;
    int i=1;
    while(i<m)
    {
        i++;
        pre=pre->next;
    }
    ppre=pre->next;
    for(i=0;i<n-m;i++)
    {
        p=ppre->next;
        ppre->next=p->next;//取下p结点
        p->next=pre->next;//头插到pre后面
        pre->next=p;
    }
    return dummy.next;
}
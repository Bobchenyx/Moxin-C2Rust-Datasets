/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getlength(struct ListNode *a){
    struct ListNode *p=a;
    int len=0;
    while(p){
        p=p->next;
        len++;
    }
    return len;
}

struct ListNode* middleNode(struct ListNode* head){
    int len=getlength(head);
    if(len%2==1){
        len=(len+1)>>1;
        len--;
    }
    else{
        len=len>>1;
        //len++;
    }
    while(len--){
        head=head->next;
    }
    return head;
}
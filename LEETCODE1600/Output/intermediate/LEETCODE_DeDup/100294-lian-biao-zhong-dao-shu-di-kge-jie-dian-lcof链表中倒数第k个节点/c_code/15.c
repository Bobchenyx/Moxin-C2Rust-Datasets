/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    //双指针，两倍，恒差
    if(k<=0||head==NULL)return NULL;
    struct ListNode *p=head,*q=head;
    while(q->next!=NULL){           //q最终指向最后一个节点
        q=q->next;
        k>1?k--:(p=p->next);        //k最终等于1
    }
    return p;
}
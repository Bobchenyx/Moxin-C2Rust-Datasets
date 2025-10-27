/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p=(struct reverseList*)malloc(sizeof(struct ListNode));
    p->next=head;
    struct ListNode *r=head;
    if(!r) return NULL;
    while(r->next){
        r=r->next;
    }
    while(p->next!=r){
        struct ListNode *temp=p->next;
        p->next=temp->next;     //temp保存需要移动的结点
        temp->next=r->next;
        r->next=temp;       //将temp插入r之后
    }
    return p->next;
}
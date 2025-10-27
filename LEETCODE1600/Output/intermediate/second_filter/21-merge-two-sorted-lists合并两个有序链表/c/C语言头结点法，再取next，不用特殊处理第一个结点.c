/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode)),*t,*p,*q;
	l3->next=NULL;l3->val=0;
	p=l1;q=l2;t=l3;
	while(p!=NULL&&q!=NULL){
		struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
		if(p->val<=q->val){
			n->val=p->val;
			n->next=NULL;
			t->next=n;
			t=t->next;
			p=p->next;
		}else{
			n->val=q->val;
			n->next=NULL;
			t->next=n;
			t=t->next;
			q=q->next;
		}
	}
	while(p){
		struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
		n->val=p->val;
		n->next=NULL;
		t->next=n;t=t->next;p=p->next;
	}
	while(q){
		struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
		n->val=q->val;
		n->next=NULL;
		t->next=n;t=t->next;q=q->next;
	}
	return l3->next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
p->val = -1;
p->next = NULL;
struct ListNode* q = p;
struct ListNode* r = NULL;
int flag,count;
struct ListNode* pr1 = NULL;
struct ListNode* pr2 = NULL;
for (pr1 = l1,pr2 = l2,flag = 0;(pr1||pr2)!=NULL;){
    if (pr1!=NULL&&pr2!=NULL){
        count = pr1->val + pr2->val + flag;
        flag = 0;
        if (count>=10){
            flag = 1;
            count = count%10;
        }

        pr1 = pr1->next;
        pr2 = pr2->next;

        r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = count;
        q->next = r;
        q = r;
    }
    if (pr1!=NULL&&pr2==NULL){
        count = pr1->val +flag;
        flag = 0;
        if (count>=10){
            flag = 1;
            count = count%10;
        }

        pr1 = pr1->next;

        r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = count;
        q->next = r;
        q = r;
    }
    if (pr1==NULL&&pr2!=NULL){
        count = pr2->val +flag;
        flag = 0;
        if (count>=10){
            flag = 1;
            count = count%10;
        }

        pr2 = pr2->next;

        r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = count;
        q->next = r;
        q = r;
    }
}
if (flag == 1){
    r = (struct ListNode*)malloc(sizeof(struct ListNode));
        r->next = NULL;
        r->val = 1;
        q->next = r;
        q = r;
}
r = p;
p = p->next;
free(r);
return p;
}
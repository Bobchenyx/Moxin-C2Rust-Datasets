/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode LNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    LNode *s, *r, *C;
    int flag = 0;

    C = (LNode*)malloc(sizeof(LNode));
    C ->next = NULL;
    r = C;

    while (l1 != NULL && l2 != NULL)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->val = l1->val + l2->val + flag;
        flag = 0;
        if (s->val > 9)
        {
            s->val = s->val - 10;
            flag = 1;
        }
        r->next = s;        //保证相加后结果倒序，所以求和链表采用尾插法
        r = s;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->val = l1->val + flag;
        flag = 0;
        if (s->val > 9)
        {
            s->val = s->val - 10;
            flag = 1;
        }
        r->next = s;
        r = s;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->val = l2->val + flag;
        flag = 0;
        if (s->val > 9)
        {
            s->val = s->val - 10;
            flag = 1;
        }
        r->next = s;
        r = s;
        l2 = l2->next;
    }
    if (flag)
    {
        flag = 0;
        s = (LNode*)malloc(sizeof(LNode));
        s->val = 1;
        r->next = s;
        r = s;
    }
    r->next = NULL;

    return C->next;
}
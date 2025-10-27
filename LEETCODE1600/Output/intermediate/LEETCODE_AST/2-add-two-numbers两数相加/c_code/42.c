/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* NewNode(int val)
{
    struct ListNode* pNode = NULL;
    pNode = (struct ListNode *)malloc(sizeof(struct ListNode)); 
    if (NULL != pNode)
    {
        pNode ->val = val;
        pNode ->next = NULL;
    }
    return pNode;
}


void AddNewList(struct ListNode* pHead, struct ListNode* l, int temp)
{
    struct ListNode *pNode = NULL;

    while (l->next != NULL)
    {
        l = l ->next;
        pNode = NewNode((l->val + temp) % 10);
        if (NULL != pNode)
        {
            temp = (l->val + temp) / 10;
            pHead ->next = pNode;
            pHead = pNode;
            pNode = NULL;
        }
    }
    if (0 != temp)
    {
        pHead->next = NewNode(temp);
    }
    return ;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *pHead = NULL;
    struct ListNode *pNode = NULL;
    struct ListNode *pNext = NULL;
    
    int temp = 0;
    pHead = NewNode((l1->val + l2->val) % 10);
    if (pHead == NULL)
    {
        return NULL;
    }
    temp = (l1->val + l2->val) / 10;
    pNext = pHead;
    while ((NULL != l1->next) && (NULL != l2->next))
    {
        l1 = l1->next;
        l2 = l2->next;
        pNode = NewNode((l1->val + l2->val + temp) % 10);
        if (NULL != pNode)
        {
            temp = (l1->val + l2 -> val + temp) / 10;
            pNext ->next = pNode;
            pNext = pNode;
            pNode = NULL;
        }
    }

    if ((NULL == l1->next) && (NULL == l2 ->next))
    {
        if (temp != 0)
        {
            pNext ->next = NewNode(temp);
        }
    }
    else if (NULL == l1 ->next)
    {
        AddNewList(pNext, l2, temp);
    }
    else
    {
        AddNewList(pNext, l1, temp);
    }
    return pHead;
}
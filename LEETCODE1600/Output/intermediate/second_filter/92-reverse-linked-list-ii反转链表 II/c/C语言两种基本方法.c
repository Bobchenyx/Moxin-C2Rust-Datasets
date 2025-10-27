struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (head == NULL) return NULL;
    struct ListNode *curr = head;
    struct ListNode *dummy, *pPrev;
    dummy = (struct ListNode*)malloc(sizeof (struct ListNode));
    struct ListNode *pNext;
    int i = 0;

    dummy->next = head;
    pPrev = dummy;    
    for (i=0; i<m-1; i++)   //leetcode上的链表head节点好像就是首元节点？控制循环次数使pPrev指向待反转的链表段起始位置
    {
        if (pPrev->next != NULL)
        {
            pPrev = pPrev->next;
        }
    }
    curr = pPrev->next;

    for (i=m; i<n; i++)
    {
        if (curr->next != NULL)
        {
            pNext = curr->next;
            curr->next = pNext->next;
            pNext->next = pPrev->next;
            pPrev->next = pNext;
        }
    }


    return dummy->next;
}
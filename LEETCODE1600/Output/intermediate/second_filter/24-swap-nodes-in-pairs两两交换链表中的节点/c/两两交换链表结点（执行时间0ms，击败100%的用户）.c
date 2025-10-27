/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *pre,*p,*curhead,*rear;
    int i;
    if(!head || (head->next == NULL))
    {
        return head;
    }
    curhead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre = p = head;
    while(p)
    {
        for (i = 1; i < 2; i++)
        {
			 if (!p)
				 break;
			 p = p->next;
        }
        if(p)
        {
            rear = p->next;
            curhead->next = NULL;
            if(pre == head)
                head = curhead;
            while(pre!= rear)
            {
                p = pre;
                pre = pre->next;
                p->next = curhead->next;
                curhead->next = p;
            }
            while(curhead->next)
            {
                curhead = curhead->next;
            }
            curhead->next = rear;
            p = pre;
        }
    }
    return head->next;
}
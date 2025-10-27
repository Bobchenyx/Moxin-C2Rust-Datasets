/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* retl1 = NULL;
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode *temp1 = l1;
    struct ListNode *temp2 = l2;
    struct ListNode *temp3 = head;

    int add =0;
    while(temp1 !=  NULL || temp2 != NULL)//开始遍历，直到都是空为止
    {
        struct ListNode *newnode= (struct ListNode*)malloc(sizeof(struct ListNode));
        if(temp1 == NULL)
        {
            newnode->val = add + temp2->val;
            temp2=temp2->next;
        }
        else if(temp2 == NULL)
        {
            newnode->val = add +temp1->val;
            temp1=temp1->next;
        }else
        {
            newnode->val = add + temp1->val + temp2->val;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(newnode->val>=10)
        {
            add = 1; 
            newnode->val %= 10;
            newnode->next = NULL;
        }
        else
        {
            add =0;
            newnode->next = NULL;
        }
        head->next = newnode;
        head=head->next;
    }
    printf("add = %d\n",add);
    if(add ==1)
    {
        struct ListNode *newnode= (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=1;
        newnode->next=NULL;
        head->next=newnode;
    }
    return temp3->next;
}
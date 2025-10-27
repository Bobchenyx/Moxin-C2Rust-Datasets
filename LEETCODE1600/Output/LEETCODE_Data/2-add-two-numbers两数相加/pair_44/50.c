/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //边界条件有两种情况，第一个是最后的进位是1，第二个是l1或l2为空
    int temp;
    int carry_bit=0;
    struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret=cur;
    while(l1 != NULL || l2 != NULL)
    {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;

        if(l1 == NULL)
        {
            temp = 0 + l2->val + carry_bit;
            l2 = l2->next;
        }   
        else if(l2 == NULL){
            temp = l1->val + 0 + carry_bit;
            l1 = l1->next;
        }
        else
        {
            temp = l1->val + l2->val + carry_bit;
            l1 = l1->next;
            l2 = l2->next;
        }

        cur->val = temp % 10;
        carry_bit = temp / 10;

        
    }
    if(carry_bit == 1)
    {
        cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = 1;
    }
    cur->next = NULL;
    return ret->next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* rear = head;
    struct ListNode* aim = head;

    if (head == NULL)
    {
        return NULL;
    }
    
    while (n--)
    {
        rear = rear->next;//停在第n个节点的
    }
    if (rear == NULL)//删除第一个元素
    {
        aim = aim->next;
        return aim;
    }
    while (rear->next != NULL) 
    {
        rear = rear->next;
        aim = aim->next;//最终会停在倒数第n个节点的前一个
    }

    rear = aim->next;
    aim->next = rear->next;
    free(rear);

    return head;

}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listLength(struct ListNode *head)
{
    int len = 0;
    while(head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    //计算链表的长度
    int len = listLength(head);

    //计算倒数第K个节点对应的正数的位置
    int m = len-k;
    while(m > 0)
    {
        head = head->next;
        m--;
    }
    return head;
}
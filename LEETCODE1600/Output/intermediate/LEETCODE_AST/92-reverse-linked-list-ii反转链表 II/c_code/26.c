/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    int len = 0;//记录链表的长度
    struct ListNode *node = head;
    struct ListNode *pre = NULL;//指向第m-1个节点
    struct ListNode *pos = NULL;//指向第n+1个节点
    while(node != NULL)
    {
        len++;
        if(len == m - 1)
            pre = node;
        if(len == n + 1)
            pos = node;
        node = node->next;
    }
    //反转链表：node指向要反转部分的第一个节点
    node = pre==NULL?head:pre->next;
    struct ListNode *cur = node->next;//cur指向当前要处理的节点
    node->next = pos;
    struct ListNode *nextNode = NULL;
    while(cur != pos)
    {
        nextNode = cur->next;//保存当前节点的下一个节点
        cur->next = node;
        node = cur;
        cur = nextNode;
    }
    if(pre != NULL)
    {
        pre->next = node;
        return head;
    }
    return node;
}
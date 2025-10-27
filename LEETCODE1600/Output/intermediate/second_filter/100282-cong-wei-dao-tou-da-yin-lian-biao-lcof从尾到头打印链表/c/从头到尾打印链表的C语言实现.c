/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize)
{
    //入参检查
    if(!head)
    {
        *returnSize = 0;
        return NULL;
    }

    //反转链表
    int len = 0;
    struct ListNode *newHead = NULL;
    struct ListNode *tmp;
    while(head)
    {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
        len++;
    }

    //创建并初始化数组
    int *result = (int*)malloc(sizeof(int) * len);
    memset(result, 0, sizeof(int)*len);

    for(int i=0; i<len; i++)
    {
        result[i] = newHead->val;
        newHead = newHead->next;
    }

    *returnSize = len;
    return result;
}
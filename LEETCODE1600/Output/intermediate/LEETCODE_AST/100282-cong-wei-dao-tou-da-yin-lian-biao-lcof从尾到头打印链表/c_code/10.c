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
//方法一：反转链表法
//反转链表并且求链表长度
struct ListNode* reverseList(struct ListNode* head, int* returnSize)
{
    struct ListNode* pstLnTemp = NULL;
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnCur = NULL;
    int iLength = 0;

    if(NULL == head)
    {
        *returnSize = iLength;
        return head;
    }
    pstLnCur = head;
    while(NULL != pstLnCur)
    {
        pstLnTemp = pstLnCur->next;
        pstLnCur->next = pstLnPre;
        pstLnPre = pstLnCur;
        pstLnCur = pstLnTemp;
        iLength++;
    }

    *returnSize = iLength;
    return pstLnPre;
}
int* reversePrint(struct ListNode* head, int* returnSize){
    struct ListNode* pstLnCur = NULL;
    int iLength = 0;
    if(NULL == head)
    {
        *returnSize = iLength;
        return head;
    }
    //反转链表
    pstLnCur = head;
    pstLnCur = reverseList(pstLnCur, &iLength);
    head = pstLnCur;

    //存入数组
    int* piArrayHead = (int*)malloc(iLength*sizeof(int));
    int* piArray = piArrayHead;
    while(NULL != pstLnCur)
    {
        *piArray = pstLnCur->val;
        piArray++;
        pstLnCur = pstLnCur->next;
    }

    //恢复原链表
    pstLnCur = head;
    pstLnCur = reverseList(pstLnCur, &iLength);

    *returnSize = iLength;
    return piArrayHead;
}
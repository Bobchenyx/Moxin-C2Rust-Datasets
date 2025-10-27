/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：快慢指针法。
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* pstLnFast = NULL;
    struct ListNode* pstLnSlow = NULL;
    if(NULL == head)
    {
        return head;
    }

    pstLnFast = head;
    pstLnSlow = head;
    while(NULL != pstLnFast)
    {
        //pstLnFast一直移动到NULL。
        pstLnFast = pstLnFast->next;

        //pstLnSlow前k个节点不移动，构造出pstLnSlow和pstLnFast指针的k个节点距离，然后两个指针同时移动，
        //当pstLnFast一直移动到NULL时，pstLnSlow则指向的就是倒数k节点的位置了。
        if(0 == k)
        {
            pstLnSlow = pstLnSlow->next;
        }
        else
        {
            k--;
        }
    }

    return pstLnSlow;
}

//方法二：常规求取长度法。
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* pstLnCur = NULL;
    int iLength = 0;
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    
    //求取链表长度
    while(NULL != pstLnCur)
    {
        iLength++;
        pstLnCur = pstLnCur->next;
    }

    pstLnCur = head;
    //找到倒数k个节点的位置
    while(iLength>k)
    {
        pstLnCur = pstLnCur->next;
        iLength--;
    }

    return pstLnCur;

}
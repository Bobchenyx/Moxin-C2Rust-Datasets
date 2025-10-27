/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 方法一：归并排序实现链表排序。（局部变量申请哨兵节点） */
struct ListNode* sortList(struct ListNode* head){
    struct ListNode* pstLnCur = NULL;
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnLeft = NULL;
    struct ListNode* pstLnRight = NULL;
    struct ListNode stLnHead = {0};
    int iLength = 0;
    stLnHead.val = 0;
    stLnHead.next = NULL;

    if((NULL == head) || (NULL == head->next))
    {
        return head;
    }
    // 获取链表长度
    iLength = listNodeLength(head);

    //局部变量申请哨兵节点，也有叫傀儡节点（处理链表问题的一般技巧）
    stLnHead.next = head;  //因为head所指节点在排序的过程中会变动。

    // 循环 log n 次
    for(int i=1; i<iLength; i<<=1)
    {
        pstLnPre = &stLnHead;
        pstLnCur = stLnHead.next;
        // 循环 n 次
        while(NULL != pstLnCur)
        {
            pstLnLeft = pstLnCur;
            pstLnRight = splitList(pstLnLeft, i);
            pstLnCur = splitList(pstLnRight, i);

            pstLnPre->next = mergeTwoLists(pstLnLeft, pstLnRight);

            //用于将两两排序好的链表链接到一起。
            while(NULL != pstLnPre->next)
            {
                pstLnPre = pstLnPre->next;
            }
        }
    }

    return stLnHead.next;
}
// 获取链表的长度
int listNodeLength(struct ListNode* head)
{
    struct ListNode* pstLnCur = NULL;
    int iLength = 0;
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    while(NULL != pstLnCur)
    {
        iLength++;
        pstLnCur = pstLnCur->next;
    }

    return iLength;
}
// 根据步长分隔链表
struct ListNode* splitList(struct ListNode* head, int step)
{
    struct ListNode *pstLnCur = NULL;
    struct ListNode *pstLnPre = NULL;
    if(NULL == head)
    {
        return head;
    }
    pstLnCur = head;
    for(int i=1; (i<step)&&(NULL != pstLnCur->next); i++) //这个判断(NULL != pstLnCur->next)需要有，否则pstLnCur可能会为空，然后出现访问空指针的错误。
    {
        pstLnCur = pstLnCur->next;
    }
    pstLnPre = pstLnCur->next;
    pstLnCur->next = NULL;
    return pstLnPre;

}
// 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* left, struct ListNode* right)
{
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnLeft = NULL;
    struct ListNode* pstLnRight = NULL;
    struct ListNode stLnHead = {0};
    if(NULL == left)
    {
        return right;
    }
    if(NULL == right)
    {
        return left;
    }
    stLnHead.val = 0;
    stLnHead.next = NULL;

    pstLnPre = &stLnHead;
    pstLnLeft = left;
    pstLnRight = right;

    while((NULL != pstLnLeft) && (NULL != pstLnRight))
    {
        if(pstLnLeft->val > pstLnRight->val)
        {
            pstLnPre->next = pstLnRight;
            pstLnRight = pstLnRight->next;
        }
        else
        {
            pstLnPre->next = pstLnLeft;
            pstLnLeft = pstLnLeft->next;
        }
        pstLnPre = pstLnPre->next;
    }

    pstLnPre->next = (NULL==pstLnLeft)?pstLnRight:pstLnLeft;

    return stLnHead.next;
}

/* 方法二：归并排序实现链表排序。（malloc申请内存） */
struct ListNode* sortList(struct ListNode* head){
    if((NULL == head) || (NULL == head->next))
    {
        return head;
    }

    // 获取链表长度。
    int iLength = listNodeLength(head);

    // 哨兵节点，也有叫傀儡节点（处理链表问题的一般技巧）
    struct ListNode* pstLnHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pstLnHead->next = head;
    struct ListNode* pstLnCur = NULL;
    struct ListNode* pstLnPre = NULL;
    struct ListNode* pstLnLeft = NULL;
    struct ListNode* pstLnRight = NULL;

    // 循环 log n 次
    for(int i=1; i<iLength; i<<=1)
    {
        pstLnPre = pstLnHead;
        pstLnCur = pstLnHead->next;
        // 循环 n 次
        while(NULL != pstLnCur)
        {
            pstLnLeft = pstLnCur;
            pstLnRight = splitList(pstLnLeft, i);
            pstLnCur = splitList(pstLnRight, i);
            pstLnPre->next = mergeTwoLists(pstLnLeft, pstLnRight);

            while(NULL != pstLnPre->next)
            {
                pstLnPre = pstLnPre->next;
            }
        }
    }

    pstLnPre = pstLnHead->next;
    free(pstLnHead);
    pstLnHead=NULL;
    return pstLnPre;
}

// 获取链表的长度
int listNodeLength(struct ListNode* head)
{
    int iLength = 0;
    
    if(NULL == head)
    {
        return 0;
    }
    while(NULL != head)
    {
        iLength++;
        head = head->next;
    }
    return iLength;
}
// 根据步长分隔链表
struct ListNode* splitList(struct ListNode* head, int step)
{
    if(NULL == head)
    {
        return head;
    }

    for(int i=1; (i < step) && (NULL != head->next); i++)
    {
        head = head->next;
    }
    struct ListNode* pstLnRight = head->next;
    head->next = NULL;
    return pstLnRight;

}
// 合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* left, struct ListNode* right){
    if(NULL == left)
    {
        return right;
    }
    if(NULL == right)
    {
        return left;
    }
    struct ListNode* pstLnHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pstLnPre = NULL;
    pstLnPre = pstLnHead;
    while((NULL != left) && (NULL != right))
    {
        if(left->val > right->val)
        {
            pstLnPre->next = right;
            right = right->next;
        }
        else
        {
            pstLnPre->next = left;
            left = left->next;
        }
        pstLnPre = pstLnPre->next;
    }

    pstLnPre->next = (NULL==left?right:left);
    pstLnPre = pstLnHead->next;
    free(pstLnHead);
    pstLnHead=NULL;
    return pstLnPre;
}

/* 方法三：冒泡法实现链表排序。 */
struct ListNode* sortList(struct ListNode* head){
    struct ListNode* pstLnHeadA = NULL;
    struct ListNode* pstLnHeadB = NULL;
    int iValTemp = 0;
    if(NULL == head)
    {
        return head;
    }

    pstLnHeadA = head;
    //pstLnHeadB = head->next;
    while(NULL != pstLnHeadA)
    {
        pstLnHeadB = pstLnHeadA->next;
        while(NULL != pstLnHeadB)
        {
            if((pstLnHeadB->val) < (pstLnHeadA->val))
            {
                iValTemp = pstLnHeadA->val;
                pstLnHeadA->val = pstLnHeadB->val;
                pstLnHeadB->val = iValTemp;
            }
            pstLnHeadB = pstLnHeadB->next;
        }
        pstLnHeadA = pstLnHeadA->next;
    }
    return head; //交换的只是链表的值，头指针没有变动。
}
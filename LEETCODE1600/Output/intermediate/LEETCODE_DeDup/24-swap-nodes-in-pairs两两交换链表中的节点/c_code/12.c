/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* retHead = NULL;//返回头节点
    struct ListNode* h = NULL;
    struct ListNode* p = NULL;
    int cnt = 1;

    retHead = (struct ListNode*)malloc(sizeof(struct ListNode));//新申请的链表头节点
    h = retHead;
    
    if (head == NULL)//空节点
    {
        return head;
    }
    /*head ！= NULL 实际上是为了检查是否为奇数个节点，因为循环里面要后退两次，所以如果后退偶数次，head为空了，那么必是奇数个节点
    head->next != NULL 是为了防止数组越界，同样因为里面h后退了两次head,如果不加以判断会报错。
    */
    while (head != NULL && head->next != NULL)
    {
        p = head;
        head = head->next;
        h->next = head;
        head = head->next;
        h = h->next;
        h->next = p;
        p->next = NULL;
        h = p;
    }
    
    h->next = head;//奇数个节点的时候有实际作用
    retHead =retHead->next;

    return retHead;

}
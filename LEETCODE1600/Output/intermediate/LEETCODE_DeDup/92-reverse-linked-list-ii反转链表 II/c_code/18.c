/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode headnode,*L=&headnode;  //设立头结点,头指针
    L->next = head;
    struct ListNode *p=L,*q,*h,*r,*rear;//p是要翻转的结点，q是p的下一个结点防止断链，h和r是翻转的那段链表的表头和表尾，rear是第m-1个结点用来链接翻转链表的
    for(int i=0;i<m-1;i++){
        p = p->next;
    }
    rear = p;   //m-1
    p = p->next; //m
    h = p;
    r = p;
    p = p->next; //m+1
    for(int i=0;i<n-m;i++){
        q = p->next;
        p->next = h;
        h = p;
        p = q;
    }
    rear->next = h;
    r->next = p;
    return L->next;
}
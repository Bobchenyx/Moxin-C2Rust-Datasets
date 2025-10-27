typedef struct ListNode* ptr;
struct ListNode* removeElements(struct ListNode* head, int val)
{
    ptr ans = (ptr)malloc(sizeof(struct ListNode));
    ans->next = NULL;
    ptr p = head, r = ans;
    while(p){
        if(p->val != val){
            r->next = p;
            r = p;
        }
        p = p->next;
    }
    r->next = NULL;
    return ans->next;
}
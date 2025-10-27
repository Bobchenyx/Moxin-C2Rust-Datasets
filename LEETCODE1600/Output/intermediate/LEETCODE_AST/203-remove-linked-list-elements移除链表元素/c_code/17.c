/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    
    if(!head)  return NULL;

    struct ListNode*p,*temp,*pre,*L; 
    L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    pre=L;
    p=head;
    while(p)
    {
        if(p->val==val)
          {
              while(p&&p->val==val)//判断是否有连续相同的值存在
              {
                  p=p->next;
              }
              if(!p)//最后一个元素为空的话
              pre->next=NULL;
              else
              {
                pre->next=p;
                pre=pre->next;
                p=p->next;
              }         
          }
        else
        {
            pre=pre->next;
            p=p->next;
        }
    }

    return L->next;
}
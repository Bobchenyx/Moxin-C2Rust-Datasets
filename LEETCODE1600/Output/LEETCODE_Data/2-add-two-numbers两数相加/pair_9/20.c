/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* add(struct ListNode*l1,struct ListNode*l2,int set)
{
    int left=0,right=0;
    int sum=0;
    struct ListNode*next_L_dir=NULL;
    struct ListNode*next_R_dir=NULL;
    if(l1==NULL&&l2==NULL)
    {
        if(set==0)
            return NULL;
        if(set==1)
            {
                struct ListNode* last=malloc(sizeof(struct ListNode));
                last->val=1;
                last->next=NULL;
                return last;
            }
    }

    if(l1)
       {
           left=l1->val;
           next_L_dir=l1->next;
       } 
    if(l2)
        {
            right=l2->val;
            next_R_dir=l2->next;
        }
       
    sum=left+right+set;
    set=sum/10;
    
    struct ListNode*new=malloc(sizeof(struct ListNode));

    if(set==0)
        new->val=sum;
    else if(set==1)
        new->val=sum-10;


    new->next=add(next_L_dir,next_R_dir,set);
   
    return new;
}



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    return add(l1,l2,0);
}
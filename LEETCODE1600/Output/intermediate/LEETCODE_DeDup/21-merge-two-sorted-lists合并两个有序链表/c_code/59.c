/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p,*q,*r,*res,*temp;
    
    if(l1==NULL || l2==NULL){
        if(l1)
            return l1;
        else
            return l2;
    }//排除链表为空的情况

    if(l1->val > l2->val){//用三元运算符的条件表达式比较好，但是不太会用
        p=l2;
        r=l1;
    }
    else{
        p=l1;
        r=l2;
    }

    res=p;//保存原结点
    
    while(p->next!=NULL && r!=NULL){//同时遍历两个链表
        q=p->next;
        if(r->val>=p->val && r->val<=q->val){
            temp = r->next;
            r->next=p->next;
            p->next=r;//将r插入p后面
            p=r;//继续基础链的后推
            r=temp;
        }
        else{//若不符合插入条件则后推一个结点
            p=p->next;
        }
    }

    if(r)//将后续的链表连上
        p->next=r;
    
    return res;
}
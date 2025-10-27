/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode* p = head;// p指向头结点，head结点最好不要动，防止原链表丢失
    struct ListNode* q; // 相当于平常使用的temp，存储临时结点
    struct ListNode* new;
    struct ListNode* new_p;
    int i;
    int n = 0; // 遍历，获取链表长度

    while(p){ // 只动p不动head
        ++n;
        p = p->next;
    }

    if(n==0){
        return head;
    }

    if(n==1){
        return head;
    }

    p = head;

    while(1){
        if(p&&p->next->next){
            p = p->next;
        }else{
            break;
        }
    }
    q = p->next;
    new = q;
    new_p = new;
    p->next = q->next;



    for(i=0;i<n-2;++i){
        p = head;
        // 循环用于定位到倒数第2个结点
        while(1){
            if(p->next->next!=NULL){
                p = p->next;
            }else{
                break;
            }
        }
        q = p->next;
        new_p->next = q;
        new_p = q;
        p->next = q->next;
        
    }

    new_p->next = head;// 执行n-2次后，只剩下一个head结点，直接赋给new_p->next
    head = new;

    return head;
    
}
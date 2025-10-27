/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


    struct ListNode* deleteDuplicates(struct ListNode* head){
        //假设1->1->3->3->4
        struct ListNode dummy;
        dummy.next = head;
        //让cur指向dummy
        struct ListNode*cur = &dummy;

        while(cur->next && cur->next->next){ 
            if(cur->next->val == cur->next->next->val){// 1->1满足条件

                struct ListNode *tmp = cur->next;

                while(tmp && tmp->next && tmp->val == tmp->next->val){//不满足
                    tmp = tmp->next;
                }
                cur->next = tmp->next;//跳过前面重复节点，直接3->3-4
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
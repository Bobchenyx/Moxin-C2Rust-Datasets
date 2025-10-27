/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre = nullptr;    //指向当前节点的前一个节点
        ListNode* p = head;     //指向当前节点
        ListNode* pNext = head->next;   //指向当前节点的后一个节点
        
        while(p != nullptr) {
            p->next = pre;
            pre = p;
            p = pNext;
            pNext =  pNext == nullptr ? nullptr : pNext->next;  //这边加一个判断,防止pNext为空指针(遍历到最后pNext要比p先到达空指针的位置)
        }
        
        return pre;
    }
    
};
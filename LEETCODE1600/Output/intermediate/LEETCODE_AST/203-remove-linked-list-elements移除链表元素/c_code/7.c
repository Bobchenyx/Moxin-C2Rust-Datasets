/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    //哨兵节点来了
    struct ListNode *sentinel = malloc(sizeof(struct ListNode));
    sentinel->next = head;
    //第一个节点的当前节点恶化前继节点
    struct ListNode *curr = head, *prev = sentinel;
    
    while (curr != NULL){
        if (curr->val == val){
            prev->next = curr->next;
        } else{
            prev = curr;
        }
        curr = curr->next;
    }
    return sentinel->next;

}
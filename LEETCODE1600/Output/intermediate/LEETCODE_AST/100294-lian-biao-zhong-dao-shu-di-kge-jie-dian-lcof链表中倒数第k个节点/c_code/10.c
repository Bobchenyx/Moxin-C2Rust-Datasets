/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* right = head;
    struct ListNode* left = right;
    int i = 1;
    while(i < k){
        right = right->next;
        i++;
    }
    while(right->next){
        right = right->next;
        left = left->next;
    }
    return left;
}
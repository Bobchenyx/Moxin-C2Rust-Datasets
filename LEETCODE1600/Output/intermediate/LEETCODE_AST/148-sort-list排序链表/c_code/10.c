/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* sortList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* fast = head->next;
    struct ListNode* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* tmp = slow->next;
    slow->next = NULL;

    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(tmp);

    struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* res = ret;

    while(left != NULL  && right != NULL){
        if(left->val < right->val){
            ret->next = left;
            left = left->next;
        }else{
            ret->next = right;
            right = right->next;
        }
        ret = ret->next;
    }
    ret->next = left != NULL ? left : right;

    return res->next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* gret = NULL;
struct ListNode* ReverseNode(struct ListNode* cur)
{
    if (cur == NULL) {
        return NULL;
    }

    if (cur->next == NULL) {
        gret = cur;
        return cur;
    }
    struct ListNode* pre = ReverseNode(cur->next);
    pre->next = cur;
    cur->next = NULL;

    return cur;
}
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    gret = NULL;
    ReverseNode(head);

    return gret;
}
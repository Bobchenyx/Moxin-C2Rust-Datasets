/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode * head = l1->val <= l2->val ? l1 : l2;
    struct ListNode * current = head;
    struct ListNode * nextNode = l1->val > l2->val ? l1 : l2;
    struct ListNode * temp = current->next;
    if (temp == NULL) {
        current->next = nextNode;
        return head;
    }
    while (nextNode != NULL && temp != NULL) {
        if (nextNode->val <= temp->val) {
            current->next = nextNode;
            current = nextNode;
            nextNode = current->next;
        } else {
            current->next = temp;
            current = temp;
            temp = current->next;
        }
        if (nextNode == NULL) {
            current->next = temp;
        }
        if (temp == NULL) {
            current->next = nextNode;
        }
    }
    return head;
}
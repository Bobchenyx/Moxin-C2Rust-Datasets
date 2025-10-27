/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }

    struct ListNode *relNode = head->next ? head->next : head;

    struct ListNode *lastNode = NULL;
    struct ListNode *fisrtNode = head;

    while(fisrtNode) {
        if(fisrtNode->next){
            struct ListNode *temp = fisrtNode->next->next;
            if(lastNode) {
                lastNode->next = fisrtNode->next;
            }
            lastNode = fisrtNode;
            fisrtNode->next->next = fisrtNode;
            fisrtNode->next = NULL;
            fisrtNode = temp;
        } else {
            if(lastNode){
                lastNode->next = fisrtNode;
            }
            fisrtNode = NULL;
        }
    }

    return relNode;

}
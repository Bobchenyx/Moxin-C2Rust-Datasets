/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int count = 0;
    struct ListNode* tmp = head;
    while (tmp) {
        tmp = tmp->next;
        count++;
    }
    tmp = head;
  
    if (count % 2 == 0)
        count = (count + 1) / 2;
    else
        count = count / 2;

    while (count) {
        tmp = tmp->next;
        count--;
    }
    return tmp;
}
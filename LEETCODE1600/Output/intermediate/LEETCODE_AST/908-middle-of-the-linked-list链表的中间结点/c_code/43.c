/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* p1 = head;
    int count = 1;
    while (p1->next != NULL) {
        count++;
        p1 = p1->next;
    }

    if (count == 1) {
        return head; // 只有1个结点
    }

    int midPotion = count / 2 + 1;
    p1 = head;
    int position = 1;
    while (p1->next != NULL) {
        position++;
        p1 = p1->next;
        if (position == midPotion) {
            return p1;
        }
    }

    return NULL;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    int i = 0;
    int pos;
    struct ListNode *listNodeCpy = head;
    int listNodeNum = 0;
    while (listNodeCpy != NULL) {
        listNodeCpy = listNodeCpy->next;
        listNodeNum++;
    }
    if (listNodeNum == 0) {
        return NULL;
    }
    if (listNodeNum % 2 == 0) {
        //4 4/2 + 1 = 2 + 1 =3
        pos = listNodeNum / 2;
    } else {
        pos = listNodeNum / 2;
    }

    for (i = 0; i < pos; i++) {
        head = head->next;
    }
    
    return head;
}
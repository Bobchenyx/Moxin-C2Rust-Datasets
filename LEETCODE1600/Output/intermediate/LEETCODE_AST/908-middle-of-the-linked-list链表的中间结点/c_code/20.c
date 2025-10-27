/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

void Recurse(node* n, int* cnt,int* size, node** res)
{
    if (!n) {
        *size = *cnt;
        (*cnt)++;
        *cnt /= 2;
        return;
    }
    (*cnt)++;
    Recurse(n->next, cnt, size, res);
    (*cnt)--;
    if (*cnt == 0) {
        *res = n;
    }
    return;
}

struct ListNode* middleNode(struct ListNode* head){
    if (!head) {
        return head;
    }
    int cnt = 0;
    int size = 0;
    node* res = NULL;
    Recurse(head, &cnt, &size, &res);
    return res;
}
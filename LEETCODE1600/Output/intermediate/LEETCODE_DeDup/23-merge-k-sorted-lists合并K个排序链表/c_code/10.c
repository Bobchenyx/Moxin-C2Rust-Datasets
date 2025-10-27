// merge2Lists,顾名思义，把两个链表合并到一起，需要考虑到各种可能的异常
struct ListNode* merge2Lists(struct ListNode* head1, struct ListNode* head2)
{
    struct ListNode * head = NULL;
    struct ListNode * tail = NULL;

    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    if (head1->val <= head2->val) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }

    while (1) {
        if ((head1 == NULL) && (head2 != NULL)) {
            tail->next = head2;
            head2 = NULL;
            break;
        }
        if ((head2 == NULL) && (head1 != NULL)) {
            tail->next = head1;
            head1 = NULL;
            break;
        }

        if (head1->val <= head2->val) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;            
        } else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int left = 0;
    int right = 0;
    int count = 0;

    if (listsSize <= 0) {
        return NULL;
    }

    do {
        count = 0;
        left = 0;
        right = listsSize-1;
        while (left < right) {
            lists[count++] = merge2Lists(lists[left++], lists[right--]);
        }   
        listsSize = (left == right)? left+1:left;
    } while (listsSize != 1);

    return lists[0];
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int mindex;
    struct ListNode* tmp[2];
    struct ListNode* head;
    struct ListNode* point;
    head = point = NULL;
    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];
    if (listsSize == 2) {
        while(lists[0] && lists[1]) {
            if (lists[0]->val < lists[1]->val) {
                if (head) {
                    point->next = lists[0];
                    point = point->next;
                } else {
                    point = head = lists[0];
                }
                lists[0] = lists[0]->next;
            } else {
                if (head) {
                    point->next = lists[1];
                    point = point->next;
                } else {
                    point = head = lists[1];
                }
                lists[1] = lists[1]->next;
            }
        }
        if (lists[0]) {
            if (head)
                point->next = lists[0];
            else
                point = head = lists[0];
        } else if (lists[1]) {
            if (head)
                point->next = lists[1];
            else
                point = head = lists[1];
        }
        return head;
    }
    mindex = listsSize / 2;
    tmp[0] = mergeKLists(lists, mindex);
    tmp[1] = mergeKLists(lists + mindex, listsSize - mindex);
    return mergeKLists(tmp, 2);
}
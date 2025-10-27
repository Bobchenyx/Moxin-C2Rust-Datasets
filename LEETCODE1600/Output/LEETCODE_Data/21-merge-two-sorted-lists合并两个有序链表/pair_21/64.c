struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)return l2;
    if(l2 == NULL)return l1;
    struct ListNode *currItem = l1;
    while(currItem->next){
        currItem = currItem->next;
    }
    currItem->next = l2;
    currItem = l1;
    struct ListNode *nextItem = NULL;
    while(currItem){
        int temp;
        nextItem = currItem->next;
        while(nextItem){
            // 这里并没有交换节点，而是交换了值
            if(currItem->val > nextItem->val){
                temp = currItem->val;
                currItem->val = nextItem->val;
                nextItem->val = temp;
            }
            nextItem = nextItem->next;
        }
        currItem = currItem->next;
    }
    return l1;
}
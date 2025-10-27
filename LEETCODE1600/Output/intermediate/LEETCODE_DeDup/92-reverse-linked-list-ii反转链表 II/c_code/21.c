struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
//借助额外的空间
    int len = n-m+1;
    int i=1,count=0;
    struct ListNode *p, *q;
    p=q=head;
    int arr[len];
    while(i<=n) {
        if(i==m)
            p = q;
        if(i>=m)
        {
            arr[count]=q->val;
            count++;
        }
        q = q->next;
        i++;
    }
    while(p!=q)
    {
        p->val = arr[count-1];
            count--;
        p = p->next;
    }
    return head;
}
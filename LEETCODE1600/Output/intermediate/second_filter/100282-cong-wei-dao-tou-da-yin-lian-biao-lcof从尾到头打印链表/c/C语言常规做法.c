int* reversePrint(struct ListNode* head, int* returnSize){
    if(head==0){
        *returnSize=0;
        return 0;
    }
    struct ListNode*tmp,*header=head;
    int length=1,i;
    while(head->next!=0){
        length++;
        tmp=head->next;
        head->next=tmp->next;
        tmp->next=header;
        header=tmp;
    }
    *returnSize=length;
    int *res=malloc(length*sizeof(int));
    for(i=0;i<length;i++){
        res[i]=header->val;
        header=header->next;
    }
    return res;
}
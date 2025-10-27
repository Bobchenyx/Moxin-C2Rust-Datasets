int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int s[50000],k=0;
    for(int i=0;i<listsSize;i++)
    {
        while(lists[i]!=NULL)
        {
            s[k++]=lists[i]->val;
            lists[i]=lists[i]->next;
        }
    }
    if(k==0)return NULL;
    qsort(s,k,sizeof(int),cmp);
    struct ListNode *p=NULL,*res,*head;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=s[0];
    p=head;
    res=head;
    for(int i=1;i<k;i++)
    {
        head=(struct ListNode*)malloc(sizeof(struct ListNode));
        head->val=s[i];
        p->next=head;
        p=head;
    }
    p->next=NULL;
    return res;
}
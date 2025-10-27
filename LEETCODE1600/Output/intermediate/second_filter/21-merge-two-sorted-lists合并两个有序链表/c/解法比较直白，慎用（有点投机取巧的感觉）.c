/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head, *nl1, *nl2, *head1, *head2;
    head1=l1; head2=l2;
    int cnt=0;
    if(head1==NULL) return head2;
    else if(head2==NULL) return head1;
    while(head1->next!=NULL){
        head1=head1->next;
        cnt++;
    }
    cnt++;
    while(head2->next!=NULL){
        head2=head2->next;
        cnt++;
    }
    head2->next=l1;
    cnt++;
    int a[cnt];
    head1=l1; head2=l2;
    int i=cnt;
    for(int j=0;j<cnt;j++){
        a[j]=head2->val;
        head2=head2->next;
    }
    qsort(a,i,sizeof(int),comp);
    cnt=i;head2=l2;i=0;
    while(cnt--){
        head2->val=a[i];
        head2=head2->next;
        i++;
    }
    return l2;
}
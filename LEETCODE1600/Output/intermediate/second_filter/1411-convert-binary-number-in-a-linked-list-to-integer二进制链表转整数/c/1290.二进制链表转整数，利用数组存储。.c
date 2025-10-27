/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int count=0;
    int SUM=0;
    int i,j,n;
    int a[30];
    int *m;
    while(head!=0)
    {
      a[count]=head->val;
      head=head->next;
      count++;
    }
  for(i=count-1;i>=0;i--)
  {
      n=count-1-i;
      m=&a[i]; 
      j=*m;
      SUM+=j<<n;
  }
    return SUM;
}
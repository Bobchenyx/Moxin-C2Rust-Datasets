/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2){
    struct ListNode *shortlist,*longlist,*q,*p,*newhead;
    int len1=0,len2=0;
    q=l1;
    while(l1){
        len1++;
        l1=l1->next;

    }
    p=l2;
    while(l2){
        len2++;
        l2=l2->next;
    }
    int m=len2>len1?len2:len1;
    int ln=len2>len1?len2-len1:len1-len2;
    int *a;
    a=(int *)malloc(sizeof(int)*(m+2));
    a[m+1]=0;
    
    if(len2>len1){
        shortlist=q;
        longlist=p;
    }
    else{
       shortlist=p;
        longlist=q; 
    }
    q=longlist;
    
    int k;
    k=1;
    while(shortlist!=NULL){
        a[k++]=longlist->val+shortlist->val;
        
        longlist=longlist->next;
        shortlist=shortlist->next;
    }
    while(longlist){
        a[k++]=longlist->val;        
       // k++;
        longlist=longlist->next;
    }
    
    for(int j=1;j<=m;j++){
        if(a[j]>9){
            int t=a[j]%10;
            int n=a[j]/10;
            a[j+1]+=n;
            a[j]=t;
        }

    }
    
    
    
    
       p=q;
        for(int i=1;i<=m;i++){
            q->val=a[i];
            
            if(q->next!=NULL) 
            q=q->next;
        }
        if(a[m+1]>0){
        newhead=(struct ListNode *)malloc(sizeof(struct ListNode));
        newhead->val=a[m+1];
        q->next=newhead;
        newhead->next=NULL;
        
    }
    newhead=p;

    return newhead;
}
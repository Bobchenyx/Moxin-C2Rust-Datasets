/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* cur =(struct ListNode*) calloc(1, sizeof(struct ListNode));
	struct ListNode* ret;
	
	ret = cur;
	int add=0;
	int tmp1,tmp2,vtmp;
	while((l1!=NULL)||(l2!=NULL)||(add!=0)){
		
		if(l1!=NULL){
			tmp1 = l1->val;
			l1 = l1->next;
		}else{
			tmp1=0;
		}
		
		if(l2!=NULL){
			tmp2 = l2->val;
			l2 = l2->next;
		}else{
			tmp2=0;
		}
		
		vtmp = tmp1+tmp2+add;
		
		
		cur->next =(struct ListNode*) calloc(1, sizeof(struct ListNode));
		cur->next->val = vtmp%10;
		add=vtmp/10;
		cur = cur->next;

	
	}
	return ret->next;
}
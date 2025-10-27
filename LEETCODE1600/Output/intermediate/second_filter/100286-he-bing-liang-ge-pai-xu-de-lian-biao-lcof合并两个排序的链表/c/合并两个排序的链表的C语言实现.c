/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    //入参检查
    if((l1 == NULL) && (l2 == NULL))
    {
        return NULL;
    }

    if((l1 == NULL) && (l2 != NULL))
    {
        return l2;
    }

    if((l1 != NULL) && (l2 == NULL))
    {
        return l1;
    }

	struct ListNode* result= (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode*temp=result;
	if(l1->val>l2->val)
	{
		temp->next=l2;
		l2=l2->next;
	}
	else
	{
		temp->next=l1;
		l1=l1->next;
	}

	temp=temp->next;
	temp->next=mergeTwoLists(l1,l2);

	return result->next;
}
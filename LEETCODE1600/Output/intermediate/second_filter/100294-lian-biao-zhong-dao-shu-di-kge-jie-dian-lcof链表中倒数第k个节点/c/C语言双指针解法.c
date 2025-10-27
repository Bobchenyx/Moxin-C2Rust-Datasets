/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *former = head;
	struct ListNode *latter = head;
	for (int i = 0; i < k; i++)
	{
		former = former->next;
	}
	while (former!=NULL)
	{
		former = former->next;
		latter = latter->next;
	}
	return latter;
}
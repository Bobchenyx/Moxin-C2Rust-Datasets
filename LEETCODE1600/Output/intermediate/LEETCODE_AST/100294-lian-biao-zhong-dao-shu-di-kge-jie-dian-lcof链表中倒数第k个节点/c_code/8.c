/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int len = 0;
	struct ListNode *temp = head;
	while (temp!=NULL)
	{
		len++;
		temp = temp->next;
	}
	struct ListNode *getlist=head;
	for (int i = 1; i <= len; i++)
	{
		if (i<=len-k)
		{
			getlist = getlist->next;
		}
		else
		{
			return getlist;
		}
	}
    return getlist;
}
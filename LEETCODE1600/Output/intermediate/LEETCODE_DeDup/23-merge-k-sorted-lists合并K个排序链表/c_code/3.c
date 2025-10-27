/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p ,*rear;
	int index, count, min,i;
    index = 0;
	newhead->next = NULL;
    rear = newhead;
	while (1)
	{
		count = 0;
		for (i = 0; i < listsSize; i++)
			if (!lists[i])
				count++;
		if (count == listsSize)
			break;
		min = INT_MAX;
		for (i = 0; i < listsSize; i++)
		{
			if(!lists[i])
                continue;
            else
            {
                if(min>lists[i]->val)
                {
                    min = lists[i]->val;
                    index = i;
                }
            }

		}
        if(min != INT_MAX)
        {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->val = lists[index]->val;
            p->next = NULL;
            rear->next = p;
            rear = p;
            lists[index] = lists[index]->next;
        }
	}

	return newhead->next;
}
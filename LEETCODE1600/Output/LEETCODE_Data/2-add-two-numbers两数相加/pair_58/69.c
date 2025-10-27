/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       ListNode* temp1 = l1;
		ListNode* temp2 = l2;
		int t;
		bool carry = false;
		for (; temp1->next&&temp2->next; temp1 = temp1->next, temp2 = temp2->next)
		{
			t = temp1->val + temp2->val + carry;
			if (t >= 10)
			{
				carry = true;
			}
			else
				carry = false;
			temp1->val = t % 10;

		}
		if (!temp1->next && !temp2->next)
		{
			t = temp1->val + temp2->val + carry;
			temp1->val = t % 10;
			temp1->val = t % 10;
			if (t >= 10)
			{
				
				temp1->next = new ListNode(1);
			}
			return l1;
		}
		if (temp1->next)
		{
			t = temp1->val + temp2->val + carry;
			if (t < 10)
			{
				temp1->val = t;
				return l1;
			}
			for (; temp1->next; temp1 = temp1->next)
			{
				temp1->val = t % 10;
				if (t >= 10)
					carry = true;
				else
					carry = false;
				t = temp1->next->val + carry;
				temp1->next->val = t;
			}
			if (t >= 10)
			{
				temp1->val = t % 10;
				temp1->next = new ListNode(1);
			}
			return l1;

		}
		if (temp2->next)
		{
			t = temp1->val + temp2->val + carry;
			temp1->next = temp2->next;
			if (t < 10)
			{
				temp1->val = t;
				return l1;
			}
			for (; temp1->next; temp1 = temp1->next)
			{
				temp1->val = t % 10;
				if (t >= 10)
					carry = true;
				else
					carry = false;
				t = temp1->next->val + carry;
				temp1->next->val = t;
			}
			if (t >= 10)
			{
				temp1->val = t % 10;
				temp1->next = new ListNode(1);
			}
			
		}
		return l1;

    }

};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> list;
        ListNode *p = head ;
        while(p)
        {
            list.push_back(p);
            p=p->next;
            
        }

        int len = list.size();
        // 长为len ， 删除倒数第n个，也就是删除正数第len -n+1,下标为 len-n；
        int i = len-n;
        if(i==0)
        {
            head=head->next;    //delect hesd
        }
        else if(i>0&&i<len)
        {
            ListNode *p = list[i-1]; //被删除节点的前驱节点
            p->next = p->next->next;
        }

        return head;
        
    }
};
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode *> res;
        while(head!=NULL){
            res.push_back(head);
            head=head->next;
        }
        return res[res.size()/2];
    }
};
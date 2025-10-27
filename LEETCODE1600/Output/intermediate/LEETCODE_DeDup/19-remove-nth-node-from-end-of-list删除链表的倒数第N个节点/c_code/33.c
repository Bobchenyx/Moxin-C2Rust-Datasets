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
    int dfs(ListNode* a,int n){
        if(a->next==NULL)
            return 1;
        int m=dfs(a->next,n);
        if(m==n){
            a->next=a->next->next;
        }
        return m+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=dfs(head,n);
        if(m==n){
            return head->next;
        }
        return head;
    }
};
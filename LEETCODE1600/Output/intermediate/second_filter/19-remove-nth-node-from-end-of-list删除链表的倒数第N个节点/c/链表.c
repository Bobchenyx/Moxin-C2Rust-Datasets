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
        ListNode *p=new ListNode(0);//创建一个头节点为0的链表
        p->next=head;//接上head链表
        ListNode *j1=p;//定义移动指针从头节点开始
        ListNode *j2=p;
        for(int k=0;k<=n;k++) j2=j2->next;//间隔选取为n
        while(j2)
        {
            j1=j1->next;
            j2=j2->next;
        }//此时j2已经为NULL，j1->next即要删除的节点
        j1->next=j1->next->next;//跳过要删的节点即可
        return p->next;//不要记入头节点
    }
};
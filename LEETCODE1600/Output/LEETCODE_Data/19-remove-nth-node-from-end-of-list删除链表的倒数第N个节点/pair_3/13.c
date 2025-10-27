/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode** record = (struct ListNode**)malloc(sizeof(struct ListNode*)*n);//存储从倒数第二个开始的，往回数的n个点，因此第一个点（即index下的点）的下一个是需要去掉的，所以record[index%n]->next = record[(index+2)%n]
    int index = 0;
    struct ListNode* temp = head;
    while (temp->next != NULL)
    {
        record[index%n] = temp;
        temp = temp->next;
        index++;
    }
    if (index < n)//表示去掉头
        return head->next;
    if (n == 1)
        record[index%n]->next = NULL;
    else if (n == 2)
        record[index%n]->next = temp;
    else
        record[index%n]->next = record[(index+2)%n];
    return head;
}
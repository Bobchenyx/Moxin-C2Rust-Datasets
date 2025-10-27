/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int listLength(struct ListNode *head)
{   
    if(!head)
    {
        return 0;
    }

    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}

int getDecimalValue(struct ListNode* head)
{
    int sum = 0;
    if(!head)
    {
        sum = 0;
    }
    else
    {
        //获取链表长度
        int length = listLength(head);
        //循环遍历链表
        while(head)
        {
            sum += (int)pow(2,--length)*(head->val);
            head = head->next;
        }
    }
    return sum;
}
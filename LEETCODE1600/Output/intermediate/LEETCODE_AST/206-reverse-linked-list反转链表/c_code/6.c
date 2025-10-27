struct ListNode *Reverse(struct ListNode *head)
{
    if (head->next == NULL)
        return head;
    Reverse(head->next)->next = head;
    return head;
}

struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    struct ListNode *end;
    struct ListNode *Copy_Head = head;
    while (Copy_Head->next != NULL)
        Copy_Head = Copy_Head->next;
    end = Copy_Head;
    Reverse(head)->next = NULL;
    return end;
}
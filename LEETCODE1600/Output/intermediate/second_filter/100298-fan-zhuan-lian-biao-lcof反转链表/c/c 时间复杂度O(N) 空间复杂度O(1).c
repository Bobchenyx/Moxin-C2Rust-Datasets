/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
*
*整体思路：
*1.将curr更新为head -> next，令head -> next = NULL,避免死循环
*2.如果curr不为NULL，进入步骤3，否则进入步骤7
*3.利用中间变量tmp占存curr->next
*4.将curr的next指向前面一个结点head
*5.更新head指向当前节点curr
*6.移动curr到下一个结点，即将暂存的tmp传给curr，进入步骤2
*7.返回head
*/

struct ListNode* reverseList(struct ListNode * head){

    //if head is NULL, returning head
    if( head == NULL ){

        return head;

    }

    //the parameter of curr points to current node in link
    struct ListNode * curr = head -> next;
    //haed points to former node in link
    head -> next = NULL;

    while( curr != NULL ){

        //saving next node in tmp
        struct ListNode * tmp = curr -> next;

        //the pointer of next in current points to fomer node
        curr -> next = head;
        //head points current node
        head = curr;
        //curr points next node
        curr = tmp;

    }

    return head;

}
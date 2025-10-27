/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL){
        return NULL;
    }
    struct ListNode* oddHeah = head; // 保存奇数u偶数链表头部
    struct ListNode* oddNode = oddHeah;
    struct ListNode* evenHeah = head -> next;
    struct ListNode* evenNode = evenHeah;
    while(evenNode != NULL && evenNode -> next != NULL){
        oddNode -> next = oddNode -> next -> next;
        evenNode -> next = evenNode -> next -> next;
        oddNode = oddNode -> next;
        evenNode = evenNode -> next;
    }
    oddNode -> next = evenHeah; // 拼接链表， 循环结束时 oddNode 指向奇数链表最后一个元素
    return oddHeah;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* rear = malloc(sizeof(struct ListNode));
    struct ListNode* front = malloc(sizeof(struct ListNode));
    front = rear = head;
    while(rear!=NULL&&rear->next!=NULL){
        front = front ->next;
        rear = rear ->next -> next;
    }
    return front;
}

/*
struct ListNode* middleNode(struct ListNode* head){
    int cou=0;
    struct ListNode* rear = malloc(sizeof(struct ListNode));
    rear = head;
    while(rear!=NULL){
        ++cou;
        rear = rear ->next;
    }
    rear = head;
    int k = cou/2;
    for(int i =1;i<=k;i++){
        rear = rear->next;
    }
    return rear;
}
*/
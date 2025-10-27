/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

方法1：原创，多次尝试的结果。
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;
    struct ListNode *head, *l3, *l4, *incre, *p;
    head = l2;
    while (l1 && l2){
        l2 -> val += l1 -> val + carry;
        if (l2 -> val >= 10){
            l2 -> val %= 10;
            carry = 1;
        }
        else
            carry = 0;
        if (l2 -> next == NULL){
            l3 = l2;//l3指向l2的末尾元素
        }
        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    if (l1){//l1长于l2
        p = l1;
        while (l1){
            l1 -> val += carry;
            if (l1 -> val >= 10){
                l1 -> val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            if (l1 -> next == NULL)
                l4 = l1;
            l1 = l1 -> next;
        }
        if (carry){
            incre =(struct ListNode*)malloc(sizeof(struct ListNode));
            incre -> val = 1;
            //头插法的运用
            incre -> next = l4 -> next;
            l4 -> next = incre;
        }   
        l3 -> next = p;
    }
    else if(l2){//l2长于l1
        while (l2){
            l2 -> val += carry;
            if (l2 -> val >= 10){
                l2 -> val %= 10;
                carry = 1;
            }
            else
                carry = 0;
            if (l2 -> next == NULL)
                l4 = l2;
            l2 = l2 -> next;
        }
        if (carry){
            incre =(struct ListNode*)malloc(sizeof(struct ListNode));
            incre -> val = 1;
            incre -> next = l4 -> next;
            l4 -> next = incre;
        }   
    }
    else{//l1和l2一样长
        if (carry){
            incre =(struct ListNode*)malloc(sizeof(struct ListNode));
            incre -> val = 1;
            incre -> next = l3 -> next;
            l3 -> next = incre;
        }
    }
    return head;
}
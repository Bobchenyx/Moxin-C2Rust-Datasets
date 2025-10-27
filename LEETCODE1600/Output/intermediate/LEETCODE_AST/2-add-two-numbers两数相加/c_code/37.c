/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 #include<stdlib.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    int count=0;//用于进位
    int sum=0;//两数相加
    struct ListNode *pNewList=(struct ListNode*)malloc(sizeof(struct ListNode));
    pNewList->val=-1;
    pNewList->next=NULL;
    struct ListNode *pTempList=pNewList;
    while(l1&&l2)//两个链表都不为空
    {
        sum=l1->val+l2->val+count;
        if(sum>9)
        {
            sum%=10;
            count=1;
        }
        else
        {
            count=0;
        }
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=sum;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pNode;

        l1=l1->next;
        l2=l2->next;
    }
    while(l1)//l1链表长度大于l2链表长度
    {
        sum=l1->val+count;
        if(sum>9)
        {
            sum%=10;
            count=1;
        }
        else
        {
            count=0;
        }
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=sum;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pNode;
        l1=l1->next;
    }
    while(l2)//l2链表长度大于l1链表长度
    {
        sum=l2->val+count;
        if(sum>9)
        {
            sum%=10;
            count=1;
        }
        else
        {
            count=0;
        }
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=sum;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pNode;
        l2=l2->next;
    }
    if(count)//最后进位1需要创建一个节点存储
    {
        struct ListNode*pNode=(struct ListNode*)malloc(sizeof(struct ListNode));
        pNode->val=count;
        pNode->next=NULL;
        pTempList->next=pNode;
        pTempList=pTempList->next;
    }

    return pNewList->next;
}
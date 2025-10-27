struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
/*算法思想：
先便利两个链表过清楚到底有多少位，然后拉到相同的位做相加
学习心得：
没有typedef 请使用 struct node的类定义变量，不要省略

指针操作出现了严重的失 
*/

    struct ListNode* retListNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    retListNode->next = NULL;
    struct ListNode* headListNode;
    headListNode = retListNode;
    headListNode->next = NULL;

    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    int l1Num = 0;
    int l2Num = 0;

    while (p1 != NULL){
        l1Num ++;
        p1 = p1->next;
    }
    while (p2 != NULL){
        l2Num ++;
        p2 = p2->next;
    }    
    int preStep = l1Num - l2Num;
    p1 = l1;//reset pointer
    p2 = l2;

    /*交换*/
    if (preStep < 0){
        struct ListNode* temp;
        temp = p1;
        p1 = p2;
        p2 = temp;
        preStep = -preStep;
        l2Num = l1Num;
    }
    /*一样长*/
    if (preStep == 0){
        int tag = 0;
        while (p1 != NULL){
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode2->val = p1->val + p2->val + tag;
            if ( newNode2->val > 9){//进位判断
                tag = 1;
                newNode2->val = newNode2->val%10;
            }
            else{
                tag = 0;
            }
            p1 = p1->next;
            p2 = p2->next;

            retListNode->next = newNode2;
            retListNode = retListNode->next; 
         }
         if (tag == 1){//最终还有进位
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode2->val = 1;
            retListNode->next = newNode2;
            retListNode = retListNode->next; 
         }
        retListNode->next = NULL;
        retListNode = headListNode->next;

        return retListNode;
    }
    else{
        /*不一样长
        先处理前面*/
        int tag = 0;
        while ( l2Num-- > 0 ){
            struct ListNode* newNode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode2->val = p1->val + p2->val + tag;
            if ( newNode2->val > 9){//进位判断
                tag = 1;
                newNode2->val = newNode2->val%10;
            }
            else{
                tag = 0;
            }
            p1 = p1->next;
            p2 = p2->next;

            retListNode->next = newNode2;
            retListNode = retListNode->next; 
        } 
        /*再摘取较长节点*/
        while ( p1 != 0 ){
            struct ListNode* newNode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode3->val = p1->val + tag;
            if ( tag == 1){
                tag = 0;
            }
            if (newNode3->val > 9){
                tag = 1;
                newNode3->val = newNode3->val%10;
            }
            p1 = p1->next;
            retListNode->next = newNode3;
            retListNode = retListNode->next; 
        }
        if (tag == 1){
            struct ListNode* newNode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
            newNode4->val = 1;
            retListNode->next = newNode4;
            retListNode = retListNode->next; 
        }
        retListNode->next = NULL;
        retListNode = headListNode->next;  
    }
return retListNode;
}
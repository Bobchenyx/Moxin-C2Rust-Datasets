typedef struct ListNode ListNode;

ListNode* createList();
ListNode* copy(ListNode* , int );

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    ListNode* l3 = createList();//initialize to be 0
    ListNode* last = l3;
    ListNode* node = NULL;

    int remain , overflow , temp;

    //if input is 0
    if(l1->val == 0 && l1->next == NULL)
    {
        l3 = copy(l2,0);
        return l3 ;
    }else if(l2->val == 0 && l2->next == NULL)
    {
        l3 = copy(l1,0);
        return l3;
    }
    // both two of the input is not zero
    temp = l1->val+l2->val;

    remain = temp%10;
    overflow = temp/10;

    l3->val = remain;
    l1 = l1->next;
    l2 = l2->next;
    
    while(l1&&l2)
    {
        temp = l1->val+l2->val+overflow;

        remain = temp % 10;
        overflow = temp/10;

        node = malloc(sizeof(ListNode));

        node->val = remain;
        node->next = NULL;

        last->next = node;
        last = node;

        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 == NULL)
    {
        node = copy(l2,overflow);

        last->next = node;

        return l3;
    }
    if(l2 == NULL)
    {
        node = copy(l1,overflow);

        last->next = node;

        return l3;
    }

   return l3;

}

struct ListNode* createList()
{
    ListNode* temp  = malloc(sizeof(ListNode));

    temp->val = 0;

    temp->next = NULL;

    return temp;
}

ListNode* copy(ListNode* target,int overflow)
{
    ListNode* l = NULL;
    ListNode* temp = NULL;
    ListNode* last = NULL;

    int remain , over , result;

    l = malloc(sizeof(ListNode));
    //first do the safty check
    if(target == NULL && overflow == 0)
    {
        return NULL;
    }
    if(target == NULL && overflow != 0)
    {
        temp = malloc(sizeof(ListNode));

        temp->val = overflow;

        temp->next =NULL;

        return temp;
    }
    
    result = target->val + overflow;

    remain = result%10;
    over = result/10;

    l->val = remain;

    l->next = NULL;

    target = target->next;

    last = l;
    
    while(target)
    {
        temp = malloc(sizeof(ListNode));

        result = target->val + over;
        remain = result%10;
        over = result/10;
        
        temp->val = remain;

        temp->next =NULL;

        last->next = temp ;

        last = temp ;

        target = target->next;
    }
    //check the overflow 
    if(over == 0)
    {
        return l;
    }
    else 
    {
        temp = malloc(sizeof(ListNode));

        temp->val = over;

        temp->next = NULL;

        last->next = temp;
        

        return l;
    }

    
}
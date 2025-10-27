/**
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l0, struct ListNode* l2){
    if(l0==NULL) return l2;
    if(l2==NULL) return l0;
    struct ListNode *l1 = l0,*prior=NULL;   //prior为l1的前继指针，这个用于后续申请空间，保存null前的结点
    int add_num=0,sum;
    while(l1!=NULL&&l2!=NULL){      //情况1: l1和l2长度一样,且不进位
        sum = l1->val+l2->val+add_num;
        l1->val = sum%10;
        add_num = sum/10;    //进位数
        prior = l1;         
        l1=l1->next;l2=l2->next;
    }
    if(l1==NULL||l2==NULL){   //这个if好像没用
        while(l2!=NULL){       //情况2: l2比l1长
            if(l1==NULL) prior->next=(struct ListNode*)malloc(sizeof(struct ListNode));//申请节点，分配给l1
            prior->next->next= NULL;    //必需，malloc必须声明其next指针指向，否则异常
            l1=prior->next;
            l1->val = (l2->val+add_num)%10;
            add_num = (l2->val+add_num)/10;
            l1=l1->next;l2=l2->next;prior=prior->next;
        }
        if(add_num!=0&&l1==NULL){   //情况2-1: l2比l1长之最后一个数进位与否问题（如：1+999）
            prior->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            prior->next->next= NULL;    //必需，malloc必须声明其next指针指向
            l1=prior->next;
            l1->val = add_num;
            add_num = add_num/10;
            l1=l1->next;prior=prior->next;
        }
        while(l1!=NULL&&add_num!=0){     //情况3: l1比l2长
            sum = l1->val+add_num;
            l1->val = sum%10;
            add_num = sum/10;
            l1=l1->next;prior = prior->next;
        }
        if(add_num!=0&&l1==NULL){       //情况3-1: 进位超过长度，申请新空间
            prior->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            prior->next->next = NULL;
            l1=prior->next;
            l1->val = add_num;
        }
    }
    return l0;
}
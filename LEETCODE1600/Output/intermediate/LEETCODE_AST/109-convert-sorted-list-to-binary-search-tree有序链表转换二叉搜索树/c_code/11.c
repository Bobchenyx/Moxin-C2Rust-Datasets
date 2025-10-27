struct TreeNode* sortedListToBST(struct ListNode* head)
{
    if(head==NULL)
        return NULL;
    struct TreeNode *tree=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct ListNode *pre=head;
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    //这里注明一下：pre初始值如果是NULL，则后面无法给它赋值pre->next,如果初始值是head可能slow最终也指向了head，此时pre容易在二叉搜索树中被插入两次（递归的问题）
     tree->val=slow->val;
    if(slow==pre)  //如果这两个指针相等
        tree->left=NULL;
    else
    {
        pre->next=NULL;
        tree->left=sortedListToBST(head);
    }
    tree->right=sortedListToBST(slow->next);
    return tree;

}
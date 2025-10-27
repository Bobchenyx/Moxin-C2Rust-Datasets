struct TreeNode *createTree(int val){
    struct TreeNode *node;
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *helper(struct ListNode *start, struct ListNode *end){

    if (end != NULL) printf("%d, %d\n", start->val, end->val);
    if (end == NULL) printf("%d\n", start->val);
    //终止条件
    //一个节点
    if ( start  == end || start->next == NULL){
        struct TreeNode *node = createTree(start->val);
        return node;
    }
    //两个节点
    if (start->next == end){
        struct TreeNode *root, *child;
        root = createTree(start->next->val);
        child = createTree(start->val);
        root->left = child;
        return root;
    }
    struct ListNode *slow = start, *fast=start;
    while ( true ){
        fast = fast->next->next;
        if ( fast != end || fast->next != end ) break;
        slow = slow->next;
    }
    struct TreeNode *root;
    root = createTree(slow->next->val);
    root->left = helper(start, slow);
    root->right = helper(slow->next->next ,fast);
    return root;
  
}
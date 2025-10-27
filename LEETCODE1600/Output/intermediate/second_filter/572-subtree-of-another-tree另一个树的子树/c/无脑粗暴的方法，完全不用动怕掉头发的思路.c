bool isSameTree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL && t == NULL) return true;
    if(s == NULL || t == NULL) return false;
    if(s->val != t->val) return false;
    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
}
void Preorder(struct TreeNode *root, int head, int * index, struct TreeNode** arr)
{
    if(root)
    {
        if(root->val == head) {
            arr[*index] = root;
            ++(*index);
        }
        Preorder(root->left, head, index, arr);
        Preorder(root->right, head, index, arr);
    }
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    struct TreeNode* arr[1024] = {0};
    int index =0;
    Preorder(s,t->val ,&index, arr);
    for(int i = 0; arr[i] != 0; i++)
    {
      if(isSameTree(arr[i], t))  return true;
      
    }
    return false;
}
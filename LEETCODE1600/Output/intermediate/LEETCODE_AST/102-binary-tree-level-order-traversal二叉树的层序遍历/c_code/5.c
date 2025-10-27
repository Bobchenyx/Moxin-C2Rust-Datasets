int getDepth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = getDepth(root->left);
    int r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

//递归的求每一层的个数，存到数组cnt里
void getcnt(struct TreeNode *root, int k, int *cnt) { //从第K曾开始求
    if(root == NULL) return ;
    cnt[k] += 1;
    getcnt(root->left, k + 1, cnt);
    getcnt(root->right, k + 1, cnt);
    return ;
}

void getresult(struct TreeNode *root, int k, int *cnt, int **ret) {
    if(root == NULL) return ;
    ret[k][cnt[k]++] = root->val; //把当前第k层的第cnt[k]++个进ret
    getresult(root->left, k + 1, cnt, ret);
    getresult(root->right, k + 1, cnt, ret);
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);//求层数
    int **ret =(int **)malloc(sizeof(int *) * depth); //给第一维开空间
    int *cnt = (int *)calloc(depth, sizeof(int)); //每层节点个数
    getcnt(root, 0, cnt);
    for(int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]); //给第二维开空间
        cnt[i] = 0; // 清零重复使用
    }
    getresult(root, 0, cnt, ret);
    *returnSize = depth; // 第一维大小， 即层数
    *returnColumnSizes = cnt; 
    /*每一层的个数(returnColumnSizes 是传出参数，本身是一个一维数组，存每一层的个数，因为是传出参数，故* *returnColumnSizes)*/
    return ret;
}
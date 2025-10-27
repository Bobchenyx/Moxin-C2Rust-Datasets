struct TreeNode* convertBST(struct TreeNode* root){
    calcNode(root);
}

int calcNode(struct TreeNode * node, int extend){
    int right, left;

    if(node.right!=NULL){
        right = calcNode(node.right, extend);
    } else {
        right = extend;
    }
    node.val += right;
    if(node.left!=NULL){
        left = calcNode(node.left, node.val);
    } else {
        left = node.val;
    }

    return left;
}
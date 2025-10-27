struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
	if (!preorderSize)
		return 0;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));

	root->val = preorder[0];
	int i = 0;
	for (; i < preorderSize; i++)
		if (root->val == inorder[i])
			break;

	root->left = buildTree(preorder + 1, i, inorder, 0);
	root->right =
		buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, 0);

	return root;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *ary[10000];

int maxDepth(struct TreeNode* root){
    int depth = 0;
	int top = 0;
	int tail = 1;

	ary[0] = root;

	if (root == NULL) {
		return 0;
	}

	while (top < tail) {
		depth++;
		int tmp = tail;
		int curlen = tail;
		for (int k = top; k < curlen; k++) {
			if (ary[k]->left != NULL) {
				ary[tail] = ary[k]->left;
				tail++;
			}
			if (ary[k]->right != NULL) {
				ary[tail] = ary[k]->right;
				tail++;
			} 
		} // 遍历层
		top = tmp;
	}
	return depth;

}
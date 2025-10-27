/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
	
	if(t1==NULL&&t2==NULL) return NULL;

	// struct TreeNode*  node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* node;
	if(t1!=NULL && t2!=NULL) {
		node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		node->val = t1->val + t2->val;		

		node->left = mergeTrees(t1->left, t2->left);
		node->right = mergeTrees(t1->right, t2->right);
	}

    struct TreeNode* head = node;

	if(t1==NULL) return t2;
	if(t2==NULL) return t1;

    return head;
}
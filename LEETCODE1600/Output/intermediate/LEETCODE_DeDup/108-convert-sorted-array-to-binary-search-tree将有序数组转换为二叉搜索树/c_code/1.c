/* *
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
struct TreeNode *GetTree(int *nums, int numsSize)
{
    if (numsSize <= 0) {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    memset(root, 0x0, sizeof(struct TreeNode));
    int rootPos = (numsSize / 2);
    root->val = nums[rootPos];

    root->left = GetTree(nums, rootPos);
    root->right = GetTree(&nums[rootPos + 1], numsSize - rootPos - 1);
    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0) {
        return NULL;
    }

    if (numsSize == 1) {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        if (root == NULL) {
            return NULL;
        }

        memset(root, 0x0, sizeof(struct TreeNode));
        root->val = nums[0];
        return root;
    }

    return GetTree(nums, numsSize);
}
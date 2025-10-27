root->left = buildBST(nums, low, mid-1);
    root->right = buildBST(nums, mid+1, high);
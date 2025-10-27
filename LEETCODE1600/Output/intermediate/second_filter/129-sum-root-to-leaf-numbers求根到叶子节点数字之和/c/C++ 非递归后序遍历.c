class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return {};
        int res = 0;
        TreeNode* prev = root;
        vector<TreeNode*> tree_st;
        tree_st.push_back(root);

        while(!tree_st.empty()){
            auto cur = tree_st.back();
            if(cur->left && cur->left!= prev && cur->right!=prev){
                tree_st.push_back(cur->left);
            }else if(cur->right && cur->right!=prev){
                tree_st.push_back(cur->right);
            }else{
                //到了叶节点，正序遍历栈
                if(!cur->left && !cur->right){
                    int cur_int = 0;
                    for_each(tree_st.cbegin(),tree_st.cend(),
                        [&cur_int](auto& ptr){cur_int = cur_int*10; cur_int+=ptr->val;});
                    //cout<<cur_int<<endl;
                    res += cur_int;
                }


                tree_st.pop_back();
                prev = cur;
            }
        }
        return res;
    }

};
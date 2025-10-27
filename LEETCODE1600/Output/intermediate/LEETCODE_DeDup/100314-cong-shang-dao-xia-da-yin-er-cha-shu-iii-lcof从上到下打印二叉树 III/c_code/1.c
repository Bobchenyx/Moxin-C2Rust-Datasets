class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root) return {};
        vector<vector<int>> res;
        vector<int> v;
        queue<pair<TreeNode*,int>>Q;
        int depth=0,size=1;
        TreeNode* tmp=NULL;
        Q.push({root,1});
        while(!Q.empty())
        {
            while(size-->0)
            {
                tmp=Q.front().first;
                depth=Q.front().second;
                Q.pop();

                if(tmp->left){
                    Q.push({tmp->left,depth+1});
                }
                if(tmp->right){
                    Q.push({tmp->right,depth+1});
                }

                v.push_back(tmp->val);
            }
            if(depth%2==0)
                reverse(v.begin(),v.end());
            res.push_back(v);
            v.clear();
            size=Q.size();
        }
        return res;
    }
};
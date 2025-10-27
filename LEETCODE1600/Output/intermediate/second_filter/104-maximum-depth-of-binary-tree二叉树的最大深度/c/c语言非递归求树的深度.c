/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    int ans = 0;
    int currentLevel = 1;
    int nextLevel = 0;
    struct TreeNode* array[50000];
    array[0] = root;
    int front = 0;
    int rear = 0;
    while(front <= rear){
        if(currentLevel == 0){//当前层节点数等于0说明d这一层已经访问完
            currentLevel = nextLevel;//开始访问下一层
            nextLevel = 0;
            ans++;
        }
        if(!array[front]){
        }
        else{
            array[rear+1] = array[front]->left;
            array[rear+2] = array[front]->right;
            rear += 2;
            nextLevel += 2;
        }
        front++;
        currentLevel--;
    }
    return ans;
}
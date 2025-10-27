/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 想法是将将二叉树一层一层放到数组中，比如一般访问左子树之后就只能
// 继续往下面找，本解法将每层访问的左右子树保存下来就能实现一层层的访问

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int index1 = 0; // 该层第一个元素
    int index2 = 0; // 下一层的起始元素
    struct TreeNode** treeArray = malloc(sizeof(struct TreeNode*) * 5000); //存放各层树节点
    treeArray[0] = root; // 首先将根节点放到数组中
    index2 = 1; // 放入第一层，更新index2
    int preindex1 = index1; // 因为index1 和 index2 在我访问过程中需要变动记录
                           // 访问到哪了，为了访问完此层后的统计，需要储存index初始值。
    int preindex2 = index2; 


    int **res = malloc(sizeof(int*) * 2000); // 最后返回的结果
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2000);
    memset(*returnColumnSizes,0,sizeof(int) * 2000);

    int i=0; //记录结果数组当前放到第几层了
    int count = 0; //统计每一层null的数量
    while(index1 < index2){
        if(treeArray[index1] == NULL){  //当前节点为null，访问下一个节点并计数
            index1++;
            count++;
        }
        else{
            treeArray[index2] = treeArray[index1]->left; //当前节点左子节点存入
            index2++;
            treeArray[index2] = treeArray[index1]->right; //当前节点右子节点存入
            index2++;
            index1++; //访问下一个节点
        }
        if(index1 == preindex2){ //index1达到上次记录的右边界，即访问完一层
            res[i] = malloc(sizeof(int) * (preindex2  - preindex1)); //统计此层宽度，申请空间
            int kk = 0;
            for(int j = 0;j < preindex2 - preindex1;j++){ //循环访问此层，添加到结果数组
                if(treeArray[preindex1 + j] != NULL){
                    res[i][kk] = treeArray[preindex1 + j]->val;
                    kk++;
                }
            }
            i++; //结果数组的层数加1
            (*returnColumnSizes)[i-1] = preindex2 - preindex1 - count; //统计此层除null之外的真正宽度
            count = 0;
            preindex1 = index1;//更新下一层边界
            preindex2 = index2;
        }
    }
    for(int aa = i;aa>=0;aa--){ //遍历下防止最后加了几层空数组
        if((*returnColumnSizes)[aa] != 0){
            *returnSize = aa+1;
            break;
        }
        if(aa==0) //如果根节点为null，返回空
            *returnSize = 0;
    }
    return res;
}
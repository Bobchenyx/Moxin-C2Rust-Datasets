/**************************通用队列实现：以下**************************/
typedef struct tagQUEUE_NODE_S{
    struct tagQUEUE_NODE_S *priv;
    struct tagQUEUE_NODE_S *next;
    void *data;   
}QUEUE_NODE_S;

/* 
    使用循环双向链表实现队列
    retval: 返回一个节点的地址，其中它的next为队列头，priv为队列尾
*/
QUEUE_NODE_S *queue_init(void) {
    QUEUE_NODE_S *node = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_NODE_S));
    if (node == NULL) {
        return NULL;
    }

    node->next = node;
    node->priv = node;
    node->data = NULL;
    return node;
}

/*
    description： 首尾相等，则队列为空。
    param：
        node：队列指针
    attention： 调用者保证指针不为空
*/
bool queue_is_empty(QUEUE_NODE_S *node) {
    if (node->next == node->priv && node->next == node) {
        return true;
    }

    return false;
}

/*
    description： 数据从队列尾入队
    param：
        node：队列指针
        data：需要入队的数据
    attention： 调用者保证指针不为空
*/
void queue_in(QUEUE_NODE_S *node, void *data) {
    QUEUE_NODE_S *newNode = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_NODE_S));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = node;
    newNode->priv = node->priv;
    node->priv->next = newNode;
    node->priv = newNode;

    return;
}
/*
    description： 数据从队列首出队
    param：
        node：队列指针
    retval：出队的数据,
    attention： 调用者释放返回的data
*/
void *queue_out(QUEUE_NODE_S *node)
{
    QUEUE_NODE_S *outNode = node->next;
    outNode->next->priv = node;
    node->next = outNode->next;

    void *data = outNode->data;
    free(outNode);

    return data;
}

/* 销毁队列 */
void queue_destroy(QUEUE_NODE_S *node)
{
    QUEUE_NODE_S *curNode = node;
    QUEUE_NODE_S *nextNode = node->next;

    while (curNode != NULL) {
        if (curNode->data != NULL) {
            free(curNode->data);
            curNode->data = NULL;
        }
        /* 先摘链，再释放 */
        if (curNode->next == curNode->priv && curNode->next == curNode) {
            free(curNode);
            curNode = NULL;
        } else {
            nextNode = curNode->next;
            curNode->next->priv = curNode->priv;
            curNode->priv->next = curNode->next;
            free(curNode);
            curNode = nextNode;
        }
    }
    return;
}
/**************************通用队列实现：以上**************************/

/* 
   使用广度优先搜索：
   1、需要一个队列，用来存储要检查的节点。队列中的每个节点保存树节点和剩余的目标和。
   2、root节点的子节点先入队，剩余目标和分别减去root节点的值。
   3、队列中弹出一个节点：
      （1）如果弹出的是叶子节点，检查剩余目标和与该节点的值是否相等。相等，则说明存在目标值相同的路径。否则继续执行3.
      （2）如果弹出的不是叶子节点，将它的子节点入队，并更新子节点的剩余目标值 = 当前弹出节点的剩余目标值 - 当前弹出节点的值。继续执行3.
      （3）如果没有节点可弹出了，说明队列为空，没有满足目标值的路径了。
*/
/*
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left;
 *    struct TreeNode *right;
 * };
 */

typedef struct tagQUEUE_DATA_S {
    struct TreeNode *node;
    int leftVal;
}QUEUE_DATA_S;

#define EOK 0
#define ERR 1

int TreeNodeQueueIn(QUEUE_NODE_S *queueHead, struct TreeNode* node, int fatherValue, int leftvalue)
{
    QUEUE_DATA_S *data = (QUEUE_NODE_S *)malloc(sizeof(QUEUE_DATA_S));
    if (data == NULL) {
        return ERR;
    }
    data->node = node;  
    data->leftVal = leftvalue - fatherValue;
    queue_in(queueHead, (void *)data);

    return EOK;
}



bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }
    /*1、需要一个队列，用来存储要检查的节点。队列中的每个节点保存树节点和剩余的目标和。*/
    QUEUE_NODE_S *queueHead = queue_init();
    if (queueHead == NULL) {
        return false;
    }

    int ret = TreeNodeQueueIn(queueHead, root, 0, sum);
    if (ret != EOK) {
        queue_destroy(queueHead);
        return false;
    }

    while(!queue_is_empty(queueHead)) {
        QUEUE_DATA_S *queueData = (QUEUE_DATA_S *)queue_out(queueHead);
        if (queueData == NULL) {
            queue_destroy(queueHead);
            return false;
        } 

        struct TreeNode *treeNode = queueData->node;
        /* 已经是叶子节点 */
        if (treeNode->left == NULL && treeNode->right == NULL) {
            if (treeNode->val == queueData->leftVal) {
                free(queueData);
                queueData = NULL;
                queue_destroy(queueHead);
                return true;
            }
            else {
                continue;
            }       
        }

        if (treeNode->left != NULL) {
            (void)TreeNodeQueueIn(queueHead, treeNode->left, treeNode->val, queueData->leftVal);
        }

        if (treeNode->right != NULL) {
            (void)TreeNodeQueueIn(queueHead, treeNode->right, treeNode->val, queueData->leftVal);  
        }

        free(queueData);
        queueData = NULL;
    }

    queue_destroy(queueHead);
    return false;
}
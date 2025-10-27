#define MAXSIZE 10000

typedef struct _qelement{
    struct TreeNode *root;
    int levelNum;
} QElem;

typedef struct _queue{
    QElem queue[ MAXSIZE ];
    int front, rear, size, maxsize;
} *Queue;

int Enqueue( struct TreeNode *root, int levelNum, Queue q ); 
// return the levelNum(int) of the node successfully enqueued, return 0 for error/null
struct TreeNode* Dequeue( Queue q );
int GetFrontNum( Queue q );
int isEmpty( Queue q );

double* averageOfLevels(struct TreeNode* root, int* returnSize){

    void levelorderTraversal( struct TreeNode *root, Queue q, int *levelSize );

    // initialize a queue for traversaling
    Queue q = ( Queue ) malloc( sizeof( struct _queue ) );
    q->front = q->rear = 0;
    q->maxsize = MAXSIZE;
    q->size = 0;

    // build the queue
    *returnSize = 1;
    levelorderTraversal( root, q, returnSize );
        
    // build the ret array by the queue
    double *ret = ( int* ) malloc( sizeof( double ) * *returnSize );
    int i;
    for( i = 0; i < *returnSize; i++ ){
        long sum = 0;
        int n = 0;
        while( GetFrontNum( q ) == i + 1 ){
            sum += Dequeue( q )->val;
            n++;
        }
        ret[ i ] = sum / (double)n;
    }

    // return 
    free( q );
    return ret;
}

void levelorderTraversal( struct TreeNode *root, Queue q, int *levelSize )
{
    // create a helper queue
    Queue helper = ( Queue ) malloc( sizeof( struct _queue ) );
    helper->front = helper->rear = 0;
    helper->maxsize = MAXSIZE;
    helper->size = 0;

    // build the queue for traversaling
    Enqueue( root, 1, helper );
    while( !isEmpty( helper ) ){
        int levelNum = GetFrontNum( helper );
        struct TreeNode *tmp = Dequeue( helper );
        Enqueue( tmp, levelNum, q );
        int flg1 = 0, flg2 = 0;
        flg1 = Enqueue( tmp->left, levelNum + 1, helper );
        flg2 = Enqueue( tmp->right, levelNum + 1, helper );
        if( flg1 || flg2 )
            *levelSize = levelNum + 1;
    }

    // return 
    free( helper );
}

int Enqueue( struct TreeNode *root, int levelNum, Queue q )
// return the levelNum(int) of the node successfully enqueued, return 0 for error/null
{
    if( !root )
        return 0;
    
    q->queue[ q->rear ].root = root;
    q->queue[ q->rear ].levelNum = levelNum;
    q->size++;
    q->rear = ( ++q->rear ) % q->maxsize;
    return levelNum;
}

struct TreeNode* Dequeue( Queue q )
{
    struct TreeNode *FrontCell = q->queue[ q->front ].root;
    q->front = ( ++q->front ) % q->maxsize;
    q->size--;
    return FrontCell;
} 

int GetFrontNum( Queue q )
{
    return q->queue[ q->front ].levelNum;
}

int isEmpty( Queue q )
{
    return ( q->size == 0 );
}
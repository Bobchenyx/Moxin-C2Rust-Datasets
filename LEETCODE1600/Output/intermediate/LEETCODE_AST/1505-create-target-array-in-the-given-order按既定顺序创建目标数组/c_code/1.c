//单向链表
 struct list {
	int val;
	struct list* pNext;
};

//创建:创建一个值为val的结点
struct list* createNode(int val)
{
	struct list* pNode = calloc(sizeof(struct list), 1);
	pNode->pNext = NULL;
	pNode->val = val;

	return pNode;
}

//插入:在target后插入节点Node
void insertNode(struct list* pTargetNode, struct list* pNode)
{
	if (!pTargetNode)
	{
		return;
	}
	if (pTargetNode->pNext)	//非空节点,在链表头部增加时，需要进行判断，否则会出问题
		pNode->pNext = pTargetNode->pNext;
	pTargetNode->pNext = pNode;
	return;
}

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
	int* retArr = calloc(sizeof(int),indexSize);
	*returnSize = indexSize;

	int i = 0, j = 0;
	struct list* pNode = NULL;
	struct list* pHead = NULL;
	struct list* pTargetNode = NULL;

	for (i = 0; i<indexSize; i++)
	{
		pNode = createNode(nums[i]);    //创建一个节点
		if (0 == i) pHead = pNode;      //第一个为头节点
		else
		{
			pTargetNode = pHead;    //从头节点开始往后数，找到插入的节点
			j = index[i];
			if (0 == j)     //在链表头部插入
			{
				insertNode(pNode, pTargetNode);
				pHead = pNode;      //更新头节点
			}
			else        //非头部插入
			{
				j--;    
				while (j--)
				{
					pTargetNode = pTargetNode->pNext;
				}
				insertNode(pTargetNode, pNode);
			}

		}
	}

	pTargetNode = pHead;
	for (i = 0; i<indexSize; i++)
	{
		retArr[i] = pTargetNode->val;
		pTargetNode = pTargetNode->pNext;
	}
	return retArr;
}
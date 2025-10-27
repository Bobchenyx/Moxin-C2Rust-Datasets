//------------------------------------一个基础队列有：建立新节点、队尾插入新节点、释放空间，三种操作
typedef struct Node
{
	int key;
	int val;
	int times;
	struct Node* next;
}Node;
Node* newNode(int Key, int Val, int Times)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->key = Key;
	n->val = Val;
	n->times = Times;
	n->next = 0;
	return n;
}
Node* queuePush(Node* Rear, int Key, int Val)
{
	Node* n = newNode(Key, Val, 1);
	n->next = Rear->next;
	Rear->next = n;
	return n;
}
Node* del(Node* Head, Node* Rear)
{
	while (Head != 0)
	{
		Node* n = Head;
		Head = Head->next;
		free(n);
	}
	return 0;
}
//------------------------------------解答
typedef struct {
	Node* head;
	Node* rear;
	int length;//当前缓存中页数
	int capacity;//缓存容量
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
	LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
	cache->head = newNode(0, 0,0);
	cache->rear = cache->head;
	cache->length = 0;
	cache->capacity = capacity;
	return cache;
}

int lFUCacheGet(LFUCache* obj, int key) {
	Node* iter = obj->head;
	while (iter->next != 0 && iter->next->key != key)
		iter = iter->next;
	if (iter->next != 0)
		if (iter->next != obj->rear)
		{
			//如果缓存中有对应的页，还要再看一下是不是最近访问过的页，不然下面的操作会把链表截断
			Node* n = iter->next;
			iter->next = n->next;//如果n是rear，这一步会截断链表的(但不会丢页)
			++(n->times);
			//取下来的页放到链表的rear端
			n->next = obj->rear->next;
			obj->rear->next = n;
			obj->rear = obj->rear->next;
			return obj->rear->val;
		}
		else
		{
			++(iter->next->times);
			return iter->next->val;
		}
	else
		return -1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
	//情况一 缓存容量本来就是0
    if(obj->capacity==0)return;
	//情况二 缓存中已经有key对应的页，更新一下value即可
    for(Node* iter=obj->head->next;iter!=0;iter=iter->next)
        if(iter->key==key)
        {
            iter->val=value;
            ++(iter->times);
            return;
        }    
	//情况三 缓存还有剩余空间
	if (obj->length < obj->capacity)
	{
		obj->rear = queuePush(obj->rear, key, value);
		++(obj->length);
	}
	//情况四 缓存满
	else
	{	//先找出访问量最少的页
		Node* minNodePre=0; int minTimes = (~((unsigned)0)) >> 1;
		for (Node* iter = obj->head; iter->next != 0; iter = iter->next)
			//注意这个判断是用小于而不是小于等于，因为我们要找的是“第一个最小的times”。
			//这个链表是有序的（根据LRU原理所创建，从head的最久未访问到rear的最近访问的页面），所以选“第一个”&&"最小times"进行记录即可。
			if (iter->next->times < minTimes)
			{
				minNodePre = iter;
				minTimes = iter->next->times;
			}
		//把最少的页调出（从链表删除对应节点）
		Node* n = minNodePre->next;
        if(n==obj->rear)
            obj->rear=minNodePre;
		minNodePre->next = n->next;
		free(n);
		//把新页放进链表rear端（作为最近访问过的页）
		obj->rear = queuePush(obj->rear, key, value);
	}
}

void lFUCacheFree(LFUCache* obj) {
	obj->rear = del(obj->head, obj->rear);
    free(obj);
}
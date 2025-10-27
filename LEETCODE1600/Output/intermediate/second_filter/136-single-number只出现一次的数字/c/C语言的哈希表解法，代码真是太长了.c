typedef struct NodeData{
    int val;
    int key;
}NodeData;
typedef struct HashNode{
    NodeData data;
    struct HashNode* next;
}HashNode;
typedef struct HashMap{
    int size;
    HashNode *table;
}HashMap;

int GetIndex(HashMap*hashmap,int value){
    int pos = abs(value)%hashmap->size;//根据哈希函数找到数据所在的行
    HashNode *hpointer=&(hashmap->table[pos]);//遍历该行的节点与数据比较
    while(hpointer!=NULL){
        if(hpointer->data.val==value){
            return hpointer->data.key;
        }
        else{
            hpointer=hpointer->next;
        }        
    }
    return -1;
}

int DeleteValue(HashMap* hashmap,int Value){
    if(GetIndex(hashmap,Value) == -1) return 0;
    int pos = abs(Value) % hashmap->size;
    int i = 0;
    if(hashmap->table[pos].data.val == Value){
        if(hashmap->table[pos].next == NULL){
            hashmap->table[pos].data.val = INT_MIN;
        }
        else{
            HashNode *hpointer = &(hashmap->table[pos]),*pre = NULL;
            while(hpointer->next != NULL){
                hpointer->data = hpointer->next->data;
                pre = hpointer;
                hpointer = hpointer->next;
            }
            pre->next = NULL;
            free(hpointer);
            return 1;
        }
    }
    else{
        HashNode *pre = &(hashmap->table[pos]);
        HashNode *hpointer = hashmap->table[pos].next;
        while(hpointer != NULL){
            if(hpointer->data.val == Value){
                pre->next = hpointer->next;
                free(hpointer);
                return 1;
            }
            else{
                pre = hpointer;
                hpointer=hpointer->next;
            }
        }
    }
    return 1;
}

int Insert(HashMap* hashmap,int key,int value){
    int pos = abs(value) % hashmap->size;//计算该数据在哈希表中的位置
    if (hashmap->table[pos].data.val == INT_MIN){//节点没有被占用，直接赋值
        hashmap->table[pos].data.val = value;
        hashmap->table[pos].data.key = key;
    }
    else{//节点被占用了，建立新节点连接到最后面
        HashNode *NewNode=(HashNode*)malloc(sizeof(HashNode));
        NewNode->data.val = value;
        NewNode->data.key = key;
        NewNode->next=NULL;
        HashNode* hpointer =&(hashmap->table[pos]);
        while(hpointer->next != NULL){//将指针移动到该行最后一个节点
            hpointer = hpointer->next;
        }
        hpointer->next=NewNode;
    }
    return 1;
}

void FreeHashMap(HashMap* hashmap){
    int i = 0;
    while(i < hashmap->size){
        HashNode* hpointer = hashmap->table[i].next;
        while(hpointer != NULL){
            hashmap->table[i].next=hpointer->next;
            free(hpointer);
            hpointer=hashmap->table[i].next;
        }
        i++;
    }
    free(hashmap->table);
    free(hashmap);
    return;
}

int singleNumber(int* nums, int numsSize){
    int ans = 0;
    HashMap *hashmap = (HashMap*)malloc(sizeof(HashMap));
    hashmap->size = 2*numsSize;
    hashmap->table = (HashNode*)malloc(sizeof(HashNode)*(hashmap->size));
    int i=0;
    while(i < hashmap->size){
        hashmap->table[i].data.val = INT_MIN;
        hashmap->table[i].next = NULL;
        i++;
    }
    for(int j = 0;j < numsSize;j++){
        if(GetIndex(hashmap,nums[j]) != -1){
            DeleteValue(hashmap, nums[j]);
        }
        else{
            Insert(hashmap,j,nums[j]);
        }
    }
    for(int j = 0;j < hashmap->size;j++){
        if(hashmap->table[j].data.val != INT_MIN){
            ans = hashmap->table[j].data.val;
        }
    }
    FreeHashMap(hashmap);
    return ans;
}
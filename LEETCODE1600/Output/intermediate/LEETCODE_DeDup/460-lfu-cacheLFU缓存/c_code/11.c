struct lianbiao{
    int key;
    int count;
    int val;
    struct lianbiao*next;
};
typedef struct lianbiao  LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache*a=(LFUCache*)malloc(sizeof(LFUCache));
    a->next=NULL;
    LFUCache*pre=a;
    LFUCache*p=a->next;
    int count=0;
    if(capacity==0)
    {
        return a;
    }
    while(count!=capacity)
    {
        p=(LFUCache*)malloc(sizeof(LFUCache));
        p->key=-1;
        p->val=-1;
        p->count=0;
        p->next=NULL;
        pre->next=p;
        pre=p;
        count++;
    }
    return a;
}
void insert(LFUCache*obj,int key,int value,int count)
{
    LFUCache*p=obj->next;
    LFUCache*pre=obj;
    LFUCache*q;
    while(p!=NULL)
    {
        if(p->count<=count)
        {
            q=(LFUCache*)malloc(sizeof(LFUCache));
            q->key=key;
            q->val=value;
            q->count=count;
            q->next=p;
            pre->next=q;
            return ;
        }
        pre=p;
        p=p->next;
    }
    q=(LFUCache*)malloc(sizeof(LFUCache));
            q->key=key;
            q->val=value;
            q->count=count;
            pre->next=q;
            free(p);
            q->next=NULL;
}
int lFUCacheGet(LFUCache* obj, int key) {
    LFUCache*pre=obj;
    LFUCache*p=obj->next;
    int tcount,tkey,tval;
    while(p!=NULL)
    {
        if(p->key==key)
        {
            tcount=p->count+1;
            tval=p->val;
            tkey=p->key;
            pre->next=p->next;
            free(p);
            insert(obj,tkey,tval,tcount);
            return tval;
        }
        pre=p;
        p=p->next;
    }
    return -1;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    LFUCache*pre=obj;
    LFUCache*p=obj->next;
    int tcount,tkey,tval;
    if(obj->next==NULL)
    {
        return ;
    }
    while(p!=NULL)
    {
        if(p->key==key)
        {
            tcount=p->count+1;
            tval=value;
            tkey=key;
            pre->next=p->next;
            free(p);
            insert(obj,tkey,tval,tcount);
            return ;
        }
        if(p->key==-1)
        {
            pre->next=p->next;
            free(p);
            insert(obj,key,value,0);
            return ;
        }
        pre=p;
        p=p->next;
    }
    pre=obj;
    p=obj->next;
    while(p!=NULL)
    {
        if(p->next==NULL)
        {
            pre->next=p->next;
            free(p);
            break;
        }
        pre=p;
        p=p->next;
    }
    insert(obj,key,value,0);
}

void lFUCacheFree(LFUCache* obj) {
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
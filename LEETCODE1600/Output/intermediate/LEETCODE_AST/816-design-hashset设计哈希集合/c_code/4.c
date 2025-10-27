#define MAXSIZE 1000001

typedef struct {
    int key[MAXSIZE];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet *tmpHashNode = (MyHashSet *)malloc(sizeof(MyHashSet));
    memset(tmpHashNode, 0, sizeof(MyHashSet));
    return tmpHashNode;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    if (obj->key[key] != 1) {
        obj->key[key] = 1;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (obj->key[key] == 1) {
        obj->key[key] = 0;
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    if (obj->key[key] == 1) {
        return true;
    } else {
        return false;
    }
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
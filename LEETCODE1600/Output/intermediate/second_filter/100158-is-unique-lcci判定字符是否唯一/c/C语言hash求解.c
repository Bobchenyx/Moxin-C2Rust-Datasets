typedef struct {
    int key;
    int counts;
    UT_hash_handle hh;
}HashMap;

bool isUnique(char* astr){
    HashMap* hashMap = NULL;
    HashMap* node;
    int value;
    bool res = true;

    for (int i = 0, length = strlen(astr); i < length; i++) {
        value = astr[i];
        HASH_FIND_INT(hashMap, &value, node);
        if (node == NULL) {
            node = (HashMap*)malloc(sizeof(HashMap));
            node->key = value;
            HASH_ADD_INT(hashMap, key, node);
        } else {
            res = false;
            break;
        }
    }

    return res;
}
typedef struct Node {
    bool isEnd;
    struct Node *next[26];
} Trie;

Trie* TrieCreate() {
    return (Trie*)calloc(1, sizeof(Trie));
}

void Trieinsert(Trie *obj, char *word) {
    while (*word) {
        if (!obj->next[(*word)-97]) {
            obj->next[(*word)-97] = TrieCreate();
        }
        obj = obj->next[(*word++)-97];
    }
    obj->isEnd = true;
}

int TrieIsunique(Trie *obj) {
    int sum = 0, unique;
    for (int i = 0; i < 26; i++) {
        if (obj->next[i]) {
            unique = i;
            sum++;
        }
    }
    return sum == 1 ? unique : -1;
}

void TrieFree(Trie *obj) {
    if (!obj) return;
    for (int i = 0; i < 26; i++) {
        TrieFree(obj->next[i]);
    }
    free(obj);
}

char * longestCommonPrefix(char ** strs, int strsSize){
    if (!strsSize) return "";
    int i, j = 0, ch;
    Trie *root = TrieCreate();  // 1.创建根节点插入单词
    for (i = 0; i < strsSize; i++) {
        if (strs[i][0]) Trieinsert(root, strs[i]);
        else return "";  // 空串直接返回
    }
    // 2.查找前缀
    while ((ch = TrieIsunique(root)) != -1 && !root->next[ch]->isEnd) {
        strs[0][j++] = ch + 97;
        root = root->next[ch];
    }
    if (ch != -1) strs[0][j++] = ch + 97;  // 说明是单词结束
    strs[0][j] = '\0';  // 结尾
    return strs[0];
}
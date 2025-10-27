typedef struct trie {
    struct trie *children[26];
} Trie;

Trie * newTrie() {
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    for (int i = 0; i < 26; i++) {
        trie->children[i] = NULL;
    }
    return trie;
}
bool isNew = false;  // 全局变量，控制当前插入的word是否为新单词

int trieInsert(Trie *obj, char *word) {
    Trie *node = obj;
    int length;
    for (int i = strlen(word) - 1; i >= 0; i--) {  //  由于判断后缀，所以倒序插入
        if (node->children[word[i] - 'a'] == NULL) {
            isNew = true;
            node->children[word[i] - 'a'] = newTrie();
        }
        node = node->children[word[i] - 'a'];
    }
    if (isNew == true) {
        length = strlen(word) + 1;
    } else {
        length = 0;
    }
    isNew = false;
    return length;
}

int cmp(const void **a, const void **b) {
    return strlen((char *)*(b)) - strlen((char *)*(a));  // 对所有单词做排序，避免先插入em，再插入emit，导致翻车的情况
}

int minimumLengthEncoding(char ** words, int wordsSize){
    Trie *root = newTrie();
    qsort(words, wordsSize, sizeof(char *), cmp);
    int length = 0;
    for (int i = 0; i < wordsSize; i++) {
        length += trieInsert(root, words[i]);
    }
    return length;
}
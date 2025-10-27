#define MAX_CHILD_NUM 26
typedef struct _TireNode {

    char ch;
    struct _TireNode* childs[MAX_CHILD_NUM];
    int isWord;
    char *word;
} TireNode;

TireNode* NewTireNode(char ch)
{
    TireNode* node = (TireNode*)malloc(sizeof(TireNode));
    memset(node, 0, sizeof(TireNode));
    node->ch = ch;
    return node;
}

void Insert(TireNode* root, char* word)
{
    TireNode* p = root;
    for (int i = 0; i < strlen(word); i++) {

        char ch = word[i];
        int pos = ch - 'a';
        if (p->childs[pos] == NULL) {
            p->childs[pos] = NewTireNode(ch);
        }
        p = p->childs[pos];
    }
    p->isWord = 1;
    p->word = word;
}

int Find(TireNode* root, char* word)
{
    TireNode* p = root;
    for (int i = 0; i < strlen(word); i++) {

        char ch = word[i];
        int pos = ch - 'a';
        if (p->childs[pos] == NULL) {
            return 0;
        }
        p = p->childs[pos];
    }
    return p != NULL;
}

void Resver(char* word)
{
    int left = 0;
    int right = strlen(word) - 1;

    while (left < right) {
        char t = word[left];
        word[left] = word[right];
        word[right] = t;
        left++;
        right--;
    }
}

int Cmp(const void* a, const void* b)
{
    char* x = *(char**)a;
    char* y = *(char**)b;
    return strcmp(y, x);
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    
    for (int i = 0; i < wordsSize; i++) {
        Resver(words[i]);
    }
    
    qsort(words, wordsSize, sizeof(char*), Cmp);
    
    TireNode* root = NewTireNode('\0');
    int result = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (Find(root, words[i]) == 0) {
            Insert(root, words[i]);
            result += strlen(words[i]) + 1;
        }
    }
    
    return result;

}
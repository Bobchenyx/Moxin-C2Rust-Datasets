#define MAX_LEN 3000

typedef struct {
    int front;
    int tail;
    char words[MAX_LEN][8];
}Queue;

void checkQueue(Queue *q, char *word) 
{
    int len1, len2, result;
    int front = q->front;
    len1 = strlen(word);
    while (q->tail != front) {
        len2 = strlen(q->words[front]);
        if (len1 == len2) {
            if (0 == strcmp(word, q->words[front])) {
                return;
            } 
        } else if (len1 > len2) {
            if (0 == strcmp(word + len1 - len2, q->words[front])) {
                strncpy(q->words[front], word, len1);
                q->words[front][len1] = 0;
                return;
            } 
        } else {
            if (0 == strcmp(word, q->words[front] + len2 - len1)) {
                return;
            } 
        }
        front++;
    }
    strncpy(q->words[q->tail], word, len1);
    q->words[q->tail][len1] = 0;
    q->tail++;
    return;
}
int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize == 0) {
        return 0;
    }
    int i, j;
    int len = 0;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->tail = 0;
    strncpy(q->words[q->tail], words[0], strlen(words[0]));
    q->words[q->tail][strlen(words[0])] = 0;
    q->tail++;
    for (i = 1; i < wordsSize; i++) {
        checkQueue(q, words[i]);
    }
    while (q->tail != q->front) {
        len += (strlen(q->words[q->front++]) + 1); 
    }

    free(q);
    return len;
}
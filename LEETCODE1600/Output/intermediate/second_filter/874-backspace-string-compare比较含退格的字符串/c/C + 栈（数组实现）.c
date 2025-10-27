#define MAX_STACK_SIZE 200

typedef struct {
    int capacity;
    int topOfStack;
    char *Array;
}StackRecord;

int IsStackFull(StackRecord *stackTemp) {
    if (stackTemp->topOfStack > stackTemp->capacity - 1) {
        return true; // 栈已满
    }

    return false;
}

int IsStackEmpty(StackRecord *stackTemp) {
    if (stackTemp->topOfStack == -1) {
        return true; // 栈为空
    }

    return false;
}

void pushElement(StackRecord *stackTemp, const char *sTemp, int Len)
{
    if (IsStackFull(stackTemp)) {
        return 0;
    }

    for (int i = 0; i < Len; i++) {
        if (sTemp[i] == '#') {
            if (stackTemp->topOfStack > -1)
                stackTemp->topOfStack--;
        } else {
            stackTemp->Array[++stackTemp->topOfStack] = sTemp[i];
        }
    }
}

char popElement(StackRecord *stackTemp) {
    if (IsStackEmpty(stackTemp)) {
        return 0;
    }

    return stackTemp->Array[stackTemp->topOfStack--];
}

bool backspaceCompare(char * S, char * T){
    StackRecord stackTempS;
    StackRecord stackTempT;
    stackTempS.topOfStack = -1;
    stackTempS.capacity = MAX_STACK_SIZE;
    stackTempS.Array = (char*)calloc(MAX_STACK_SIZE + 1, sizeof(char));
    stackTempT.topOfStack = -1;
    stackTempT.capacity = MAX_STACK_SIZE;
    stackTempT.Array = (char*)calloc(MAX_STACK_SIZE + 1, sizeof(char));

    int sLen = strlen(S);
    int tLen = strlen(T);

    pushElement(&stackTempS, S, sLen);
    pushElement(&stackTempT, T, tLen);

    if (stackTempS.topOfStack != stackTempT.topOfStack) {
        return false;
    }

    while (stackTempS.topOfStack > -1) {
        if (popElement(&stackTempS) != popElement(&stackTempT)) {
            return false;
        }
    }

    return true;
}
C []
typedef struct _Data{
    int index;
    char *info;
}Data;

int cmp(const void *a, const void *b){
    
    int ret = strcmp(((Data*)a)->info, ((Data*)b)->info);    
    return ret;
}

char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    *returnSize = 0;
    char** res = (char**)malloc((list1Size > list2Size ? list2Size : list1Size) * sizeof(char*));
    Data *src1 = (Data*)malloc(list1Size * sizeof(Data));
    Data *src2 = (Data*)malloc(list2Size * sizeof(Data));
    int i, j = 0, val, max = list1Size + list2Size, sum;
    for (i = 0; i < list1Size; ++i) {
        src1[i].index = i;
        src1[i].info = list1[i];
    }
    for (i = 0; i < list2Size; ++i){
        src2[i].index = i;
        src2[i].info = list2[i];
    }
    qsort(src1, list1Size, sizeof(Data), cmp);
    qsort(src2, list2Size, sizeof(Data), cmp);
    
    i = 0, j = 0;
    while (i < list1Size && j < list2Size){
        val = strcmp(src1[i].info, src2[j].info);
        if (val < 0){
            ++i;
        } else if (val == 0){
            sum = src1[i].index + src2[j].index;
            if (sum < max){
                max = sum;
                *returnSize = 0;
                res[(*returnSize)++] = src1[i].info;
            } else if (sum == max){
                res[(*returnSize)++] = src1[i].info;
            }
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    free(src1);
    free(src2);
    return res;
}
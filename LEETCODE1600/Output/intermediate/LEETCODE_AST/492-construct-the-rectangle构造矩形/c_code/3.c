int* constructRectangle(int area, int* returnSize){
    *returnSize = 2;
    int *ret = malloc(sizeof(int) * *returnSize);
    ret[1] = (int)sqrt(area);
    while(ret[1]){
        if(area % ret[1] == 0){
            ret[0] = area / ret[1];
            return ret; 
        }
        ret[1]--;
    }
    return NULL;
}
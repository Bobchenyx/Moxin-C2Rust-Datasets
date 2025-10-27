int cmp(const void *a, const void *b)
{
    return *((int*)b) - *((int*)a); 
}

int largestPerimeter(int* A, int ASize){
    if ((A == NULL) || (ASize < 3)) {
        return 0;
    }
    qsort(A, ASize, sizeof(int), cmp);

    for (int i = 0; i < ASize - 2; i++) {
        if (*(A + i) < (*(A + i + 1) + *(A + i + 2))) {
            return *(A + i + 1) + *(A + i + 2) + *(A + i);
        } 
    }
    return 0;
   
}
#define DAY_MINU (24*60)
int  compare(const void *a,const void *b) {
    return (*((int*) a) - *((int*) b));
}
int findMinDifference(char ** timePoints, int timePointsSize){
    int minu_array[timePointsSize], hour, minu;
    for (int i = 0; i < timePointsSize; ++i) {
        sscanf(timePoints[i], "%d:%d", &hour, &minu);
        minu_array[i] = hour*60 + minu;
    }
    qsort(minu_array, timePointsSize, sizeof(int), compare);
    
    int min_point = 0x7fffffff;
    for (int i = 0; i < timePointsSize-1; ++i) {
        int tmp = minu_array[i+1] - minu_array[i];
        if (tmp == 0) return 0;  //没有比0更小的间隔了
        if (tmp < min_point) min_point = tmp;
    }

    return (DAY_MINU-minu_array[timePointsSize-1] + minu_array[0]) < min_point ?
           (DAY_MINU-minu_array[timePointsSize-1] + minu_array[0]) :
           min_point;
}
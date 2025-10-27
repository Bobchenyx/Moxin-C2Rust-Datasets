#define MAXMIMUTE 1440
int getMin(char * time)
{
    return  ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[3] - '0') * 10 + (time[4] - '0'));
}

int cmp(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int findMinDifference(char ** timePoints, int timePointsSize){
    if (timePoints == NULL) {
        return -1;
    }
    int diff = 0;
    int *min = malloc(sizeof(int) * timePointsSize);
    memset(min, 0 , sizeof(int) * timePointsSize);

    for (int i = 0; i < timePointsSize; i++) {
        min[i] = getMin(timePoints[i]);
    }
    
    qsort(min, timePointsSize, sizeof(min[0]), cmp);
    diff = min[1] - min[0];
    for(int j = 0; j < timePointsSize - 1; j++) {
        if(min[j+1] - min[j] < diff) {
            diff = min[j+1] - min[j];
        }
    }

    if (MAXMIMUTE + min[0] - min[timePointsSize -1] < diff) {
        diff = MAXMIMUTE + min[0] - min[timePointsSize -1];
    }
    return diff;
}
#define MIN(a,b) ((a<b) ? a : b)

int cmp(const void *a, const void *b){
    char *ap = *(char **)a;       
    char *bp = *(char **)b;

    if(ap[0] != bp[0])
        return ap[0] - bp[0];
    
    if(ap[1] != bp[1])
        return ap[1] - bp[1];
    
    if(ap[3] != bp[3])
        return ap[3] - bp[3];
    
    return ap[4] - bp[4];
}

int getdiff(char * p1, char * p2){
    int i, j, k, l;
    i = p2[0] - p1[0];
    j = p2[1] - p1[1];
    k = p2[3] - p1[3];
    l = p2[4] - p1[4];
    return (i*10+j)*60 + (k*10+l);
}

int findMinDifference(char ** timePoints, int timePointsSize){
    int count=1440, i;
    char dlimit[6] = "00:00";
    char tlimit[6] = "24:00";

    qsort(timePoints, timePointsSize, sizeof(char *), cmp);

    for(i=1; i<timePointsSize; i++)
        count = MIN(count, getdiff(timePoints[i-1], timePoints[i]));
    
    return MIN(count, getdiff(timePoints[timePointsSize-1], tlimit) + getdiff(dlimit, timePoints[0]));
}
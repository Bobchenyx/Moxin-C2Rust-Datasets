inline double getLength(int *point1, int *point2)
{
    return sqrt((point1[0]-point2[0])*(point1[0]-point2[0]) + \
                (point1[1]-point2[1])*(point1[1]-point2[1]));
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    int  i, j, k;

    double a;
    double b;
    double c;
    double p;
    double s;
    double ret;
    
    
    for(i = 0; i < pointsSize - 2; i++) {
        for(j = i + 1; j < pointsSize - 1; j++) {
            for(k = j + 1; k < pointsSize; k++) {
                a = getLength(points[i],points[j]);
                b = getLength(points[i],points[k]);
                c = getLength(points[j],points[k]);
                
                p = (a + b + c) / 2;
                s = sqrt(p * (p - a) * (p - b) * (p - c));
                ret = ret < s ? s : ret;
            }
        }
    }
    
    return ret;
}
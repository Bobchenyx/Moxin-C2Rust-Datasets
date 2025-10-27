int SubFuncMaxVal(int a, int b) 
{
    return a > b ? a : b;
}

int SubFuncMinVal(int a, int b) 
{
    return a > b ? b : a;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if ((rec1 == NULL) || (rec1Size == 0) || (rec2 == NULL) || (rec2Size == 0)) {
        return false;
    }

    //矩形--A
    int x1 = rec1[0];
    int y1 = rec1[1];
    int x2 = rec1[2];
    int y2 = rec1[3];

    //矩形--B
    int u1 = rec2[0];
    int v1 = rec2[1];
    int u2 = rec2[2];
    int v2 = rec2[3];

    if ((SubFuncMinVal(x2, u2) > SubFuncMaxVal(x1, u1))
        && (SubFuncMinVal(y2, v2) > SubFuncMaxVal(y1, v1))) {
            return true;
        }

    return false;
}
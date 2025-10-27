bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    bool flag1=(rec2[0]>=rec1[2]||rec2[2]<=rec1[0])?0:1;
    bool flag2=(rec2[1]>=rec1[3]||rec2[3]<=rec1[1])?0:1;
    return flag1&&flag2;
}
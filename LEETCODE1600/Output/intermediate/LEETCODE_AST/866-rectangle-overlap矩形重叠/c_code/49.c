bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[1]>=rec2[3])//在上方
        return false;
    if(rec1[3]<=rec2[1])//在下方
        return false;
    if(rec1[0]>=rec2[2])//在右方
        return false;
    if(rec1[2]<=rec2[0])//在左方
        return false;

    return true;
}
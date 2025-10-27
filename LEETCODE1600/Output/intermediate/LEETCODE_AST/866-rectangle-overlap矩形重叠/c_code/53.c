bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[0]>rec2[0] ){
        int t=0;
        for(int i =0;i<4;i++){
            t = rec1[i];
            rec1[i] = rec2[i];
            rec2[i] = t;
        }
    }   //保证rec1为靠左矩形
    if(rec2[0] >= rec1[2])
        return false;           //rec2左沿相比rec1右沿靠右
    else if(rec2[1] >= rec1[3])
        return false;           //rec2下沿高于rec1上沿
    else if(rec2[3] <= rec1[1])
        return false;           //rec2上沿低于rec1下沿
    else
        return true;
}
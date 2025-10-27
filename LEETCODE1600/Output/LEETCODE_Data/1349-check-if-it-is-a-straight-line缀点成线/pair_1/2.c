bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    double x=coordinates[1][0]-coordinates[0][0],y=coordinates[1][1]-coordinates[0][1];
    double k;
    int t=0;
    if(y==0)
        t=1;
    else
        k=x/y;
    for(int i=1;i<coordinatesSize-1;i++){
        y=coordinates[i+1][1]-coordinates[i][1];
        if(t&&y)
            return false;
        x=coordinates[i+1][0]-coordinates[i][0];
        if(!t&&k!=x/y)
            return false;
    }
    return true;
}
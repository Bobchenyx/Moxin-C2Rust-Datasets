bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
long long x1=rec1[0];
long long y1=rec1[1];
long long x2=rec1[2];
long long y2=rec1[3];
long long x3=rec2[0];
long long y3=rec2[1];
long long x4=rec2[2];
long long y4=rec2[3];
long long hor=((x1>x2?x1:x2)-(x3<x4?x3:x4))*((x1<x2?x1:x2)-(x3>x4?x3:x4));
long long ver=((y1>y2?y1:y2)-(y3<y4?y3:y4))*((y1<y2?y1:y2)-(y3>y4?y3:y4));
if(hor<0&&ver<0)
{
    return 1;
}
else
{
    return 0;
}
}
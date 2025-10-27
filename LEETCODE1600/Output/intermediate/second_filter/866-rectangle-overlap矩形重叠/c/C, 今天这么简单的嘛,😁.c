bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
	if(rec2[0] < rec1[rec1Size-2] && rec2[1] < rec1[rec1Size-1] && 
	   rec2[rec2Size-2] > rec1[0] && rec2[rec2Size-1] > rec1[1])
	return true;
	else
	return false;
}
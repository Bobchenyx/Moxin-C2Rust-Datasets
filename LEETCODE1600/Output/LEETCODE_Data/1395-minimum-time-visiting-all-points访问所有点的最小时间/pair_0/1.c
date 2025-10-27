int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize){
	if (pointsSize == 1)
		return 0;
	int max = 0, a, b;
	for (int i = 1; i < pointsSize; i++){
		a = abs(points[i][0] - points[i - 1][0]);
		b = abs(points[i][1] - points[i - 1][1]);
		max += a>b ? a : b;
	}
	return max;
}
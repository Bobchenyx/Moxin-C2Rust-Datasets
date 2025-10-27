思路一：（超时）
int distance_2(int X1, int Y1, int X2, int Y2)
{
	int x = X1 > X2 ? X1 - X2 : X2 - X1;
	int y = Y1 > Y2 ? Y1 - Y2 : Y2 - Y1;
	return x * x + y * y;
}
int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
	int result = 0;
	for (int i = 0; i < pointsSize; ++i)
		for (int j = 0; j < pointsSize; ++j)
			for (int k = 0; k < pointsSize; ++k)
				if (i != j && distance_2(points[i][0], points[i][1], points[k][0], points[k][1])
					== distance_2(points[j][0], points[j][1], points[k][0], points[k][1]))
					++result;
	return result;
}

思路二：可以通过。参考
作者：shugangwang
链接：https://leetcode-cn.com/problems/number-of-boomerangs/solution/cyu-yan-shi-xian-by-shugangwang-8/
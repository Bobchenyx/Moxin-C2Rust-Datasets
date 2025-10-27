c
int maxArea(int* height, int heightSize) {
	// check
	if (!height || heightSize < 2)
		return 0;
	int max_area = 0;
	int head = 0;
	int end = heightSize - 1;
	int h;
	int l;
	while (head != end) {
		l = end - head;
		if (height[head] < height[end]) {
			h = height[head];
			head++;
		} else {
			h = height[end];
			end--;
		}
		max_area = max_area > h * l ? max_area : h * l;
	}
	return max_area;
}
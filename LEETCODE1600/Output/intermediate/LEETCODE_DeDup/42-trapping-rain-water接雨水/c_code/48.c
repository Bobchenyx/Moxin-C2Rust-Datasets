/*
int trap(int* height, int heightSize){
    
    int i,j;
    int n,m;
    n = -1;m = -1;
    int max = 0;
    for(i = 0;i < heightSize;i++){
        if(height[i] > max) max = height[i];
    }
    int sum = 0,sum_j = 0;
    int min = 0;
    for(i = 1;i <= max;i++){
        sum_j = 0;
        n = -1;
        for(j = 0;j < heightSize;j++){
            if(height[j] >= i){
                if(min == 0) min = height[j];
                if(min > height[j]) min = height[j];
                if(n == -1){
                    n = j;
                }
                else if(j > n){
                    sum_j += j-n-1;
                    n = j;
                }
            }
        }
        sum += sum_j*(min-i+1);
        i+=min-i;
    }
    return sum;
}
*/
int trap(int* height, int heightSize) {
    if (heightSize == 1 || heightSize == 0) return 0;
	int i;
	int m = -1, n = -1;
	int max = 0;
	int sum = 0;
	for (i = 0; i < heightSize; i++) {
		if (max <= height[i]) {
			max = height[i];
			n = m;
			m = i;
		}
		else if (n == -1 || height[i] > height[n]) n = i;
	}
	if (n == -1 || m == -1) return 0;
	if (n > m) {
		n ^= m;
		m ^= n;
		n ^= m;
	}
	for (i = n + 1; i < m; i++) {
		sum -= height[i];
	}
	sum += (m - n - 1)*(height[n] > height[m] ? height[m] : height[n]);
	return trap(height, n + 1) + sum + trap(height + m, heightSize - m);
}
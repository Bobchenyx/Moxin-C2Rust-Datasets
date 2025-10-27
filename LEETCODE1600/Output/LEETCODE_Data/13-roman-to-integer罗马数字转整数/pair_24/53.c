int romanToInt(char * s) {
	int i, k = 0, temp, sum = 0;
	int v[MAX];
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'I') v[k++] = 1;
		else if (s[i] == 'V') v[k++] = 5;
		else if (s[i] == 'X') v[k++] = 10;
		else if (s[i] == 'L') v[k++] = 50;
		else if (s[i] == 'C') v[k++] = 100;
		else if (s[i] == 'D') v[k++] = 500;
		else v[k++] = 1000;
	}
	for (i = 0; i < k; i++) {
/*当最后两个数前者大于等于后者，循环到最后一个元素时，直接保存最后一个属的值，不用比较*/
		if (v[i] >= v[i + 1] || i == k - 1)
			temp = v[i];
		else {
			temp = v[i + 1] - v[i];
			i++;
		}
		sum += temp;
	}
	return sum;
}
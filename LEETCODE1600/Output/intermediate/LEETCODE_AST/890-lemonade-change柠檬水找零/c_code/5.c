bool lemonadeChange(int* bills, int billsSize){
	if (!billsSize)
		return 1;
	int *t = (int*)calloc(2, sizeof(int));
	for (int i = 0; i<billsSize; i++){
		if (bills[i] == 5)
			t[0]++;
		else if (bills[i] == 10){
			if (t[0] == 0)
				return 0;
			t[0]--;
			t[1]++;
		}
		else{
			if ((t[0] == 0) || (t[1] == 0 && t[0] < 3))
				return 0;
			if (t[1] > 0){
				t[1]--;
				t[0]--;
			}
			else
				t[0] -= 3;			
		}
	}
	return 1;
}
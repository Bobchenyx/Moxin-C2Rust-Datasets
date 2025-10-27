char * dayOfTheWeek(int day, int month, int year){
	char *res[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int start = 4;
	for (int y = 1971; y < year; y++)
		if ((y % 4 == 0) && y != 2100)
			start += 366;
		else
			start += 365;	
	for (int m = 1; m < month; m++){
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
			start += 31;
		else if (m == 2){
			if ((year % 4 == 0) && year != 2100)
				start += 29;
			else
				start += 28;
		}
		else
			start += 30;
	}
	start += day;
	start %= 7;
	return res[start];
}
int getYMD(char *date, int *y, int *m, int *d)
{
	int stat = 0;
	*y = *m = *d = 0;
	while (*date != '\0') {
		if (*date == '-') {
			stat++;
			date++;
			continue;
		}
		if (stat == 0) {
			*y = (*y) * 10 + (*date - '0'); 
		} else if (stat == 1) {
			*m = (*m) * 10 + (*date - '0'); 
		} else {
			*d = (*d) * 10 + (*date - '0'); 
		}
		date++;
	}
	return 0;
}
int dayOfYear(char * date){
	int i;
	int rlt = 0;
	int y, m, d;
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	getYMD(date, &y, &m, &d);
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		month[1] = 29;
	}
	for (i = 1; i < m; i++) {
		rlt += month[i - 1];
	}
	rlt += d;
	return rlt;
}
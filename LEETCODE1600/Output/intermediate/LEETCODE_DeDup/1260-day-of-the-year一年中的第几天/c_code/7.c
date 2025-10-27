int judgeYear(int year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 29;
	return 28;
}
int judgeMonth(int year, int month, int day){
	switch(month){
		case 1:break;
        case 2:day += 31;break;
        case 3:day += (31 + judgeYear(year));break;
        case 4:day += (62 + judgeYear(year));break;
        case 5:day += (92 + judgeYear(year));break;
        case 6:day += (123 + judgeYear(year));break;
        case 7:day += (153 + judgeYear(year));break;
        case 8:day += (184 + judgeYear(year));break;
        case 9:day += (215 + judgeYear(year));break;
        case 10:day += (245 + judgeYear(year));break;
        case 11:day += (276 + judgeYear(year));break;
        case 12:day += (306 + judgeYear(year));break;
        default:break;
	}
	return day;
}
int dayOfYear(char * date){
    int year;
    int month;
    int day;

    sscanf(date, "%d-%d-%d", &year, &month, &day);
    return judgeMonth(year, month, day);
}
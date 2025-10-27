int dayOfYear(char * date){
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i;
    int year = atoi(date);
    int month = atoi(date+5)-1;
    int day = atoi(date+8);
    
    if(((year%4==0) && (year%100!=0))||(year%400==0)){ // leap year
        days[1]++;
    }
    
    for(i=0; i<month; i++){
        day += days[i];
    }
    
    return day;
}
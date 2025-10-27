//
int isRunnian(int year){
    if(year%400==0||(year%100!=0&&year%4==0)){
        return 1;
    }
    return 0;
}
//by default date1 is earlier than date2
int minus(int day,int month,int year){
    int p[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int r[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int sum=0,i=0;
    for(i=1971;i<year;i++){
        sum+=365+isRunnian(i);
    }
    int*k=(isRunnian(year)==1)?r:p;
    for(i=1;i<month;i++){
        sum=sum+k[i];
    }
    sum+=day-1;
    return sum;
}
char * dayOfTheWeek(int day, int month, int year){
    char*whatday[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    //Jesus says that 1/1/1971 is Friday;
    int k=minus(day,month,year);
    return whatday[(5+k)%7];
}
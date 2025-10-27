int dayOfYear(char * date){
    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 +(date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    int arr1[]={31, 28, 31, 30, 31,30, 31, 31, 30, 31, 30,31};
    int arr2[]={31, 29, 31, 30, 31,30, 31, 31, 30, 31, 30,31};
    int res = day;
    if (year%4 == 0 && year%100!=0){
        for (int i=0; i<month-1; i++){
            res += arr2[i];
        }
    }
    else if(year%400 == 0){
        for (int i=0; i<month-1; i++){
            res += arr2[i];
        }
    }else{
        for (int i=0; i<month-1; i++){
            res += arr1[i];
        }
    }

    return res;
}
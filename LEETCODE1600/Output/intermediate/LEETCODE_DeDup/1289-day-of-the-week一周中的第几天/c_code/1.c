char * dayOfTheWeek(int day, int month, int year){
            int flag = 0;
            int dayOfMonth[][2] = {
                0,1,
                31,31,
                28,29,
                31,31,
                30,30,
                31,31,
                30,30,
                31,31,
                31,31,
                30,30,
                31,31,
                30,30,
                31,31
            };
            
            int sum = 0;
            
            for(int i = 1971; i < year; i++){
                if((i%4 == 0 && i%100 != 0 ) || (i % 400 == 0))
                {
                    sum+=2;
                }else{
                    sum+=1;
                }
            }    
            if((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0)){
                flag = 1;
            }
            
            for(int i = 1; i < month; i++){
                
                sum+=dayOfMonth[i][flag];
            }
            
            sum+=day;
            sum--;
            
            int mat = (5 + (sum % 7))%7;
            
            switch(mat){
                case 0:return "Sunday";
                case 1:return "Monday";
                case 2:return "Tuesday";
                case 3:return "Wednesday";
                case 4:return "Thursday";
                case 5:return "Friday";
                case 6:return "Saturday";
                default:
                    return 0;
            }
        }
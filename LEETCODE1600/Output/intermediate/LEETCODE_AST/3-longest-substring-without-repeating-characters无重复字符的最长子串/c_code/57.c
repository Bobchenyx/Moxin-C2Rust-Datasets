int lengthOfLongestSubstring(char * s){
            int NoRepeatNumber,MaxSubstringLength=0,SubStringFront=0,flag=0;   
                                        //NoRepeatNumber为当前子串长度
                                        //MaxSubstringLength为最大子串长度
                                        //SubStringFront为字串开头位置
                                        //flag用来记录当前字符串长度是否有效,0为有效
            char AtPresentChar;         //用来存储当前提取出的字符
            for(int i=0;s[i]!='\0';i++){
                AtPresentChar=s[i];
                NoRepeatNumber=i-SubStringFront+1;
                for(int j=i-1;j>=SubStringFront;j--){
                    if(AtPresentChar==s[j]){
                        NoRepeatNumber=1;
                        SubStringFront=j+1;
                        flag=1;
                        break;
                    }
                    else
                        flag=0; 
                }
                if(flag==0)
                    MaxSubstringLength=MaxSubstringLength>NoRepeatNumber?MaxSubstringLength:NoRepeatNumber;
            }
            return MaxSubstringLength;
}
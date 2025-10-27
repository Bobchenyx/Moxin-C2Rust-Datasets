java []
class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length()==0)
            return 0;

        // 去除空白, 直接调用trim()
        str = str.trim();
        if(str.length()==0)
            return 0;

        long res = 0L;
        int index = 0;
        int sgn = 1;
        
        // 符号判断
        if(str.charAt(index) == '+'){
            ++index;
            sgn = 1;
        }else if(str.charAt(index)=='-'){
            ++index;
            sgn = -1;
        }else if(!Character.isDigit(str.charAt(index))){
            return 0;
        }

        for(int i=index; i<str.length(); ++i){
            if(Character.isDigit(str.charAt(i))){
                res = res*10+(str.charAt(i)-'0');
                if(res*sgn > Integer.MAX_VALUE || res*sgn < Integer.MIN_VALUE)
                    return sgn==1? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }else{
                break;
            }
        }
        return (int)res*sgn;
        
    }
}
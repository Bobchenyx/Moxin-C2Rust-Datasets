c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();

        // 9..9
        //遍历一遍digits
        //如果存在不等于9的位，flag = 0
        //否则flag再循环结束的时候会保持1不变
        int flag = 1; 
        for(int i = 0 ; i < len ; i++)
            if(digits[i] != 9){
                flag = 0;
                break;
            }
        if(flag){	//确认是9..9的格式
            digits[0] = 1;
            for(int i = 1; i < len ;i++)
                digits[i] = 0;
            digits.push_back(0);
            return digits;
        }
		
        //1234 && 1999
        //设立p指针从最后以为向 ← 遍历
        //temp用来保存digits[p]+1
        //再次用到flag变量，如果在计算过程中没有进位（temp!=10）,则可以提前结束循环
        int p = len - 1;
        int temp;
        flag = 1;
        while(flag && p >= 0){
            temp = digits[p] + 1;
            digits[p] = temp%10;
            if(temp != 10) flag = 0;
            p--;
        }

        return digits;
    }
};
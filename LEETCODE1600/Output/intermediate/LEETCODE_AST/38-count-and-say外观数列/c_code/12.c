class Solution {
public:
    string countAndSay(int n) {
	    if (n == 1)
	    	return "1";
	    else
	    {
	    	string a = countAndSay(n - 1);//获取上一层字符串
	    	string b;
	    	int count = 1;
	    	char temp = a[0];//设一个temp用于判断当前字符和前一个字符是否相同
	    	for (int i = 1; i < a.size(); i++)//报数过程
	    	{
	       		if (temp == a[i])//当前字符和前一个字符相同 计数值加一
	    			count++;
	    		else    //否则 将之前几个字符计数情况存起来  并改变temp值
		    	{
		    		temp = a[i];
		    		b.push_back(count+'0');//存计数值count
		    		b.push_back(a[i - 1]);
                    count=1;
		    	}
	    	}
            //注意最后一组字符的处理（一组指几个相同字符或者单独一个字符，其与它之前一个字符不同）
	    	b.push_back(count+'0');
	    	b.push_back(a.back());
	    	return b;
	    }
    }
};
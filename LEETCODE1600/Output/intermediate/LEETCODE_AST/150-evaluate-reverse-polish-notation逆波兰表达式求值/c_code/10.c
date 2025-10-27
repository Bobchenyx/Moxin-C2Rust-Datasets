class Solution {
public:
    int str2num(string s) //将string转换为int类型的函数，在之后要调用
    {   
        int num;
        stringstream ss(s);
        ss>>num;
        return num;
    }
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        int n = tokens.size();
        int ans;
        if(tokens[0] != "+" && tokens[0] != "-" && tokens[0] != "*" && tokens[0] != "/") //防止测试数据仅有一个数字
            ans = str2num(tokens[0]);
        for(int i = 0; i <= n - 1 ; ++i) //运算过程
        {
            if(tokens[i] == "+")
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                ans = left + right;
                s.push(ans);
            }
            else if(tokens[i] == "-")
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                ans = left - right;
                s.push(ans);
            }
            else if(tokens[i] == "*")
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                ans = left * right;
                s.push(ans);
            }
            else if(tokens[i] == "/")
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                ans = left / right;
                s.push(ans);
            }
            else
            {
                int r = str2num(tokens[i]); //遇到数字直接push
                s.push(r);
            }
        }
        return ans;
    }
};
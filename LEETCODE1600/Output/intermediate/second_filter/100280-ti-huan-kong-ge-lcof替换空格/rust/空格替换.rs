C++ []
class Solution
{
public:
    string replaceSpace(string s)
    {
        string res = "";
        size_t const len = s.size();
        for (size_t i = 0; i < len; i++)
            if (s[i] == ' ')
                res += "%20";
            else
                res += s[i];

        return res;
    }
};
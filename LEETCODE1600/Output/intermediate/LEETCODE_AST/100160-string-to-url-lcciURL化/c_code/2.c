class Solution {
public:
    string replaceSpaces(string S, int length) {
        int _size = S.size();
        //cout<<_size<<' '<<length<<endl;
        while(length--)
        {
            if(S[length] == ' ')
            {
                S[--_size] = '0';
                S[--_size] = '2';
                S[--_size] = '%';
            }else
            {
                S[--_size] = S[length];
            }
        }
        return S.substr(_size);
    }
};
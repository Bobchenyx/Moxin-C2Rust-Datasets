class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length()-1;
        int count=0;
        for(int i=index;i>=0;i--){
          if(s[i]!=' ') count++;
          else if(s[i]==' ' && count==0) continue;
          else break;
        }

        return count;
    }
};
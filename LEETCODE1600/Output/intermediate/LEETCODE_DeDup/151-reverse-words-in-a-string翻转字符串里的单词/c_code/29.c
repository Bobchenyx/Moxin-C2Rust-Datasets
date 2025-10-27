class Solution {
public:
    string reverseWords(string s) {
        int n=s.length(),left=0,right=0;
        while(left<n&&s[left]==' ')left++;
        if(left==n)return "";
        right=left;
        while(right<n&&s[right]!=' ')right++;
        for(int i=0;i<n;i++)
        {
            if(left==n)break;
            for(int j=left;j<=(left+right-1)/2;j++)
            {
                char tmp=s[j];
                s[j]=s[right-1-j+left];
                s[right-1-j+left]=tmp;
            }
            left=right;
            while(left<n&&s[left]==' ')left++;
            if(left==n)break;
            right=left;
            while(right<n&&s[right]!=' ')right++;
        }
        for(int i=0;i<n/2;i++)
        {
            char tmp=s[i];
            s[i]=s[n-1-i];
            s[n-i-1]=tmp;
        }
        int i=0;
        while(i<n&&s[i]==' ')  i++;
        s=s.substr(i,n);
        bool flag=true;
        string::iterator it;
        //cout<<s;
        for(it=s.begin();it<s.end();it++)
        {
            if(*it==' ')
            {
                if(flag==false)
                {
                    while(it<s.end()&&*it==' ')
                    {
                        //cout<<"erase ";
                        s.erase(it);
                    }
                    flag=true;
                }
                else {flag=false;}
            }
            else flag=true;
        }
        it=s.end()-1;
        if(*it==' ')s.erase(it);
        return s;
    }
};
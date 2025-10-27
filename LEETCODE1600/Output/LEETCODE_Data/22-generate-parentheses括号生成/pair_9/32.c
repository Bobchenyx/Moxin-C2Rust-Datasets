vector<string> ans;int N;
void dfs(int l,int r,string has){
    if(r>l)return;
    if(l > N)return;
    if(l == r&& r == N){
        ans.push_back(has);return;
    }
    dfs(l+1,r,has + "(");
    dfs(l,r+1,has + ")");
}
vector<string> generateParenthesis(int n) {
    N=n;if(!N)return {};
    dfs(0,0,"");
    return ans;
}
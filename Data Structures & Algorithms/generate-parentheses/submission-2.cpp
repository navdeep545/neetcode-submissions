class Solution {

void dfs(string curr , int open, int closed, unordered_set<string> &ans){
    if(open == 0 and closed == 0){
        ans.insert(curr) ;
        return ;
    } 
    if(open > 0) dfs(curr + "(", open-1, closed, ans) ;
    if(closed > open){
        dfs(curr + ")", open, closed - 1, ans) ;
    }
    return ;
}

public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> ans ;
        string curr = "" ;
        dfs(curr,n,n, ans) ;
        return vector<string> (ans.begin(), ans.end()) ;
    }
};

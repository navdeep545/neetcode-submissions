class Solution {

int n ;

bool dfs(string& s,int idx,int open){
    if(idx == n) return open == 0 ;
    if(open < 0) return false ;
    if(s[idx] == '(') return dfs(s,idx+1,open+1) ;
    if(s[idx] == ')') return dfs(s,idx+1,open-1) ;

    return dfs(s,idx+1,open) | dfs(s,idx+1,open-1) | dfs(s,idx+1,open+1) ;
}

public:
    bool checkValidString(string s) {
        n = s.length() ;
        return dfs(s,0,0) ;
    }
};

class Solution {

int n ;
int dp[101][101] ;

bool dfs(string& s,int idx,int open){
    if(idx == n) return open == 0 ;
    if(open < 0) return false ;

    if(dp[idx][open] != -1) return dp[idx][open] ;

    if(s[idx] == '(') return dp[idx][open] = dfs(s,idx+1,open+1) ;
    if(s[idx] == ')') return dp[idx][open] = dfs(s,idx+1,open-1) ;

    return dp[idx][open] =  dfs(s,idx+1,open) | dfs(s,idx+1,open-1) | dfs(s,idx+1,open+1) ;
}

public:
    bool checkValidString(string s) {
        n = s.length() ;
        memset(dp,-1,sizeof(dp)) ;
        return dfs(s,0,0) ;
    }
};

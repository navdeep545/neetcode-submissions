class Solution {
    int n ;
    bool helper(string& s,int idx,unordered_set<string>& st,vector<int>& dp){
        if(idx == n){
            return true ;
        }
        if(dp[idx] != -1) return dp[idx] ;
        int i = idx ;
        while(i < n){
            if(st.count(s.substr(idx,i-idx+1))){
                if(helper(s,i+1,st,dp)) return dp[idx] = true ;
            }
            i++ ;
        }
        return dp[idx] = false ;
    }

public:
    bool wordBreak(string s, vector<string>& w) {
    unordered_set<string> st(w.begin(),w.end()) ;
    n = s.length() ;
    vector<int> dp(n,-1) ;
    return helper(s,0,st,dp) ;
    }
};

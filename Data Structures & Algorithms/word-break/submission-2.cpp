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
    vector<bool> dp(n+1,false) ;
    dp[n] = true ;

    for(int idx = n-1;idx >= 0 ;idx--){
        for(int i=idx;i<n;i++){
            if(st.count(s.substr(idx,i-idx+1)) && dp[i+1]){
                dp[idx] = true ;
                break ;
            }
            dp[idx] = false ;
        }
    }

    return dp[0] ;
    }
};

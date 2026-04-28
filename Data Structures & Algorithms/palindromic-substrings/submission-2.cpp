class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length() ;
        // vector<vector<bool>> dp(n,vector<bool>(n,false)) ;
        // for(int i=0;i<n;i++) dp[i][i] = true ;
        vector<bool> prev(n,false);

        int res = 0 ;
        for(int i=n-1;i>=0;i--){
            prev[i] = true ;
            vector<bool> cur(n,false) ;
            for(int j=i;j<n;j++){
                if(s[i] == s[j] && (j-i <= 2 || prev[j-1])){
                    cur[j] = true ;
                    res++ ;
                }
            }
            prev = cur ;
        }

        return res ;
    }
};

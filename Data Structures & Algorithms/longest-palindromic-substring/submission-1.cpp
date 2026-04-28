class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(),res=0,idx=-1 ;
        vector<vector<bool>> dp(n,vector<bool>(n,false)) ;
        for(int i=0;i<n;i++) dp[i][i] = true ;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true ;
                    if(j-i+1 > res){
                        idx = i ;
                        res = j-i+1 ;
                    }
                }
            }
        }

        return s.substr(idx,res) ;
    }
};

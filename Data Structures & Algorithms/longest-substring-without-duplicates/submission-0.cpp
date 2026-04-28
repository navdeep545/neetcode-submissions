class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length() ;
        int l = 0,ans = 0 ;
        unordered_set<char> s1 ;
        for(int i=0;i<n;i++){
            while(!s1.empty() && s1.count(s[i])){
                s1.erase(s[l]) ;
                l++ ;
            }
            s1.insert(s[i]) ;
            ans = max(ans,i-l+1) ;
        }

        return ans ;
    }
};

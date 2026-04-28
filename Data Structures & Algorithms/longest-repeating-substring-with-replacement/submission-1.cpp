class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size() ,l=0,res = INT_MIN ;
        vector<int> count(26,0) ;

        for(int i=0;i<n;i++){
            count[s[i]-'A']++ ;
            int currentLength = i-l+1 ;
            int mostFreq = 0 ;
            for(auto &i:count){
                mostFreq = max(mostFreq,i) ;
            }
            if(currentLength - mostFreq <= k){
                res = max(res,currentLength) ;
            }
            else {
                count[s[l]-'A']--;
                l++ ;
            }
        }
        return res ;
    }
};

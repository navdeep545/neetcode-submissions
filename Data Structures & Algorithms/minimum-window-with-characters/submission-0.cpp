class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="") return "" ;

        int n = s.length(),l=0,ans=INT_MAX,have=0,need=0;
        unordered_map<char,int> needMap,window ;
        pair<int,int> range = {-1,-1} ;

        for(auto &c:t){
            needMap[c]++ ;
        }
        need = needMap.size() ;
        for(int r=0;r<n;r++){

            window[s[r]]++ ;
            if(needMap.count(s[r]) && needMap[s[r]] == window[s[r]]){
                have++ ;
            }

            while(have==need){
                if(r-l+1 < ans){
                    ans = r-l+1 ;
                    range = {l,r}  ;
                }

                window[s[l]]-- ;
                if(needMap.count(s[l]) && window[s[l]] < needMap[s[l]]){
                    have-- ;
                }
                l++ ;
            }
        }

        return ans==INT_MAX?"":s.substr(range.first,ans) ;
    }
};

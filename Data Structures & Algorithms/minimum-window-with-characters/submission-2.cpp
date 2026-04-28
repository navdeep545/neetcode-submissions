class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.size() ;
        unordered_map<int,int> needMap,window ;
        int have=0,need=0,ans=INT_MAX,cur ;
        pair<int,int> range = {-1,-1} ;
        for(auto&i:t){
            needMap[i]++ ;
        }
        need = needMap.size() ;
        int l = 0 ;
        for(int r=0;r<n;r++){
            window[s[r]]++ ;
            if(needMap.count(s[r]) && window[s[r]] == needMap[s[r]]){
                have++ ;
            }
            while(have >= need){
                cur = r-l+1 ;
                if(cur < ans){
                    ans = cur ;
                    range = {l,r} ;
                }
                window[s[l]]-- ;
                if(needMap.count(s[l]) && needMap[s[l]] > window[s[l]]){
                    have-- ;
                }
                l++ ;
            }
        }

        return (range.first == -1) ? "" : s.substr(range.first,ans) ;
    }
};

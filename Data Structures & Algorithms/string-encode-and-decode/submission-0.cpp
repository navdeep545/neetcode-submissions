class Solution {
public:

    string encode(vector<string>& strs) {
        string ans ;
        for(auto &i:strs){
            ans.push_back('#') ;
            ans.push_back((i.length()+'0')) ;
            ans += i ;
        }
        return ans ;
    }

    vector<string> decode(string s) {
        int i = 1 ;
        int n = s.length() ;
        vector<string> ans ;
        while(i<s.length()){
            int sz = s[i]-'0' ;
            int j = i+1 ;
            string cur ;
            while(j<n && sz--){
                cur += s[j] ;
                j++ ;
            }
            ans.push_back(cur) ;
            i = j+1 ;
        }

        return ans ;
    }
};

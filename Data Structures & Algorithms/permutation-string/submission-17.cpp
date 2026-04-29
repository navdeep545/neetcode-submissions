class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length() ;
        // sort(s1.begin(), s1.end()) ;
        unordered_map<int,int> freq1 ;
        for(char& c:s1) freq1[c-'a']++ ;
        if(n > m) return false ;
        for(int i=0;i<=m-n;i++){
            string x = s2.substr(i,n) ;
            unordered_map<int,int> freq2 ;
            for(char &c:x) freq2[c-'a']++ ;
            if (freq1 == freq2) return true ;
        }

        return false ;
    }
};

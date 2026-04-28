class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length() ;
        sort(s1.begin(), s1.end()) ;
        if(n > m) return false ;
        for(int i=0;i<=m-n;i++){
            string x = s2.substr(i,n) ;
            cout << x << "\n" ;
            sort(x.begin(),x.end()) ;
            if (x == s1) return true ;
        }

        return false ;
    }
};

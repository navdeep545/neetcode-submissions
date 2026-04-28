class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() < t.length()) return isAnagram(t,s) ;
        multiset<char> s1 ;
        for(auto &i:s) s1.insert(i) ;
        for(auto &i:t){
            auto itr = s1.find(i) ;
            if(itr != s1.end()){
                s1.erase(itr) ;
            }
        }

        return s1.size() == 0 ;
    }
};

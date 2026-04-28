class Solution {

bool dfs(stack<char>& stack,unordered_map<char,vector<char>>& nodes,vector<bool>& visited,unordered_set<char>& curNodes,char node){
    visited[node-'a'] = true ;
    for(auto &i:nodes[node]){
        if(curNodes.count(i)){
            return false ;
        }
        if(!visited[i-'a']){
            curNodes.insert(i) ;
            if(!dfs(stack,nodes,visited,curNodes,i)) return false ;
            curNodes.erase(i) ;
        }
    }
    stack.push(node) ;
    return true ;
}

void helper(stack<char>& ans,unordered_map<char,vector<char>>& nodes){
    vector<bool> visited(26,false) ;
    unordered_set<char> recursion_stack ;
    for(int i=0;i<26;i++){
        if(!visited[i]){
            recursion_stack.insert(i+'a') ;
            if(!dfs(ans,nodes,visited,recursion_stack,i+'a')){
                ans = stack<char>() ;
                return ;
            } 
            recursion_stack.erase(i+'a') ;
        }
    }
}

public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> nodes ;
        for(int i=0;i<words.size()-1;i++){
            auto w1 = words[i],w2 = words[i+1] ;
            int n = words[i].length(), m = words[i+1].length() ;
            if( n > m && words[i+1].substr(0,m) == words[i].substr(0,m)) return "" ;
            for(int j=0;j<min(n,m);j++){
                if(words[i][j] != words[i+1][j]){
                    nodes[words[i][j]].push_back(words[i+1][j]) ;
                    break ;
                }
            }
        }

        stack<char> stack ;
        helper(stack,nodes) ;
        string ans = "";
        while(!stack.empty()){
            ans.push_back(stack.top()) ;
            stack.pop() ;
        }

        return ans ;
    }
};

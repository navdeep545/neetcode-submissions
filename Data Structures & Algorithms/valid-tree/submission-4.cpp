class Solution {
    
unordered_set<int> visited ;
vector<vector<int>> adj_list ;

bool dfs(int node, int parent){

    if (!visited.contains(node)) visited.insert(node) ;

    for(auto & a:adj_list[node]){
        if (a != parent){
            if (visited.contains(a)) return false ;
            int flag = dfs(a, node) ;
            if (!flag) return false ;
        }
    }

    return true ;
}

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        adj_list.resize(n) ;
        visited.clear() ;

        for(auto& e:edges){
            adj_list[e[0]].push_back(e[1]) ;
            adj_list[e[1]].push_back(e[0]) ;
        }

        return dfs(0,-1) and visited.size() == n ;
    }
};

class Solution {

bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj_list){

    if (visited[node] == 0) visited[node]++ ;

    for(auto & a:adj_list[node]){
        if (a != parent){
            if (visited[a] > 0) return false ;
            int flag = dfs(a, node, visited, adj_list) ;
            if (!flag) return false ;
        }
    }

    return true ;
}

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adj_list(n) ;

        for(auto& e:edges){
            adj_list[e[0]].push_back(e[1]) ;
            adj_list[e[1]].push_back(e[0]) ;
        }
        if (!dfs(0,-1, visited, adj_list)) return false ;
        for( auto& v:visited){
            if(v > 0){
                n-- ;
            }
        }
        return n==0 ;
    }
};

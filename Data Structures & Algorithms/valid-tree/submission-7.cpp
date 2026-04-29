class Solution {
    
vector<int> visited ;
vector<vector<int>> adj_list ;

bool dfs(int node, int parent){

    if (visited[node] == 0) visited[node]++ ;

    for(auto & a:adj_list[node]){
        if (a != parent){
            if (visited[a] > 0) return false ;
            int flag = dfs(a, node) ;
            if (!flag) return false ;
        }
    }

    return true ;
}

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        adj_list.assign(n, vector<int>()) ;
        visited.assign(n,0) ;

        for(auto& e:edges){
            adj_list[e[0]].push_back(e[1]) ;
            adj_list[e[1]].push_back(e[0]) ;
        }
        if (!dfs(0,-1)) return false ;
        for( auto& v:visited){
            if(v > 0){
                n-- ;
            }
        }
        return n==0 ;
    }
};

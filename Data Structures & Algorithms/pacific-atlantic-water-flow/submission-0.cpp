class Solution {
int m,n ;

void makeSet(queue<pair<int,int>>& que,unordered_set<int>& s1,vector<vector<int>>& heights){
    vector<vector<int>> dir = {
        {0,1},
        {1,0},
        {-1,0},
        {0,-1}
    } ;

    while(!que.empty()){
        auto top = que.front() ;
        que.pop() ;
        for(auto &d:dir){
            int x = top.first + d[0] ;
            int y = top.second + d[1] ;
            if(x >= 0 && x < n && y >= 0 && y < m && !s1.count(x*m + y) && heights[x][y] >= heights[top.first][top.second]){
                que.push({x,y}) ;
                s1.insert(x*m + y) ;
            }
        }
    }
}

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size() ;
        m = heights[0].size() ;
        queue<pair<int,int>> topLeft,bottomRight ;
        unordered_set<int> vis1,vis2 ;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 || j == 0){
                    topLeft.push({i,j}) ;
                    vis1.insert(i*m + j) ;
                }
                if(i == n-1 || j == m-1){
                    bottomRight.push({i,j}) ;
                    vis2.insert(i*m + j) ;
                }
            }
        }

        makeSet(topLeft,vis1,heights) ;
        makeSet(bottomRight,vis2,heights) ;

        vector<vector<int>> ans ;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cur = i*m + j ;
                if(vis1.count(cur) && vis2.count(cur)){
                    ans.push_back({i,j}) ;
                }
            }
        }

        return ans ;
    }
};

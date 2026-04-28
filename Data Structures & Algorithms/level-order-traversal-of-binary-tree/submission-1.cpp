/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {} ;

        queue<TreeNode*> q ;
        vector<vector<int>> ans ;

        q.push(root) ;
        while(!q.empty()){
            int sz = q.size() ;
            vector<int> cur ;
            while(sz--)
            {
                auto top = q.front() ;
                q.pop() ;
                cur.push_back(top->val) ;
                if(top->left) q.push(top->left) ;
                if(top->right) q.push(top->right) ;
            }
            ans.push_back(cur) ;
        }

        return ans ;
    }
};

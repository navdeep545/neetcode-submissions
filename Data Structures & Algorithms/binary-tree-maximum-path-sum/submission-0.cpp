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

int maxPathSum(TreeNode* root,int &res) {
        if(!root) return 0 ;
        int left = maxPathSum(root->left,res) ;
        int right = maxPathSum(root->right,res) ;
        int ans = max(root->val,max(left,right) + root->val) ;
        res = max({res,ans,root->val + left + right}) ;
        return ans ;
    }
 
    
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root,res) ;
        return res ;
    }
};

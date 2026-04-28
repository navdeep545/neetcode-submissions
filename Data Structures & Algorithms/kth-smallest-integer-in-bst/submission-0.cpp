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
vector<int> inorder(TreeNode* root){
    if(!root) return {} ;

    auto cur = inorder(root->left) ;
    cur.push_back(root->val) ;
    auto pur = inorder(root->right) ;
    cur.insert(cur.end(),pur.begin(),pur.end()) ;

    return cur ;
}

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec = inorder(root) ;
        return vec[k-1] ;
    }
};

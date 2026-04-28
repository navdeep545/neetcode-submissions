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

TreeNode* maker(vector<int>& preorder,unordered_map<int, int>& umap,int preorder_start,int preorder_end,int inorder_start,int inorder_end){
    if(preorder_end < preorder_start || inorder_end < inorder_start) return NULL ;
    if(preorder_end == preorder_start) {TreeNode* root = new TreeNode(preorder[preorder_start]) ; return root ;}
    TreeNode* root = new TreeNode(preorder[preorder_start]) ;

    int   left_preorder_start = preorder_start + 1 ;
    int   left_inorder_start = inorder_start ;
    int   left_inorder_end = umap[root->val]-1 ;
    int   left_preorder_end = left_preorder_start + left_inorder_end - left_inorder_start ;
    int   right_preorder_start = left_preorder_end + 1 ;
    int   right_preorder_end = preorder_end ;
    int   right_inorder_start = umap[root->val]+1 ;
    int   right_inorder_end = inorder_end ;
    root->left = maker(preorder,umap,left_preorder_start,left_preorder_end,left_inorder_start,left_inorder_end) ;
    root->right = maker(preorder,umap,right_preorder_start,right_preorder_end,right_inorder_start,right_inorder_end) ;

    return root ;
}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> umap ;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]] = i ;
        }
        
        return maker(preorder,umap,0,preorder.size(),0,inorder.size()-1) ;
    }
};

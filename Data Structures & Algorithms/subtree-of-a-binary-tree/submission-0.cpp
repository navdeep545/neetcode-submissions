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
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool flag = false) {

        if(!subRoot && !root) return true ;
        if((!root && subRoot) || (!subRoot && root)) return false ;
        if(flag) {
            if(root->val != subRoot->val) return false ;
            else {
                return (isSubtree(root->left,subRoot->left,flag) && isSubtree(root->right,subRoot->right,flag)) ;
            }
        }
        auto nf = false ;
        if(root->val == subRoot->val){
            nf = (isSubtree(root->left,subRoot->left,true) && isSubtree(root->right,subRoot->right,true)) ;
        }

        if(nf) return true ;

        return isSubtree(root->left,subRoot,false) | isSubtree(root->right,subRoot,false) ;
    }
};

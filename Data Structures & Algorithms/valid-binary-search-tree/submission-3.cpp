class Solution {
private:
bool F(TreeNode* root,long long maxLim,long long minLim){
    if(!root) return true ;

    if(1LL*root->val <= minLim || 1LL*root->val >= maxLim) return false ;

    auto lefter = F(root->left,root->val,minLim) ;
    if(!lefter) return false ;
    auto righter = F(root->right,maxLim,root->val) ;
    if(!righter) return false ;

    return true ;
}

public:
    bool isValidBST(TreeNode* root) {
        return F(root, LLONG_MAX, LLONG_MIN) ;
    }
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        
        int leftDepth = root->left ? minDepth(root->left) : INT_MAX;
        int rightDepth = root->right ? minDepth(root->right) : INT_MAX;
        
        return 1 + min(leftDepth, rightDepth);
    }
};
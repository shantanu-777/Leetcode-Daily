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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);

        if(root==nullptr){
            return {};
        }

        vector<int> ans;
        while(!q.empty()){
            int n = q.size();

            int res = INT_MIN;
            for(int i=0;i<n;i++){
                auto t = q.front();
                q.pop();

                res = max(res, t->val);

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

            ans.push_back(res);

        }
        return ans;
    }
};
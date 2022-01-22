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
    vector<vector<int>> Ans;
    void _solve(TreeNode* root, vector<int>& path, int targetSum){
        if(!root->left && !root->right && targetSum == root->val){
            path.push_back(root->val);
            Ans.push_back(path);
            path.pop_back();
            return ;
        }
        path.push_back(root->val);
        if(root->left) _solve(root->left, path, targetSum - root->val);
        if(root->right) _solve(root->right, path, targetSum - root->val);
        path.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> Path;
        _solve(root, Path, targetSum);
        return Ans;
    }
};
